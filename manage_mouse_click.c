/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** manage_mouse_click
*/
#include "include/csfml_include.h"

void manage_mouse_click(sfMouseButtonEvent event)
{
    printf("Mouse x=%d y=%d\n", event.x, event.y);
}
