#include <iostream>
#include <string>
#include <ctime>
#include <cmath>
#include <stdlib.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

SDL_Window* screen;
SDL_Renderer* renderer;
SDL_Surface* tank_sur;
SDL_Texture* tank_tex;
SDL_Surface* cannon_sur;
SDL_Texture* cannon_tex;
SDL_Surface* square_sur;
SDL_Texture* square_tex;
SDL_Surface* circle_sur;
SDL_Texture* circle_tex;
SDL_Surface* triangle_sur;
SDL_Texture* triangle_tex;
SDL_Surface* bullet_sur;
SDL_Texture* bullet_tex;
SDL_Rect tank_src;
SDL_Rect tank_dest;
SDL_Rect cannon_src;
SDL_Rect cannon_dest;
SDL_Rect circle_src;
SDL_Rect circle_dest;
SDL_Rect square_src;
SDL_Rect square_dest;
SDL_Rect triangle_src;
SDL_Rect triangle_dest;
SDL_Rect bullet_src;
SDL_Rect bullet_dest;
int x_1, y_1, x_2, y_2, x_3, y_3;
bool shapesShown[] = {true, true, true};
double angle = 0.0;
char state = 'A';
double m;
double y_int;
double x_start;
double y_start;
double x_goal;
double y_goal;


void SDLSetup()
{
    if (SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER|SDL_INIT_AUDIO) != 0)
    {
        std::cout << "SDL failed to init: " << std::endl;
        SDL_GetError();
        exit(1);
    }
    /* - Create window and renderer - */
    screen = SDL_CreateWindow("Cannon Firing", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE);
    
    if ((screen == NULL) || (renderer == NULL))
    {
        std::cout << "SDL_CreateWindowAndRenderer Error: " << std::endl;
        SDL_GetError();
        exit(1);
    }
    tank_sur = IMG_Load("tank.png");
    tank_tex = SDL_CreateTextureFromSurface(renderer, tank_sur);
    
    cannon_sur = IMG_Load("cannon.png");
    cannon_tex = SDL_CreateTextureFromSurface(renderer, cannon_sur);
    
    circle_sur = IMG_Load("circle.png");
    circle_tex = SDL_CreateTextureFromSurface(renderer, circle_sur);
    
    square_sur = IMG_Load("square.png");
    square_tex = SDL_CreateTextureFromSurface(renderer, square_sur);
    
    triangle_sur = IMG_Load("triangle.png");
    triangle_tex = SDL_CreateTextureFromSurface(renderer, triangle_sur);
    
    bullet_sur = IMG_Load("bullet.png");
    bullet_tex = SDL_CreateTextureFromSurface(renderer, bullet_sur);
}

void displayCircle()
{
    x_1 = rand() % 725;
    y_1 = rand() % 525;
    if (x_1 < 100)
    {
        y_1 = rand() % 425;
    }
    circle_src = {0,0,75,75}; circle_dest = {x_1,y_1,75,75};
}

void displaySquare()
{
    x_2 = rand() % 750;
    y_2 = rand() % 550;
    if (x_2 < 100)
    {
        y_2 = rand() % 450;
    }
    square_src = {0,0,50,50}; square_dest = {x_2,y_2,50,50};
}

void displayTriangle()
{
    x_3 = rand() % 710;
    y_3 = rand() % 510;
    if (x_3 < 100)
    {
        y_3 = rand() % 410;
    }
    triangle_src = {0,0,90,90}; triangle_dest = {x_3,y_3,90,90};
}

int main()
{
    srand((unsigned)time(0));
    bool running = true;
    SDL_Event event;
    SDLSetup();
    displayCircle();
    displaySquare();
    displayTriangle();
    bool hasCalculated = false;
    double currX = 0;
    tank_src = {0,0,100,100}; tank_dest = {0,500,100,100};
    cannon_src = {0,0,50,10}; cannon_dest = {60,550,50,10};
    bullet_src = {0,0,10,10}; bullet_dest = {0,0,10,10};
    
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    
    SDL_Point p = {0, 0};
    while (running)
    {
        SDL_RenderClear(renderer);
        SDL_RenderCopyEx(renderer, cannon_tex, &cannon_src, &cannon_dest, angle, &p, SDL_FLIP_NONE);
        SDL_RenderCopy(renderer, tank_tex, &tank_src, &tank_dest);
        
        if (hasCalculated)
        {
            SDL_RenderCopy(renderer, bullet_tex, &bullet_src, &bullet_dest);
        }
        if (shapesShown[0])
        {
            SDL_RenderCopy(renderer, circle_tex, &circle_src, &circle_dest);
        }
        if (shapesShown[1])
        {
            SDL_RenderCopy(renderer, square_tex, &square_src, &square_dest);
        }
        if (shapesShown[2])
        {
            SDL_RenderCopy(renderer, triangle_tex, &triangle_src, &triangle_dest);
        }
        
        SDL_RenderPresent(renderer);
        
        if ((SDL_PollEvent(&event) > 0) && (state == 'A'))
        {
            switch (event.type)
            {
                case SDL_KEYDOWN:
                    if (event.key.keysym.sym == SDLK_UP)
                    {
                        if (angle > -90)
                        {
                        angle -= 1.0;
                        SDL_RenderPresent(renderer);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_DOWN)
                    {
                        if (angle < 0)
                        {
                            angle += 1.0;
                            SDL_RenderPresent(renderer);
                        }
                    }
                    else if (event.key.keysym.sym == SDLK_SPACE)
                    {
                        x_start = cannon_dest.x;
                        y_start = cannon_dest.y - 5;
                        x_goal = 800 * cos((std::abs(angle) * 0.0174533));
                        y_goal = 800 * sin((std::abs(angle) * 0.0174533));
                        
                        if (angle == 0)
                        {
                            m = 0;
                        }
                        else if (angle == -90)
                        {
                            
                        }
                        else
                        {
                        m = (y_goal - y_start)/(x_goal - x_start);
                        }
                        
                        std::cout << m << " = (" << y_goal << " - " << y_start << ") / (" << x_goal << " - " << x_start << ")" << std:: endl;
                        
                        y_int = y_start - m * x_start;
                        
                        std::cout << y_int << " = " << y_start << " - (" << m << " * " << x_start << ")" << std:: endl;
                        
                        
                        hasCalculated = true;
                        currX = x_start;
                        state = 'F';
                    }
                    else if (event.key.keysym.sym == SDLK_ESCAPE)
                        running = false;
                    break;
                    
                case SDL_QUIT:
                    running = false;
                    break;
                
                default:
                    break;
            }
        }
        else if (state == 'F')
        {
            /*std::cout << bullet_dest.x << std::endl;
            std::cout << x_goal << std::endl;
            std::cout << bullet_dest.y << std::endl;
            std::cout << y_goal << std::endl;*/
            if ((bullet_dest.x >= x_goal) )
            {
                std::cout << "Done shooting" << std::endl;
                state = 'A';
            }
            /*else if (shapesShown[0] == true)
            {
                // circle
            }
            else if (shapesShown[1] == true)
            {
                // square
            }
            else if (shapesShown[2] == true)
            {
                // triangle
            }*/
            else
            {
                if (hasCalculated)
                {
                    bullet_dest.x = currX;
                    bullet_dest.y = m * currX + y_int;
                    //std::cout << y_int << std::endl;
                    //std::cout << bullet_dest.y << std::endl;
                    currX++;
                }
            }
        }
    }
    return 0;
}
