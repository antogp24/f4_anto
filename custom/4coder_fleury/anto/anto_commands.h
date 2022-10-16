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

// Normal Mode Commands

CUSTOM_COMMAND_SIG( eol_ins ) {
    seek_end_of_line( app );
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( sol_ins ) {
    seek_beginning_of_line( app );
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( nxt_chr_ins ) {
    if (!is_on_end_of_line(app))
        move_right( app );
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( nxt_ln_ins ) {
    seek_end_of_line( app );
    casey_newline_and_indent( app );
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( prev_ln_ins ) {
    seek_beginning_of_line( app );
    casey_newline_and_indent( app );
    move_up( app );
    go_to_insert_mode( app );
}

CUSTOM_COMMAND_SIG( go_to_visual_line ) {
    go_to_visual_mode( app );
    seek_beginning_of_line( app );
    set_mark( app );
    seek_end_of_line( app );
}

CUSTOM_COMMAND_SIG( nxt_ln_paste ) {
    seek_end_of_line( app );
    casey_newline_and_indent( app );
    paste_and_indent( app );
}

CUSTOM_COMMAND_SIG( copy_ln ) {
    go_to_visual_line( app );
    copy( app );
    go_to_normal_mode( app );
    seek_beginning_of_line( app );
}

CUSTOM_COMMAND_SIG( cut_ln ) {
    go_to_visual_line( app );
    cut( app );
    go_to_normal_mode( app );
    seek_beginning_of_line( app );
}

// "Smart" Commands

CUSTOM_COMMAND_SIG( mouse_visual_selection ) {
    if (current_anto_cursor != anto_cursor_visual) {
        go_to_visual_mode( app );
    }
    click_set_cursor_and_mark( app );
}

// Dumb Autocomplete Commands

CUSTOM_COMMAND_SIG( write_curly ) {
    View_ID view = get_active_view( app, 0 );
    write_string( app, string_u8_litexpr( "{}" ) );
    view_set_cursor( app, view, seek_pos( view_get_cursor_pos( app, view ) - 1 ) );
}

CUSTOM_COMMAND_SIG( write_square ) {
    View_ID view = get_active_view( app, 0 );
    write_string( app, string_u8_litexpr( "[]" ) );
    view_set_cursor( app, view, seek_pos( view_get_cursor_pos( app, view ) - 1 ) );
}

CUSTOM_COMMAND_SIG( write_dquotes ) {
    View_ID view = get_active_view( app, 0 );
    write_string( app, string_u8_litexpr( "\"\"" ) );
    view_set_cursor( app, view, seek_pos( view_get_cursor_pos( app, view ) - 1 ) );
}

// Lister

CUSTOM_COMMAND_SIG( lister_next ) {
    View_ID view = get_active_view(app, 0);
    Lister *lister = view_get_lister(app, view);
    lister->handlers.navigate(app, view, lister, 1); // Forward
}

CUSTOM_COMMAND_SIG( lister_prev ) {
    View_ID view = get_active_view(app, 0);
    Lister *lister = view_get_lister(app, view);
    lister->handlers.navigate(app, view, lister, -1); // Backwards
}

#endif //ANTO_COMMANDS_H
