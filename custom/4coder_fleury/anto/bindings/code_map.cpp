Bind(move_left_alpha_numeric_boundary,           KeyCode_Left, KeyCode_Control);
Bind(move_right_alpha_numeric_boundary,          KeyCode_Right, KeyCode_Control);
Bind(move_left_alpha_numeric_or_camel_boundary,  KeyCode_Left, KeyCode_Alt);
Bind(move_right_alpha_numeric_or_camel_boundary, KeyCode_Right, KeyCode_Alt);
Bind(anto_autocomplete,          KeyCode_Tab);
Bind(word_complete_drop_down,    KeyCode_Tab, KeyCode_Shift, KeyCode_Control);
Bind(write_todo,                 KeyCode_T, KeyCode_Alt);
Bind(write_note,                 KeyCode_Y, KeyCode_Alt);
Bind(list_all_locations_of_type_definition,               KeyCode_D, KeyCode_Alt);
Bind(list_all_locations_of_type_definition_of_identifier, KeyCode_T, KeyCode_Alt, KeyCode_Shift);
Bind(open_long_braces,           KeyCode_LeftBracket, KeyCode_Control);
Bind(open_long_braces_semicolon, KeyCode_LeftBracket, KeyCode_Control, KeyCode_Shift);
Bind(open_long_braces_break,     KeyCode_RightBracket, KeyCode_Control, KeyCode_Shift);
Bind(open_file_in_quotes,        KeyCode_1, KeyCode_Alt);
Bind(write_zero_struct,          KeyCode_0, KeyCode_Control);

// NOTE(anto): Fleury stuff
BindTextInput(fleury_write_text_and_auto_indent);
