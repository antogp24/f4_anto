#include "normal_map.cpp"

// Selection Actions
Bind( set_mark,            KeyCode_Space );
Bind( cursor_mark_swap,    KeyCode_Space, KeyCode_Control );
Bind( delete_range,        KeyCode_D );
Bind( cut,                 KeyCode_C );
Bind( copy,                KeyCode_Y );

// Indentation
Bind( auto_indent_range,          KeyCode_Tab );
Bind( auto_indent_line_at_cursor, KeyCode_Tab, KeyCode_Shift );

// Scopes
Bind( if0_off,                             KeyCode_I, KeyCode_Alt );
Bind( place_in_scope,                      KeyCode_ForwardSlash, KeyCode_Alt );
Bind( write_block,                         KeyCode_Semicolon, KeyCode_Control );
Bind( delete_current_scope,                KeyCode_Minus, KeyCode_Alt);
Bind( select_surrounding_scope,            KeyCode_S );
Bind( select_surrounding_scope_maximal,    KeyCode_S, KeyCode_Shift );
Bind( select_prev_scope_absolute,          KeyCode_LeftBracket );
Bind( select_prev_top_most_scope,          KeyCode_LeftBracket, KeyCode_Shift );
Bind( select_next_scope_absolute,          KeyCode_RightBracket );
Bind( select_next_scope_after_current,     KeyCode_RightBracket, KeyCode_Shift );
