// Most Used:
Bind(save,                        KeyCode_S, KeyCode_Control);
Bind(save,                        KeyCode_S, KeyCode_Alt);
Bind(search,                      KeyCode_F, KeyCode_Control);

Bind( move_left,  KeyCode_Left );
Bind( move_right, KeyCode_Right );
Bind( move_up,    KeyCode_Up );
Bind( move_down,  KeyCode_Down );

Bind( redo,  KeyCode_Z, KeyCode_Control, KeyCode_Shift );
Bind( undo,  KeyCode_Z, KeyCode_Control );
Bind( cut,   KeyCode_X, KeyCode_Control );
Bind( copy,  KeyCode_C, KeyCode_Control );
Bind( paste, KeyCode_V, KeyCode_Control );

Bind(interactive_new,               KeyCode_N,     KeyCode_Control);
Bind(interactive_open_or_new,       KeyCode_O,     KeyCode_Control);
Bind(interactive_open_or_new,       KeyCode_O,     KeyCode_Alt);
Bind(interactive_switch_buffer,     KeyCode_I,     KeyCode_Control);
Bind(interactive_switch_buffer,     KeyCode_I,     KeyCode_Alt);

// Most Important:
BindCore(fleury_startup,   CoreCode_Startup);
BindCore(default_try_exit, CoreCode_TryExit);
Bind(exit_4coder,          KeyCode_F4, KeyCode_Alt);
Bind(command_lister,       KeyCode_X, KeyCode_Alt);
Bind(project_fkey_command, KeyCode_F1);
Bind(project_fkey_command, KeyCode_F2);
Bind(project_fkey_command, KeyCode_F3);
Bind(project_fkey_command, KeyCode_F4);
Bind(project_fkey_command, KeyCode_F5);
Bind(project_fkey_command, KeyCode_F6);
Bind(project_fkey_command, KeyCode_F7);
Bind(project_fkey_command, KeyCode_F8);
Bind(project_fkey_command, KeyCode_F9);
Bind(project_fkey_command, KeyCode_F10);
Bind(project_fkey_command, KeyCode_F11);
Bind(project_fkey_command, KeyCode_F12);
Bind(project_fkey_command, KeyCode_F13);
Bind(project_fkey_command, KeyCode_F14);
Bind(project_fkey_command, KeyCode_F15);
Bind(project_fkey_command, KeyCode_F16);

// Mouse:
BindMouseWheel(mouse_wheel_scroll);
BindMouseWheel(mouse_wheel_change_face_size, KeyCode_Control);
// NOTE(anto): Modified @4coder_base_commands.cpp
BindMouse(mouse_insert_drag,        MouseCode_Left);
BindMouseRelease(click_set_cursor,  MouseCode_Left);
BindMouse(mouse_visual_selection,   MouseCode_Right);
BindMouseRelease(click_set_cursor,  MouseCode_Right);
BindCore(click_set_cursor_and_mark, CoreCode_ClickActivateView);
BindMouseMove(click_set_cursor_if_lr_button);


// Misc:
Bind(keyboard_macro_start_recording , KeyCode_LeftBracket, KeyCode_Control);
Bind(keyboard_macro_finish_recording, KeyCode_LeftBracket, KeyCode_Control, KeyCode_Shift);
Bind(keyboard_macro_replay,           KeyCode_LeftBracket, KeyCode_Alt);
Bind(change_active_panel_backwards, KeyCode_Comma, KeyCode_Control, KeyCode_Shift);
Bind(open_in_other,                 KeyCode_O, KeyCode_Alt);
Bind(project_go_to_root_directory,  KeyCode_H, KeyCode_Control);
Bind(save_all_dirty_buffers,        KeyCode_S, KeyCode_Control, KeyCode_Shift);
Bind(change_to_build_panel,         KeyCode_Period, KeyCode_Alt);
Bind(close_build_panel,             KeyCode_Comma, KeyCode_Alt);
Bind(goto_next_jump,                KeyCode_N, KeyCode_Alt);
Bind(goto_prev_jump,                KeyCode_N, KeyCode_Alt, KeyCode_Shift);
Bind(build_in_build_panel,          KeyCode_M, KeyCode_Alt);
Bind(goto_first_jump,               KeyCode_M, KeyCode_Alt, KeyCode_Shift);
Bind(toggle_filebar,                KeyCode_B, KeyCode_Alt);
Bind(execute_any_cli,               KeyCode_Z, KeyCode_Alt);
Bind(execute_previous_cli,          KeyCode_Z, KeyCode_Alt, KeyCode_Shift);
Bind(project_command_lister,        KeyCode_X, KeyCode_Alt, KeyCode_Shift);
Bind(quick_swap_buffer,             KeyCode_BackwardSlash, KeyCode_Alt);
Bind(jump_to_last_point,            KeyCode_P, KeyCode_Control);
Bind(list_all_functions_current_buffer_lister, KeyCode_I, KeyCode_Control, KeyCode_Shift);

// Fleury stuff
BindCore(fleury_startup, CoreCode_Startup);
BindCore(default_try_exit, CoreCode_TryExit);
Bind(exit_4coder,          KeyCode_F4, KeyCode_Alt);
BindMouseWheel(mouse_wheel_scroll);
BindMouseWheel(mouse_wheel_change_face_size, KeyCode_Control);
