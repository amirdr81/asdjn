//main libraries
#include <math.h>

//new & external libraries
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "../header/functions.h"
#include "../header/scorebox.h"
#include "../header/map1.h"


void map_2_exe(char *klkl)
{
    SDL_bool shallExit = SDL_FALSE;
    SDL_bool win_lost = SDL_FALSE;
    SDL_INIT();
    //make new window
    SDL_Window *sdlWindow = SDL_CreateWindow("Test_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,
                                             480, SDL_WINDOW_OPENGL);
    //define variables & structs
    int a = -1, b = -1, s = 0, n, se;
    int majoon_1_time = rand() % 400 + 300; // between 3 and 7
    int majoon_2_time = rand() % 400 + 200; // between 2 and 6
    int majoon_3_time = rand() % 500 + 500; // between 5 and 10
    int majoon_4_time = rand() % 600 + 500; // between 5 and 10
    //make random n
    n = 10;
    struct all_house w[n];
    struct nahiye c[10];
    struct tak_sarbaz e[1000][100];
    struct majoon1 maj1;
    struct majoon1 maj2;
    struct majoon1 maj_sarbaz1;
    struct majoon1 maj_sarbaz2;
    long long int time = 1;
    make_map_2(w);

    //make random places for soldior houses
    make_soldior_houses(w,n);
    for(int i = 0; i < 10; i++)
    {
        c[i].color1 = 0x330000ff;
        c[i].color2 = 0x3300ff00;
        c[i].color3 = 0x33ff0000;
        c[i].momtane = 0x77a1a1a1;
        c[i].main_color = c[i].momtane;
    }

    //player 1
    //1 or 2 or 3 houses for user
    int m = rand() % 3 + 1;
    for(int i = 0; i < m; i++)
    {
        int y = rand() % n;
        w[y].flag = 1;
        w[y].main_color = w[i].color1;
        w[y].number = 15;
        c[y].main_color = c[i].color1;
    }

    //player 2
    //just 1 house
    w[m].flag = 2;
    w[m].main_color = w[1].color3;
    w[m].number = 15;
    c[m].main_color = c[m].color2;

    //player 3
    //just 1 house
    w[m + 1].flag = 3;
    w[m + 1].main_color = w[1].color4;
    w[m + 1].number = 15;
    c[m + 1].main_color = c[m + 1].color3;

    //create renderer
    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    //majoon 1
    int v1 = rand() % n;
    int v2 = rand() % n;
    if(v1 == v2 && v2 != 0)
    {
        v2--;
    }
    else if(v1 == v2 && v2 == 0)
    {
        v2 = 1;
    }
    int x1 = majoon_x(w,v1,v2);
    int y1 = majoon_y(w,v1,v2);
    //define majoon 1
    maj1.x = x1; maj1.y = y1;
    maj1.flag = 0; maj1.color = 0xff00ffff;//yellow

    //majoon 2
    v1 = rand() % n;
    v2 = rand() % n;
    if(v1 == v2 && v2 != 0)
    {
        v2--;
    }
    else if(v1 == v2 && v2 == 0)
    {
        v2 = 1;
    }
    x1 = majoon_x(w,v1,v2);
    y1 = majoon_y(w,v1,v2);
    //define majoon 2
    maj2.x = x1; maj2.y = y1;
    maj2.flag = 0; maj2.color = 0xffff1493;//purple

    //majoon 3
    v1 = rand() % n;
    v2 = rand() % n;
    if(v1 == v2 && v2 != 0)
    {
        v2--;
    }
    else if(v1 == v2 && v2 == 0)
    {
        v2 = 1;
    }
    x1 = majoon_x(w,v1,v2);
    y1 = majoon_y(w,v1,v2);
    //define majoon 2
    maj_sarbaz1.x = x1; maj_sarbaz1.y = y1;
    maj_sarbaz1.flag = 0; maj_sarbaz1.color = 0xff8b4513;//dark blue

    //majoon 4
    v1 = rand() % n;
    v2 = rand() % n;
    if(v1 == v2 && v2 != 0)
    {
        v2--;
    }
    else if(v1 == v2 && v2 == 0)
    {
        v2 = 1;
    }
    x1 = majoon_x(w,v1,v2);
    y1 = majoon_y(w,v1,v2);
    //define majoon 2
    maj_sarbaz2.x = x1; maj_sarbaz2.y = y1;
    maj_sarbaz2.flag = 0; maj_sarbaz2.color = 0xffffd700;//gold

    int arr1[n], arr2[n];
    int num1, num2;
    int random1, random2;
    int mabda1, mabda2;
    int maghsad1, maghsad2;
    //loop
    const Sint16 c0x[4] = {117, 200, 240, 80};
    const Sint16 c0y[4] = {80, 80, 170, 180};
    const Sint16 c1x[4] = {305, 420, 330, 240};
    const Sint16 c1y[4] = {265, 320, 410, 340};
    const Sint16 c2x[4] = {370, 580, 420, 305};
    const Sint16 c2y[4] = {190, 230, 320, 265};
    const Sint16 c3x[4] = {50, 190, 180, 100};
    const Sint16 c3y[4] = {290, 250, 295, 340};
    const Sint16 c4x[6] = {240, 180, 190, 160, 240, 370};
    const Sint16 c4y[6] = {340, 295, 250, 175, 170, 190};
    const Sint16 c5x[4] = {400, 370, 580, 540};
    const Sint16 c5y[4] = {70, 190, 230, 100};
    const Sint16 c6x[4] = {80, 50, 190, 160 } ;
    const Sint16 c6y[4] = {180, 290, 250, 175};
    const Sint16 c7x[4] = {240, 200, 400, 370};
    const Sint16 c7y[4] = {170, 80, 70, 190};
    const Sint16 c8x[4] = {180, 100, 200, 240};
    const Sint16 c8y[4] = {295, 340, 440, 340};
    const Sint16 c9x[4] = {330, 200, 240, 240};
    const Sint16 c9y[4] = {410, 440, 340, 340};
///////////////
    while(shallExit == SDL_FALSE)
    {
        //colors of the renderer
        SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlRenderer);

        //soldior houses
        filledPolygonColor(sdlRenderer, c0x, c0y, 4, c[0].main_color);
        filledPolygonColor(sdlRenderer, c1x, c1y, 4, c[1].main_color);
        filledPolygonColor(sdlRenderer, c2x, c2y, 4, c[2].main_color);
        filledPolygonColor(sdlRenderer, c3x, c3y, 4, c[3].main_color);
        filledPolygonColor(sdlRenderer, c4x, c4y, 6, c[4].main_color);
        filledPolygonColor(sdlRenderer, c5x, c5y, 4, c[5].main_color);
        filledPolygonColor(sdlRenderer, c6x, c6y, 4, c[6].main_color);
        filledPolygonColor(sdlRenderer, c7x, c7y, 4, c[7].main_color);
        filledPolygonColor(sdlRenderer, c8x, c8y, 4, c[8].main_color);
        filledPolygonColor(sdlRenderer, c9x, c9y,4, c[9].main_color);
        show_soldior_houses(sdlRenderer, n, w, a);

        //lost
        if(lost(w,n) == 0)
        {
            shallExit = SDL_TRUE;
            break;
        }
        //win
        if(win(w,n) == 0)
        {
            win_lost = SDL_TRUE;
            shallExit = SDL_TRUE;
            break;
        }
        //moving soldiors
        for(int j = 0; j < s; j++)
        {
            send(sdlRenderer, w, e[0][j].a, e[0][j].b, e[0][j].number, shallExit,e,e[0][j].vatar, e[0][j].p, j, s, c, se);
            //majoon ha
            for(int i = 0; i < e[0][j].number; i++)
            {
                //majoone aval
                if(sqrt(pow((e[i][j].x - maj1.x),2) + pow((e[i][j].y - maj1.y),2)) < 22 && maj1.flag == 1 && w[e[i][j].a].flag_maj == 0)
                {
                    majoon_1_time = time;
                    maj1.flag = 2;
                    w[e[i][j].a].flag_maj = 1;
                    for(int v = 0; v < n; v++)
                    {
                        if(w[v].flag == e[i][j].pl)
                        {
                            w[v].main_color = w[v].maj_1_color;
                            w[v].r = 20;
                            w[v].flag_maj_1 = 1;
                        }
                    }
                }
                //majoone dovom
                if(sqrt(pow((e[i][j].x - maj2.x),2) + pow((e[i][j].y - maj2.y),2)) < 22 && maj2.flag == 1 && w[e[i][j].a].flag_maj == 0)
                {
                    majoon_2_time = time;
                    se = 1;
                    maj2.flag = 2;
                    w[e[i][j].a].flag_maj = 1;
                    for(int v = 0; v < n; v++)
                    {
                        if(w[v].flag == e[i][j].pl)
                        {
                            w[v].main_color = w[v].maj_2_color;
                            w[v].r = 20;
                            w[v].flag_maj_2 = 1;
                        }
                    }

                }
                //majoone sevom(sarbazkhoone 1)
                if(sqrt(pow((e[i][j].x - maj_sarbaz1.x),2) + pow((e[i][j].y - maj_sarbaz1.y),2)) < 22 && maj_sarbaz1.flag == 1 && w[e[i][j].a].flag_maj == 0)
                {
                    majoon_3_time = time;
                    maj_sarbaz1.flag = 2;
                    w[e[i][j].a].flag_maj = 1;
                    for(int v = 0; v < n; v++)
                    {
                        if(w[v].flag == e[i][j].pl)
                        {
                            w[v].main_color = w[v].maj_3_color;
                            w[v].r = 20;
                            w[v].flag_maj_3 = 1;
                        }
                    }
                }
                //majoone chaharom(sarbazkhoone 2)
                if(sqrt(pow((e[i][j].x - maj_sarbaz2.x),2) + pow((e[i][j].y - maj_sarbaz2.y),2)) < 22 && maj_sarbaz2.flag == 1 && w[e[i][j].a].flag_maj == 0)
                {
                    majoon_4_time = time;
                    maj_sarbaz2.flag = 2;
                    w[e[i][j].a].flag_maj = 1;
                    for(int v = 0; v < n; v++)
                    {
                        if(w[v].flag == e[i][j].pl)
                        {
                            w[v].main_color = w[v].maj_4_color;
                            w[v].r = 20;
                            w[v].flag_maj_4 = 1;
                        }
                    }

                }
            }
        }
        //namayeshe sahebe majoon ha ( majoone 1)
        if(maj1.flag == 2)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag_maj_1 == 1)
                {
                    w[i].flag_maj = 1;
                    w[i].main_color = w[i].maj_1_color;
                    w[i].r = 20;
                }
            }
        }
        //namayeshe sahebe majoon ha ( majoone 2)
        if(maj2.flag == 2)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag_maj_1 == 1)
                {
                    w[i].flag_maj = 1;
                    w[i].main_color = w[i].maj_1_color;
                    w[i].r = 20;
                }
            }
        }
        //namayeshe sahebe majoon ha ( majoone 3)
        if(maj_sarbaz1.flag == 2)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag_maj_3 == 1)
                {
                    w[i].flag_maj = 1;
                    w[i].main_color = w[i].maj_3_color;
                    w[i].r = 20;
                }
            }
        }
        //namayeshe sahebe majoon ha ( majoone 4)
        if(maj_sarbaz2.flag == 2)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag_maj_4 == 1)
                {
                    w[i].flag_maj = 1;
                    w[i].main_color = w[i].maj_4_color;
                    w[i].r = 20;
                }
            }
        }

        //namayeshe majoon ha rooye safhe be soorate tasadofi
        //majoone aval
        if(time > majoon_1_time)
        {
            if(maj1.flag == 0)
            {
                maj1.flag = 1;
            }
            if(maj1.flag == 1)
            {
                filledCircleColor(sdlRenderer, maj1.x, maj1.y, 12, maj1.color);
            }
        }
        //majoone dovom
        if(time > majoon_2_time)
        {
            if(maj2.flag == 0)
            {
                maj2.flag = 1;
            }
            if(maj2.flag == 1)
            {
                filledCircleColor(sdlRenderer, maj2.x, maj2.y, 12, maj2.color);
            }
        }
        //majoone dovom
        if(time > majoon_3_time)
        {
            if(maj_sarbaz1.flag == 0)
            {
                maj_sarbaz1.flag = 1;
            }
            if(maj_sarbaz1.flag == 1)
            {
                filledCircleColor(sdlRenderer, maj_sarbaz1.x, maj_sarbaz1.y, 12, maj_sarbaz1.color);
            }
        }
        //majoone chaharom
        if(time > majoon_4_time)
        {
            if(maj_sarbaz2.flag == 0)
            {
                maj_sarbaz2.flag = 1;
            }
            if(maj_sarbaz2.flag == 1)
            {
                filledCircleColor(sdlRenderer, maj_sarbaz2.x, maj_sarbaz2.y, 12, maj_sarbaz2.color);
            }
        }
        //etmame namayeshe majoon ha rooye safhe + etmame karayi
        //majoone aval
        if(time == majoon_1_time + 700)
        {
            maj1.flag = 3;
        }
        //majoone dovom
        if(time == majoon_2_time + 400)
        {
            se = 0;
            maj2.flag = 3;
        }
        //majoone sevom
        if(time == majoon_3_time + 500)
        {
            maj_sarbaz1.flag = 3;
        }
        //majoone chaharom
        if(time == majoon_4_time + 700)
        {
            maj_sarbaz2.flag = 3;
        }
        //bargasht be halate addi
        //majoone aval
        if(maj1.flag == 3)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag_maj_1 == 1)
                {
                    w[i].flag_maj_1 = 0;
                    w[i].flag_maj = 0;
                    if(w[i].flag == 1)
                    {
                        w[i].main_color = w[i].color1;
                    }
                    if(w[i].flag == 2)
                    {
                        w[i].main_color = w[i].color3;
                    }
                    if(w[i].flag == 3)
                    {
                        w[i].main_color = w[i].color4;
                    }
                    w[i].r = 15;
                }
            }
        }
        //majoone dovom
        if(maj2.flag == 3)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag_maj_2 == 1)
                {
                    w[i].flag_maj = 0;
                    w[i].flag_maj_2 = 0;
                    if(w[i].flag == 1)
                    {
                        w[i].main_color = w[i].color1;
                    }
                    if(w[i].flag == 2)
                    {
                        w[i].main_color = w[i].color3;
                    }
                    if(w[i].flag == 3)
                    {
                        w[i].main_color = w[i].color4;
                    }
                    w[i].r = 15;
                }
            }
        }
        //majoone sevom
        if(maj_sarbaz1.flag == 3)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag_maj_3 == 1)
                {
                    w[i].flag_maj = 0;
                    w[i].flag_maj_3 = 0;
                    if(w[i].flag == 1)
                    {
                        w[i].main_color = w[i].color1;
                    }
                    if(w[i].flag == 2)
                    {
                        w[i].main_color = w[i].color3;
                    }
                    if(w[i].flag == 3)
                    {
                        w[i].main_color = w[i].color4;
                    }
                    w[i].r = 15;
                }
            }
        }
        //majoone chaharom
        if(maj_sarbaz2.flag == 3)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag_maj_4 == 1)
                {
                    w[i].flag_maj = 0;
                    w[i].flag_maj_4 = 0;
                    if(w[i].flag == 1)
                    {
                        w[i].main_color = w[i].color1;
                    }
                    if(w[i].flag == 2)
                    {
                        w[i].main_color = w[i].color3;
                    }
                    if(w[i].flag == 3)
                    {
                        w[i].main_color = w[i].color4;
                    }
                    w[i].r = 15;
                }
            }
        }
        //random sending soldiors by player2
        if(time % 350 == 0)
        {
            //find player2 houses
            ///////////
            num1 = 0;
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag == 2)
                {
                    arr1[num1] = i;
                    num1++;
                }
            }
            ////////////
            random1 = rand() % num1;
            mabda1 = arr1[random1];
            maghsad1 = rand() % n;
            if(maghsad1 == mabda1 && maghsad1 != n - 1)
            {
                maghsad1++;
            }
            else if(maghsad1 == mabda1 && maghsad1 == n - 1)
            {
                maghsad1--;
            }
            while(w[maghsad1].flag_maj_3 == 1)
            {
                maghsad1 = rand() % n;
            }
            //define new mission for sending soldiors
            for(int j = 0; j < w[mabda1].number; j++)
            {
                change(e,j,s,mabda1,maghsad1,w,w[mabda1].number);
                e[j][s].pl = 2;
                w[mabda1].target = maghsad1;
            }
            s++;
            if(s > 50)
            {
                s = s % 51;
            }
        }

        //player 3
        if(time % 450 == 0)
        {
            //find player3 houses
            ///////////
            num2 = 0;
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag == 3)
                {
                    arr2[num2] = i;
                    num2++;
                }
            }
            ////////////
            random2 = rand() % num2;
            mabda2 = arr2[random2];
            maghsad2 = rand() % n;
            if(maghsad2 == mabda2 && maghsad2 != n - 1)
            {
                maghsad2++;
            }
            else if(maghsad2 == mabda2 && maghsad2 == n - 1)
            {
                maghsad2--;
            }
            while(w[maghsad2].flag_maj_3 == 1)
            {
                maghsad2 = rand() % n;
            }
            //define new mission for sending soldiors
            for(int j = 0; j < w[mabda2].number; j++)
            {
                change(e,j,s,mabda2,maghsad2,w,w[mabda2].number);
                e[j][s].pl = 3;
                w[mabda2].target = maghsad2;
            }
            s++;
            if(s > 50)
            {
                s = s % 51;
            }
        }
        //input key or mouse
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
                        for(int i = 0; i < n; i++)
                        {
                            if(sqrt(pow((x - w[i].x),2) + pow((y - w[i].y),2)) < 15)
                            {
                                if(a == -1 && w[i].flag == 1)
                                {
                                    a = i;
                                }
                                else if(a == -1)
                                {
                                    break;
                                }
                                else
                                {
                                    if(i != a && w[i].flag_maj_3 != 1)
                                    {
                                        b = i;
                                        if(w[a].flag_maj_1 == 1)
                                        {
                                            w[a].main_color = w[a].maj_1_color;
                                        }
                                        else if(w[a].flag_maj_2 == 1)
                                        {
                                            w[a].main_color = w[a].maj_2_color;
                                        }
                                        else
                                        {
                                            w[a].main_color = w[a].color1;
                                        }
                                        ////////////////////////
                                        //define new mission for sending soldiors
                                        for(int j = 0; j < w[a].number; j++)
                                        {
                                            change(e,j,s,a,b,w,w[a].number);
                                            e[j][s].pl = 1;
                                            w[a].target = b;
                                        }
                                        s++;
                                        if(s > 50)
                                        {
                                            s = s % 51;
                                        }
                                        ////////////////////////


                                    }
                                    else
                                    {
                                        w[a].main_color = w[a].color1;
                                        w[b].main_color = w[b].color1;
                                        a = -1;
                                        b = -1;
                                        break;
                                    }
                                    a = -1;
                                    b = -1;
                                    break;
                                }

                                //change the color of cells(if it's needed)
                                if(w[i].main_color == w[i].color1)
                                {
                                    w[i].main_color = w[i].color2;
                                }
                                else
                                {
                                    w[i].main_color = w[i].color1;
                                }
                            }
                        }

                    }

            }

        }
        //time and adding new soldiors
        //manage time and number of soldiors
        time++;
        if(time % 60 == 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].number < 20 && w[i].flag != 0 && w[i].target == -1 && w[i].flag_maj_4 != 1)
                {
                    w[i].number++;
                }
            }
        }
        if(time % 20 == 0)
        {
            for(int i = 0; i < n; i++)
            {
                if(w[i].number < 20 && w[i].flag != 0 && w[i].target == -1 && w[i].flag_maj_4 == 1)
                {
                    w[i].number++;
                }
            }
        }
        //present the renderer
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(1000 / 30);
    }


    SDL_DestroyRenderer(sdlRenderer);
    SDL_DestroyWindow(sdlWindow);
    //score
    char *name[100];
    char *id[100];
    for(int i = 0; i < 100; i++)
    {
        name[i] = malloc(20);
        id[i] = malloc(20);
    }
    int po = 0;
    if(win_lost == SDL_TRUE)
    {
        FILE *f = fopen("/Users/amir/Desktop/test/scores/name.txt", "a+");
        fprintf(f, "%s\n", klkl);
        fclose(f);
    }
    FILE *file = fopen("/Users/amir/Desktop/test/scores/name.txt", "r");
    for(int i = 0; i < 100; i++)
    {
        int flag = 0;
        if(fscanf(file, "%[^\n ] ", name[i]) != EOF)
        {
            for(int j = 0; j < i; j++)
            {
                if(strcmp(name[i],name[j]) != 0)
                {
                    flag++;
                }
            }
            if(flag == i)
            {
                id[po] = name[i];
                po++;
            }
        }
    }
    fclose(file);
    show_score(win_lost,id,po,name);

    SDL_Quit();

}
