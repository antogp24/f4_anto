
// Modes Actions
Bind( go_to_normal_mode,   KeyCode_N );
Bind( go_to_visual_mode,   KeyCode_V );
Bind( go_to_visual_line,   KeyCode_V, KeyCode_Shift );

// Selection Actions
Bind( set_mark,            KeyCode_Space );
Bind( cursor_mark_swap,    KeyCode_S );
Bind( delete_range,        KeyCode_D );
Bind( delete_line,         KeyCode_D, KeyCode_Shift );
Bind( if0_off,             KeyCode_I, KeyCode_Alt );
Bind( place_in_scope,      KeyCode_ForwardSlash, KeyCode_Alt );

// Clipboard Actions
Bind( copy,             KeyCode_Y );
Bind( copy_ln,          KeyCode_Y, KeyCode_Shift );
Bind( cut,              KeyCode_C );
Bind( cut_ln,           KeyCode_C, KeyCode_Shift );
Bind( paste_and_indent, KeyCode_P );
Bind( nxt_ln_paste,     KeyCode_P, KeyCode_Shift );

// History Actions
Bind( undo, KeyCode_U);
Bind( redo, KeyCode_U, KeyCode_Shift );

// Fuck yes, vim
Bind( go_to_insert_mode, KeyCode_I );
Bind( move_left,  KeyCode_H );
Bind( move_right, KeyCode_L );
Bind( move_up,    KeyCode_K );
Bind( move_down,  KeyCode_J );

// Vim Actions
Bind( sol_ins,     KeyCode_I, KeyCode_Shift );
Bind( eol_ins,     KeyCode_A, KeyCode_Shift );
Bind( nxt_chr_ins, KeyCode_A );
Bind( nxt_ln_ins,  KeyCode_O );
Bind( prev_ln_ins, KeyCode_O, KeyCode_Shift );

// Boundary Navigation Actions
Bind( move_left_token_boundary,          KeyCode_B );
Bind( move_right_token_boundary,         KeyCode_W );
Bind( move_left_alpha_numeric_boundary,  KeyCode_H, KeyCode_Control );
Bind( move_right_alpha_numeric_boundary, KeyCode_L, KeyCode_Control );
Bind( move_up_to_blank_line_end,         KeyCode_K, KeyCode_Control );
Bind( move_down_to_blank_line_end,       KeyCode_J, KeyCode_Control );

// Jumping Actions
Bind( goto_beginning_of_file,               KeyCode_G );
Bind( goto_end_of_file,                     KeyCode_G, KeyCode_Shift );
Bind( seek_beginning_of_textual_line,       KeyCode_0 );
Bind( seek_end_of_textual_line,             KeyCode_4, KeyCode_Shift);