
        String_ID global_map_id = vars_save_string_lit("keys_global");
String_ID file_map_id = vars_save_string_lit("keys_file");
String_ID code_map_id = vars_save_string_lit("keys_code");

// Modes
mapid_shared = vars_save_string_lit( "mapid_shared" );
mapid_normal = vars_save_string_lit( "mapid_normal" );
mapid_visual = vars_save_string_lit( "mapid_visual" );
mapid_insert = vars_save_string_lit( "mapid_insert" );

// Misc.
mapid_lister = vars_save_string_lit( "mapid_lister" );


//~ NOTE(anto): Fleury stuff

String_ID global_command_map_id = vars_save_string_lit("keys_global_1");
String_ID file_command_map_id = vars_save_string_lit("keys_file_1");
String_ID code_command_map_id = vars_save_string_lit("keys_code_1");

implicit_map_function = F4_ImplicitMap;

//~

MappingScope( );
SelectMapping( &framework_mapping );

SelectMap( global_map_id );
#include "bindings/global_map.cpp"

SelectMap( mapid_shared );
ParentMap(global_map_id);
#include "bindings/global_map.cpp"
Bind( go_to_normal_mode, KeyCode_Escape );
Bind( go_to_normal_mode, KeyCode_N, KeyCode_Alt );

SelectMap( mapid_normal );
ParentMap( mapid_shared );
#include "bindings/modes/normal_map.cpp"

SelectMap( mapid_visual );
ParentMap( mapid_shared );
#include "bindings/modes/visual_map.cpp"

SelectMap( mapid_insert );
ParentMap( mapid_shared );
BindTextInput(fleury_write_text_and_auto_indent);
#include "bindings/modes/insert_map.cpp"


// This is to make sure that the default bindings on the buffers will be mapid_normal.
SelectMap( file_map_id );
ParentMap( mapid_normal );

SelectMap( code_map_id );
ParentMap( mapid_normal );

//~ NOTE(anto): Fleury stuff

SelectMap(global_command_map_id);
ParentMap(global_map_id);
GlobalCommandMapReroute[0].From = global_map_id;
GlobalCommandMapReroute[0].To = global_command_map_id;

SelectMap(file_command_map_id);
ParentMap(global_command_map_id);
GlobalCommandMapReroute[1].From = file_map_id;
GlobalCommandMapReroute[1].To = file_command_map_id;

SelectMap(code_command_map_id);
ParentMap(file_command_map_id);
GlobalCommandMapReroute[2].From = code_map_id;
GlobalCommandMapReroute[2].To = code_command_map_id;

//~

// Misc.
SelectMap( mapid_lister );
#include "bindings/misc/lister_map.cpp"
