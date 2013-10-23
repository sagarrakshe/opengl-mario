#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include "game.cpp"

using namespace std;

float angle = 0.0;
const int triangle = 1;
GLfloat x=0.5;
GLint mariox=0,marioy=0;

// Mario *mario = new Mario();
// Level *level1 = new Level();

unsigned int basewall,brick,pipe;
unsigned int mario,question,enemy;
unsigned int cloud,bush,hill;

void drawBase(int x, int y)
{
    glBindTexture(GL_TEXTURE_2D, basewall);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+128,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+64,y+128,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+64,y,0.0);
    glEnd();
}

void drawSmallCloud(int x, int y){
    glBindTexture(GL_TEXTURE_2D, cloud);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+512,-1.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+64+512,-1.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+128,y+64+512,-1.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+128,y+512,-1.0);
    glEnd();
}

void drawBush(int x, int y){
    glBindTexture(GL_TEXTURE_2D, bush);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+128,-1.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+64+128,-1.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+256,y+64+128,-1.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+256,y+128,-1.0);
    glEnd();

}

void drawSmallHill(int x, int y){
    glBindTexture(GL_TEXTURE_2D, hill);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+128,-1.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+64+128,-1.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+192,y+64+128,-1.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+192,y+128,-1.0);
    glEnd();
}

void drawPipe(int x, int y){
    glBindTexture(GL_TEXTURE_2D, pipe);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+128,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+192+128,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+128,y+192+128,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+128,y+128,0.0);
    glEnd();
}

void drawBrick(int x, int y){
    glBindTexture(GL_TEXTURE_2D, brick);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+320,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+64+320,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+64,y+64+320,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+64,y+320,0.0);
    glEnd();

}

void drawQuestion(int x, int y){
    glBindTexture(GL_TEXTURE_2D, question);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+320,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+64+320,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+64,y+64+320,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+64,y+320,0.0);
    glEnd();

}

void drawMario(int x, int y){
    glBindTexture(GL_TEXTURE_2D, mario);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+128,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+128+64,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+64,y+128+64,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+64,y+128,0.0);
    glEnd();
}

void drawEnemy(int x, int y){
    glBindTexture(GL_TEXTURE_2D, enemy);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(x,y+128,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(x,y+64+128,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(x+64,y+64+128,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(x+64,y+128,0.0);
    glEnd();
}

unsigned int loadTexture(const char* filename)
{
	// SDL_Surface* img = SDL_LoadBMP(filename);
    SDL_Surface *img = IMG_Load(filename);
	unsigned int id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SDL_FreeSurface(img);
	return id;
}

void init()
{
	glClearColor(0.48,0.47,1.0,1.0);	//background color and alpha
    glOrtho(0.0,1360.0,0.0,760.0,-10.0,10.0);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	// glMatrixMode(GL_PROJECTION);
	// glLoadIdentity();
	// gluPerspective(45,640.0/480.0,1.0,600.0);
	// glMatrixMode(GL_MODELVIEW);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE_2D);

	basewall = loadTexture("../media/bmps/newbase.bmp");
    brick = loadTexture("../media/bmps/brick.bmp");
    mario = loadTexture("../media/bmps/mario.png");
    question = loadTexture("../media/bmps/question.bmp");
    cloud = loadTexture("../media/bmps/cloud.bmp");
    bush = loadTexture("../media/bmps/bush.bmp");
    hill = loadTexture("../media/bmps/hill.bmp");
    pipe = loadTexture("../media/bmps/pipe.bmp");
    enemy = loadTexture("../media/bmps/owl.bmp");
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	// glLoadIdentity();
    GLint startx=0, starty=0;

    //Draw Base-wall
    for(int i=0;i<22;i++){

        drawBase(startx, starty);

        if(i==5){
            drawSmallCloud(startx, starty);
            drawBush(startx, starty);
        }

        glPushMatrix();
        if(i==10){
            // glTranslatef(-x,0,0);
            drawEnemy(startx, starty);
        }
        glPopMatrix();

        if(i==13){
            drawSmallHill(startx, starty);
        }

        if(i==16){
            drawPipe(startx, starty);
        }

        if(i>=9 && i<=13)
        {
            if(i%2)
                drawBrick(startx, starty);
            else
                drawQuestion(startx, starty);
        }

        startx+=64;
    }

    glPushMatrix();
    glTranslatef(mariox,marioy,0);
    drawMario(128,0);
    glPopMatrix();
    // x+=2;
}

int main(int argc, char** argv)
{
    bool direction[4] = {0,0,0,0};
    int jumpFlag=0;
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen;
	screen = SDL_SetVideoMode(1344, 768, 32, SDL_SWSURFACE|SDL_OPENGL | SDL_FULLSCREEN);
	// screen = SDL_SetVideoMode(1344, 768, 32, SDL_SWSURFACE|SDL_OPENGL );
	bool running = true;
	const int FPS = 30;
	Uint32 start;
	SDL_Event event;
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
            mariox-=5;

        if(direction[1])
            mariox+=5;

        if(direction[2])
        {
            // cout<<marioy<<endl;
            if(marioy<=258){
                marioy+=5;
                direction[2]=1;
            }
            else{
                direction[2]=0;
                direction[3]=1;
            }

        }

        if(direction[3])
        {
            if(marioy>0)
                marioy-=5;
            else
            {
               direction[3]=0; 
               jumpFlag=1;
            }
        }

		display();
		SDL_GL_SwapBuffers();
		angle += 0.9;
		if(angle > 360)
			angle -= 360;
		if(1000/FPS > SDL_GetTicks()-start)
			SDL_Delay(1000/FPS-(SDL_GetTicks()-start));
	}
	//SDL_Quit();
	atexit(SDL_Quit);
	return 0;
}
