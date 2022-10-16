// Main reason to make this file
Bind(lister_next, KeyCode_N, KeyCode_Control);
Bind(lister_prev, KeyCode_P, KeyCode_Control);

// Non intrusive:
Bind(save,       KeyCode_S, KeyCode_Control);
Bind(move_up,    KeyCode_Up );
Bind(move_down,  KeyCode_Down );
Bind(project_go_to_root_directory,  KeyCode_H,     KeyCode_Control);
Bind(save_all_dirty_buffers,        KeyCode_S,     KeyCode_Control, KeyCode_Shift, KeyCode_Alt);
Bind(interactive_new,               KeyCode_N,     KeyCode_Control, KeyCode_Shift);
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
BindMouse(click_set_cursor_and_mark,         MouseCode_Left);
BindMouse(mouse_visual_selection,            MouseCode_Left);
BindMouseRelease(click_set_cursor,           MouseCode_Left);
BindCore(click_set_cursor_and_mark,          CoreCode_ClickActivateView);
BindMouseMove(click_set_cursor_if_lbutton);

// Fleury stuff
BindCore(fleury_startup,   CoreCode_Startup);
BindCore(default_try_exit, CoreCode_TryExit);
Bind(exit_4coder,          KeyCode_F4, KeyCode_Alt);
BindMouseWheel(mouse_wheel_scroll);
BindMouseWheel(mouse_wheel_change_face_size, KeyCode_Control);
