//main libraries
#include <stdlib.h>
//new & external libraries
#include "SDL.h"
#include "SDL2_gfxPrimitives.h"
#include "functions.h"
#include "SDL_ttf.h"
#include "SDL_image.h"
#include "map1.h"

int new_page()
{
    TTF_Init();
    SDL_bool quit = SDL_FALSE;
    SDL_INIT();
    IMG_Init(IMG_INIT_JPG | IMG_INIT_PNG);


    //new window
    SDL_Window * window = SDL_CreateWindow("menu",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,480, 0);

    //renderer
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    //fonts
    TTF_Font * font_1 = TTF_OpenFont("/Users/amir/Desktop/test/fonts/a.ttf", 35);
    TTF_Font * font_2 = TTF_OpenFont("/Users/amir/Desktop/test/fonts/a.ttf", 20);
    TTF_Font * font_3 = TTF_OpenFont("/Users/amir/Desktop/test/fonts/a.ttf", 45);

    //colors
    SDL_Color color = { 120, 120, 0 };
    SDL_Color white = { 255, 255, 255 };

    //define surfaces
    SDL_Surface *map1 = TTF_RenderText_Solid(font_1,"Map 1", white);
    SDL_Surface *map2 = TTF_RenderText_Solid(font_1,"Map 2", white);
    SDL_Surface *note = TTF_RenderText_Solid(font_3,"Note: ", white);
    SDL_Surface *yellow = TTF_RenderText_Solid(font_2,"Yellow Potion: Boost Your Soldiores's Speed for 7 Seconds!", white);
    SDL_Surface *light = TTF_RenderText_Solid(font_2,"Light Blue Potion: Boost Soldier's production speed (3 Times)", white);
    SDL_Surface *light2 = TTF_RenderText_Solid(font_2,"for 7 Seconds!", white);
    SDL_Surface *purple = TTF_RenderText_Solid(font_2,"Purple Potion: Stop the Enemy for 4 Seconds!", white);
    SDL_Surface *dark = TTF_RenderText_Solid(font_2,"Dark Blue Potion: Enemy cannot attack You!", white);
    SDL_Surface *background = IMG_Load("/Users/amir/Desktop/test/pictures/Mountains_of_Wadi_Shawka.jpg");
    SDL_Surface *map_1 = IMG_Load("/Users/amir/Desktop/test/pictures/map1.png");
    SDL_Surface *map_2 = IMG_Load("/Users/amir/Desktop/test/pictures/map2.png");


    //define textures
    SDL_Texture * map1_tex = SDL_CreateTextureFromSurface(renderer, map1);
    SDL_Texture * map2_tex = SDL_CreateTextureFromSurface(renderer, map2);
    SDL_Texture * note_tex = SDL_CreateTextureFromSurface(renderer, note);
    SDL_Texture * yellow_tex = SDL_CreateTextureFromSurface(renderer, yellow);
    SDL_Texture * purple_tex = SDL_CreateTextureFromSurface(renderer, purple);
    SDL_Texture * dark_tex = SDL_CreateTextureFromSurface(renderer, dark);
    SDL_Texture * light_tex = SDL_CreateTextureFromSurface(renderer, light);
    SDL_Texture * light2_tex = SDL_CreateTextureFromSurface(renderer, light2);
    SDL_Texture * texture_image = SDL_CreateTextureFromSurface(renderer, background);
    SDL_Texture * map_1_tex = SDL_CreateTextureFromSurface(renderer, map_1);
    SDL_Texture * map_2_tex = SDL_CreateTextureFromSurface(renderer, map_2);

    //////positions/////////
    int texW = 0;
    int texH = 0;
    //map1's position
    SDL_QueryTexture(map1_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect1 = { 150, 100, texW, texH };
    //map2's position
    SDL_QueryTexture(map2_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect2 = { 400, 100, texW, texH };
    //note
    SDL_QueryTexture(note_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect3 = { 30, 240, texW, texH };
    //yellow
    SDL_QueryTexture(yellow_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect4 = { 30, 300, texW, texH };
    //dark
    SDL_QueryTexture(dark_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect5 = { 30, 330, texW, texH };
    //light
    SDL_QueryTexture(light_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect6 = { 30, 360, texW, texH };
    //light2
    SDL_QueryTexture(light2_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect7 = { 30, 390, texW, texH };
    //purple
    SDL_QueryTexture(purple_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect8 = { 30, 420, texW, texH };
    //map1
    SDL_QueryTexture(map_1_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect9 = { 145, 160, 108, 80 };
    //map2
    SDL_QueryTexture(map_2_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect10 = { 395, 160, 108, 80 };


    //box map 1
    SDL_Rect box1;
    box1.x = 145;
    box1.y = 105;
    box1.w = 108;
    box1.h = 45;

    //box map 2
    SDL_Rect box2;
    box2.x = 395;
    box2.y = 105;
    box2.w = 108;
    box2.h = 45;

    int flag;
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
                flag = 0;
            case SDL_MOUSEBUTTONUP:
                if (event.button.button == SDL_BUTTON_LEFT)
                {
                    int x = event.button.x;
                    int y = event.button.y;
                    if(y > 110 && y < 135 && x > 150 && x < 245)
                    {
                        flag = 1;
                        quit = SDL_TRUE;
                    }
                    else if(x > 400 && x < 495 && y > 110 && y < 135)
                    {
                        flag = 2;
                        quit = SDL_TRUE;
                    }
                }



        }
        //show background
        SDL_RenderCopy(renderer, texture_image, NULL, NULL);

        //maps
        SDL_RenderCopy(renderer, map_1_tex, NULL, &dstrect9);
        SDL_RenderCopy(renderer, map_2_tex, NULL, &dstrect10);

        //boxes
        SDL_RenderFillRect(renderer, &box1);
        SDL_SetRenderDrawColor(renderer, 120, 120, 0, 220);
        SDL_RenderFillRect(renderer, &box2);

        //titles
        SDL_RenderCopy(renderer, map1_tex, NULL, &dstrect1);
        SDL_RenderCopy(renderer, map2_tex, NULL, &dstrect2);
        SDL_RenderCopy(renderer, note_tex, NULL, &dstrect3);
        SDL_RenderCopy(renderer, yellow_tex, NULL, &dstrect4);
        SDL_RenderCopy(renderer, dark_tex, NULL, &dstrect5);
        SDL_RenderCopy(renderer, light_tex, NULL, &dstrect6);
        SDL_RenderCopy(renderer, light2_tex, NULL, &dstrect7);
        SDL_RenderCopy(renderer, purple_tex, NULL, &dstrect8);

        SDL_RenderPresent(renderer);

    }
    //free textures
    SDL_DestroyTexture(map1_tex);
    SDL_DestroyTexture(map2_tex);
    SDL_DestroyTexture(note_tex);
    SDL_DestroyTexture(yellow_tex);
    SDL_DestroyTexture(purple_tex);
    SDL_DestroyTexture(light_tex);
    SDL_DestroyTexture(light2_tex);
    SDL_DestroyTexture(dark_tex);
    SDL_DestroyTexture(texture_image);
    SDL_DestroyTexture(map_2_tex);
    SDL_DestroyTexture(map_1_tex);


    //free surfaces
    SDL_FreeSurface(map1);
    SDL_FreeSurface(map2);
    SDL_FreeSurface(note);
    SDL_FreeSurface(yellow);
    SDL_FreeSurface(purple);
    SDL_FreeSurface(light);
    SDL_FreeSurface(light2);
    SDL_FreeSurface(dark);
    SDL_FreeSurface(background);
    SDL_FreeSurface(map_1);
    SDL_FreeSurface(map_2);

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
    return flag;

}