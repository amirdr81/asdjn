#include <stdio.h>
#include "SDL.h"

struct soldior
{
    float x, y;
    Uint32 color1;
    Uint32 color2;
    Uint32 main_color;
    int flag;

};


struct tak_sarbaz
{
    float x, y;
    Uint32 color;
    int flag;
};


struct all_house
{
    //x-y
    float x, y;
    //number
    int number;
    //colors
    Uint32 color1;
    Uint32 color2;
    Uint32 main_color;
    Uint32 momtane;

};

void send_soldior(SDL_Renderer *sdlRenderer, SDL_bool shallExit, struct soldior a, struct soldior b, struct soldior c);

void change_color(int x, int y, SDL_Renderer *sdlRenderer, struct soldior a);

void select_a_cell(SDL_Renderer *sdlRenderer, struct soldior a);

int SDL_INIT();


void select(SDL_Event sdlEvent, struct soldior s);
void send(SDL_Renderer *sdlRenderer, struct soldior s[], int a, int b, int n, SDL_bool shallExit, int d);


