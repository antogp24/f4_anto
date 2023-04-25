Bind(delete_char,            KeyCode_Delete);
Bind(backspace_char,         KeyCode_Backspace);
Bind(move_up,                KeyCode_Up);
Bind(move_down,              KeyCode_Down);
Bind(move_left,              KeyCode_Left);
Bind(move_right,             KeyCode_Right);
Bind(seek_end_of_line,       KeyCode_End);
Bind(seek_beginning_of_line, KeyCode_Home);
Bind(page_up,                KeyCode_PageUp);
Bind(page_down,              KeyCode_PageDown);
Bind(goto_beginning_of_file, KeyCode_PageUp, KeyCode_Control);
Bind(goto_end_of_file,       KeyCode_PageDown, KeyCode_Control);
Bind(move_up_to_blank_line_end,        KeyCode_Up, KeyCode_Control);
Bind(move_down_to_blank_line_end,      KeyCode_Down, KeyCode_Control);
Bind(move_left_whitespace_boundary,    KeyCode_Left, KeyCode_Control);
Bind(move_right_whitespace_boundary,   KeyCode_Right, KeyCode_Control);
Bind(move_line_up,                     KeyCode_Up, KeyCode_Alt);
Bind(move_line_down,                   KeyCode_Down, KeyCode_Alt);
Bind(backspace_alpha_numeric_boundary, KeyCode_Backspace, KeyCode_Control);
Bind(delete_alpha_numeric_boundary,    KeyCode_Delete, KeyCode_Control);
Bind(snipe_backward_whitespace_or_token_boundary, KeyCode_Backspace, KeyCode_Alt);
Bind(snipe_forward_whitespace_or_token_boundary,  KeyCode_Delete, KeyCode_Alt);
Bind(set_mark,                    KeyCode_Space, KeyCode_Control);
Bind(replace_in_range,            KeyCode_A, KeyCode_Control);
Bind(copy,                        KeyCode_C, KeyCode_Control);
Bind(delete_range,                KeyCode_D, KeyCode_Control);
Bind(delete_line,                 KeyCode_D, KeyCode_Control, KeyCode_Shift);
Bind(center_view,                 KeyCode_E, KeyCode_Control);
Bind(left_adjust_view,            KeyCode_E, KeyCode_Control, KeyCode_Shift);
Bind(search,                      KeyCode_F, KeyCode_Control);
Bind(list_all_locations,          KeyCode_F, KeyCode_Control, KeyCode_Shift);
Bind(list_all_substring_locations_case_insensitive, KeyCode_F, KeyCode_Alt);
Bind(goto_line,                   KeyCode_G, KeyCode_Control);
Bind(list_all_locations_of_selection,  KeyCode_G, KeyCode_Control, KeyCode_Shift);
Bind(snippet_lister,              KeyCode_J, KeyCode_Control);
Bind(kill_buffer,                 KeyCode_K, KeyCode_Control, KeyCode_Shift);
Bind(duplicate_line,              KeyCode_L, KeyCode_Control);
Bind(reopen,                      KeyCode_O, KeyCode_Control, KeyCode_Shift);
Bind(query_replace,               KeyCode_Q, KeyCode_Control);
Bind(query_replace_identifier,    KeyCode_Q, KeyCode_Control, KeyCode_Shift);
Bind(query_replace_selection,     KeyCode_Q, KeyCode_Alt);
Bind(reverse_search,              KeyCode_R, KeyCode_Control);
Bind(save,                        KeyCode_S, KeyCode_Control);
Bind(save_all_dirty_buffers,      KeyCode_S, KeyCode_Control, KeyCode_Shift);
Bind(search_identifier,           KeyCode_T, KeyCode_Control);
Bind(list_all_locations_of_identifier, KeyCode_T, KeyCode_Control, KeyCode_Shift);
Bind(paste_and_indent,            KeyCode_V, KeyCode_Control);
Bind(paste_next_and_indent,       KeyCode_V, KeyCode_Control, KeyCode_Shift);
Bind(cut,                         KeyCode_X, KeyCode_Control);
Bind(redo,                        KeyCode_Y, KeyCode_Control);
Bind(undo,                        KeyCode_Z, KeyCode_Control);
Bind(if_read_only_goto_position,  KeyCode_Return);
Bind(if_read_only_goto_position_same_panel, KeyCode_Return, KeyCode_Shift);
Bind(view_jump_list_with_lister,  KeyCode_Period, KeyCode_Control, KeyCode_Shift);

// Fleury:
BindTextInput(fleury_write_text_input);
Bind(fleury_write_zero_struct,      KeyCode_0, KeyCode_Control);

// NOTE(anto): Modified @4coder_base_commands.cpp
BindMouse(mouse_insert_drag,        MouseCode_Left);
BindMouseRelease(click_set_cursor,  MouseCode_Left);
BindMouse(mouse_visual_selection,   MouseCode_Right);
BindMouseRelease(click_set_cursor,  MouseCode_Right);
BindCore(click_set_cursor_and_mark, CoreCode_ClickActivateView);
BindMouseMove(click_set_cursor_if_lr_button);