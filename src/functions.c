//libraries
#include <stdio.h>
#include <math.h>
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
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

//make random X-Y for soldior houses
void make_soldior_houses(struct all_house w[], int n)
{
    for(int i = 0; i < n; i++)
    {
        //w[i].x = rand() % 420 + 110;
        //w[i].y = rand() % 260 + 110;
        //while(make_sure(w,i))
        //{
          //  w[i].x = rand() % 420 + 110;
            //w[i].y = rand() % 260 + 110;
        //}
        w[i].color1 = 0x990000ff;
        w[i].color2 = 0xff0000ff;
        w[i].color3 = 0xff00ff00;
        w[i].color4 = 0xffff0000;
        w[i].maj_1_color = 0xff00ffff;
        w[i].maj_2_color = 0xffff1493;
        w[i].maj_3_color = 0xff8b4513;
        w[i].maj_4_color = 0xffffd700;
        w[i].momtane = 0xeea1a1a1;
        w[i].main_color = w[i].momtane;
        w[i].number = 10;
        w[i].flag = 0;
        w[i].target = -1;
        w[i].r = 15;
        w[i].flag_maj_1 = 0;
        w[i].flag_maj_2 = 0;
        w[i].flag_maj_3 = 0;
        w[i].flag_maj_4 = 0;
        w[i].flag_maj = 0;

    }
}

//sending soldiors
void send(SDL_Renderer *sdlRenderer, struct all_house s[], int a, int b, int n, SDL_bool shallExit, struct tak_sarbaz e[][100],
        double vatar, int p, int m, int c, struct nahiye w[], int se)
{

    for (int i = 0; i < p; i++)
    {
        //tasire majoone dovom
        if (s[b].x > s[a].x && s[b].y > s[a].y && e[i][m].x < s[b].x && e[i][m].flag == 0 && s[a].flag_maj_2 != 1 && se == 1)
        {

        }
        else if (s[b].x > s[a].x && s[b].y > s[a].y && e[i][m].x < s[b].x && e[i][m].flag == 0 && s[a].flag_maj_2 == 1 && se == 1 && s[a].flag != e[i][m].pl)
        {

        }
        //tasire majoone aval
        else if (s[b].x > s[a].x && s[b].y > s[a].y && e[i][m].x < s[b].x && e[i][m].flag == 0 && s[a].flag_maj_1 == 1)
        {
            e[i][m].x += 5 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 5 * (s[b].y - s[a].y) / vatar;
        }
        //nothing
        else if (s[b].x > s[a].x && s[b].y > s[a].y && e[i][m].x < s[b].x && e[i][m].flag == 0)
        {
            e[i][m].x += 2.5 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 2.5 * (s[b].y - s[a].y) / vatar;
        }
        //majoone dovom
        else if (s[b].x > s[a].x && s[b].y < s[a].y && e[i][m].y > s[b].y && e[i][m].flag == 0 && s[a].flag_maj_2 != 1 && se == 1)
        {

        }
        else if (s[b].x > s[a].x && s[b].y < s[a].y && e[i][m].y > s[b].y && e[i][m].flag == 0 && s[a].flag_maj_2 == 1 && se == 1 && s[a].flag != e[i][m].pl)
        {

        }
        //majoone aval
        else if (s[b].x > s[a].x && s[b].y < s[a].y && e[i][m].y > s[b].y && e[i][m].flag == 0 && s[a].flag_maj_1 == 1)
        {
            e[i][m].x += 5 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 5 * (s[b].y - s[a].y) / vatar;
        }
        //nothing
        else if (s[b].x > s[a].x && s[b].y < s[a].y && e[i][m].y > s[b].y && e[i][m].flag == 0)
        {
            e[i][m].x += 2.5 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 2.5 * (s[b].y - s[a].y) / vatar;
        }
        //majoone dovom
        else if (s[b].x < s[a].x && s[b].y > s[a].y && e[i][m].y < s[b].y && e[i][m].flag == 0 && s[a].flag_maj_2 != 1 && se == 1)
        {

        }
        else if (s[b].x < s[a].x && s[b].y > s[a].y && e[i][m].y < s[b].y && e[i][m].flag == 0 && s[a].flag_maj_2 == 1 && se == 1 && s[a].flag != e[i][m].pl)
        {

        }
        //majoone aval
        else if (s[b].x < s[a].x && s[b].y > s[a].y && e[i][m].y < s[b].y && e[i][m].flag == 0 && s[a].flag_maj_1 == 1)
        {
            e[i][m].x += 5 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 5 * (s[b].y - s[a].y) / vatar;
        }
        //nothing
        else if (s[b].x < s[a].x && s[b].y > s[a].y && e[i][m].y < s[b].y && e[i][m].flag == 0)
        {
            e[i][m].x += 2.5 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 2.5 * (s[b].y - s[a].y) / vatar;
        }
        //majoone dovom
        else if (s[b].x < s[a].x && s[b].y < s[a].y && e[i][m].x > s[b].x && e[i][m].flag == 0 && s[a].flag_maj_2 != 1 && se == 1)
        {

        }
        else if (s[b].x < s[a].x && s[b].y < s[a].y && e[i][m].x > s[b].x && e[i][m].flag == 0 && s[a].flag_maj_2 == 1 && se == 1 && s[a].flag != e[i][m].pl)
        {

        }
        //majoone aval
        else if (s[b].x < s[a].x && s[b].y < s[a].y && e[i][m].x > s[b].x && e[i][m].flag == 0 && s[a].flag_maj_1 == 1)
        {
            e[i][m].x += 5 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 5 * (s[b].y - s[a].y) / vatar;
        }
        //nothing
        else if (s[b].x < s[a].x && s[b].y < s[a].y && e[i][m].x > s[b].x && e[i][m].flag == 0)
        {
            e[i][m].x += 2.5 * (s[b].x - s[a].x) / vatar;
            e[i][m].y += 2.5 * (s[b].y - s[a].y) / vatar;
        }
        else
        {
            if(e[i][m].flag == 0)
            {
                //changing the target's number of soldior
                e[i][m].flag = 1;
                if(s[b].flag == e[i][m].pl)
                {
                    s[b].number++;
                }
                else
                {
                    s[b].number--;
                    //fath tavasote pl1
                    if(s[b].number < 0 && e[i][m].pl == 1)
                    {
                        s[b].number = 0;
                        if(s[a].main_color == s[a].maj_1_color && s[a].flag == 1)
                        {
                            s[b].main_color = s[a].maj_1_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else if(s[a].main_color == s[a].maj_2_color && s[a].flag == 1)
                        {
                            s[b].main_color = s[a].maj_2_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else if(s[a].main_color == s[a].maj_3_color && s[a].flag == 1)
                        {
                            s[b].main_color = s[a].maj_3_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else if(s[a].main_color == s[a].maj_4_color && s[a].flag == 1)
                        {
                            s[b].main_color = s[a].maj_4_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else
                        {
                            s[b].main_color = s[a].color1;
                        }
                        if(s[a].flag_maj_1 == 1)
                        {
                            s[b].flag_maj_1 = 1;
                        }
                        else if(s[a].flag_maj_2 == 1)
                        {
                            s[b].flag_maj_2 = 1;
                        }
                        else if(s[a].flag_maj_3 == 1)
                        {
                            s[b].flag_maj_3 = 1;
                        }
                        else if(s[a].flag_maj_4 == 1)
                        {
                            s[b].flag_maj_4 = 1;
                        }
                        else
                        {
                            s[b].flag_maj_1 = 0;
                            s[b].flag_maj_2 = 0;
                            s[b].r = 15;
                        }
                        w[b].main_color = w[b].color1;
                        s[b].flag = 1;


                    }
                    //fath tavasote pl2
                    else if(s[b].number < 0 && e[i][m].pl == 2)
                    {
                        s[b].number = 0;
                        if(s[a].main_color == s[a].maj_1_color && s[a].flag == 2)
                        {
                            s[b].main_color = s[a].maj_1_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else if(s[a].main_color == s[a].maj_2_color && s[a].flag == 2)
                        {
                            s[b].main_color = s[a].maj_2_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else if(s[a].main_color == s[a].maj_3_color && s[a].flag == 2)
                        {
                            s[b].main_color = s[a].maj_3_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else if(s[a].main_color == s[a].maj_4_color && s[a].flag == 2)
                        {
                            s[b].main_color = s[a].maj_4_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else
                        {
                            s[b].main_color = s[b].color3;
                        }
                        if(s[a].flag_maj_1 == 1)
                        {
                            s[b].flag_maj_1 = 1;
                        }
                        else if(s[a].flag_maj_2 == 1)
                        {
                            s[b].flag_maj_2 = 1;
                        }
                        else if(s[a].flag_maj_3 == 1)
                        {
                            s[b].flag_maj_3 = 1;
                        }
                        else if(s[a].flag_maj_4 == 1)
                        {
                            s[b].flag_maj_4 = 1;
                        }
                        else
                        {
                            s[b].flag_maj_1 = 0;
                            s[b].flag_maj_2 = 0;
                            s[b].r = 15;
                        }
                        w[b].main_color = w[b].color2;
                        s[b].flag = 2;
                    }
                    //fath tavasote pl3
                    else if(s[b].number < 0 && e[i][m].pl == 3)
                    {
                        s[b].number = 0;
                        if(s[a].main_color == s[a].maj_1_color && s[a].flag == 3)
                        {
                            s[b].main_color = s[a].maj_1_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else if(s[a].main_color == s[a].maj_2_color && s[a].flag == 3)
                        {
                            s[b].main_color = s[a].maj_2_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else if(s[a].main_color == s[a].maj_3_color && s[a].flag == 3)
                        {
                            s[b].main_color = s[a].maj_3_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else if(s[a].main_color == s[a].maj_4_color && s[a].flag == 3)
                        {
                            s[b].main_color = s[a].maj_4_color;
                            s[b].r = 20;
                            s[b].flag_maj = 1;
                        }
                        else
                        {
                            s[b].main_color = s[b].color4;
                        }
                        if(s[a].flag_maj_1 == 1)
                        {
                            s[b].flag_maj_1 = 1;
                        }
                        else if(s[a].flag_maj_2 == 1)
                        {
                            s[b].flag_maj_2 = 1;
                        }
                        else if(s[a].flag_maj_3 == 1)
                        {
                            s[b].flag_maj_3 = 1;
                        }
                        else if(s[a].flag_maj_4 == 1)
                        {
                            s[b].flag_maj_4 = 1;
                        }
                        else
                        {
                            s[b].flag_maj_1 = 0;
                            s[b].flag_maj_2 = 0;
                            s[b].r = 15;
                        }
                        w[b].main_color = w[b].color3;
                        s[b].flag = 3;
                    }
                }
            }
            else if(e[i][m].flag == 1)
            {
                e[i][m].flag = 2;
            }
        }
    }
    //accidents
    //group 1
    for(int i = 0; i < c; i++)
    {
        //group 2
        for(int j = 0; j < c; j++)
        {
            //soldiors of group 1
            for(int k = 0; k < e[e[0][i].number - 1][i].number; k++)
            {
                //soldiors of group 2
                for(int q = 0; q < e[e[0][j].number - 1][j].number; q++)
                {
                    if(sqrt(pow((e[k][i].y - e[q][j].y),2) + pow((e[k][i].x - e[q][j].x),2)) < 18 && e[k][i].pl != e[q][j].pl && e[k][i].flag == 0 && e[q][j].flag == 0)
                    {
                        e[k][i].flag = 1;
                        e[q][j].flag = 1;
                    }
                }
            }
        }
    }

    for(int i = 0; i < e[0][m].number; i++)
    {
        if(s[e[0][m].a].number > 0 && s[e[0][m].a].target == e[0][m].b && sqrt(pow((e[e[0][m].p - 1][m].y - e[e[0][m].p][m].y),2) + pow((e[e[0][m].p - 1][m].x - e[e[0][m].p][m].x),2)) > 21)
        {
            e[0][m].p++;
            e[e[0][m].p - 1][m].flag = 0;
            s[e[0][m].a].number--;
            if(s[e[0][m].a].number == 0)
            {
                s[e[0][m].a].target = -1;
            }
        }
        //player 1
        //majoone 1
        if(e[i][m].flag == 0 && e[i][m].pl == 1 && s[e[0][m].a].main_color == s[0].maj_1_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_1_color);
        }
        //majoone 2
        else if(e[i][m].flag == 0 && e[i][m].pl == 1 && s[e[0][m].a].main_color == s[0].maj_2_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_2_color);
        }
        //majoone 3
        else if(e[i][m].flag == 0 && e[i][m].pl == 1 && s[e[0][m].a].main_color == s[0].maj_3_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_3_color);
        }
        //majoone 4
        else if(e[i][m].flag == 0 && e[i][m].pl == 1 && s[e[0][m].a].main_color == s[0].maj_4_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_4_color);
        }
        //nothing
        else if(e[i][m].flag == 0 && e[i][m].pl == 1)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].color1);
        }
        //player 2
        //majoone 1
        else if(e[i][m].flag == 0 && e[i][m].pl == 2 && s[e[0][m].a].main_color == s[0].maj_1_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_1_color);
        }
        //majoone 2
        else if(e[i][m].flag == 0 && e[i][m].pl == 2 && s[e[0][m].a].main_color == s[0].maj_2_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_2_color);
        }
        //majoone 3
        else if(e[i][m].flag == 0 && e[i][m].pl == 2 && s[e[0][m].a].main_color == s[0].maj_3_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_3_color);
        }
        //majoone 4
        else if(e[i][m].flag == 0 && e[i][m].pl == 2 && s[e[0][m].a].main_color == s[0].maj_4_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_4_color);
        }
        //nothing
        else if(e[i][m].flag == 0 && e[i][m].pl == 2)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].color2);
        }
        //player 3
        //majoone 1
        else if(e[i][m].flag == 0 && e[i][m].pl == 3 && s[e[0][m].a].main_color == s[0].maj_1_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_1_color);
        }
        //majoone 2
        else if(e[i][m].flag == 0 && e[i][m].pl == 3 && s[e[0][m].a].main_color == s[0].maj_2_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_2_color);
        }
        //majoone 3
        else if(e[i][m].flag == 0 && e[i][m].pl == 3 && s[e[0][m].a].main_color == s[0].maj_3_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_3_color);
        }
        //majoone 4
        else if(e[i][m].flag == 0 && e[i][m].pl == 3 && s[e[0][m].a].main_color == s[0].maj_4_color)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].maj_4_color);
        }
        //nothing
        else if(e[i][m].flag == 0 && e[i][m].pl == 3)
        {
            filledCircleColor(sdlRenderer,e[i][m].x, e[i][m].y, 10, e[i][m].color3);
        }
    }
}

//make new mission for attack
void change(struct tak_sarbaz e[][100], int j, int s, int a, int b, struct all_house w[], int q)
{
    //X-Y
    e[j][s].x = w[a].x;
    e[j][s].y = w[a].y;
    //color
    e[j][s].color1 = w[a].color2;
    e[j][s].color2 = w[a].color3;
    e[j][s].color3 = w[a].color4;
    e[j][s].maj_1_color = w[a].maj_1_color;
    e[j][s].maj_2_color = w[a].maj_2_color;
    e[j][s].maj_3_color = w[a].maj_3_color;
    e[j][s].maj_4_color = w[a].maj_4_color;
    //position
    e[j][s].flag = -1;
    e[j][s].pl = 0;
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

//show each house soldior on the map at any time
void show_soldior_houses(SDL_Renderer *sdlRenderer, int n, struct all_house w[], int a)
{
    for(int i = 0; i < n; i++)
    {
        int x, y;
        char s[5];
        //number of soldiors in each soldior_house
        gcvt(w[i].number, 10, s);
        stringRGBA(sdlRenderer, w[i].x, w[i].y + 20, s, 0x00, 0x00, 0x00, 0xff);
        Uint32 e = SDL_GetMouseState(&x, &y);
        if(sqrt(pow((x - w[i].x),2) + pow((y - w[i].y),2)) < 15 && w[i].flag == 1 && a == -1)
        {
            filledCircleColor(sdlRenderer,w[i].x,w[i].y,w[i].r,w[i].color2);
        }
        else if(sqrt(pow((x - w[i].x),2) + pow((y - w[i].y),2)) < 15 && a != -1)
        {
            if(w[i].flag_maj_1 == 1)
            {
                filledCircleColor(sdlRenderer,w[i].x,w[i].y,w[i].r,w[i].maj_1_color);
            }
            else if(w[i].flag_maj_2 == 1)
            {
                filledCircleColor(sdlRenderer,w[i].x,w[i].y,w[i].r,w[i].maj_2_color);
            }
            else
            {
                filledCircleColor(sdlRenderer,w[i].x,w[i].y,w[i].r,w[i].color1);
            }
        }
        else
        {
            filledCircleColor(sdlRenderer,w[i].x,w[i].y,w[i].r,w[i].main_color);
        }
    }
}



//win or lost
int lost(struct all_house w[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(w[i].flag == 1)
        {
            return 1;
        }
    }
    return 0;
}

int win(struct all_house w[], int n)
{
    for(int i = 0; i < n; i++)
    {
        if(w[i].flag != 1 && w[i].flag != 0)
        {
            return 1;
        }
    }
    return 0;
}

int majoon_x(struct all_house w[], int v1, int v2)
{
    return (w[v1].x + w[v2].x) / 2;
}

int majoon_y(struct all_house w[], int v1, int v2)
{
    return (w[v1].y + w[v2].y) / 2;
}


void make_map_1(struct all_house w[])
{
    w[0].x = 117; w[0].y = 179;
    w[1].x = 343; w[1].y = 328;
    w[2].x = 480; w[2].y = 342;
    w[3].x = 433; w[3].y = 119;
    w[4].x = 257; w[4].y = 253;
    w[5].x = 160; w[5].y = 323;
    w[6].x = 243; w[6].y = 126;
    w[7].x = 450; w[7].y = 195;
    w[8].x = 338; w[8].y = 173;
    w[9].x = 420; w[9].y = 256;
}

void make_map_2(struct all_house w[])
{
    w[0].x = 179; w[0].y = 117;
    w[1].x = 328; w[1].y = 343;
    w[2].x = 400; w[2].y = 230;
    w[3].x = 119; w[3].y = 290;
    w[4].x = 253; w[4].y = 257;
    w[5].x = 500; w[5].y = 160;
    w[6].x = 126; w[6].y = 210;
    w[7].x = 270; w[7].y = 130;
    w[8].x = 173; w[8].y = 338;
    w[9].x = 256; w[9].y = 400;
}

int cal_score(char *a[], char *b)
{
    int score = 0;
    for(int i = 0; i < 100; i++)
    {
        if(strcmp(a[i], b) == 0)
        {
            score++;
        }
    }
    return score;
}

int find_max(int s[], int n)
{
    int high = 0, flag;
    for(int i = 0; i < n; i++)
    {
        if(s[i] > high)
        {
            high = s[i];
            flag = i;
        }
    }
    return flag;
}


