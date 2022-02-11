#include <stdlib.h>
#include <stdio.h>

#include "SDL.h"
#include "SDL_ttf.h"
#include "functions.h"
#include "map1.h"
#include "map2.h"
#include "SDL_image.h"


SDL_bool quit = SDL_FALSE;

int tim = 0;

void show_score(SDL_bool text, char *b[], int n, char *a[])
{
    //calcute scores
    int score[100];
    int num = 0;
    for(int i = 0; i < n; i++)
    {
        score[num] = cal_score(a,b[i]);
        num++;
    }
    int first = find_max(score, num);
    int first_score = score[first];
    score[first] = 0;
    char *f1 = malloc(5);
    gcvt(first_score, 10, f1);
    int second = find_max(score, num);
    int second_score = score[second];
    score[second] = 0;
    char *f2 = malloc(5);
    gcvt(second_score, 10, f2);

    ///////////add/update user's score/////////
    SDL_INIT();
    TTF_Init();

    //new window
    SDL_Window * window = SDL_CreateWindow("scorebox",SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640,480, 0);

    //new renderer
    SDL_Renderer * renderer = SDL_CreateRenderer(window, -1, 0);

    //fonts
    TTF_Font * font1 = TTF_OpenFont("/Users/amir/Desktop/test/fonts/a.ttf", 25);

    //colors
    SDL_Color white = { 120, 120, 0 };

    //new surfaces
    SDL_Surface * surface1;
    SDL_Surface *p1 = TTF_RenderText_Solid(font1,b[first], white);
    SDL_Surface *p2 = TTF_RenderText_Solid(font1,b[second], white);
    SDL_Surface *note = TTF_RenderText_Solid(font1,"Top 2 Players", white);
    SDL_Surface *bye = TTF_RenderText_Solid(font1,"source: commons.wikimedia.org", white);
    SDL_Surface *background = IMG_Load("/Users/amir/Desktop/test/pictures/Mountains_of_Wadi_Shawka.jpg");

    //new textures
    SDL_Texture * texture1;
    SDL_Texture * p1_tex = SDL_CreateTextureFromSurface(renderer, p1);
    SDL_Texture * p2_tex = SDL_CreateTextureFromSurface(renderer, p2);
    SDL_Texture * note_tex = SDL_CreateTextureFromSurface(renderer, note);
    SDL_Texture * bye_tex = SDL_CreateTextureFromSurface(renderer, bye);
    SDL_Texture * texture_image = SDL_CreateTextureFromSurface(renderer, background);

    //positions
    //lost-win
    int tex1W = 180;
    int tex1H = 100;
    SDL_Rect dstrect = { 240, 40, tex1W,tex1H };

    int texW = 0;
    int texH = 0;
    //p1
    SDL_QueryTexture(p1_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect1 = { 260, 180, texW, texH };
    //p2
    SDL_QueryTexture(p2_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect2 = { 260, 210, texW, texH };

    //note
    SDL_QueryTexture(note_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect4 = { 260, 130, texW, texH };
    //source
    SDL_QueryTexture(bye_tex, NULL, NULL, &texW, &texH);
    SDL_Rect dstrect5 = { 150, 430, texW, texH };


    while (quit == SDL_FALSE)
    {
        //render
        SDL_RenderClear(renderer);

        ///////quit//////
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
        ///////////////
        //show background
        SDL_RenderCopy(renderer, texture_image, NULL, NULL);


        //show lost or win
        if(text == SDL_TRUE)
        {
            surface1 = TTF_RenderText_Solid(font1, "You Win:))))", white);
        }
        else
        {
            surface1 = TTF_RenderText_Solid(font1, "You lost:(((", white);
        }

        //others
        texture1 = SDL_CreateTextureFromSurface(renderer, surface1);
        SDL_QueryTexture(texture1, NULL, NULL, &tex1W, &tex1H);

        //scores
        stringRGBA(renderer, 390, 197, f1, 0x00, 0x00, 0x00, 0xff);
        stringRGBA(renderer,390, 227, f2, 0x00, 0x00, 0x00, 0xff);

        //present
        SDL_RenderCopy(renderer, texture1, NULL, &dstrect);
        SDL_RenderCopy(renderer, p1_tex, NULL, &dstrect1);
        SDL_RenderCopy(renderer, p2_tex, NULL, &dstrect2);
        SDL_RenderCopy(renderer, note_tex, NULL, &dstrect4);
        SDL_RenderCopy(renderer, bye_tex, NULL, &dstrect5);
        SDL_RenderPresent(renderer);
    }

    //free surface
    SDL_FreeSurface(surface1);
    SDL_FreeSurface(p1);
    SDL_FreeSurface(p2);
    SDL_FreeSurface(note);
    SDL_FreeSurface(bye);
    SDL_FreeSurface(background);
    //free texture
    SDL_DestroyTexture(texture1);
    SDL_DestroyTexture(p1_tex);
    SDL_DestroyTexture(p2_tex);
    SDL_DestroyTexture(note_tex);
    SDL_DestroyTexture(bye_tex);
    SDL_DestroyTexture(texture_image);

    //render & window
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);

    //font
    TTF_CloseFont(font1);

    //
    TTF_Quit();
    SDL_Quit();
}