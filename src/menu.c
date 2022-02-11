//main libraries
#include <stdlib.h>
//new & external libraries
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "functions.h"
#include "SDL_ttf.h"
#include "SDL_image.h"

char* main_menu()
{
    TTF_Init();
    SDL_bool quit = SDL_FALSE;
    SDL_INIT();
    IMG_Init(IMG_INIT_JPG);

    //variables
    char *user = malloc(15);
    int num = 0;

    //new window
    SDL_Window * window = SDL_CreateWindow("menu",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,480, 0);

    //renderer
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    //fonts
    TTF_Font * font_1 = TTF_OpenFont("/Users/amir/Desktop/test/fonts/a.ttf", 35);
    TTF_Font * font_2 = TTF_OpenFont("/Users/amir/Desktop/test/fonts/a.ttf", 20);

    //colors
    SDL_Color color = { 120, 120, 0 };

    //define surfaces
    SDL_Surface * welcome = TTF_RenderText_Solid(font_1,"Welcome to state.io", color);
    SDL_Surface *background = IMG_Load("/Users/amir/Desktop/test/pictures/Mountains_of_Wadi_Shawka.jpg");
    SDL_Surface *me_name = TTF_RenderText_Solid(font_2, "Created by: AmirMohammad Derakhshandeh", color);
    SDL_Surface *me_student_id = TTF_RenderText_Solid(font_2, "StudentID: 400101153", color);
    SDL_Surface *input = TTF_RenderText_Solid(font_1, "User Name: ", color);

    //define textures
    SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, welcome);
    SDL_Texture * texture_image = SDL_CreateTextureFromSurface(renderer, background);
    SDL_Texture * me_name_tex = SDL_CreateTextureFromSurface(renderer, me_name);
    SDL_Texture * me_id_tex = SDL_CreateTextureFromSurface(renderer, me_student_id);
    SDL_Texture * input_tex = SDL_CreateTextureFromSurface(renderer, input);


    //////positions/////////
    int texW = 0;
    int texH = 0;
    //welcome's position
    SDL_QueryTexture(texture, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect1 = { 160, 10, texW, texH };

    //me_name's position
    SDL_QueryTexture(me_name_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect2 = { 120, 390, texW, texH};

    //me_StudentID's position
    SDL_QueryTexture(me_id_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect3 = { 220, 420, texW, texH};

    //UserName's position
    SDL_QueryTexture(input_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect4 = { 100, 150, texW, texH};

    //box's position
    SDL_Rect box;
    box.x = 330;
    box.y = 160;
    box.w = 200;
    box.h = 30;


    //////end of positions/////////
    while (!quit)
    {
        ////////////////////
        SDL_Event event;
        SDL_PollEvent(&event);
        switch (event.type)
        {
            case SDL_QUIT:
                quit = SDL_TRUE;
                break;

            case SDL_KEYDOWN:
                if(event.key.keysym.sym == SDLK_a)
                {
                    user[num] = 'a';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_b)
                {
                    user[num] = 'b';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_c)
                {
                    user[num] = 'c';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_d)
                {
                    user[num] = 'd';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_e)
                {
                    user[num] = 'e';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_f)
                {
                    user[num] = 'f';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_g)
                {
                    user[num] = 'g';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_h)
                {
                    user[num] = 'h';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_i)
                {
                    user[num] = 'i';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_j)
                {
                    user[num] = 'j';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_k)
                {
                    user[num] = 'k';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_l)
                {
                    user[num] = 'l';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_m)
                {
                    user[num] = 'm';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_n)
                {
                    user[num] = 'n';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_o)
                {
                    user[num] = 'o';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_p)
                {
                    user[num] = 'p';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_q)
                {
                    user[num] = 'q';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_r)
                {
                    user[num] = 'r';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_s)
                {
                    user[num] = 's';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_t)
                {
                    user[num] = 't';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_u)
                {
                    user[num] = 'u';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_v)
                {
                    user[num] = 'v';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_w)
                {
                    user[num] = 'w';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_x)
                {
                    user[num] = 'x';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_y)
                {
                    user[num] = 'y';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_z)
                {
                    user[num] = 'z';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_SPACE)
                {
                    user[num] = ' ';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_0)
                {
                    user[num] = '0';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_1)
                {
                    user[num] = '1';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_2)
                {
                    user[num] = '2';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_3)
                {
                    user[num] = '3';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_4)
                {
                    user[num] = '4';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_5)
                {
                    user[num] = '5';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_6)
                {
                    user[num] = '6';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_7)
                {
                    user[num] = '7';
                    num++;

                }
                if(event.key.keysym.sym == SDLK_8)
                {
                    user[num] = '8';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_9)
                {
                    user[num] = '9';
                    num++;
                }
                if(event.key.keysym.sym == SDLK_BACKSPACE)
                {
                    num--;
                    user[num] = NULL;
                }
                if(event.key.keysym.sym == SDLK_RETURN)
                {
                    quit = SDL_TRUE;
                    break;
                }

        }
        ///////////////////
        //update username on screen
        SDL_Rect dstrect5 = {340, 160, 13 * (num + 1), texH};
        SDL_Surface *username = TTF_RenderText_Solid(font_2, user, color);
        SDL_Texture * username_tex = SDL_CreateTextureFromSurface(renderer, username);
        SDL_QueryTexture(username_tex, NULL, NULL, &texW, &texH);

        //show background
        SDL_RenderCopy(renderer, texture_image, NULL, NULL);

        //box
        SDL_RenderDrawRect(renderer, &box);
        SDL_SetRenderDrawColor(renderer, 120, 120, 0, 0);

        //titles
        SDL_RenderCopy(renderer, texture, NULL, &dstrect1);
        SDL_RenderCopy(renderer, me_name_tex, NULL, &dstrect2);
        SDL_RenderCopy(renderer, me_id_tex, NULL, &dstrect3);
        SDL_RenderCopy(renderer, input_tex, NULL, &dstrect4);
        SDL_RenderCopy(renderer, username_tex, NULL, &dstrect5);
        SDL_RenderPresent(renderer);

        //free username on screen
        SDL_DestroyTexture(username_tex);
        SDL_FreeSurface(username);
    }

    //free textures
    SDL_DestroyTexture(texture);
    SDL_DestroyTexture(texture_image);
    SDL_DestroyTexture(me_name_tex);
    SDL_DestroyTexture(me_id_tex);
    SDL_DestroyTexture(input_tex);

    //free surfaces
    SDL_FreeSurface(welcome);
    SDL_FreeSurface(background);
    SDL_FreeSurface(me_name);
    SDL_FreeSurface(me_student_id);
    SDL_FreeSurface(input);


    //destroy renderer
    SDL_DestroyRenderer(renderer);

    //destroy window
    SDL_DestroyWindow(window);

    //close
    TTF_CloseFont(font_1);
    TTF_CloseFont(font_2);
    SDL_Quit();
    TTF_Quit();
    IMG_Quit();

    return user;
}