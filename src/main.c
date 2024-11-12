/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** main
*/
#include "../include/csfml_include.h"

int main(void)
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow *window;
    sfTexture *texture;
    sfSprite *sprite;
    sfEvent event;

    window = sfRenderWindow_create(mode, "ELIOOOTTTTTTTTTTTT",
    sfResize | sfClose, NULL);
    texture = sfTexture_createFromFile("src/eliott.jpeg", NULL);
    sprite = sfSprite_create();
    if (!window || !texture) {
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
