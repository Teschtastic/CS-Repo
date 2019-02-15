//
//  main.cpp
//  Tic Tac Toe
//
//  Created by Sean Tesch on 9/22/16.
//  Copyright © 2016 Sean Tesch. All rights reserved.
//

#include <iostream>
#include <sstream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>
#include <SDL2_ttf/SDL_ttf.h>

/* - Declares Window and Renderer - */
SDL_Window* screen;
SDL_Renderer* renderer;
SDL_Surface* board_sur;
SDL_Surface* X_sur;
SDL_Surface* O_sur;
SDL_Surface* XW_sur;
SDL_Surface* OW_sur;
SDL_Surface* stale_sur;
SDL_Surface* x_score_sur;
SDL_Surface* o_score_sur;
SDL_Texture* board_tex;
SDL_Texture* X_tex;
SDL_Texture* O_tex;
SDL_Texture* XW_tex;
SDL_Texture* OW_tex;
SDL_Texture* stale_tex;
SDL_Texture* x_score_tex;
SDL_Texture* o_score_tex;
SDL_Event event;
SDL_Rect board_src;
SDL_Rect board_dest;
SDL_Rect x_src;
SDL_Rect x_dest;
SDL_Rect o_src;
SDL_Rect o_dest;
SDL_Rect xwin_src;
SDL_Rect xwin_dest;
SDL_Rect owin_src;
SDL_Rect owin_dest;
SDL_Rect stale_src;
SDL_Rect stale_dest;
SDL_Rect x_score_src;
SDL_Rect x_score_dest;
SDL_Rect o_score_src;
SDL_Rect o_score_dest;
SDL_Color text_color = {255,255,255};
//std::string fontpath = "/Library/Fonts/";
std::string score_text_x = "";
std::string score_text_o = "";
std::stringstream strm_x, strm_o;
bool running = true;
int turn = 1, xwin = 0, owin = 0, fontsize = 24, f_height = 0, f_width = 0;
char winner = 'N';
//TTF_Font* font = TTF_OpenFont(fontpath.c_str(), fontsize);
char boardArray[] = {'E','E','E',
                     'E','E','E',
                     'E','E','E'};

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
    //SDL_CreateWindowAndRenderer(820, 600, SDL_WINDOW_SHOWN, &screen, &renderer);
    
    screen = SDL_CreateWindow("Tic Tac Toe", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 820, 600, SDL_WINDOW_SHOWN);
    
    renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_SOFTWARE);
    
    /* - Adds the sprites from PNG files - */
    board_sur = IMG_Load("board.png");
    board_tex = SDL_CreateTextureFromSurface(renderer, board_sur);
    
    X_sur = IMG_Load("x.png");
    X_tex = SDL_CreateTextureFromSurface(renderer, X_sur);
    
    XW_sur = IMG_Load("xwin.png");
    XW_tex = SDL_CreateTextureFromSurface(renderer, XW_sur);
    
    O_sur = IMG_Load("o.png");
    O_tex = SDL_CreateTextureFromSurface(renderer, O_sur);
    
    OW_sur = IMG_Load("owin.png");
    OW_tex = SDL_CreateTextureFromSurface(renderer, OW_sur);
    
    stale_sur = IMG_Load("stalemate.png");
    stale_tex = SDL_CreateTextureFromSurface(renderer, stale_sur);
    
    if ((screen == NULL) || (renderer == NULL))
    {
        std::cout << "SDL_CreateWindowAndRenderer Error: " << std::endl;
        SDL_GetError();
        exit(1);
    }
    
    if ((board_tex == NULL) || (X_tex == NULL) || (O_tex == NULL))
    {
        std::cout << "Failed to load image" << std::endl;
        SDL_GetError();
        exit(1);
    }
    
    /*if (font == NULL)
    {
        std::cout << "Failed the load the font" << std::endl;
        std::cout << "SDL_TTF Error: " << TTF_GetError() << std::endl;
    }
    else
    {
        x_score_sur = TTF_RenderText_Solid(font, score_text_x.c_str(), text_color);
        o_score_sur = TTF_RenderText_Solid(font, score_text_o.c_str(), text_color);
        
        x_score_tex = SDL_CreateTextureFromSurface(renderer, x_score_sur);
        o_score_tex = SDL_CreateTextureFromSurface(renderer, o_score_sur);
    }*/
}

int main()
{
    // Runs Setup function
    SDLSetup();
    
    // Sets the board on the right side of the screen
    board_src.x = 0; board_src.y = 0; board_src.h = 600; board_src.w = 600;
    board_dest.x = 0; board_dest.y = 0; board_dest.h = 600; board_dest.w = 600;
    
    x_src.x = 0; x_src.y = 0; x_src.h = 100; x_src.w = 100;
    x_dest.x = 0; x_dest.y = 0; x_dest.h = 100; x_dest.w = 100;
    xwin_src.x = 0; xwin_src.y = 0; xwin_src.h = 600; xwin_src.w = 820;
    xwin_dest.x = 0; xwin_dest.y = 0; xwin_dest.h = 600; xwin_dest.w = 820;
    o_src.x = 0; o_src.y = 0; o_src.h = 100; o_src.w = 100;
    o_dest.x = 0; o_dest.y = 0; o_dest.h = 100; o_dest.w = 100;
    owin_src.x = 0; owin_src.y = 0; owin_src.h = 600; owin_src.w = 820;
    owin_dest.x = 0; owin_dest.y = 0; owin_dest.h = 600; owin_dest.w = 820;
    stale_src.x = 0; stale_src.y = 0; stale_src.h = 600; stale_src.w = 820;
    stale_dest.x = 0; stale_dest.y = 0; stale_dest.h = 600; stale_dest.w = 820;
    x_score_src.x = 0; x_score_src.y = 0; x_score_src.h = 50; x_score_src.w = 50;
    x_score_dest.x = 650; x_score_dest.y = 450; x_score_dest.h = 0; x_score_dest.w = 0;
    o_score_src.x = 0; o_score_src.y = 0; o_score_src.h = 50; o_score_src.w = 50;
    o_score_dest.x = 750; o_score_dest.y = 450; o_score_dest.h = 0; o_score_dest.w = 0;
    
    /* - Set the background color to white - */
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 1);
    SDL_RenderClear(renderer);
    SDL_RenderCopy(renderer, board_tex, &board_src, &board_dest);
    SDL_RenderCopy(renderer, x_score_tex, NULL, &x_score_dest);
    SDL_RenderCopy(renderer, x_score_tex, NULL, &o_score_dest);

    
    while (running)
    {
        if (turn % 2 == 1)
        {
            x_dest.x = 660;
            x_dest.y = 50;
            SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
        }
        else if (turn % 2 == 0)
        {
            o_dest.x = 660;
            o_dest.y = 50;
            SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
        }
        if (((boardArray[0] == 'X') && (boardArray[1] == 'X') && (boardArray[2] == 'X')) || ((boardArray[3] == 'X') && (boardArray[4] == 'X') && (boardArray[5] == 'X')) || ((boardArray[6] == 'X') && (boardArray[7] == 'X') && (boardArray[8] == 'X')) || ((boardArray[0] == 'X') && (boardArray[4] == 'X') && (boardArray[8] == 'X')) || ((boardArray[2] == 'X') && (boardArray[4] == 'X') && (boardArray[6] == 'X')) || ((boardArray[0] == 'X') && (boardArray[3] == 'X') && (boardArray[6] == 'X')) || ((boardArray[1] == 'X') && (boardArray[4] == 'X') && (boardArray[7] == 'X')) || ((boardArray[2] == 'X') && (boardArray[5] == 'X') && (boardArray[8] == 'X')))
        {
            winner = 'X';
        }
        
        else if (((boardArray[0] == 'O') && (boardArray[1] == 'O') && (boardArray[2] == 'O')) || ((boardArray[3] == 'O') && (boardArray[4] == 'O') && (boardArray[5] == 'O')) || ((boardArray[6] == 'O') && (boardArray[7] == 'O') && (boardArray[8] == 'O')) || ((boardArray[0] == 'O') && (boardArray[4] == 'O') && (boardArray[8] == 'O')) || ((boardArray[2] == 'O') && (boardArray[4] == 'O') && (boardArray[6] == 'O')) || ((boardArray[0] == 'O') && (boardArray[3] == 'O') && (boardArray[6] == 'O')) || ((boardArray[1] == 'O') && (boardArray[4] == 'O') && (boardArray[7] == 'O')) || ((boardArray[2] == 'O') && (boardArray[5] == 'O') && (boardArray[8] == 'O')))
        {
            winner = 'O';
        }
        
        if ((((boardArray[0] == 'X') || (boardArray[0] == 'O')) && boardArray[0] != 'E') && (((boardArray[1] == 'X') || (boardArray[1] == 'O')) && boardArray[1] != 'E') && (((boardArray[2] == 'X') || (boardArray[2] == 'O')) && boardArray[2] != 'E') && (((boardArray[3] == 'X') || (boardArray[3] == 'O')) && boardArray[3] != 'E') && (((boardArray[4] == 'X') || (boardArray[4] == 'O')) && boardArray[4] != 'E') && (((boardArray[5] == 'X') || (boardArray[5] == 'O')) && boardArray[5] != 'E') && (((boardArray[6] == 'X') || (boardArray[6] == 'O')) && boardArray[6] != 'E') && (((boardArray[7] == 'X') || (boardArray[7] == 'O')) && boardArray[7] != 'E') && (((boardArray[8] == 'X') || (boardArray[8] == 'O')) && boardArray[8] != 'E'))
        {
            winner = 'S';
        }
        
        switch (winner) {
            case 'X':
            {
                for (int i = 0; i < 9; i++)
                    boardArray[i] = 'E';
                winner = 'N';
                turn = 1;
                xwin += 1;
                score_text_x = std::to_string(xwin);
                SDL_RenderCopy(renderer, XW_tex, &xwin_src, &xwin_dest);
                SDL_RenderPresent(renderer);
                SDL_Delay(1000);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, board_tex, &board_src, &board_dest);
                SDL_RenderCopy(renderer, x_score_tex, NULL, &x_score_dest);
            }
                break;
            case 'O':
            {
                for (int i = 0; i < 9; i++)
                    boardArray[i] = 'E';
                winner = 'N';
                turn = 1;
                owin += 1;
                score_text_o = std::to_string(owin);
                SDL_RenderCopy(renderer, OW_tex, &owin_src, &owin_dest);
                SDL_RenderPresent(renderer);
                SDL_Delay(1000);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, board_tex, &board_src, &board_dest);
                SDL_RenderCopy(renderer, o_score_tex, NULL, &o_score_dest);
            }
                break;
                
                case 'S':
            {
                for (int i = 0; i < 9; i++)
                    boardArray[i] = 'E';
                winner = 'N';
                turn = 1;
                SDL_RenderCopy(renderer, stale_tex, &stale_src, &stale_dest);
                SDL_RenderPresent(renderer);
                SDL_Delay(1000);
                SDL_RenderClear(renderer);
                SDL_RenderCopy(renderer, board_tex, &board_src, &board_dest);
            }
                break;
                
            default:
                break;
        }
        SDL_RenderPresent(renderer);
        while (SDL_PollEvent(&event))
        {
            switch (event.type)
            {
                case SDL_MOUSEBUTTONDOWN:
                {
                    if ((event.button.y >= 17) && (event.button.y <= 190))
                    {
                        if ((event.button.x >= 12) && (event.button.x <= 190))
                        {
                            if ((boardArray[0] == 'E') && (boardArray[0] != 'O') && (turn % 2 == 1))
                            {
                                boardArray[0] = 'X';
                                turn++;
                                x_dest.x = 50;
                                x_dest.y = 50;
                                SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
                            }
                            else if ((boardArray[0] == 'E') && (boardArray[0] != 'X') && (turn % 2 == 0))
                            {
                                boardArray[0] = 'O';
                                turn++;
                                o_dest.x = 50;
                                o_dest.y = 50;
                                SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
                            }
                        }
                        else if ((event.button.x >= 209) && (event.button.x <= 390))
                        {
                            if ((boardArray[1] == 'E') && (boardArray[1] != 'O') && (turn % 2 == 1))
                            {
                                boardArray[1] = 'X';
                                turn++;
                                x_dest.x = 250;
                                x_dest.y = 50;
                                SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
                                
                            }
                            else if ((boardArray[1] == 'E') && (boardArray[1] != 'X') && (turn % 2 == 0))
                            {
                                boardArray[1] = 'O';
                                turn++;
                                o_dest.x = 250;
                                o_dest.y = 50;
                                SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
                            }
                        }
                        else if ((event.button.x >= 409) && (event.button.x <= 584))
                        {
                            
                            if ((boardArray[2] == 'E') && (boardArray[2] != 'O') && (turn % 2 == 1))
                            {
                                boardArray[2] = 'X';
                                turn++;
                                x_dest.x = 450;
                                x_dest.y = 50;
                                SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
                                
                            }
                            else if ((boardArray[2] == 'E') && (boardArray[2] != 'X') && (turn % 2 == 0))
                            {
                                boardArray[2] = 'O';
                                turn++;
                                o_dest.x = 450;
                                o_dest.y = 50;
                                SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
                            }
                        }
                    }
                    else if ((event.button.y >= 209) && (event.button.y <= 390))
                    {
                        if ((event.button.x >= 12) && (event.button.x <= 190))
                        {
                            if ((boardArray[3] == 'E') && (boardArray[3] != 'O') && (turn % 2 == 1))
                            {
                                boardArray[3] = 'X';
                                turn++;
                                x_dest.x = 50;
                                x_dest.y = 250;
                                SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
                            }
                            else if ((boardArray[3] == 'E') && (boardArray[3] != 'X') && (turn % 2 == 0))
                            {
                                boardArray[3] = 'O';
                                turn++;
                                o_dest.x = 50;
                                o_dest.y = 250;
                                SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
                            }
                        }
                        else if ((event.button.x >= 209) && (event.button.x <= 390))
                        {
                            if ((boardArray[4] == 'E') && (boardArray[4] != 'O') && (turn % 2 == 1))
                            {
                                boardArray[4] = 'X';
                                turn++;
                                x_dest.x = 250;
                                x_dest.y = 250;
                                SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
                            }
                            else if ((boardArray[4] == 'E') && (boardArray[4] != 'X') && (turn % 2 == 0))
                            {
                                boardArray[4] = 'O';
                                turn++;
                                o_dest.x = 250;
                                o_dest.y = 250;
                                SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
                            }
                        }
                        else if ((event.button.x >= 409) && (event.button.x <= 584))
                        {
                            if ((boardArray[5] == 'E') && (boardArray[5] != 'O') && (turn % 2 == 1))
                            {
                                boardArray[5] = 'X';
                                turn++;
                                x_dest.x = 450;
                                x_dest.y = 250;
                                SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
                            }
                            else if ((boardArray[5] == 'E') && (boardArray[5] != 'X') && (turn % 2 == 0))
                            {
                                boardArray[5] = 'O';
                                turn++;
                                o_dest.x = 450;
                                o_dest.y = 250;
                                SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
                            }
                        }
                    }
                    else if ((event.button.y >= 410) && (event.button.y <= 583))
                    {
                        if ((event.button.x >= 12) && (event.button.x <= 190))
                        {
                            if ((boardArray[6] == 'E') && (boardArray[6] != 'O') && (turn % 2 == 1))
                            {
                                boardArray[6] = 'X';
                                turn++;
                                x_dest.x = 50;
                                x_dest.y = 450;
                                SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
                            }
                            else if ((boardArray[6] == 'E') && (boardArray[6] != 'X') && (turn % 2 == 0))
                            {
                                boardArray[6] = 'O';
                                turn++;
                                o_dest.x = 50;
                                o_dest.y = 450;
                                SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
                            }
                        }
                        else if ((event.button.x >= 209) && (event.button.x <= 390))
                        {
                            if ((boardArray[7] == 'E') && (boardArray[7] != 'O') && (turn % 2 == 1))
                            {
                                boardArray[7] = 'X';
                                turn++;
                                x_dest.x = 250;
                                x_dest.y = 450;
                                SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
                            }
                            else if ((boardArray[7] == 'E') && (boardArray[7] != 'X') && (turn % 2 == 0))
                            {
                                boardArray[7] = 'O';
                                turn++;
                                o_dest.x = 250;
                                o_dest.y = 450;
                                SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
                            }
                        }
                        else if ((event.button.x >= 409) && (event.button.x <= 584))
                        {
                            if ((boardArray[8] == 'E') && (boardArray[8] != 'O') && (turn % 2 == 1))
                            {
                                boardArray[8] = 'X';
                                turn++;
                                x_dest.x = 450;
                                x_dest.y = 450;
                                SDL_RenderCopy(renderer, X_tex, &x_src, &x_dest);
                            }
                            else if ((boardArray[8] == 'E') && (boardArray[8] != 'X') && (turn % 2 == 0))
                            {
                                boardArray[8] = 'O';
                                turn++;
                                o_dest.x = 450;
                                o_dest.y = 450;
                                SDL_RenderCopy(renderer, O_tex, &o_src, &o_dest);
                            }
                        }
                    }
                }
                    break;
                case SDL_QUIT:
                {
                    running = false;
                }
                    break;
                    
                case SDLK_ESCAPE:
                {
                    running = false;
                }
                    break;
                    
                default:
                    break;
            }
        }
    }
    return 0;
}
