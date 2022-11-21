
//~ NOTE(anto): This file is included in "4coder_fleury.cpp" and "4coder_lists.cpp"

if (fcolor_id(anto_normal_cursor_color).id != 0)
{
    ANTO_MODAL_NORMAL_ID_COLOR = anto_ARGBFromID(active_color_table, anto_normal_cursor_color, 0);
}
else
{
    ANTO_MODAL_NORMAL_ID_COLOR = 0xffffffff;
}

if (fcolor_id(anto_visual_cursor_color).id != 0)
{
    ANTO_MODAL_VISUAL_ID_COLOR = anto_ARGBFromID(active_color_table, anto_visual_cursor_color, 0);
}
else
{
    ANTO_MODAL_VISUAL_ID_COLOR = 0xffffffff;
}

if (fcolor_id(anto_insert_cursor_color).id != 0)
{
    ANTO_MODAL_INSERT_ID_COLOR = anto_ARGBFromID(active_color_table, anto_insert_cursor_color, 0);
}
else
{
    ANTO_MODAL_INSERT_ID_COLOR = 0xffffffff;
}

//~