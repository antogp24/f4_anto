/* date = August 20th 2022 9:52 pm */

#ifndef ANTO_MODAL_H
#define ANTO_MODAL_H

#include "anto_map_ids.h"
#include "anto_modes_theme.h"

// NOTE(anto): The modes on startup code is in 4coder_fleury.cpp
// NOTE(anto): The cursor changing code is in 4coder_fleury_cursor.cpp
// NOTE(anto): The default mode on switch buffer code is in 4coder_lists.cpp
// NOTE(anto): Modified 4coder_lister_base.cpp
// NOTE(anto): Ctrl+n Ctrl+p in search, on 4coder_base_commands.cpp

static b32 config_anto_cursor_modal_color_in_top_base = false; // by default

void set_current_mapid( Application_Links* app, Command_Map_ID mapid ) {
    
    View_ID view = get_active_view( app, 0 );
    Buffer_ID buffer = view_get_buffer( app, view, 0 );
    Managed_Scope scope = buffer_get_managed_scope( app, buffer );
    Command_Map_ID* map_id_ptr = scope_attachment( app, scope, buffer_map_id, Command_Map_ID );
    *map_id_ptr = mapid;
}

// Base Modal Commands

CUSTOM_COMMAND_SIG( go_to_normal_mode ) {
    
    set_current_mapid( app, mapid_normal );
    current_anto_cursor = anto_cursor_normal;
    
    active_color_table.arrays[ defcolor_cursor ].vals[ 0 ] = ANTO_MODAL_NORMAL_ID_COLOR;
    if (config_anto_cursor_modal_color_in_top_base)
    {
        active_color_table.arrays[ defcolor_base ].vals[ 0 ] = ANTO_MODAL_NORMAL_ID_COLOR;
    }
    
}

CUSTOM_COMMAND_SIG( go_to_visual_mode ) {
    
    set_current_mapid( app, mapid_visual );
    current_anto_cursor = anto_cursor_visual;
    
    set_mark( app );
    active_color_table.arrays[ defcolor_cursor ].vals[ 0 ] = ANTO_MODAL_VISUAL_ID_COLOR;
    if (config_anto_cursor_modal_color_in_top_base)
    {
        active_color_table.arrays[ defcolor_base ].vals[ 0 ] = ANTO_MODAL_VISUAL_ID_COLOR;
    }
}


CUSTOM_COMMAND_SIG( go_to_insert_mode ) {
    
    set_current_mapid( app, mapid_insert );
    current_anto_cursor = anto_cursor_insert;
    
    active_color_table.arrays[ defcolor_cursor ].vals[ 0 ] = ANTO_MODAL_INSERT_ID_COLOR;
    if (config_anto_cursor_modal_color_in_top_base)
    {
        active_color_table.arrays[ defcolor_base ].vals[ 0 ] = ANTO_MODAL_INSERT_ID_COLOR;
    }
}

#endif //ANTO_MODAL_H
