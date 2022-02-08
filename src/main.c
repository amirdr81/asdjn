//main libraries
#include <math.h>

//new & external libraries
#include "SDL.h"
#include "../header/functions.h"
#include "../header/scorebox.h"

SDL_bool shallExit = SDL_FALSE;
SDL_bool win_lost = SDL_FALSE;

int main()
{
    srand(time(0));
    SDL_INIT();
    //make new window
    SDL_Window *sdlWindow = SDL_CreateWindow("Test_Window", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640,
                                             480, SDL_WINDOW_OPENGL);
    //define variables & structs
    int a = -1, b = -1, s = 0, n;

    //make random n
    n = 3;
    struct all_house w[n];
    struct tak_sarbaz e[1000][100];
    long long int time = 1;

    //make random places for soldior houses
    make_soldior_houses(w,n);

    //player 1
    w[0].flag = 1;
    w[0].main_color = w[0].color1;
    w[0].number = 15;

    //player 2
    w[1].flag = 2;
    w[1].main_color = w[1].color3;
    w[1].number = 15;

    //player 3
    w[2].flag = 3;
    w[2].main_color = w[2].color4;
    w[2].number = 15;
    //create renderer
    SDL_Renderer *sdlRenderer = SDL_CreateRenderer(sdlWindow, -1, SDL_RENDERER_PRESENTVSYNC | SDL_RENDERER_ACCELERATED);

    //loop
    while(shallExit == SDL_FALSE)
    {
        //colors of the renderer
        SDL_SetRenderDrawColor(sdlRenderer, 0xff, 0xff, 0xff, 0xff);
        SDL_RenderClear(sdlRenderer);

        //soldior houses
        show_soldior_houses(sdlRenderer, n, w, a, b);

        //lost
        if(lost(w,n) == 0)
        {
            shallExit == SDL_TRUE;
            break;
        }
        //win
        if(win(w,n) == 0)
        {
            win_lost = SDL_TRUE;
            shallExit == SDL_TRUE;
            break;
        }
        //moving soldiors
        for(int j = 0; j < s; j++)
        {
            send(sdlRenderer, w, e[0][j].a, e[0][j].b, e[0][j].number, shallExit,e,e[0][j].vatar, e[0][j].p, j, w);
        }

        //random sending soldiors by player2
        if(time % 500 == 0)
        {
            //find player2 houses
            ///////////
            int arr[n];
            int num = 0;
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag == 2)
                {
                    arr[num] = i;
                    num++;
                }
            }
            ////////////
            int random = rand() % num;
            int mabda = arr[random];
            int maghsad = rand() % n;
            if(maghsad == mabda && maghsad != n - 1)
            {
                maghsad++;
            }
            else if(maghsad == mabda && maghsad == n - 1)
            {
                maghsad--;
            }
            int q = w[mabda].number;
            w[mabda].number = 0;
            //define new mission for sending soldiors
            for(int j = 0; j < q; j++)
            {
                change(e,j,s,mabda,maghsad,w,q);
                e[j][s].pl = 2;
            }
            s++;
            if(s > 99)
            {
                s = s % 100;
            }

        }

        //random sending soldiors by player3
        if(time % 450 == 0)
        {
            //find player3 houses
            ///////////
            int arr[n];
            int num = 0;
            for(int i = 0; i < n; i++)
            {
                if(w[i].flag == 3)
                {
                    arr[num] = i;
                    num++;
                }
            }
            ////////////
            int random = rand() % num;
            int mabda = arr[random];
            int maghsad = rand() % n;
            if(maghsad == mabda && maghsad != n - 1)
            {
                maghsad++;
            }
            else if(maghsad == mabda && maghsad == n - 1)
            {
                maghsad--;
            }
            int q = w[mabda].number;
            w[mabda].number = 0;
            //define new mission for sending soldiors
            for(int j = 0; j < q; j++)
            {
                change(e,j,s,mabda,maghsad,w,q);
                e[j][s].pl = 3;
            }
            s++;
            if(s > 99)
            {
                s = s % 100;
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
                                    if(i != a)
                                    {
                                        b = i;
                                        w[a].main_color = w[a].color1;
                                        ////////////////////////
                                        int q = w[a].number;
                                        w[a].number = 0;
                                        //define new mission for sending soldiors
                                        for(int j = 0; j < q; j++)
                                        {
                                            change(e,j,s,a,b,w,q);
                                            e[j][s].pl = 1;
                                        }
                                        s++;
                                        if(s > 99)
                                        {
                                            s = s % 100;
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
                if(w[i].number < 20)
                {
                    w[i].number++;
                }
            }
        }
        //present the renderer
        SDL_RenderPresent(sdlRenderer);
        SDL_Delay(1000 / 30);
    }
    show_score(win_lost);
    SDL_DestroyWindow(sdlWindow);


    SDL_Quit();
    return 0;
}
