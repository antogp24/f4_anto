// Selection Actions
Bind( delete_char,         KeyCode_X );
Bind( delete_line,         KeyCode_D, KeyCode_Shift );
Bind( move_line_up,        KeyCode_K, KeyCode_Alt );
Bind( move_line_down,      KeyCode_J, KeyCode_Alt );
Bind( duplicate_line,      KeyCode_L, KeyCode_Shift );
Bind( comment_line_toggle, KeyCode_Semicolon );

// Font Actions
Bind( increase_face_size, KeyCode_Equal, KeyCode_Shift );
Bind( decrease_face_size, KeyCode_Minus, KeyCode_Shift );

// Clipboard Actions
Bind( copy_ln,          KeyCode_Y, KeyCode_Shift );
Bind( cut_ln,           KeyCode_C, KeyCode_Shift );
Bind( paste_and_indent, KeyCode_P );
Bind( nxt_ln_paste,     KeyCode_P, KeyCode_Shift );

// History Actions
Bind( undo, KeyCode_U);
Bind( redo, KeyCode_U, KeyCode_Shift );

// Jumping Actions
Bind( goto_beginning_of_file,               KeyCode_G );
Bind( goto_end_of_file,                     KeyCode_G, KeyCode_Shift );
Bind( seek_beginning_of_textual_line,       KeyCode_0 );
Bind( seek_end_of_textual_line,             KeyCode_4, KeyCode_Shift );
Bind( goto_line,                            KeyCode_G, KeyCode_Alt );
Bind( search,                               KeyCode_ForwardSlash );
Bind( reverse_search,                       KeyCode_ForwardSlash, KeyCode_Shift );
Bind( jump_to_definition_at_cursor,         KeyCode_J, KeyCode_Shift );
Bind( jump_to_definition,                   KeyCode_J, KeyCode_Shift, KeyCode_Alt );

// Listing Actions
Bind( list_all_locations_of_identifier, KeyCode_L, KeyCode_Alt );

// Panels Actions
Bind( change_active_panel,   KeyCode_Comma );
Bind( close_panel,           KeyCode_0, KeyCode_Alt );
Bind( swap_panels,           KeyCode_1 );
Bind( open_panel_hsplit,     KeyCode_2 );
Bind( open_panel_vsplit,     KeyCode_3 );

// Buffers Actions
Bind( interactive_kill_buffer,   KeyCode_K, KeyCode_Shift );

// Replacing Actions
Bind( query_replace, KeyCode_R );

// Fuck yes, vim
Bind( go_to_insert_mode, KeyCode_I );
Bind( go_to_visual_mode, KeyCode_V );
Bind( go_to_visual_line, KeyCode_V, KeyCode_Shift );
Bind( move_left,         KeyCode_H );
Bind( move_right,        KeyCode_L );
Bind( move_up,           KeyCode_K );
Bind( move_down,         KeyCode_J );

// Vim Actions
Bind( sol_ins,     KeyCode_I, KeyCode_Shift );
Bind( eol_ins,     KeyCode_A, KeyCode_Shift );
Bind( nxt_chr_ins, KeyCode_A );
Bind( nxt_ln_ins,  KeyCode_O );
Bind( prev_ln_ins, KeyCode_O, KeyCode_Shift );

// Boundary Navigation Actions
Bind( move_left_token_boundary,          KeyCode_B );
Bind( move_right_token_boundary,         KeyCode_W );
Bind( move_left_alpha_numeric_boundary,  KeyCode_H,     KeyCode_Control );
Bind( move_right_alpha_numeric_boundary, KeyCode_L,     KeyCode_Control );
Bind( move_up_to_blank_line_end,         KeyCode_K,     KeyCode_Control );
Bind( move_down_to_blank_line_end,       KeyCode_J,     KeyCode_Control );
Bind( move_left_alpha_numeric_boundary,  KeyCode_Left,  KeyCode_Control );
Bind( move_right_alpha_numeric_boundary, KeyCode_Right, KeyCode_Control );
Bind( move_up_to_blank_line_end,         KeyCode_Up,    KeyCode_Control );
Bind( move_down_to_blank_line_end,       KeyCode_Down,  KeyCode_Control );

// Fleury:
//Bind( f4_search_for_definition__project_wide, KeyCode_J, KeyCode_Shift );
//Bind( f4_search_for_definition__current_file, KeyCode_J, KeyCode_Shift, KeyCode_Alt );
Bind( fleury_toggle_battery_saver,            KeyCode_Tick );
