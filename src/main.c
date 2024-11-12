/*
** EPITECH PROJECT, 2024
** Bootstrap-MyHunter
** File description:
** main
*/
#include "../include/csfml_include.h"

typedef struct sfMusic sfMusic;

int main() 
{
    sfVideoMode mode = {800, 600, 32};
    sfRenderWindow* window;
    sfTexture* texture;
    sfSprite* sprite;
    sfEvent event;
    /* Create the main window */
    window = sfRenderWindow_create(mode, "ELIOOOTTTTTTTTTTTT", sfResize | sfClose, NULL);
    if (!window) {
        return EXIT_FAILURE;
    }
    texture = sfTexture_createFromFile("src/eliott.jpeg", NULL);
    if (!texture) {
        return EXIT_FAILURE;
    }
    sprite = sfSprite_create();
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfRenderWindow_setFramerateLimit(window, 30);
    while (sfRenderWindow_isOpen(window)) {
        
        sfRenderWindow_clear(window, sfBlack);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
    /* Cleanup resources */
    sfSprite_destroy(sprite);
    sfTexture_destroy(texture);
    sfRenderWindow_destroy(window);
    return EXIT_SUCCESS;
}

void analyse_events(sfRenderWindow *window, sfEvent event)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
            if (event.type == sfEvtClosed) {
                sfRenderWindow_close(window);
            }
            if (event.type == sfEvtMouseButtonPressed) {
                if (event.mouseButton.button) {
                    manage_mouse_click(event.mouseButton);
                }
            }
        }
}