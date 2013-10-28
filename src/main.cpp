#include <iostream>
#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "textures.h"

using namespace std;

Textures *texture = new Textures();

unsigned int basewalltex,bricktex,pipetex;
unsigned int mariotex,questiontex,enemytex;
unsigned int cloudtex,bushtex,hilltex;

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
    for(int i=0;i<22;i++)
    {
        texture->drawBaseWall(startx, starty);
        startx+=64;
    }

    //Draw Base-wall
    // for(int i=0;i<22;i++){

    //     drawBase(startx, starty);

    //     if(i==5){
    //         drawSmallCloud(startx, starty);
    //         drawBush(startx, starty);
    //     }

    //     glPushMatrix();
    //     if(i==10){
    //         // glTranslatef(-x,0,0);
    //         drawEnemy(startx, starty);
    //     }
    //     glPopMatrix();

    //     if(i==13){
    //         drawSmallHill(startx, starty);
    //     }

    //     if(i==16){
    //         drawPipe(startx, starty);
    //     }

    //     if(i>=9 && i<=13)
    //     {
    //         if(i%2)
    //             drawBrick(startx, starty);
    //         else
    //             drawQuestion(startx, starty);
    //     }

    //     startx+=64;
    // }

    glPushMatrix();
    // glTranslatef(mario->mariox,mario->marioy,0);
    texture->drawMario(64, 0);
    glPopMatrix();
    // x+=2;
}

int main(int argc, char** argv)
{
    bool direction[4] = {0,0,0,0};
    int jumpFlag=0;
    // mario->mariox=0;
    // mario->marioy=0;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen;
	screen = SDL_SetVideoMode(1344, 768, 32, SDL_SWSURFACE|SDL_OPENGL | SDL_FULLSCREEN);
	// screen = SDL_SetVideoMode(1344, 768, 32, SDL_SWSURFACE|SDL_OPENGL );
	bool running = true;
	const int FPS = 30;
	Uint32 start;
	SDL_Event event;

    // createLevel();

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
                            jumpFlag=0;
                            direction[2]=1;
                            break;
                        case SDLK_DOWN:
                            if(direction[2]==0)
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
                            jumpFlag=0;
                            break;
                        case SDLK_DOWN:
                            if(jumpFlag==1)
                                direction[3]=0;
                            break;
                    }
                    break; 
            }
        }

        if(direction[0])
            // moveBack();
            // mariox-=5;

        if(direction[1])
            // moveFront();
            // mariox+=5;

        if(direction[2])
        {
            // // cout<<marioy<<endl;
            // if(marioy<=258){
            //     marioy+=5;
            //     direction[2]=1;
            // }
            // else{
            //     direction[2]=0;
            //     direction[3]=1;
            // }

        }

        if(direction[3])
        {
            // if(marioy>0)
            //     marioy-=5;
            // else
            // {
            //    direction[3]=0; 
            //    jumpFlag=1;
            // }
        }

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
