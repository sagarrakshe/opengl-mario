#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "textures.h"
#include "game.h"

#define MAX 22

using namespace std;

Textures *texture = new Textures();
Level *level1 = new Level(); 
Mario *mario = new Mario();

int jumpFlag=0,up=0,down;
bool direction[4] = {0,0,0,0};

void die(){
    exit(1);
}

void createLevel(){
    for(int i=0;i<MAX;i++){ 
        // level1->baseWall[i] = (i%7);
        level1->baseWall[i] = 1;
        level1->pipe[i] = (i%5==0);
        if(level1->pipe[i-1]==1 && ((i-1)%5==0))
            level1->pipe[i]=1;
    }
    level1->pipe[0]=0;
}

void moveBack(){
    if(level1->pipe[(mario->mariox-1)/64]){
        if(mario->marioy/64>=3)
            mario->mariox-=4;
        else
            mario->mariox=mario->mariox;
    }
    else if(level1->baseWall[(mario->mariox+31)/64])
        mario->mariox-=4;
    else
        die();
}

void moveFront(){
    if(level1->pipe[(mario->mariox+65)/64]){
        if(mario->marioy/64>=3)
            mario->mariox+=4;
        else
            mario->mariox=mario->mariox;
    }
    else if(level1->baseWall[(mario->mariox+33)/64])
        mario->mariox+=4;
    else if(mario->marioy)
        mario->mariox+=4;
    else
        die();
}

void moveUp(){
    if(!jumpFlag){
        jumpFlag=mario->marioy+224;
        up=1;
    }
    if(jumpFlag && (mario->marioy<=jumpFlag) && up)
        mario->marioy+=4;
    else
        up=0;
    if(!up)
    {
        if(level1->pipe[(mario->mariox+64)/64] || level1->pipe[(mario->mariox+4)/64]){
            mario->base=1;
            if(mario->marioy>=188)
                mario->marioy-=4;
            if(mario->marioy==192){
                direction[2]=0;
                jumpFlag=0;
            }
        }

        else if(!(level1->pipe[(mario->mariox+64)/64]) || !(level1->pipe[(mario->mariox+4)/64]) ){
            mario->base=0;
            if(mario->marioy>=4)
                mario->marioy-=4;
            if(mario->marioy==0){
                direction[2]=0;
                jumpFlag=0;
            }
        }
    }
}

void moveDown(){
}

void init()
{
    glClearColor(0.48,0.47,1.0,1.0);	
    glOrtho(0.0,1360.0,0.0,760.0,-10.0,10.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_TEXTURE_2D);
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    GLint startx=0,starty=0;

    // cout<<mario->marioy/64<<endl;
    for(int i=0;i<MAX;i++)
    {
        if(level1->baseWall[i])
            texture->drawBaseWall(startx, starty);
        if(level1->pipe[i] && (i%5==0))
            texture->drawPipe(startx, starty);
        startx+=64;
    }

    glPushMatrix();
        glTranslatef(mario->mariox,mario->marioy,0);
        texture->drawMario(0, 0);
    glPopMatrix();

    
}

int main(int argc, char** argv)
{
    mario->mariox=832;
    mario->marioy=0;
    mario->base=0;

    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Surface *screen;
    // screen = SDL_SetVideoMode(1344, 768, 32, SDL_SWSURFACE|SDL_OPENGL | SDL_FULLSCREEN);
    screen = SDL_SetVideoMode(1344, 768, 32, SDL_SWSURFACE|SDL_OPENGL );
    bool running = true;
    const int FPS = 30;
    Uint32 start;
    SDL_Event event;

    createLevel();

    init();

    while(running) {
        start = SDL_GetTicks();
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    running = false;
                    break;
                case SDL_KEYDOWN:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_ESCAPE:
                            running = false;
                            break;
                        case SDLK_LEFT:
                            direction[0]=1;
                            break;
                        case SDLK_RIGHT:
                            direction[1]=1;
                            break;
                        case SDLK_UP:
                            // jumpFlag=0;
                            direction[2]=1;
                            break;
                        case SDLK_DOWN:
                            // if(direction[2]==0)
                            direction[3]=1;
                            break;
                    }
                    break;
                case SDL_KEYUP:
                    switch(event.key.keysym.sym)
                    {
                        case SDLK_LEFT:
                            direction[0]=0;
                            break;
                        case SDLK_RIGHT:
                            direction[1]=0;
                            break;
                        case SDLK_UP:
                            // direction[2]=0;
                            // jumpFlag=0;
                            break;
                        case SDLK_DOWN:
                            // if(jumpFlag==1)
                            direction[3]=0;
                            break;
                    }
                    break; 
            }
        }

        if(direction[0])
            moveBack();
        // mariox-=5;

        if(direction[1])
            moveFront();
        // mariox+=5;

        if(direction[2])
            moveUp();

        if(direction[3])
            moveDown();

        display();
        SDL_GL_SwapBuffers();
        // angle += 0.9;
        // if(angle > 360)
        // 	angle -= 360;
        if(1000/FPS > SDL_GetTicks()-start)
            SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
    }
    //SDL_Quit();
    atexit(SDL_Quit);
    return 0;
}
