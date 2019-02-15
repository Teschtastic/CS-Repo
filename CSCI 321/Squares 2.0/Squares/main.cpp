//
//  main.cpp
//  Squares
//
//  Created by Sean Tesch on 9/3/16.
//  Copyright © 2016 Sean Tesch. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_mixer/SDL_mixer.h>

SDL_Window* screen;
SDL_Renderer* renderer;

void SDLSetup()
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO) != 0)
    {
        std::cout << "SDL failed to init: " << std::endl;
        SDL_GetError();
        exit(1);
    }
    
    /* - Create window and renderer - */
    SDL_CreateWindowAndRenderer(600, 400, SDL_WINDOW_SHOWN, &screen, &renderer);
    
    screen = SDL_CreateWindow("Draw squares", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 400, SDL_WINDOW_SHOWN);
    
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE);
    
    if ((screen == NULL) || (renderer == NULL))
    {
        std::cout << "SDL_CreateWindowAndRenderer Error: " << std::endl;
        SDL_GetError();
        exit(1);
    }
}

int main()
{
    SDLSetup();
    
    SDL_Event event;
    SDL_Rect* square;
    
    Mix_Music* horn;
    horn = Mix_LoadMUS("Airhorn.mp3");
    Mix_PlayMusic(horn, -1);
    Mix_FreeMusic(horn);
    horn = NULL;
    
    SDL_SetRenderDrawColor(renderer, 0, 0, 255, 1);
    SDL_RenderClear(renderer);
    
    while (1)
    {
        SDL_RenderPresent(renderer);
        
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                {
                    int x, y, w = 50, h = 50;
                    SDL_GetMouseState(&x, &y);
                    std::cout << "You clicked at x:" << x << " and y:" << y << std::endl;
                    
                    if ((x == 300) && (y == 200))
                    {
                        std::cout << "You win!" << std::endl;
                        exit(1);
                    }
                    else if ((x > 550) && (y > 350))
                    {
                        SDL_SetRenderDrawColor(renderer, 0, 0, 255, 1);
                        SDL_RenderClear(renderer);
                    }
                    else
                    {
                        square -> x = x - 25;
                        square -> y = y - 25;
                        square -> h = h;
                        square -> w = w;
                        
                        SDL_SetRenderDrawColor(renderer, 128, 0, 128, 1);
                        SDL_RenderFillRect(renderer, square);
                    }
                    break;
                }
                    
                default:
                    break;
            }
        }
    }
    return 0;
}
