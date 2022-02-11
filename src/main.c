#include <stdlib.h>
#include <stdio.h>
#include "functions.h"
#include "scorebox.h"
#include "map1.h"
#include "map2.h"
#include "menu.h"
#include "new.h"

int main()
{
    //main menu + user ID
    char *id = main_menu();
    //choose map, play and show scoreboard
    int which_map = new_page();
    if(which_map == 1)
    {
        map_1_exe(id);
    }
    if(which_map == 2)
    {
        map_2_exe(id);
    }
}
