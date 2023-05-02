/* date = August 21st 2022 1:36 pm */

#ifndef ANTO_COMMANDS_H
#define ANTO_COMMANDS_H

// Helper Functions

bool is_on_end_of_line(Application_Links *app)
{
    View_ID view = get_active_view(app, Access_ReadVisible);
    Buffer_ID buffer = view_get_buffer(app, view, Access_ReadVisible);
    i64 pos = view_get_cursor_pos(app, view);
    i64 line_number = get_line_number_from_pos(app, buffer, pos);
    i64 end_pos = get_line_end_pos(app, buffer, line_number);
    return pos == end_pos;
}

internal f32
anto_get_half_page_jump(Application_Links *app, View_ID view)
{
    Rect_f32 region = view_get_buffer_region(app, view);
    f32 page_jump = rect_height(region)*.9f;
    return(page_jump/1.2f);
}

#include "anto_search.cpp"

// Normal Mode Commands

CUSTOM_COMMAND_SIG(half_page_up)
CUSTOM_DOC("(Control+U): Scrolls the view and cursor up by half a view height.")
{
    View_ID view = get_active_view(app, Access_ReadVisible);
    f32 page_jump = anto_get_half_page_jump(app, view);
    move_vertical_pixels(app, -page_jump/2);
    center_view( app );
}

CUSTOM_COMMAND_SIG(half_page_down)
CUSTOM_DOC("(Control+D): Scrolls the view and cursor down by half a view height.")
{
    View_ID view = get_active_view(app, Access_ReadVisible);
    f32 page_jump = anto_get_half_page_jump(app, view);
    move_vertical_pixels(app, page_jump/2);
    center_view( app );
}

CUSTOM_COMMAND_SIG(anto_jump_to_definition)
CUSTOM_DOC("(Alt+Shift+J): Select a token in the list to go to it's definition.")
{
    go_to_normal_mode( app );
    jump_to_definition( app );
    center_view( app );
}

CUSTOM_COMMAND_SIG(anto_jump_to_definition_at_cursor)
CUSTOM_DOC("(Shift+J): Goes to the definition of the token that the cursor sits on.")
{
    go_to_normal_mode( app );
    jump_to_definition_at_cursor( app );
    center_view( app );
}

CUSTOM_COMMAND_SIG( eol_ins )
CUSTOM_DOC("(Shift+A): End of line and go to insert mode.")
{
    seek_end_of_line( app );
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( sol_ins )
CUSTOM_DOC("(Shift+I): Start of line and go to insert mode.")
{
    seek_beginning_of_line( app );
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( nxt_chr_ins )
CUSTOM_DOC("(A): Move right the cursor and go to insert mode.")
{
    if (!is_on_end_of_line(app))
    {
        move_right( app );
    }
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( nxt_ln_ins )
CUSTOM_DOC("(O): Move right the cursor and go to insert mode.")
{
    seek_end_of_line( app );
    casey_newline_and_indent( app );
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( prev_ln_ins )
CUSTOM_DOC("(Shift+O): Move right the cursor and go to insert mode.")
{
    seek_beginning_of_line( app );
    casey_newline_and_indent( app );
    move_up( app );
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( go_to_visual_line )
CUSTOM_DOC("(Shift+V): Highlight the line and go to visual mode.")
{
    go_to_visual_mode( app );
    seek_beginning_of_line( app );
    set_mark( app );
    seek_end_of_line( app );
}

CUSTOM_COMMAND_SIG( nxt_ln_paste )
CUSTOM_DOC("(Shift+P): Go to the next line and paste.")
{
    seek_end_of_line( app );
    casey_newline_and_indent( app );
    paste_and_indent( app );
}

CUSTOM_COMMAND_SIG( copy_ln )
CUSTOM_DOC("(Shift+Y): Copy the line at the cursor.")
{
    go_to_visual_line( app );
    copy( app );
    go_to_normal_mode( app );
    seek_beginning_of_line( app );
}

CUSTOM_COMMAND_SIG( cut_ln )
CUSTOM_DOC("(Shift+C): Cut the line at the cursor.")
{
    go_to_visual_line( app );
    cut( app );
    go_to_normal_mode( app );
    seek_beginning_of_line( app );
}

// "Smart" Commands

CUSTOM_COMMAND_SIG( mouse_insert_drag )
CUSTOM_DOC("Go to insert mode when dragging the cursor.")
{
    if (current_anto_cursor != anto_cursor_insert)
    {
        go_to_insert_mode( app );
    }
    click_set_cursor_and_mark( app );
}

CUSTOM_COMMAND_SIG( mouse_visual_selection )
CUSTOM_DOC("Go to visual mode when dragging the cursor.")
{
    if (current_anto_cursor != anto_cursor_visual)
    {
        go_to_visual_mode( app );
    }
    click_set_cursor_and_mark( app );
}

// Insert Mode

CUSTOM_COMMAND_SIG(anto_autocomplete)
CUSTOM_DOC("Word completion with a pretty drop-down.")
{
    View_ID view = get_active_view(app, Access_ReadWriteVisible);
    Buffer_ID buffer = view_get_buffer(app, view, Access_ReadWriteVisible);
    
    if (buffer != 0)
    {
        Edit edit = anto_get_word_complete_from_user_drop_down(app);
        if (edit.text.size > 0)
        {
            buffer_replace_range(app, buffer, edit.range, edit.text);
            view_set_cursor_and_preferred_x(app, view, seek_pos(edit.range.min + edit.text.size));
        }
    }
}

// Dumb Autocomplete Commands

CUSTOM_COMMAND_SIG( write_curly )
CUSTOM_DOC("Autocomplete {} on insert mode.")
{
    View_ID view = get_active_view( app, 0 );
    write_string( app, string_u8_litexpr( "{}" ) );
    view_set_cursor( app, view, seek_pos( view_get_cursor_pos( app, view ) - 1 ) );
}

CUSTOM_COMMAND_SIG( write_square )
CUSTOM_DOC("Autocomplete [] on insert mode.")
{
    View_ID view = get_active_view( app, 0 );
    write_string( app, string_u8_litexpr( "[]" ) );
    view_set_cursor( app, view, seek_pos( view_get_cursor_pos( app, view ) - 1 ) );
}

CUSTOM_COMMAND_SIG( write_dquotes )
CUSTOM_DOC("Autocomplete \"\" on insert mode.")
{
    View_ID view = get_active_view( app, 0 );
    write_string( app, string_u8_litexpr( "\"\"" ) );
    view_set_cursor( app, view, seek_pos( view_get_cursor_pos( app, view ) - 1 ) );
}

// Lister

CUSTOM_COMMAND_SIG( lister_next )
CUSTOM_DOC("(Ctrl/Alt+N): Move to the next element in the lister.")
{
    View_ID view = get_active_view(app, 0);
    Lister *lister = view_get_lister(app, view);
    
    if (lister->handlers.navigate != 0)
    {
        lister->handlers.navigate(app, view, lister, 1); // Forward
    }
}

CUSTOM_COMMAND_SIG( lister_prev )
CUSTOM_DOC("(Ctrl/Alt+P): Move to the previous element in the lister.")
{
    View_ID view = get_active_view(app, 0);
    Lister *lister = view_get_lister(app, view);
    if (lister->handlers.navigate != 0)
    {
        lister->handlers.navigate(app, view, lister, -1); // Backwards
    }
}

#endif //ANTO_COMMANDS_H
