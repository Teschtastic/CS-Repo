/*
 * This code was created by Jeff Molofee '99
 * (ported to Linux/SDL by Ti Leggett '01)
 *
 * If you've found this code useful, please let me know.
 *
 * Visit Jeff at http://nehe.gamedev.net/
 *
 * or for port-specific comments, questions, bugreports etc.
 * email to leggett@eecs.tulane.edu
 */

/* Modified by Dr. Ev'l Schemm for a CSCI 321 assignment framework
 * on 11 Novemebr 2010.  Students need to write the function
 * GenerateShape in myshape.c using GenList.
 *
 *
 *
 * The global variables are not mine.  They are Jeff's.
 *
 *
 * Update 23 Oct 2014 for SDL2 by Ev'l Schemm
 *
 * Updated 13 October 2016 to add a culling option to the display.
 * Default is to cull backface.
 */


#include <stdio.h>
#include <stdlib.h>
#include <OpenGL/gl.h>
#include <OpenGL/glu.h>
#include <GLUT/glut.h>
#include <SDL2/SDL.h>
#include <SDL2_image/SDL_image.h>


#include "myshape.h"


#  define GL_BGR 0x80E0


/* screen width, height, and bit depth */
#define SCREEN_WIDTH  640
#define SCREEN_HEIGHT 480
#define SCREEN_BPP     16

/* Set up some booleans */
#define TRUE  1
#define FALSE 0


SDL_Window* window;
SDL_GLContext glcontext;


/* Whether or not lighting is on */
int light = FALSE;

GLfloat xrot;      /* X Rotation */
GLfloat yrot;      /* Y Rotation */
GLfloat xspeed;    /* X Rotation Speed */
GLfloat yspeed;    /* Y Rotation Speed */
GLfloat z = -5.0f; /* Depth Into The Screen */
int cull;

/* Ambient Light Values ( NEW ) */
GLfloat LightAmbient[]  = { 0.5f, 0.5f, 0.5f, 1.0f };
/* Diffuse Light Values ( NEW ) */
GLfloat LightDiffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
/* Light Position ( NEW ) */
GLfloat LightPosition[] = { 0.0f, 0.0f, 2.0f, 1.0f };

GLuint filter;     /* Which Filter To Use */
GLuint texture[3]; /* Storage for 3 textures */


/* function to release/destroy our resources and restoring the old desktop */
void Quit( int returnCode )
{
    SDL_GL_DeleteContext(glcontext);
    /* clean up the window */
    SDL_Quit( );
    
    /* and exit appropriately */
    exit( returnCode );
}


/* Setup our texture.  Code for this function swiped from TwigMan and
 the Quest for the Diet Cola.  NOTE:  Uses RGBA image data, not RGB! */
void setup_texture(SDL_Surface * image, int num,
                   GLfloat MinFilter, GLfloat MagFilter)
{
    glGenTextures(1, &texture[num]);
    glBindTexture(GL_TEXTURE_2D, texture[num]);
    
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,MagFilter);
    glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,MinFilter);
    
    glTexImage2D(GL_TEXTURE_2D,
                 0,
                 GL_RGBA,
                 image->w, image->h,
                 0,
                 GL_BGRA,
                 GL_UNSIGNED_BYTE,
                 image->pixels);
    
}







/* function to reset our viewport after a window resize */
int resizeWindow( int width, int height )
{
    /* Height / width ration */
    GLfloat ratio;
    
    /* Protect against a divide by zero */
    if ( height == 0 )
        height = 1;
    
    ratio = ( GLfloat )width / ( GLfloat )height;
    
    /* Setup our viewport. */
    glViewport( 0, 0, ( GLint )width, ( GLint )height );
    
    /* change to the projection matrix and set our viewing volume. */
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );
    
    /* Set our perspective */
    gluPerspective( 45.0f, ratio, 0.1f, 100.0f );
    
    /* Make sure we're chaning the model view and not the projection */
    glMatrixMode( GL_MODELVIEW );
    
    /* Reset The View */
    glLoadIdentity( );
    
    return( TRUE );
}

/* function to handle key press events */
void handleKeyPress( SDL_Keysym *keysym )
{
    switch ( keysym->sym )
    {
        case SDLK_ESCAPE:
            /* ESC key was pressed */
            Quit( 0 );
            break;
        case SDLK_l:
            /* 'l' key was pressed
             * this toggles the light
             */
            light = !light;
            if ( !light )
                glDisable( GL_LIGHTING );
            else
                glEnable( GL_LIGHTING );
            break;
        case SDLK_c:
            if (cull == 0)
            {
                glEnable(GL_CULL_FACE);
                glCullFace(GL_BACK);
                cull = 1;
            }
            else
            {
                cull = 0;
                glDisable(GL_CULL_FACE);
            }
            break;
        case SDLK_PAGEUP:
            /* PageUp key was pressed
             * this zooms into the scene
             */
            z -= 0.02f;
            break;
        case SDLK_PAGEDOWN:
            /* PageDown key was pressed
             * this zooms out of the scene
             */
            z += 0.02f;
            break;
        case SDLK_UP:
            /* Up arrow key was pressed
             * this affects the x rotation
             */
            xspeed -= 0.01f;
            break;
        case SDLK_DOWN:
            /* Down arrow key was pressed
             * this affects the x rotation
             */
            xspeed += 0.01f;
            break;
        case SDLK_RIGHT:
            /* Right arrow key was pressed
             * this affects the y rotation
             */
            yspeed += 0.01f;
            break;
        case SDLK_LEFT:
            /* Left arrow key was pressed
             * this affects the y rotation
             */
            yspeed -= 0.01f;
            break;
        default:
            break;
    }
    
    return;
}

/* general OpenGL initialization function */
int initGL( GLvoid )
{
    SDL_Surface *texturepic;
    
    texturepic = IMG_Load(MYTEXTUREFILE);
    
    if (texturepic == NULL)
    {
        printf("IMG error:%s\n", SDL_GetError());
    }
    
    /* Activate blending for our possibly transparent stuff */
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA );
    
    
    /* Load our texture into an OpenGL structure */
    setup_texture(texturepic, 0, GL_NEAREST, GL_NEAREST);
    
    /* Enable Texture Mapping ( NEW ) */
    glEnable( GL_TEXTURE_2D );
    
    /* Enable smooth shading */
    glShadeModel( GL_SMOOTH );
    
    /* Set the background black */
    glClearColor( 0.0f, 0.0f, 0.0f, 0.0f );
    
    /* Depth buffer setup */
    glClearDepth( 1.0f );
    
    /* Enables Depth Testing */
    glEnable( GL_DEPTH_TEST );
    
    /* The Type Of Depth Test To Do */
    glDepthFunc( GL_LEQUAL );
    
    /* Really Nice Perspective Calculations */
    glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
    
    /* Setup The Ambient Light */
    glLightfv( GL_LIGHT1, GL_AMBIENT, LightAmbient );
    
    /* Setup The Diffuse Light */
    glLightfv( GL_LIGHT1, GL_DIFFUSE, LightDiffuse );
    
    /* Position The Light */
    glLightfv( GL_LIGHT1, GL_POSITION, LightPosition );
    
    /* Enable Light One */
    glEnable( GL_LIGHT1 );
    
    return( TRUE );
}










/* Here goes our drawing code */
int drawGLScene( GLvoid )
{
    /* These are to calculate our fps */
    static GLint T0     = 0;
    static GLint Frames = 0;
    
    /* Clear The Screen And The Depth Buffer */
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
    
    /* Reset the view */
    glLoadIdentity( );
    
    /* Translate Into/Out Of The Screen By z */
    glTranslatef( 0.0f, 0.0f, z );
    
    glRotatef( xrot, 1.0f, 0.0f, 0.0f); /* Rotate On The X Axis By xrot */
    glRotatef( yrot, 0.0f, 1.0f, 0.0f); /* Rotate On The Y Axis By yrot */
    
    /* Select A Texture Based On filter */
    glBindTexture( GL_TEXTURE_2D, texture[0] );
    
    /* Call our compiled function */
    glCallList(object);
    
    /* Draw it to the screen */
    SDL_GL_SwapWindow(window);
    
    /* Gather our frames per second */
    Frames++;
    {
        GLint t = SDL_GetTicks();
        if (t - T0 >= 5000) {
            GLfloat seconds = (t - T0) / 1000.0;
            GLfloat fps = Frames / seconds;
            printf("%d frames in %g seconds = %g FPS\n", Frames, seconds, fps);
            T0 = t;
            Frames = 0;
        }
    }
    
    xrot += xspeed; /* Add xspeed To xrot */
    yrot += yspeed; /* Add yspeed To yrot */
    
    return( TRUE );
}

int main( int argc, char **argv )
{
    /* main loop variable */
    int done = FALSE;
    /* used to collect events */
    SDL_Event event;
    /* whether or not the window is active */
    int isActive = TRUE;
    
    
    /* initialize SDL */
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        fprintf( stderr, "Video initialization failed: %s\n",
                SDL_GetError( ) );
        Quit( 1 );
    }
    
    
    
    /* Sets up OpenGL double buffering */
    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
    
    /* Create window and context */
    window = SDL_CreateWindow("Shape Demonstration",
                              SDL_WINDOWPOS_UNDEFINED,
                              SDL_WINDOWPOS_UNDEFINED,
                              SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_OPENGL|SDL_WINDOW_RESIZABLE);
    
    glcontext = SDL_GL_CreateContext(window);
    
    /* initialize OpenGL */
    initGL( );
    
    /* resize the initial window */
    resizeWindow( SCREEN_WIDTH, SCREEN_HEIGHT );
    
    /* Default is backface culling on */
    cull = 1;
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    
    glEnable (GL_BLEND); glBlendFunc (GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_ALPHA_TEST);
    glAlphaFunc(GL_GREATER, 0.1f);
    
    /* Setup the GenList for our shape */
    GenerateShape();
    
    /* wait for events */
    while ( !done )
    {
        /* handle the events in the queue */
        
        while ( SDL_PollEvent( &event ) )
        {
            switch( event.type )
            {
                case SDL_KEYDOWN:
                    /* handle key presses */
                    handleKeyPress( &event.key.keysym );
                    break;
                case SDL_QUIT:
                    /* handle quit requests */
                    done = 1;
                    break;
                default:
                    break;
            }
        }
        
        /* draw the scene */
        if ( isActive )
            drawGLScene( );
    }
    
    /* clean ourselves up and exit */
    Quit( 0 );
    
    /* Should never get here */
    return( 0 );
}
