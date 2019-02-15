//
//  main.cpp
//  Final Project
//
//  Created by Sean Tesch on 9/12/16.
//  Copyright © 2016 Sean Tesch. All rights reserved.
//
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

/* - Declares Window, Renderer, and variables - */
SDL_Window* screen;                     SDL_Renderer* renderer;
SDL_Surface* player_sur;                SDL_Texture* player_tex;
SDL_Surface* player_dagger_sur;         SDL_Texture* player_dagger_tex;
SDL_Surface* player_spear_sur;          SDL_Texture* player_spear_tex;
SDL_Surface* player_steel_sur;          SDL_Texture* player_steel_tex;
SDL_Surface* player_steel_dagger_sur;   SDL_Texture* player_steel_dagger_tex;
SDL_Surface* player_steel_spear_sur;    SDL_Texture* player_steel_spear_tex;
SDL_Surface* player_gold_sur;           SDL_Texture* player_gold_tex;
SDL_Surface* player_gold_dagger_sur;    SDL_Texture* player_gold_dagger_tex;
SDL_Surface* player_gold_spear_sur;     SDL_Texture* player_gold_spear_tex;
SDL_Surface* orc_sur;                   SDL_Texture* orc_tex;
SDL_Surface* human_sur;                 SDL_Texture* human_tex;
SDL_Surface* dark_elf_sur;              SDL_Texture* dark_elf_tex;
SDL_Surface* human2_sur;                SDL_Texture* human2_tex;
SDL_Surface* gold_sur;                  SDL_Texture* gold_tex;
SDL_Surface* steel_sur;                 SDL_Texture* steel_tex;
SDL_Surface* dagger_sur;                SDL_Texture* dagger_tex;
SDL_Surface* spear_sur;                 SDL_Texture* spear_tex;
SDL_Surface* map_sur;                   SDL_Texture* map_tex;
SDL_Surface* win_sur;                   SDL_Texture* win_tex;
SDL_Surface* lose_sur;                  SDL_Texture* lose_tex;
SDL_Rect gold_src;                      SDL_Rect gold_dest;
SDL_Rect steel_src;                     SDL_Rect steel_dest;
SDL_Rect dagger_src;                    SDL_Rect dagger_dest;
SDL_Rect spear_src;                     SDL_Rect spear_dest;
SDL_Rect player_src;                    SDL_Rect player_dest;
SDL_Rect orc_src;                       SDL_Rect orc_dest;
SDL_Rect human1_1_src;                  SDL_Rect human1_1_dest;
SDL_Rect human2_1_src;                  SDL_Rect human2_1_dest;
SDL_Rect dark_elf_1_src;                SDL_Rect dark_elf_1_dest;
SDL_Rect human1_2_src;                  SDL_Rect human1_2_dest;
SDL_Rect human2_2_src;                  SDL_Rect human2_2_dest;
SDL_Rect dark_elf_2_src;                SDL_Rect dark_elf_2_dest;
SDL_Rect boss_src;                      SDL_Rect boss_dest;
SDL_Rect map_src;                       SDL_Rect map_dest;
SDL_Rect win_src;                       SDL_Rect win_dest;
SDL_Rect lose_src;                      SDL_Rect lose_dest;
SDL_Event event;
bool attacking = false;
bool gameRunning = true;
int screenHeight = 600, screenWidth = 800;

/* - Map structure - */
struct mapItem
{
    // Used for boundaries
    bool top;
    bool bottom;
    bool left;
    bool right;
    int roomShown;
};

/* - Player structure - */
struct player
{
    SDL_Texture* shownPlayer;
    bool hasSteelArmor;
    bool hasGoldArmor;
    bool hasDagger;
    bool hasSpear;
    double health;
    int damage;
    int roomIn;
    bool alive;
};

/* - Player structure - */
struct enemy
{
    double health;
    int damage;
    bool alive;
};

/* - Setup function - */
void SDLSetup()
{
    if
        (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO) != 0)
    {
        std::cout << "SDL failed to init: " << std::endl;
        SDL_GetError();
        exit(1);
    }
    
    /* - Create window and renderer - */
    SDL_CreateWindowAndRenderer(screenWidth, screenHeight, SDL_WINDOW_SHOWN, &screen, &renderer);
    
    if ((screen == NULL) || (renderer == NULL))
    {
        std::cout << "SDL_CreateWindowAndRenderer Error: " << std::endl;
        SDL_GetError();
        exit(1);
    }
    
    /* - Adds the sprites from PNG files - */
    player_sur =                IMG_Load("player.png");                 player_tex = SDL_CreateTextureFromSurface(renderer, player_sur);
    player_dagger_sur =         IMG_Load("player_dagger.png");          player_dagger_tex = SDL_CreateTextureFromSurface(renderer, player_dagger_sur);
    player_spear_sur =          IMG_Load("player_spear.png");           player_spear_tex = SDL_CreateTextureFromSurface(renderer, player_spear_sur);
    player_steel_sur =          IMG_Load("player_steel.png");           player_steel_tex = SDL_CreateTextureFromSurface(renderer, player_steel_sur);
    player_steel_dagger_sur =   IMG_Load("player_steel_dagger.png");    player_steel_dagger_tex = SDL_CreateTextureFromSurface(renderer, player_steel_dagger_sur);
    player_steel_spear_sur =    IMG_Load("player_steel_spear.png");     player_steel_spear_tex = SDL_CreateTextureFromSurface(renderer, player_steel_spear_sur);
    player_gold_sur =           IMG_Load("player_gold.png");            player_gold_tex = SDL_CreateTextureFromSurface(renderer, player_gold_sur);
    player_gold_dagger_sur =    IMG_Load("player_gold_dagger.png");     player_gold_dagger_tex = SDL_CreateTextureFromSurface(renderer, player_gold_dagger_sur);
    player_gold_spear_sur =     IMG_Load("player_gold_spear.png");      player_gold_spear_tex = SDL_CreateTextureFromSurface(renderer, player_gold_spear_sur);
    human_sur =                 IMG_Load("human.png");                  human_tex = SDL_CreateTextureFromSurface(renderer, human_sur);
    human2_sur =                IMG_Load("human2.png");                 human2_tex = SDL_CreateTextureFromSurface(renderer, human2_sur);
    orc_sur =                   IMG_Load("orc.png");                    orc_tex = SDL_CreateTextureFromSurface(renderer, orc_sur);
    dark_elf_sur =              IMG_Load("dark_elf.png");               dark_elf_tex = SDL_CreateTextureFromSurface(renderer, dark_elf_sur);
    gold_sur =                  IMG_Load("goldArmor.png");              gold_tex = SDL_CreateTextureFromSurface(renderer, gold_sur);
    steel_sur =                 IMG_Load("steelArmor.png");             steel_tex = SDL_CreateTextureFromSurface(renderer, steel_sur);
    dagger_sur =                IMG_Load("dagger.png");                 dagger_tex = SDL_CreateTextureFromSurface(renderer, dagger_sur);
    spear_sur =                 IMG_Load("spear.png");                  spear_tex = SDL_CreateTextureFromSurface(renderer, spear_sur);
    map_sur =                   IMG_Load("map.png");                    map_tex = SDL_CreateTextureFromSurface(renderer, map_sur);
    win_sur =                   IMG_Load("win.png");                    win_tex = SDL_CreateTextureFromSurface(renderer, win_sur);
    lose_sur =                  IMG_Load("lose.png");                   lose_tex = SDL_CreateTextureFromSurface(renderer, lose_sur);
}

int main()
{
    /* - Runs setup Function - */
    SDLSetup();

    /* - Sets Initail settings for the map - */
    mapItem room;
    room.roomShown = 1; mapItem map[5];
    map[0].top = false; map[0].bottom = false; map[0].left = false; map[0].right = false;
    map[1].top = false; map[1].bottom = false; map[1].left = false; map[1].right = false;
    map[2].top = false; map[2].bottom = false; map[2].left = false; map[2].right = false;
    map[3].top = false; map[3].bottom = false; map[3].left = false; map[3].right = false;
    map[4].top = false; map[4].bottom = false; map[4].left = false; map[4].right = false;
    
    /* - Sets initil settings for the player - */
    player player;
    player.alive = true;
    player.roomIn = 1;
    player.health = 10; player.damage = 1;
    player.hasDagger = false; player.hasSpear = false; player.hasSteelArmor = false; player.hasGoldArmor = false;
    player.shownPlayer = player_tex;
    
    /* - Sets up initial setting for the enemies - */
    // Orc for room 1
    enemy room1_orc;
    room1_orc.health = 2; room1_orc.damage = 1; room1_orc.alive = true;
    
    //Humans for room tow
    enemy room2_human[2];
    room2_human[0].health = 4;      room2_human[1].health = 4;
    room2_human[0].damage = 1;      room2_human[1].damage = 1;
    room2_human[0].alive = true;    room2_human[1].alive = true;
    
    //Dark Elves for room 3
    enemy room3_elves[2];
    room3_elves[0].health = 4;      room3_elves[1].health = 4;
    room3_elves[0].damage = 2;      room3_elves[1].damage = 2;
    room3_elves[0].alive = true;    room3_elves[1].alive = true;
    
    //Humans for room 4
    enemy room4_human[2];
    room4_human[0].health = 5;      room4_human[1].health = 5;
    room4_human[0].damage = 3;      room4_human[1].damage = 3;
    room4_human[0].alive = true;    room4_human[1].alive = true;
    
    //Boss
    enemy boss;
    boss.health = 10; boss.damage = 5; boss.alive = true;
    
    /* - Sets up the source and some destination rectangles - */
    player_src =     {0,710,64,64};     player_dest =       {270,235, 64, 64};
    orc_src =        {0,580,64,64};     orc_dest =          {500,230, 64, 64};
    human1_1_src =   {0,580,64,64};     human1_1_dest =     {300,200, 64, 64};
    human1_2_src =   {0,580,64,64};     human1_2_dest =     {300,400, 64, 64};
    human2_1_src =   {0,580,64,64};     human2_1_dest =     {500,150, 64, 64};
    human2_2_src =   {0,580,64,64};     human2_2_dest =     {500,450, 64, 64};
    dark_elf_1_src = {0,580,64,64};     dark_elf_1_dest =   {400,200, 64, 64};
    dark_elf_2_src = {0,580,64,64};     dark_elf_2_dest =   {400,400, 64, 64};
    boss_src =       {0,580,64,64};     boss_dest =         {600,300,128,128};
    dagger_src =     {0,  0,25,16};     spear_src =         {  0,  0, 60, 11};
    steel_src =      {0,  0,24,21};     gold_src =          {  0,  0, 25, 21};
    map_src =        {0,0,800,600};     map_dest =          {  0,  0,800,600};
    win_src =        {0,0,800,600};
    lose_src =       {0,0,800,600};
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    SDL_RenderClear(renderer);
    
    while (gameRunning)
    {
        /* - Renders the map - */
        SDL_RenderCopy(renderer, map_tex, &map_src, &map_dest);
        
        /* - Rendering in the enemies - */
        SDL_RenderCopy(renderer, orc_tex,                   &orc_src,           &orc_dest);
        
        if (room1_orc.alive == false && (room.roomShown == 2 && player.roomIn == 2))
        {
            SDL_RenderCopy(renderer, human_tex,                 &human1_1_src,      &human1_1_dest);
            //SDL_RenderCopy(renderer, human_tex,                 &human1_2_src,      &human1_2_dest);
        }
        if ((room2_human[0].alive == false) && (room.roomShown == 3 && player.roomIn == 3))
        {
            SDL_RenderCopy(renderer, dark_elf_tex,              &dark_elf_1_src,    &dark_elf_1_dest);
            //SDL_RenderCopy(renderer, dark_elf_tex,              &dark_elf_2_src,    &dark_elf_2_dest);
        }
        if ((room3_elves[0].alive == false) && (room.roomShown == 4 && player.roomIn == 4))
        {
            SDL_RenderCopy(renderer, human2_tex,                &human2_1_src,      &human2_1_dest);
            //SDL_RenderCopy(renderer, human2_tex,                &human2_2_src,      &human2_2_dest);
        }
        if ((room4_human[0].alive == false) && (room.roomShown == 5 && player.roomIn == 5))
        {
            SDL_RenderCopy(renderer, player_gold_spear_tex,     &boss_src,          &boss_dest);
        }
        
        /* - Rendering in the items - */
        SDL_RenderCopy(renderer, steel_tex, &steel_src, &steel_dest);
        SDL_RenderCopy(renderer, dagger_tex, &dagger_src, &dagger_dest);
        SDL_RenderCopy(renderer, gold_tex, &gold_src, &gold_dest);
        SDL_RenderCopy(renderer, spear_tex, &spear_src, &spear_dest);
        
        /* - When the room one enemy is defeated, drops the dagger - */
        if (player.roomIn == 1 && room.roomShown == 1 && player.shownPlayer == player_tex && room1_orc.alive == false)
            dagger_dest = {400, 300, 25, 16};
        else
            dagger_dest.y = 1000;
        
        /* - When the room two enemy is defeated, drops the steel armor - */
        if (player.roomIn == 2 && room.roomShown == 2 && player.shownPlayer == player_dagger_tex && room2_human[0].alive == false)
            steel_dest = {400,300,24,21};
        else if (player.shownPlayer == player_steel_dagger_tex)
            steel_dest.y = 1000;
        else
            steel_dest.y = 1000;
        
        /* - When the room three enemy is defeated, drops the spear - */
        if (player.roomIn == 3 && room.roomShown == 3 && player.shownPlayer == player_steel_dagger_tex && room3_elves[0].alive == false)
            spear_dest = {400, 300, 60, 11};
        else if (player.shownPlayer == player_steel_spear_tex)
            spear_dest.y = 1000;
        else
            spear_dest.y = 1000;
        
        /* - When the room four enemy is defeated, drops the fold armor - */
        if (player.roomIn == 4 && room.roomShown == 4 && player.shownPlayer == player_steel_spear_tex && room4_human[0].alive == false)
            gold_dest = {400,300,25,21};
        else if (player.shownPlayer == player_gold_spear_tex)
            gold_dest.y = 1000;
        else
            gold_dest.y = 1000;
        
        /* - Conditionals used for picking up the dagger - */
        if ((player_dest.y <= dagger_dest.y + 10 && player_dest.y >= dagger_dest.y - 10) && (player_dest.x <= dagger_dest.x + 10 && player_dest.x >= dagger_dest.x - 5))
        {
            if (player.shownPlayer == player_tex)
            {
                player.shownPlayer = player_dagger_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            else if (player.shownPlayer == player_steel_tex)
            {
                player.shownPlayer = player_steel_dagger_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            else if (player.shownPlayer == player_gold_tex)
            {
                player.shownPlayer = player_gold_dagger_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            player.hasDagger = true;
            player.damage = 2;
            SDL_FreeSurface(dagger_sur);
        }
        
        /* - Conditionals used for picking up the spear - */
        if ((player_dest.y <= spear_dest.y + 10 && player_dest.y >= spear_dest.y - 10) && (player_dest.x <= spear_dest.x + 60 && player_dest.x >= spear_dest.x - 5))
        {
            if (player.shownPlayer == player_tex || player.shownPlayer == player_dagger_tex)
            {
                player.shownPlayer = player_spear_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            else if (player.shownPlayer == player_steel_tex || player.shownPlayer == player_steel_dagger_tex)
            {
                player.shownPlayer = player_steel_spear_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            else if (player.shownPlayer == player_gold_tex || player.shownPlayer == player_gold_dagger_tex)
            {
                player.shownPlayer = player_gold_spear_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            player.hasDagger = false;
            player.hasSpear = true;
            player.damage = 4;
            SDL_FreeSurface(spear_sur);
        }
        
        /* - Conditionals used for picking up the steel armor - */
        if ((player_dest.y <= steel_dest.y + 10 && player_dest.y >= steel_dest.y - 10) && (player_dest.x <= steel_dest.x + 10 && player_dest.x >= steel_dest.x - 10))
        {
            if (player.shownPlayer == player_tex)
            {
                player.shownPlayer = player_steel_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            else if (player.shownPlayer == player_dagger_tex)
            {
                player.shownPlayer = player_steel_dagger_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            else if (player.shownPlayer == player_spear_tex)
            {
                player.shownPlayer = player_steel_spear_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            player.hasSteelArmor = true;
            player.health = 15;
            SDL_FreeSurface(steel_sur);
        }
        
        /* - Conditionals used for picking up the gold armor - */
        if ((player_dest.y <= gold_dest.y + 20 && player_dest.y >= gold_dest.y - 5) && (player_dest.x <= gold_dest.x + 20 && player_dest.x >= gold_dest.x - 5))
        {
            if (player.shownPlayer == player_tex || player.shownPlayer == player_steel_tex)
            {
                player.shownPlayer = player_gold_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            else if (player.shownPlayer == player_dagger_tex || player.shownPlayer == player_steel_dagger_tex)
            {
                player.shownPlayer = player_gold_dagger_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            else if (player.shownPlayer == player_spear_tex || player.shownPlayer == player_steel_spear_tex)
            {
                player.shownPlayer = player_gold_spear_tex;
                SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
            }
            player.hasSteelArmor = false;
            player.hasGoldArmor = true;
            player.health = 20;
            gold_dest.y = 1000;
            SDL_FreeSurface(gold_sur);
        }
        
        SDL_RenderCopy(renderer, player.shownPlayer, &player_src, &player_dest);
        SDL_RenderPresent(renderer);
        
        /* - For moving to different parts of the map - */
        // Room 1 to 2
        if ((room.roomShown == 1 && player.roomIn == 1) && (player_dest.x > screenWidth) && (map[0].right == true) && (player_dest.y > 208 && player_dest.y < 382))
        {
            room.roomShown = 2;
            player.roomIn = 2;
            player_dest.x = 0;
            map_src.x += screenWidth;
        }
        //room 2 to 3
        if ((room.roomShown == 2) && (player.roomIn == 2) && (player_dest.x > screenWidth) && (map[1].right == true) && (player_dest.y > 208) && (player_dest.y < 382))
        {
            room.roomShown = 3;
            player.roomIn = 3;
            player_dest.x = 0;
            map_src.x += screenWidth;
        }
        //room 3 to 4
        else if ((room.roomShown == 3) && (player.roomIn == 3) && (player_dest.x > screenWidth) && (map[2].right == true) && (player_dest.y > 208) && (player_dest.y < 382))
        {
            room.roomShown = 4;
            player.roomIn = 4;
            player_dest.x = 0;
            map_src.x += screenWidth;
        }
        //room 4 to 5
        else if ((room.roomShown == 4) && (player.roomIn == 4) && (player_dest.x > screenWidth) && (map[3].right == true) && (player_dest.y > 208) && (player_dest.y < 382))
        {
            room.roomShown = 5;
            player.roomIn = 5;
            player_dest.x = 0;
            map_src.x += screenWidth;
        }
        //room 5 to end - win condition
        else if ((room.roomShown == 5) && (player.roomIn == 5) && (player_dest.y > screenHeight) && (map[4].bottom == true) && (player_dest.x < 385) && (player_dest.x > 314))
        {
            win_dest = {0,0,800,600};
            SDL_RenderCopy(renderer, win_tex, &win_src, &win_dest);
            SDL_RenderPresent(renderer);
            SDL_Delay(2500);
            gameRunning = false;
        }
        
        /* - If your player dies - */
        if (player.health <= 0)
            player.alive = false;
        
        if (player.alive == false)
        {
            lose_dest = {0,0,800,600};
            SDL_RenderCopy(renderer, lose_tex, &lose_src, &lose_dest);
            SDL_RenderPresent(renderer);
            SDL_Delay(2500);
            gameRunning = false;
        }
        
        /* - Enemy Attacks and movement - */
        /*if (orc_dest.x == player_dest.x && orc_dest.y == player_dest.y)
        {
            player.health -= room1_orc.damage;
            SDL_Delay(500);
        }
        if (human1_1_dest.x == player_dest.x && human1_1_dest.y == player_dest.y)
        {
            player.health -= room2_human[0].damage;
            SDL_Delay(500);
        }
        if (dark_elf_1_dest.x == player_dest.x && dark_elf_1_dest.y == player_dest.y)
        {
            player.health -= room3_elves[0].damage;
            SDL_Delay(500);
        }
        if (human2_1_dest.x == player_dest.x && human2_1_dest.y == player_dest.y)
        {
            player.health -= room4_human[0].damage;
            SDL_Delay(500);
        }
        if (boss_dest.x == player_dest.x && boss_dest.y == player_dest.y)
        {
            player.health -= boss.damage;
            SDL_Delay(500);
        }*/
        
        //Orc movement
        do
        {
            if (player_dest.x > orc_dest.x) orc_dest.x += 1;
            if (player_dest.x < orc_dest.x) orc_dest.x -= 1;
            if (player_dest.y > orc_dest.y) orc_dest.y += 1;
            if (player_dest.y < orc_dest.y) orc_dest.y -= 1;
        }
        while ((orc_dest.x != player_dest.x && orc_dest.y != player_dest.y) && room1_orc.alive == true && (room.roomShown == 1 && player.roomIn == 1));
        
        //Human1-1 movement
        do
        {
            if (player_dest.x > human1_1_dest.x) human1_1_dest.x += 1;
            if (player_dest.x < human1_1_dest.x) human1_1_dest.x -= 1;
            if (player_dest.y > human1_1_dest.y) human1_1_dest.y += 1;
            if (player_dest.y < human1_1_dest.y) human1_1_dest.y -= 1;
        }
        while (human1_1_dest.x != player_dest.x && human1_1_dest.y != player_dest.y && room2_human[0].alive == true && room.roomShown == 2 && player.roomIn == 2);
        
        //Human2-1 movement
        do
        {
            if (player_dest.x > human2_1_dest.x) human2_1_dest.x += 1;
            if (player_dest.x < human2_1_dest.x) human2_1_dest.x -= 1;
            if (player_dest.y > human2_1_dest.y) human2_1_dest.y += 1;
            if (player_dest.y < human2_1_dest.y) human2_1_dest.y -= 1;
        }
        while (human2_1_dest.x != player_dest.x && human2_1_dest.y != player_dest.y && room4_human[0].alive == true && room.roomShown == 3 && player.roomIn == 3);
        
        //elf-1 movement
        do
        {
            if (player_dest.x > dark_elf_1_dest.x) dark_elf_1_dest.x += 1;
            if (player_dest.x < dark_elf_1_dest.x) dark_elf_1_dest.x -= 1;
            if (player_dest.y > dark_elf_1_dest.y) dark_elf_1_dest.y += 1;
            if (player_dest.y < dark_elf_1_dest.y) dark_elf_1_dest.y -= 1;
        }
        while (dark_elf_1_dest.x != player_dest.x && dark_elf_1_dest.y != player_dest.y && room3_elves[0].alive == true && room.roomShown == 4 && player.roomIn == 4);
        
        //Boss Movement
        do
        {
            if (player_dest.x > boss_dest.x) boss_dest.x += 1;
            if (player_dest.x < boss_dest.x) boss_dest.x -= 1;
            if (player_dest.y > boss_dest.y) boss_dest.y += 1;
            if (player_dest.y < boss_dest.y) boss_dest.y -= 1;
        }
        while (boss_dest.x != player_dest.x && boss_dest.y != player_dest.y && room4_human[0].alive == true && room.roomShown == 5 && player.roomIn == 5);

        /* - Player attacks - */
        if (attacking == true)
        {
            if (player.roomIn == 1 && room.roomShown == 1)
            {
                //Orc defeat
                if ((player_dest.y <= orc_dest.y + 60 && player_dest.y >= orc_dest.y - 5) && (player_dest.x <= orc_dest.x + 70 && player_dest.x >= orc_dest.x - 40))
                {
                    room1_orc.alive = false;
                    orc_dest.y = 1000000;
                    map[0].right = true;
                }
            }
            else if (player.roomIn == 2 && room.roomShown == 2)
            {
                // Human 1 defeats
                if ((player_dest.y <= human1_1_dest.y + 60 && player_dest.y >= human1_1_dest.y - 5) && (player_dest.x <= human1_1_dest.x + 70 && player_dest.x >= human1_1_dest.x - 40))
                {
                    room2_human[0].alive = false;
                    human1_1_dest.y = 1000000;
                    map[1].right = true;
                }
            }
            else if (player.roomIn == 3 && room.roomShown == 3)
            {
                //Elf defeats
                if ((player_dest.y <= dark_elf_1_dest.y + 60 && player_dest.y >= dark_elf_1_dest.y - 5) && (player_dest.x <= dark_elf_1_dest.x + 70 && player_dest.x >= dark_elf_1_dest.x - 40))
                {
                    room3_elves[0].alive = false;
                    dark_elf_1_dest.y = 1000000;
                    map[2].right = true;
                }
                
            }
            else if (player.roomIn == 4 && room.roomShown == 4)
            {
                //Human 2 defeats
                if ((player_dest.y <= human2_1_dest.y + 60 && player_dest.y >= human2_1_dest.y - 5) && (player_dest.x <= human2_1_dest.x + 70 && player_dest.x >= human2_1_dest.x - 40))
                {
                    room4_human[0].alive = false;
                    human2_1_dest.y = 1000000;
                    map[3].right = true;
                }
            }
            else if (player.roomIn == 5 && room.roomShown == 5)
            {
                //Boss defeat
                if ((player_dest.y <= boss_dest.y + 100 && player_dest.y >= boss_dest.y - 5) && (player_dest.x <= boss_dest.x + 90 && player_dest.x >= boss_dest.x - 40))
                {
                    boss.alive = false;
                    boss_dest.y = 1000000;
                    map[4].bottom = true;
                }
            }
            attacking = false;
        }

        if (SDL_PollEvent(&event) > 0)
        {
            switch (event.type)
            {
                /* - When the 'X' button is hit, quit the game - */
                case SDL_QUIT:
                    gameRunning = false;
                    break;
                    
                case SDL_KEYDOWN:
                    /* - Moves the character up the screen - */
                    if (event.key.keysym.sym == SDLK_w)
                    {
                        // Running
                        if(event.key.keysym.mod & KMOD_SHIFT)
                        {
                            player_src.y = 515;
                            player_src.x += 64; if (player_src.x >= 576) player_src.x = 0;
                            player_dest.y -= 10;
                        }
                        // Walking
                        else
                        {
                            player_src.y = 515;
                            player_src.x += 64; if (player_src.x >= 576) player_src.x = 0;
                            player_dest.y -= 20;
                        }
                    }
                    
                    /* - Moves the character left on the screen - */
                    if (event.key.keysym.sym == SDLK_a)
                    {
                        // Running
                        if(event.key.keysym.mod & KMOD_SHIFT)
                        {
                            player_src.y = 580;
                            player_src.x += 64; if (player_src.x >= 576) player_src.x = 0;
                            player_dest.x -= 10;
                        }
                        // Walking
                        else
                        {
                            player_src.y = 580;
                            player_src.x += 64; if (player_src.x >= 576) player_src.x = 0;
                            player_dest.x -= 20;
                        }
                    }
                    
                    /* - Moves the character down the screen - */
                    if (event.key.keysym.sym == SDLK_s)
                    {
                        // Running
                        if(event.key.keysym.mod & KMOD_SHIFT)
                        {
                            player_src.y = 645;
                            player_src.x += 64; if (player_src.x >= 576) player_src.x = 0;
                            player_dest.y += 10;
                        }
                        // Walking
                        else
                        {
                            player_src.y = 645;
                            player_src.x += 64; if (player_src.x >= 576) player_src.x = 0;
                            player_dest.y += 20;
                        }
                    }
                    
                    /* - Moves the character right on the screen - */
                    if (event.key.keysym.sym == SDLK_d)
                    {
                        // Running
                        if(event.key.keysym.mod & KMOD_SHIFT)
                        {
                            player_src.y = 710;
                            player_src.x += 64; if (player_src.x >= 576) player_src.x = 0;
                            player_dest.x += 10;
                        }
                        // Walking
                        else
                        {
                            player_src.y = 710;
                            player_src.x += 64; if (player_src.x >= 576) player_src.x = 0;
                            player_dest.x += 20;
                        }
                    }
                    
                    /* - Starts attack animation - */
                    if (event.key.keysym.sym == SDLK_SPACE)
                    {
                        /* - If facing up - */
                        if (player_src.y == 515)
                        {
                            player_src.y = 775;
                            player_src.x += 64; if (player_src.x >= 384) player_src.x = 0;
                            attacking = true;
                        }
                        /* - If facing left - */
                        else if (player_src.y == 580)
                        {
                            player_src.y = 840;
                            player_src.x += 64; if (player_src.x >= 384) player_src.x = 0;
                            attacking = true;                        }
                        /* - If facing down - */
                        else if (player_src.y == 645)
                        {
                            player_src.y = 900;
                            player_src.x += 64; if (player_src.x >= 384) player_src.x = 0;
                            attacking = true;
                        }
                        /* - If facing right - */
                        else if (player_src.y == 710)
                        {
                            player_src.y = 965;
                            player_src.x += 64; if (player_src.x >= 384) player_src.x = 0;
                            attacking = true;
                        }
                    }
                    
                    /* - When the escape key is hit, quit the game - */
                    if (event.key.keysym.sym == SDLK_ESCAPE)
                        gameRunning = false;
                    break;
                    
                default:
                    break;
            }
        }
        SDL_Delay(20);
    }
    exit(0);
}
