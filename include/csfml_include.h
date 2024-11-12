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
void analyse_events(sfRenderWindow *window, sfEvent event);
void manage_mouse_click(sfMouseButtonEvent event);
void close_window(sfRenderWindow *window);
void main_loop(sfRenderWindow* window, sfEvent event, sfSprite *sprite);
#endif
