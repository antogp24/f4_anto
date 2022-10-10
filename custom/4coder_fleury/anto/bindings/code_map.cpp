Bind(move_left_alpha_numeric_boundary,           KeyCode_Left, KeyCode_Control);
Bind(move_right_alpha_numeric_boundary,          KeyCode_Right, KeyCode_Control);
Bind(move_left_alpha_numeric_or_camel_boundary,  KeyCode_Left, KeyCode_Alt);
Bind(move_right_alpha_numeric_or_camel_boundary, KeyCode_Right, KeyCode_Alt);
Bind(comment_line_toggle,        KeyCode_Semicolon, KeyCode_Control);
Bind(word_complete,              KeyCode_Tab);
Bind(auto_indent_range,          KeyCode_Tab, KeyCode_Control);
Bind(auto_indent_line_at_cursor, KeyCode_Tab, KeyCode_Shift);
Bind(word_complete_drop_down,    KeyCode_Tab, KeyCode_Shift, KeyCode_Control);
Bind(write_block,                KeyCode_R, KeyCode_Alt);
Bind(write_todo,                 KeyCode_T, KeyCode_Alt);
Bind(write_note,                 KeyCode_Y, KeyCode_Alt);
Bind(list_all_locations_of_type_definition,               KeyCode_D, KeyCode_Alt);
Bind(list_all_locations_of_type_definition_of_identifier, KeyCode_T, KeyCode_Alt, KeyCode_Shift);
Bind(open_long_braces,           KeyCode_LeftBracket, KeyCode_Control);
Bind(open_long_braces_semicolon, KeyCode_LeftBracket, KeyCode_Control, KeyCode_Shift);
Bind(open_long_braces_break,     KeyCode_RightBracket, KeyCode_Control, KeyCode_Shift);
Bind(select_surrounding_scope,   KeyCode_LeftBracket, KeyCode_Alt);
Bind(select_surrounding_scope_maximal, KeyCode_LeftBracket, KeyCode_Alt, KeyCode_Shift);
Bind(select_prev_scope_absolute, KeyCode_RightBracket, KeyCode_Alt);
Bind(select_prev_top_most_scope, KeyCode_RightBracket, KeyCode_Alt, KeyCode_Shift);
Bind(select_next_scope_absolute, KeyCode_Quote, KeyCode_Alt);
Bind(select_next_scope_after_current, KeyCode_Quote, KeyCode_Alt, KeyCode_Shift);
Bind(place_in_scope,             KeyCode_ForwardSlash, KeyCode_Alt);
Bind(delete_current_scope,       KeyCode_Minus, KeyCode_Alt);
//Bind(if0_off,                    KeyCode_I, KeyCode_Alt);
Bind(open_file_in_quotes,        KeyCode_1, KeyCode_Alt);
Bind(open_matching_file_cpp,     KeyCode_2, KeyCode_Alt);
Bind(write_zero_struct,          KeyCode_0, KeyCode_Control);
Bind(jump_to_definition_at_cursor, KeyCode_W, KeyCode_Control);

// NOTE(anto): Fleury stuff
BindTextInput(fleury_write_text_and_auto_indent);
BindMouse(f4_lego_click_store_token_1, MouseCode_Right);
BindMouse(f4_lego_click_store_token_2, MouseCode_Middle);