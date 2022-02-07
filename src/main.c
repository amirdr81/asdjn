//main libraries
#include <stdio.h>
#include <math.h>

//new & external libraries
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL_image.h"
#include "../header/functions.h"

SDL_bool shallExit = SDL_FALSE;

int main()
{
    SDL_INIT();
    SDL_Window *sdlWindow = SDL_CreateWindow("Test_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,
                                             480, SDL_WINDOW_OPENGL);

    //mine
    struct soldior s[3];
    for(int i = 0; i < 3; i++)
    {
        s[i].x = rand() % 640 + 1;
        s[i].y = rand() % 480 + 1;
        s[i].color1 = 0xffff0000;
        s[i].color2 = 0xff00ff00;
        s[i].main_color = s[i].color1;
        s[i].flag = 0;
    }

    //all
    struct all_house w[10];
    for(int i = 0; i < 10; i++)
    {
        w[i].x = rand() % 610 + 15;
        w[i].y = rand() % 450 + 15;
        w[i].color1 = 0xffff0000;
        w[i].color2 = 0xff00ff00;
        w[i].main_color = s[i].color1;
        w[i].momtane = 0xb4b9b300;
    }
    //create renderer
    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);
    //loop
    int a = -1, b = -1;
    while(shallExit == SDL_FALSE)
    {
        //colors of the renderer
        SDL_SetRenderDrawColor(sdlRenderer, 0xb4, 0xb9, 0xb3, 0xff);
        SDL_RenderClear(sdlRenderer);
        for(int i = 0; i < 3; i++)
        {
            filledCircleColor(sdlRenderer,s[i].x , s[i].y, 15, s[i].main_color);
            select_a_cell(sdlRenderer, s[i]);
        }
        for(int i = 0; i < 10; i++)
        {
            filledCircleColor(sdlRenderer,w[i].x , w[i].y, 15, w[i].momtane);
            select_a_cell(sdlRenderer, s[i]);
        }
        SDL_Event sdlEvent;

        while (SDL_PollEvent(&sdlEvent))
        {
            switch (sdlEvent.type)
            {
                case SDL_QUIT:
                    shallExit = SDL_TRUE;
                    break;
                case SDL_MOUSEBUTTONUP:
                    if (sdlEvent.button.button == SDL_BUTTON_LEFT)
                    {

                        int x = sdlEvent.button.x;
                        int y = sdlEvent.button.y;
                        for(int i = 0; i < 3; i++)
                        {
                            if(sqrt(pow((x - s[i].x),2) + pow((y - s[i].y),2)) < 15)
                            {
                                if(a == -1)
                                {
                                    a = i;
                                }
                                else
                                {
                                    b = i;
                                    s[a].main_color = s[a].color1;
                                    s[b].main_color = s[b].color1;
                                    send(sdlRenderer, s, a, b, 4, shallExit, 3);
                                    a = -1;
                                    b = -1;
                                    break;
                                }

                                if(s[i].main_color == s[i].color1)
                                {
                                    s[i].main_color = s[i].color2;
                                }
                                else
                                {
                                    s[i].main_color = s[i].color1;
                                }
                            }
                        }

                    }

            }
        }
        //present the renderer
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(1000 / 30);
    }

    SDL_DestroyWindow(sdlWindow);


    SDL_Quit();
    return 0;
}
