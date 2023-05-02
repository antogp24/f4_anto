
#define MOVE_LEFT_KEY  KeyCode_H
#define MOVE_DOWN_KEY  KeyCode_J
#define MOVE_UP_KEY    KeyCode_K
#define MOVE_RIGHT_KEY KeyCode_L

// Selection Actions
Bind( delete_char,         KeyCode_X );
Bind( delete_line,         KeyCode_D, KeyCode_Shift );
Bind( move_line_up,        MOVE_UP_KEY, KeyCode_Alt );
Bind( move_line_down,      MOVE_DOWN_KEY, KeyCode_Alt );
Bind( duplicate_line,      KeyCode_L, KeyCode_Shift );
Bind( comment_line_toggle, KeyCode_Semicolon );

// Font Actions
Bind( increase_face_size,  KeyCode_Equal, KeyCode_Shift );
Bind( decrease_face_size,  KeyCode_Minus, KeyCode_Shift );
Bind( center_view,         KeyCode_E, KeyCode_Control );

// Clipboard Actions
Bind( copy_ln,          KeyCode_Y, KeyCode_Shift );
Bind( cut_ln,           KeyCode_C, KeyCode_Shift );
Bind( paste_and_indent, KeyCode_P );
Bind( nxt_ln_paste,     KeyCode_P, KeyCode_Shift );

// History Actions
Bind( undo, KeyCode_U);
Bind( redo, KeyCode_U, KeyCode_Shift );

// Jumping Actions
Bind( goto_beginning_of_file,              KeyCode_G );
Bind( goto_end_of_file,                    KeyCode_G, KeyCode_Shift );
Bind( seek_beginning_of_textual_line,      KeyCode_0 );
Bind( seek_end_of_textual_line,            KeyCode_4, KeyCode_Shift );
Bind( seek_end_of_textual_line,            KeyCode_4);
Bind( goto_line,                           KeyCode_G, KeyCode_Alt );
Bind( search,                              KeyCode_ForwardSlash );
Bind( search_identifier,                   KeyCode_ForwardSlash, KeyCode_Shift );
Bind( anto_jump_to_definition_at_cursor,   KeyCode_J, KeyCode_Shift );
Bind( anto_jump_to_definition,             KeyCode_J, KeyCode_Shift, KeyCode_Alt );
Bind( casey_find_matching_file,            KeyCode_H, KeyCode_Control );

// Listing Actions
Bind( list_all_locations_of_identifier, KeyCode_L, KeyCode_Alt );

// Panels Actions
Bind( change_active_panel,   KeyCode_Comma );
Bind( close_panel,           KeyCode_0, KeyCode_Alt );
Bind( close_panel,           KeyCode_0, KeyCode_Control );
Bind( swap_panels,           KeyCode_1 );
Bind( open_panel_hsplit,     KeyCode_2 );
Bind( open_panel_vsplit,     KeyCode_3 );

// Buffers Actions
Bind( interactive_kill_buffer,   KeyCode_K, KeyCode_Shift );

// Replacing Actions
Bind( query_replace, KeyCode_R );

// Vim-like
Bind( go_to_insert_mode, KeyCode_I );
Bind( go_to_visual_mode, KeyCode_V );
Bind( go_to_visual_line, KeyCode_V, KeyCode_Shift );
Bind( move_left,         MOVE_LEFT_KEY );
Bind( move_right,        MOVE_RIGHT_KEY );
Bind( move_up,           MOVE_UP_KEY );
Bind( move_down,         MOVE_DOWN_KEY );
Bind( command_lister,    KeyCode_Semicolon, KeyCode_Shift );

// Vim Actions
Bind( sol_ins,     KeyCode_I, KeyCode_Shift );
Bind( eol_ins,     KeyCode_A, KeyCode_Shift );
Bind( nxt_chr_ins, KeyCode_A );
Bind( nxt_ln_ins,  KeyCode_O );
Bind( prev_ln_ins, KeyCode_O, KeyCode_Shift );

// Boundary Navigation Actions
Bind( move_left_alpha_numeric_boundary,  KeyCode_B );
Bind( move_right_alpha_numeric_boundary, KeyCode_W );
Bind( half_page_up,                      KeyCode_U,      KeyCode_Control );
Bind( half_page_down,                    KeyCode_D,      KeyCode_Control );
Bind( move_up_to_blank_line_end,         MOVE_UP_KEY,    KeyCode_Control );
Bind( move_down_to_blank_line_end,       MOVE_DOWN_KEY,  KeyCode_Control );

Bind( move_left_alpha_numeric_boundary,  KeyCode_Left,   KeyCode_Control );
Bind( move_right_alpha_numeric_boundary, KeyCode_Right,  KeyCode_Control );
Bind( move_left_alpha_numeric_or_camel_boundary,  KeyCode_Left, KeyCode_Alt);
Bind( move_right_alpha_numeric_or_camel_boundary, KeyCode_Right, KeyCode_Alt);
Bind( move_up_to_blank_line_end,         KeyCode_Up,     KeyCode_Control );
Bind( move_down_to_blank_line_end,       KeyCode_Down,   KeyCode_Control );

// Fleury:
//Bind( f4_search_for_definition__project_wide, KeyCode_J, KeyCode_Shift );
//Bind( f4_search_for_definition__current_file, KeyCode_J, KeyCode_Shift, KeyCode_Alt );
Bind( fleury_toggle_battery_saver,            KeyCode_Tick );
