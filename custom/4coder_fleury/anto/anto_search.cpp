
global i32 global_anto_autocomplete_index = 0;

//~

function Rect_f32
anto_draw_drop_down(Application_Links *app, Face_ID face, Fancy_Block *index_block, Fancy_Block *block,
                    Vec2_f32 p, Rect_f32 region, f32 x_padding, f32 x_half_padding,
                    FColor outline_color, FColor back_color){
    Rect_f32 box = Rf32(p, p);
    if (block->line_count > 0)
    {
        Vec2_f32 dims = get_fancy_block_dim(app, face, block);
        dims += V2f32(x_padding, 4.f);
        box = get_contained_box_near_point(region, p, dims);
        box.x0 = f32_round32(box.x0);
        box.y0 = f32_round32(box.y0);
        box.x1 = f32_round32(box.x1);
        box.y1 = f32_round32(box.y1);
        
        Face_Metrics metrics = get_face_metrics(app, face);
        
        // NOTE(anto): Little box for the index.
        Rect_f32 index_box = {0};
        index_box.x0 = box.x0 - metrics.line_height;
        index_box.x1 = box.x0;
        index_box.y0 = box.y0;
        index_box.y1 = box.y0 + metrics.line_height;
        
        // NOTE(anto): Debugging the position of the rectangles.
        /* 
                Scratch_Block scratch(app);
                print_message(app, push_u8_stringf(scratch, "line_height: %.1f\n", metrics.line_height));
                print_message(app, push_u8_stringf(scratch, "block: (x0:%.1f, y0:%.2f), (x1:%.1f, y1:%.1f)\n", box.x0, box.y0, box.x1, box.y1));
                print_message(app, push_u8_stringf(scratch, "index: (x0:%.1f, y0:%.2f), (x1:%.1f, y1:%.1f)\n", index_box.x0, index_box.y0, index_box.x1, index_box.y1));
                 */
        
        Rect_f32 prev_clip = draw_set_clip(app, box);
        F4_DrawTooltipRect(app, box);
        draw_rectangle_outline(app, box, 4.f, 3.f, fcolor_resolve(fcolor_id(defcolor_margin_active)));
        draw_margin(app, box, rect_inner(box, 1.f), outline_color);
        draw_fancy_block(app, face, fcolor_zero(), block, box.p0 + V2f32(x_half_padding, 2.f));
        draw_set_clip(app, prev_clip);
        
        if (0)
        {
            F4_DrawTooltipRect(app, index_box);
            draw_rectangle_outline(app, index_box, 4.f, 3.f, fcolor_resolve(fcolor_id(defcolor_margin_active)));
            draw_margin(app, index_box, rect_inner(index_box, 1.f), outline_color);
            draw_fancy_block(app, face, fcolor_zero(), index_block, index_box.p0 + V2f32(x_half_padding, 2.f));
        }
    }
    return(box);
}

//~

function void
anto_word_complete_menu_render(Application_Links *app, Frame_Info frame_info, View_ID view)
{
    Managed_Scope scope = view_get_managed_scope(app, view);
    Word_Complete_Menu **menu_ptr = scope_attachment(app, scope, view_word_complete_menu, Word_Complete_Menu*);
    Word_Complete_Menu *menu = *menu_ptr;
    
    if (menu != 0)
    {
        menu->prev_render_caller(app, frame_info, view);
        
        Face_ID face = global_anto_code_face;
        Scratch_Block scratch(app);
        
        Fancy_Block block = {};
        for (i32 i = 0; i < menu->count; i += 1)
        {
            if (menu->options[i].size > 0)
            {
                FColor option_color = {0};
                Fancy_Line *line = push_fancy_line(scratch, &block, face);
                
                if (i == global_anto_autocomplete_index)
                {
                    option_color = fcolor_id(defcolor_cursor);
                    push_fancy_stringf(scratch, line, fcolor_id(defcolor_pop2), "*");
                }
                else
                {
                    option_color = fcolor_id(defcolor_comment);
                    push_fancy_stringf(scratch, line, fcolor_id(defcolor_pop2), " ");
                }
                
                push_fancy_string(scratch, line, option_color, menu->options[i]);
                
                if (i == global_anto_autocomplete_index)
                {
                    push_fancy_stringf(scratch, line, fcolor_id(defcolor_pop2), "*");
                }
                else
                {
                    push_fancy_stringf(scratch, line, fcolor_id(defcolor_pop2), " ");
                }
            }
        }
        
        //~ NOTE(anto): This allows to show the index at the index_box left to the autocomplete_box
        
        Scratch_Block index_scratch(app);
        
        Fancy_Block index_block = {};
        Fancy_Line *index_line = push_fancy_line(index_scratch, &index_block, face);
        push_fancy_stringf(index_scratch, index_line, fcolor_id(defcolor_pop1), "%d", global_anto_autocomplete_index + 1);
        
        //~
        
        Rect_f32 region = view_get_buffer_region(app, view);
        
        Buffer_Scroll scroll = view_get_buffer_scroll(app, view);
        Buffer_Point buffer_point = scroll.position;
        i64 pos = view_get_cursor_pos(app, view);
        Vec2_f32 cursor_p = view_relative_xy_of_pos(app, view, buffer_point.line_number, pos);
        cursor_p -= buffer_point.pixel_shift;
        cursor_p += region.p0;
        
        Face_Metrics metrics = get_face_metrics(app, face);
        f32 x_padding = metrics.normal_advance;
        f32 x_half_padding = x_padding*0.5f;
        
        anto_draw_drop_down(app, face, &index_block, &block, cursor_p, region, x_padding, x_half_padding,
                            fcolor_id(defcolor_margin_hover), fcolor_id(defcolor_back));
    }
}

//~

// TODO(anto): Fix the bug where the largest option of text is preferred to the shorter ones in the options. Not to do with the index being offset.

//get_word_complete_from_user_drop_down
function Edit
anto_get_word_complete_from_user_drop_down(Application_Links *app)
{
    View_ID view = get_this_ctx_view(app, Access_Always);
    View_Context ctx = view_current_context(app, view);
    Render_Caller_Function *prev_render_caller = ctx.render_caller;
    
    Edit result = {};
    
    Word_Complete_Iterator *it = word_complete_get_shared_iter(app);
    
    i64 pos = view_get_cursor_pos(app, view);
    Buffer_ID buffer = view_get_buffer(app, view, Access_ReadWriteVisible);
    Range_i64 range = get_word_complete_needle_range(app, buffer, pos);
    
    if (range_size(range) != 0)
    {
        word_complete_iter_init(buffer, range, it);
        Word_Complete_Menu menu = make_word_complete_menu(prev_render_caller, it);
        word_complete_menu_next(&menu);
        
        ctx.render_caller = anto_word_complete_menu_render;
        View_Context_Block ctx_block(app, view, &ctx);
        
        Managed_Scope scope = view_get_managed_scope(app, view);
        Word_Complete_Menu **menu_ptr = scope_attachment(app, scope, view_word_complete_menu, Word_Complete_Menu*);
        *menu_ptr = &menu;
        
        // NOTE(anto): The maximum amount of options is 8.
        if (global_anto_autocomplete_index + 1 > 8)
        {
            global_anto_autocomplete_index = 7;
        }
        
        b32 keep_looping_menu = true;
        for (;keep_looping_menu;)
        {
            User_Input in = get_next_input(app, EventPropertyGroup_Any, EventProperty_Escape);
            
            // NOTE(anto): Hitting escape will cause to abort the input handling.
            if (in.abort)
            {
                global_anto_autocomplete_index = 0;
                break;
            }
            
            b32 handled = true;
            switch (in.event.kind)
            {
                case InputEventKind_TextInsert:
                {
                    write_text_input(app);
                    pos = view_get_cursor_pos(app, view);
                    range = get_word_complete_needle_range(app, buffer, pos);
                    if (range_size(range) == 0)
                    {
                        keep_looping_menu = false;
                        global_anto_autocomplete_index = 0;
                    }
                    else
                    {
                        word_complete_iter_init(buffer, range, it);
                        menu = make_word_complete_menu(prev_render_caller, it);
                        word_complete_menu_next(&menu);
                        if (menu.count == 0)
                        {
                            keep_looping_menu = false;
                            global_anto_autocomplete_index = 0;
                        }
                    }
                }break;
                
                case InputEventKind_KeyStroke:
                {
                    switch (in.event.key.code)
                    {
                        case KeyCode_Return:
                        {
                            i32 index = global_anto_autocomplete_index;
                            result.text = menu.options[index];
                            result.range = range;
                            keep_looping_menu = false;
                            global_anto_autocomplete_index = 0;
                        }break;
                        
                        case KeyCode_Tab:
                        {
                            i32 next = global_anto_autocomplete_index + 1;
                            
                            if (next >= menu.count)
                            {
                                global_anto_autocomplete_index = 0;
                                word_complete_menu_next(&menu);
                            }
                            else
                            {
                                global_anto_autocomplete_index += 1;
                            }
                        }break;
                        
                        case KeyCode_Down:
                        {
                            i32 next = global_anto_autocomplete_index + 1;
                            
                            if (next >= menu.count)
                            {
                                global_anto_autocomplete_index = 0;
                            }
                            else
                            {
                                global_anto_autocomplete_index += 1;
                            }
                        }break;
                        
                        case KeyCode_Up:
                        {
                            i32 prev = global_anto_autocomplete_index - 1;
                            
                            if (prev < 0)
                            {
                                global_anto_autocomplete_index = menu.count - 1;
                            }
                            else
                            {
                                global_anto_autocomplete_index -= 1;
                            }
                        }break;
                        
                        case KeyCode_Backspace:
                        {
                            backspace_char(app);
                            pos = view_get_cursor_pos(app, view);
                            range = get_word_complete_needle_range(app, buffer, pos);
                            if (range_size(range) == 0)
                            {
                                keep_looping_menu = false;
                                global_anto_autocomplete_index = 0;
                            }
                            else
                            {
                                word_complete_iter_init(buffer, range, it);
                                menu = make_word_complete_menu(prev_render_caller, it);
                                word_complete_menu_next(&menu);
                                if (menu.count == 0)
                                {
                                    keep_looping_menu = false;
                                    global_anto_autocomplete_index = 0;
                                }
                            }
                        }break;
                        
                        default:
                        {
                            leave_current_input_unhandled(app);
                        }break;
                    }
                }break;
                
                case InputEventKind_MouseButton:
                {
                    leave_current_input_unhandled(app);
                    keep_looping_menu = false;
                }break;
                
                default:
                {
                    handled = false;
                }break;
            }
            
            if (!handled)
            {
                leave_current_input_unhandled(app);
            }
        }
        
        scope = view_get_managed_scope(app, view);
        menu_ptr = scope_attachment(app, scope, view_word_complete_menu, Word_Complete_Menu*);
        *menu_ptr = 0;
    }
    
    return(result);
}