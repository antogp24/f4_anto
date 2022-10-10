/* date = August 25th 2022 0:52 pm */

#ifndef ANTO_MODES_THEME_H
#define ANTO_MODES_THEME_H


// NOTE(anto): ARGB_Color -> u32 -> unsigned int

static ARGB_Color ANTO_MODAL_NORMAL_ID_COLOR = 0xffffffff; // default
static ARGB_Color ANTO_MODAL_VISUAL_ID_COLOR = 0xffffffff; // default
static ARGB_Color ANTO_MODAL_INSERT_ID_COLOR = 0xffffffff; // default

CUSTOM_ID(colors, anto_normal_cursor_color);
CUSTOM_ID(colors, anto_visual_cursor_color);
CUSTOM_ID(colors, anto_insert_cursor_color);


//~ NOTE(anto): The same implementation as Ryan's F4_ARGBFromID()

static ARGB_Color
anto_ARGBFromID(Color_Table table, Managed_ID id, int subindex)
{
    ARGB_Color result = 0;
    FColor color = fcolor_id(id);
    if (color.a_byte == 0){
        if (color.id != 0){
            result = finalize_color(table, color.id, subindex);
        }
    }
    else {
        result = color.argb;
    }
    return(result);
}


//~

#endif //ANTO_MODES_THEME_H
