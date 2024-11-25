/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** csfml_include
*/
#include <SFML/Graphics.h>
#include <SFML/Graphics/Export.h>
#include <SFML/Graphics/Color.h>
#include <SFML/Window.h>
#include <SFML/Window/Event.h>
#include <SFML/Window/Mouse.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef INCLUDED_CSFML_INCLUDE_H
    #define INCLUDED_CSFML_INCLUDE_H

struct csfml_var {
    sfVideoMode mode;
    sfRenderWindow *window;
    sfEvent event;
    sfMouseButtonEvent event;
    sfSprite *sprite;
    sfTexture *texture;
    sfIntRect rect;
};
void analyse_events(struct csfml_var *csfml_var);
void manage_mouse_click(struct csfml_var *csfml_var);
void close_window(struct csfml_var *csfml_var);
void main_loop(struct csfml_var *csfml_var);
#endif
