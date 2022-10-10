/* date = August 20th 2022 9:36 pm */

#ifndef ANTO_MAP_IDS_H
#define ANTO_MAP_IDS_H

extern String_ID mapid_shared;
extern String_ID mapid_normal;
extern String_ID mapid_visual;
extern String_ID mapid_insert;


typedef enum anto_cursor_styles {
    anto_cursor_normal,
    anto_cursor_visual,
    anto_cursor_insert,
} anto_cursor_styles;

static anto_cursor_styles current_anto_cursor;

#endif //ANTO_MAP_IDS_H
