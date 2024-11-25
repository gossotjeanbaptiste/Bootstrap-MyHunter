/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** main
*/
#include "include/csfml_include.h"
#include "include/my.h"
#include "include/my_graphical.h"
#include "include/struct_fb.h"

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;
    sfIntRect rect;

    rect.top = 0;
    rect.left = 0;
    rect.height = 110;
    rect.width = 110;

    window = sfRenderWindow_create(mode, "Bootstrap My_Hunter",
    sfResize | sfClose, NULL);
    texture = sfTexture_createFromFile("src/my_hunter_spritesheet.png", NULL);
    sprite = sfSprite_create();
    sfSprite_setTextureRect(sprite, rect);
    if (!window || !texture || !sprite) {
        return EXIT_FAILURE;
    }
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 30);
    main_loop(window, event, sprite);
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}

void main_loop(sfRenderWindow* window, sfEvent event, sfSprite *sprite)
{
    while (sfRenderWindow_isOpen(window)) {
        analyse_events(window, event);
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            close_window(window);
        }
        if (event.type == sfEvtMouseButtonPressed) {
            manage_mouse_click(event.mouseButton);
        }
    }
}
