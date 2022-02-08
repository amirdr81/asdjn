//libraries
#include <stdio.h>
#include <math.h>
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "SDL_ttf.h"
#include "../header/functions.h"


//functions


int SDL_INIT()
{
    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) < 0)
    {
        printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
        return 0;
    }
    return 1;
}

void make_sure(struct all_house w[], int j, int i)
{
    if(sqrt(pow((w[i].x - w[j].x), 2) + pow((w[i].y - w[j].y), 2)) < 100 || w[i].x < 80 || w[i].x > 560 || w[i].y < 80 || w[i].y > 400)
    {
        w[i].x = rand() % 610 + 15;
        w[i].y = rand() % 450 + 15;
        make_sure(w,j,i);
    }
}

void make_soldior_houses(struct all_house w[], int n)
{
    for(int i = 0; i < n; i++)
    {
        w[i].x = rand() % 610 + 15;
        w[i].y = rand() % 450 + 15;
        for(int j = 0; j < i; j++)
        {
            make_sure(w,j,i);
        }
        w[i].color1 = 0xff0000ff;
        w[i].color2 = 0xffff60ff;
        w[i].color3 = 0xff00ff00;
        w[i].color4 = 0xff00aa00;
        w[i].momtane = 0x80808000;
        w[i].main_color = w[i].momtane;
        w[i].number = 5;
        w[i].flag = 0;

    }
}
void send(SDL_Renderer *sdlRenderer, struct all_house s[], int a, int b, int n, SDL_bool shallExit, struct tak_sarbaz e[][100],
        double vatar, int p, int m, struct all_house w[], int flag_player2, int arr[])
{

    for (int i = 0; i < p; i++)
    {
        if (s[b].x > s[a].x && s[b].y > s[a].y && e[i][m].x < s[b].x && e[i][m].flag == 0)
        {
            e[i][m].x += 2 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 2 * (s[b].y - s[a].y) / vatar;
        }
        else if (s[b].x > s[a].x && s[b].y < s[a].y && e[i][m].y > s[b].y && e[i][m].flag == 0)
        {
            e[i][m].x += 2 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 2 * (s[b].y - s[a].y) / vatar;
        }
        else if (s[b].x < s[a].x && s[b].y > s[a].y && e[i][m].y < s[b].y && e[i][m].flag == 0)
        {
            e[i][m].x += 2 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 2 * (s[b].y - s[a].y) / vatar;
        }
        else if (s[b].x < s[a].x && s[b].y < s[a].y && e[i][m].x > s[b].x && e[i][m].flag == 0)
        {
            e[i][m].x += 2 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 2 * (s[b].y - s[a].y) / vatar;
        }
        else
        {
            if(e[i][m].flag == 0)
            {
                e[i][m].flag = 1;
                if(s[b].flag == e[i][m].pl)
                {
                    s[b].number++;
                }
                else
                {
                    s[b].number--;
                    if(s[b].number < 0 && e[i][m].pl == 1)
                    {
                        s[b].number = 0;
                        s[b].main_color = s[b].color1;
                        s[b].flag = 1;
                    }
                    else if(s[b].number < 0 && e[i][m].pl == 2)
                    {
                        s[b].number = 0;
                        s[b].main_color = s[b].color3;
                        s[b].flag = 2;
                        arr[flag_player2] = b;
                    }
                }
            }
            else if(e[i][m].flag == 1)
            {
                e[i][m].flag = 2;
            }
        }
    }
    for(int i = 0; i < e[0][m].number; i++)
    {
        if(e[0][m].p < e[0][m].number && sqrt(pow((e[e[0][m].p - 1][m].y - e[e[0][m].p][m].y),2) + pow((e[e[0][m].p - 1][m].x - e[e[0][m].p][m].x),2)) > 21)
        {
            e[0][m].p++;
            e[e[0][m].p - 1][m].flag = 0;
        }
        if(e[i][m].flag == 0 && e[i][m].pl == 1)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].color1);
        }
        if(e[i][m].flag == 0 && e[i][m].pl == 2)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].color2);
        }
    }
}

void change(struct tak_sarbaz e[][100], int j, int s, int a, int b, struct all_house w[], int q)
{
    //X-Y
    e[j][s].x = w[a].x;
    e[j][s].y = w[a].y;
    //color
    e[j][s].color1 = w[a].color1;
    e[j][s].color2 = w[a].color3;
    //position
    e[j][s].flag = -1;
    e[j][s].pl = 0;
    e[j][s].x1 = w[a].x;
    e[j][s].y1 = w[a].y;
    e[j][s].x2 = w[b].x;
    e[j][s].y2 = w[b].y;
    //number of all soldiors
    e[j][s].number = q;
    //related to w[]
    e[j][s].a = a;
    e[j][s].b = b;
    //length
    e[j][s].vatar = sqrt(pow((w[a].y - w[b].y),2) + pow((w[a].x - w[b].x),2));
    //number of moving soldiors
    e[j][s].p = 0;
}

void show_soldior_houses(SDL_Renderer *sdlRenderer, int n, struct all_house w[], int a, int b)
{
    for(int i = 0; i < n; i++)
    {
        int x, y;
        char s[5], t[4];
        //number of soldiors in each soldior_house
        gcvt(w[i].number, 10, s);
        gcvt(i, 10, t);
        stringRGBA(sdlRenderer, w[i].x, w[i].y + 20, s , 0x00, 0x00,0x00,0xff);
        stringRGBA(sdlRenderer, w[i].x, w[i].y - 20, t , 0x00, 0x00,0x00,0xff);
        Uint32 e = SDL_GetMouseState(&x, &y);
        if(sqrt(pow((x - w[i].x),2) + pow((y - w[i].y),2)) < 15 && w[i].flag == 1 && a == -1)
        {
            filledCircleColor(sdlRenderer,w[i].x,w[i].y,15,w[i].color2);
        }
        else if(sqrt(pow((x - w[i].x),2) + pow((y - w[i].y),2)) < 15 && a != -1)
        {
            filledCircleColor(sdlRenderer,w[i].x,w[i].y,15,w[i].color2);
        }
        else
        {
            filledCircleColor(sdlRenderer,w[i].x,w[i].y,15,w[i].main_color);
        }
    }
}





