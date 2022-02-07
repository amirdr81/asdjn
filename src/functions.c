//libraries
#include <stdio.h>
#include <math.h>
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "../header/functions.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;
const int FPS = 60;



//structs


//functions
void change_color(int x, int y, SDL_Renderer *sdlRenderer, struct soldior a)
{
    if(sqrt(pow((x - a.x),2) + pow((y - a.y),2)) < 15)
    {
        filledCircleColor(sdlRenderer,a.x,a.y,15,a.color2);
    }

}

void select_a_cell(SDL_Renderer *sdlRenderer, struct soldior a)
{
    int x, y;
    Uint32 state = SDL_GetMouseState(&x, &y);
    change_color(x,y,sdlRenderer, a);

}

int SDL_INIT()
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    return 1;
}

void send(SDL_Renderer *sdlRenderer, struct soldior s[], int a, int b, int n, SDL_bool shallExit, int d)
{
    //length between 2 soldior_houses
    double vatar = sqrt(pow((s[a].y - s[b].y),2) + pow((s[a].x - s[b].x),2));
    struct tak_sarbaz e[n];
    for(int i = 0; i < n; i++)
    {
        e[i].x = s[a].x;
        e[i].y = s[a].y;
        e[i].color = s[a].color1;
        e[i].flag = 0;
    }
    SDL_bool quit = SDL_FALSE;
    int p = 1;

    while(quit == SDL_FALSE)
    {
        SDL_SetRenderDrawColor(sdlRenderer, 0xb4, 0xb9, 0xb3, 0xff);
        SDL_RenderClear(sdlRenderer);
        for (int i = 0; i < p; i++)
        {
            if (s[b].x > s[a].x && s[b].y > s[a].y && e[i].x < s[b].x)
            {
                e[i].x += (s[b].x - s[a].x) / vatar;
                e[i].y += (s[b].y - s[a].y) / vatar;
            }
            else if (s[b].x > s[a].x && s[b].y < s[a].y && e[i].y > s[b].y)
            {
                e[i].x += (s[b].x - s[a].x) / vatar;
                e[i].y += (s[b].y - s[a].y) / vatar;
            }
            else if (s[b].x < s[a].x && s[b].y > s[a].y && e[i].y < s[b].y)
            {
                e[i].x += (s[b].x - s[a].x) / vatar;
                e[i].y += (s[b].y - s[a].y) / vatar;
            }
            else if (s[b].x < s[a].x && s[b].y < s[a].y && e[i].x > s[b].x)
            {
                e[i].x += (s[b].x - s[a].x) / vatar;
                e[i].y += (s[b].y - s[a].y) / vatar;
            }
            else
            {
                e[i].flag = 1;
            }

            //show movments
            filledCircleColor(sdlRenderer, e[i].x, e[i].y, 15, 0xffff0000);

            //show soldior houses
            for (int j = 0; j < d; j++)
            {
                filledCircleColor(sdlRenderer, s[j].x, s[j].y, 15, s[a].color1);
            }

            //number of moving soldiors
            if(p < n)
            {
                if(sqrt(pow((e[p - 1].x - e[p].x),2) + pow((e[p - 1].y - e[p].y),2)) > 32)
                {
                    p++;
                }
            }
        }

        //exit
        SDL_Event sdlEvent;
        while (SDL_PollEvent(&sdlEvent))
        {
            switch (sdlEvent.type)
            {
                case SDL_QUIT:
                    quit = SDL_TRUE;
                    shallExit = SDL_TRUE;
                    break;
            }
        }

        if(e[n - 1].flag == 1)
        {
            quit = SDL_TRUE;
            shallExit = SDL_TRUE;
            break;
        }
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(1000 / FPS);

    }

}



