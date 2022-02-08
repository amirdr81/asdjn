#include <stdio.h>
#include "SDL.h"

//structs
struct tak_sarbaz
{
    float x, y;
    Uint32 color1;
    Uint32 color2;
    int flag;
    int a, b;
    float x1, y1, x2, y2;
    int number;
    double vatar;
    int p;
    int pl;
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
    Uint32 color3;
    Uint32 color4;
    Uint32 main_color;
    Uint32 momtane;
    //flag
    int flag;
};

//functions
int SDL_INIT();

int SDL_TTF_INIT();

void make_sure(struct all_house w[], int j, int i);

void make_soldior_houses(struct all_house w[], int n);

void send(SDL_Renderer *sdlRenderer, struct all_house s[], int a, int b, int n, SDL_bool shallExit, struct tak_sarbaz e[][100],
          double vatar, int p, int m, struct all_house w[], int flag_player2, int arr[]);

void change(struct tak_sarbaz e[][100], int j, int s, int a, int b, struct all_house w[], int q);

void show_soldior_houses(SDL_Renderer *sdlRenderer, int n, struct all_house w[], int a, int b);

void change_color(struct all_house w[], int i);

