#include <stdio.h>
#include "SDL.h"
#include "SDL_ttf.h"

//structs
struct tak_sarbaz
{
    float x, y;
    Uint32 color1;
    Uint32 color2;
    Uint32 color3;
    Uint32 maj_1_color;
    Uint32 maj_2_color;
    Uint32 maj_3_color;
    Uint32 maj_4_color;
    int flag;
    int a, b;
    int number;
    double vatar;
    int p;
    int pl;
};

struct scores
{
    char a[15];
    int score;
};
struct all_house
{
    //x-y
    float x, y;
    //number
    int number;
    int r;
    //colors
    Uint32 color1;
    Uint32 color2;
    Uint32 color3;
    Uint32 color4;
    Uint32 main_color;
    Uint32 momtane;
    Uint32 maj_1_color;
    Uint32 maj_2_color;
    Uint32 maj_3_color;
    Uint32 maj_4_color;
    //flag(s)
    int flag;
    int target;
    int flag_maj_1;//majoone sorate khodam
    int flag_maj_2;//majoone sabet kardane digaran
    int flag_maj_3;//adame hamleye harif be sarbaz khoone
    int flag_maj_4;//afzayeshe sorat dar sarbazkhoone ha
    int flag_maj;//vaziaye dashtan ya nadashtane majoon

};


struct nahiye
{
    Uint32 color1;
    Uint32 color2;
    Uint32 color3;
    Uint32 momtane;
    Uint32 main_color;
};

struct majoon1
{
    float x, y;
    int flag;
    Uint32 color;
};


//functions
int SDL_INIT();

void make_soldior_houses(struct all_house w[], int n);

void send(SDL_Renderer *sdlRenderer, struct all_house s[], int a, int b, int n, SDL_bool shallExit, struct tak_sarbaz e[][100],
          double vatar, int p, int m, int c, struct nahiye w[], int se);

void change(struct tak_sarbaz e[][100], int j, int s, int a, int b, struct all_house w[], int q);

void show_soldior_houses(SDL_Renderer *sdlRenderer, int n, struct all_house w[], int a);

int lost(struct all_house w[], int n);

int win(struct all_house w[], int n);

int majoon_x(struct all_house w[], int v1, int v2);

int majoon_y(struct all_house w[], int v1, int v2);

void make_map_1(struct all_house w[]);

void make_map_2(struct all_house w[]);

int cal_score(char *a[], char *b);

int find_max(int s[], int n);

