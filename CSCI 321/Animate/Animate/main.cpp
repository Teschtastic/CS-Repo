//
//  main.cpp
//  Animate
//
//  Created by Sean Tesch on 9/7/16.
//  Copyright © 2016 Sean Tesch. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

/* - Declares Window and Renderer - */
SDL_Window* screen;
SDL_Renderer* renderer;
SDL_Surface* surface_rt;
SDL_Surface* surface_jj;
SDL_Surface* surface_rocket;
SDL_Texture* rotate;
SDL_Texture* jumping;
SDL_Texture* rocket;

/* - Setup function - */
void SDLSetup()
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO) != 0)
    {
        std::cout << "SDL failed to init: " << std::endl;
        SDL_GetError();
        exit(1);
    }
    
    /* - Create window and renderer - */
    //SDL_CreateWindowAndRenderer(1000, 600, SDL_WINDOW_SHOWN, &screen, &renderer);
    
    screen = SDL_CreateWindow("Animation!", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1000, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE);
    
    if ((screen == NULL) || (renderer == NULL))
    {
        std::cout << "SDL_CreateWindowAndRenderer Error: " << std::endl;
        SDL_GetError();
        exit(1);
    }
    
    /* - Adds the sprites from PNG files - */
    surface_rt = IMG_Load("Rotate.png");
    rotate = SDL_CreateTextureFromSurface(renderer, surface_rt);
    
    surface_jj = IMG_Load("Jumping.png");
    jumping = SDL_CreateTextureFromSurface(renderer, surface_jj);
    
    surface_rocket = IMG_Load("Rocket.png");
    rocket = SDL_CreateTextureFromSurface(renderer, surface_rocket);
}

int main()
{
    /* - Calls setup function - */
    SDLSetup();
    
    /* - Declares an event - */
    SDL_Event event;
    
    /* - Declares the rectangles for big white sprite - */
    SDL_Rect asrc;
    SDL_Rect adest;
    
    /* - Sets where the big white sprite is on the window - */
    asrc.x = 0; asrc.y = 0; asrc.w = 250; asrc.h = 250;
    adest.x = 50; adest.y = 150; adest.w =250; adest.h =250;
    
    /* - Declares the rectangles for dude guy - */
    SDL_Rect jsrc;
    SDL_Rect jdest;
    
    /* - Sets where dude guy is on the window - */
    jsrc.x = 0; jsrc.y = 0; jsrc.w = 100; jsrc.h = 100;
    jdest.x = 400; jdest.y = 400; jdest.w = 100; jdest.h = 100;
    
    /* - Declares the rectangles for the rocket - */
    SDL_Rect rsrc;
    SDL_Rect rdest;
    
    /* - Sets where the rocket is on the window - */
    rsrc.x = 0; rsrc.y = 0; rsrc.w = 150; rsrc.h = 150;
    rdest.x = 100; rdest.y = 400; rdest.w = 150; rdest.h = 150;
    
    /* - Sets background color to green - */
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 1);
    
    while (1)
    {
        SDL_RenderClear(renderer);
        
        SDL_RenderCopy(renderer, rotate, &asrc, &adest);
        SDL_RenderCopy(renderer, jumping, &jsrc, &jdest);
        SDL_RenderCopy(renderer, rocket, &rsrc, &rdest);
        
        SDL_RenderPresent(renderer);
        
        /* - "Animates" the big white sprite - */
        asrc.x += 250; if (asrc.x >= 1000) asrc.x = 0;
        /* - "Animates" dude guy - */
        jsrc.x += 100; if (jsrc.x >= 400) jsrc.x = 0;
        /* - "Animates" the rocket - */
        rsrc.x += 150; if (rsrc.x >= 600) rsrc.x = 0;
        
        /* - Moves the big white sprite across the window - */
        if (adest.x >= 50) adest.x += 25;
        if (adest.x >= 700) adest.x -= 50;
        
        /* - Moves dude guy up the window - */
        if (jdest.y <= 400) jdest.y -=2;
        if (jdest.y <= 20) jdest.y += 4;
        
        /* - Moves the rocket diagonally up the screen - */
        rdest.x +=15; rdest.y -=15;
        if ((rdest.x >= 500) && (rdest.y <= 50)) {rdest.x -=15; rdest.y +=15;}
        
        SDL_RenderCopy(renderer, rotate, &asrc, &adest);
        SDL_RenderCopy(renderer, jumping, &jsrc, &jdest);
        SDL_RenderCopy(renderer, rocket, &rsrc, &rdest);
        
        SDL_RenderPresent(renderer);
        
        if (SDL_PollEvent(&event) > 0)
        {
           switch (event.type)
            {
                case SDL_QUIT:
                    exit(1);
            }
        }
        
        SDL_Delay(50);
    }
    return 0;
}
