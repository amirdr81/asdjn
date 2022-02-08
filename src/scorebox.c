#include <stdio.h>
#include <SDL.h>
#include <SDL_ttf.h>
#include "functions.h"


SDL_bool quit = SDL_FALSE;

int tim = 0;

void show_score(SDL_bool text)
{
    SDL_INIT();
    TTF_Init();

    SDL_Window * window = SDL_CreateWindow("scorebox",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,480, 0);
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);
    SDL_Surface * surface;
    SDL_Texture * texture;
    int texW = 110;
    int texH = 110;
    TTF_Font * font = TTF_OpenFont("/Users/amir/Desktop/test/fonts/XB Zar bold.ttf", 25);
    SDL_Color color = { 255, 255, 255 };
    while (quit == SDL_FALSE)
    {
        SDL_RenderClear(renderer);

        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_QUIT:
                    quit = SDL_TRUE;
                    break;
            }
        }
        if(text == SDL_TRUE)
        {
            surface = TTF_RenderText_Solid(font, "You Win!", color);
        }
        else
        {
            surface = TTF_RenderText_Solid(font, "You Lost:(", color);
        }
        texture = SDL_CreateTextureFromSurface(renderer, surface);

        SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);

        SDL_FreeSurface(surface);
        SDL_Rect dstrect = { 290, 210, texW,texH };
        SDL_RenderCopy(renderer, texture, NULL, &dstrect);
        SDL_RenderPresent(renderer);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
    TTF_Quit();
    SDL_Quit();
}