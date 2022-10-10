/* date = August 26th 2022 5:19 pm */

#ifndef ANTO_CURSOR_H
#define ANTO_CURSOR_H

// NOTE(anto): This is what gets included in the "4coder_fleury_cursor.cpp" file, which is heavily modified

#include "anto_map_ids.h"

// Default values:
static b32 anto_cursor_should_glow = true;
static b32 anto_cursor_should_anim = true;
static b32 anto_cursor_draw_text_c = false;
static b32 anto_draw_mark_range_vs = true;

// From config

static b32 config_anto_cursor_should_glow_normal_mode = false;
static b32 config_anto_cursor_should_anim_normal_mode = false;

static b32 config_anto_cursor_should_glow_visual_mode = false;
static b32 config_anto_cursor_should_anim_visual_mode = false;

static b32 config_anto_cursor_should_glow_insert_mode = false;
static b32 config_anto_cursor_should_anim_insert_mode = false;

// Misc.

static u64 config_anto_cursor_soft_scalar_normal_mode = 0;


u32 get_face_size(Application_Links* app)
{
    View_ID view = get_active_view(app, Access_Always);
    Buffer_ID buffer = view_get_buffer(app, view, Access_Always);
    Face_ID face_id = get_face_id(app, buffer);
    Face_Description description = get_face_description(app, face_id);
    return description.parameters.pt_size;
}

#endif //ANTO_CURSOR_H
