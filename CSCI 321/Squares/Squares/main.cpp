//
//  main.cpp
//  Squares
//
//  Created by Sean Tesch on 9/3/16.
//  Copyright © 2016 Sean Tesch. All rights reserved.
//

#include <iostream>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>

/* - Declares Window and Renderer - */
SDL_Window* screen;
SDL_Renderer* renderer;

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
    /* - Calls setup function - */
    SDLSetup();
    
    /* - Declares an event and a rectangle - */
    SDL_Event event;
    SDL_Rect square;
    
    /* - Set the background color to blue - */
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
                    /* - Declares x,y,w, and h variables - */
                    int x, y, w = 50, h = 50;
                    
                    /* - Gets the mouse position clicked - */
                    SDL_GetMouseState(&x, &y);
                    
                    /* - Where you clicked - */
                    //std::cout << "You clicked at x:" << x << " and y:" << y << std::endl;
                    
                    /* - Closes the application if the user clicks at 50x50- */
                    if ((x < 50) && (y < 50))
                    {
                        exit(1);
                    }
                    
                    /* - Places a purple square centered on the mouse click - */
                    else
                    {
                        square.x = x - 25;
                        square.y = y - 25;
                        square.h = h;
                        square.w = w;
                        
                        SDL_SetRenderDrawColor(renderer, 128, 0, 128, 1);
                        SDL_RenderFillRect(renderer, &square);
                    }
                }
                    break;
                
                case SDL_QUIT:
                {
                    exit(1);
                }
                    break;
                    
                default:
                    break;
            }
        }
    }
    return 0;
}
