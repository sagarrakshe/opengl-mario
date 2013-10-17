#include <SDL/SDL.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

float angle = 0.0;
const int triangle = 1;
GLfloat x=0.5;

unsigned int loadTexture(const char* filename)
{
	SDL_Surface* img = SDL_LoadBMP(filename);
	unsigned int id;
	glGenTextures(1, &id);
	glBindTexture(GL_TEXTURE_2D, id);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->w, img->h, 0, GL_RGB, GL_UNSIGNED_SHORT_5_6_5, img->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	SDL_FreeSurface(img);
	return id;
}

unsigned int basewall,brick,pipe;
unsigned int mario,question,enemy;
unsigned int cloud,bush,hill;

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
    mario = loadTexture("../media/bmps/mario.bmp");
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

	    glBindTexture(GL_TEXTURE_2D, basewall);
        glBegin(GL_QUADS);
            glTexCoord2f(0.0,1.0);
            glVertex3f(startx,starty,0.0);
            glTexCoord2f(0.0,0.0);
            glVertex3f(startx,starty+128,0.0);
            glTexCoord2f(1.0,0.0);
            glVertex3f(startx+64,starty+128,0.0);
            glTexCoord2f(1.0,1.0);
            glVertex3f(startx+64,starty,0.0);
        glEnd();

        if(i==5){
            glBindTexture(GL_TEXTURE_2D, cloud);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0,1.0);
                glVertex3f(startx,starty+512,0.0);
                glTexCoord2f(0.0,0.0);
                glVertex3f(startx,starty+64+512,0.0);
                glTexCoord2f(1.0,0.0);
                glVertex3f(startx+128,starty+64+512,0.0);
                glTexCoord2f(1.0,1.0);
                glVertex3f(startx+128,starty+512,0.0);
            glEnd();

            glBindTexture(GL_TEXTURE_2D, bush);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0,1.0);
                glVertex3f(startx,starty+128,0.0);
                glTexCoord2f(0.0,0.0);
                glVertex3f(startx,starty+64+128,0.0);
                glTexCoord2f(1.0,0.0);
                glVertex3f(startx+256,starty+64+128,0.0);
                glTexCoord2f(1.0,1.0);
                glVertex3f(startx+256,starty+128,0.0);
            glEnd();

        }

        glPushMatrix();
        if(i==10){
            glTranslatef(-x,0,0);
            glBindTexture(GL_TEXTURE_2D, enemy);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0,1.0);
                glVertex3f(startx,starty+128,0.0);
                glTexCoord2f(0.0,0.0);
                glVertex3f(startx,starty+64+128,0.0);
                glTexCoord2f(1.0,0.0);
                glVertex3f(startx+64,starty+64+128,0.0);
                glTexCoord2f(1.0,1.0);
                glVertex3f(startx+64,starty+128,0.0);
            glEnd();
        }
        glPopMatrix();

        if(i==13){
            glBindTexture(GL_TEXTURE_2D, hill);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0,1.0);
                glVertex3f(startx,starty+128,0.0);
                glTexCoord2f(0.0,0.0);
                glVertex3f(startx,starty+64+128,0.0);
                glTexCoord2f(1.0,0.0);
                glVertex3f(startx+192,starty+64+128,0.0);
                glTexCoord2f(1.0,1.0);
                glVertex3f(startx+192,starty+128,0.0);
            glEnd();
        }
        if(i==16){
            glBindTexture(GL_TEXTURE_2D, pipe);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0,1.0);
                glVertex3f(startx,starty+128,0.0);
                glTexCoord2f(0.0,0.0);
                glVertex3f(startx,starty+192+128,0.0);
                glTexCoord2f(1.0,0.0);
                glVertex3f(startx+128,starty+192+128,0.0);
                glTexCoord2f(1.0,1.0);
                glVertex3f(startx+128,starty+128,0.0);
            glEnd();
        }

        if(i>=9 && i<=13)
        {
            if(i%2)
                glBindTexture(GL_TEXTURE_2D, brick);
            else
                glBindTexture(GL_TEXTURE_2D, question);
            glBegin(GL_QUADS);
                glTexCoord2f(0.0,1.0);
                glVertex3f(startx,starty+320,0.0);
                glTexCoord2f(0.0,0.0);
                glVertex3f(startx,starty+64+320,0.0);
                glTexCoord2f(1.0,0.0);
                glVertex3f(startx+64,starty+64+320,0.0);
                glTexCoord2f(1.0,1.0);
                glVertex3f(startx+64,starty+320,0.0);
            glEnd();
        }

        startx+=64;
    }

    glPushMatrix();
    startx=starty=0; 
    glBindTexture(GL_TEXTURE_2D, mario);
    glBegin(GL_QUADS);
        glTexCoord2f(0.0,1.0);
        glVertex3f(startx,starty+128,0.0);
        glTexCoord2f(0.0,0.0);
        glVertex3f(startx,starty+128+64,0.0);
        glTexCoord2f(1.0,0.0);
        glVertex3f(startx+64,starty+128+64,0.0);
        glTexCoord2f(1.0,1.0);
        glVertex3f(startx+64,starty+128,0.0);
    glEnd();
    glPopMatrix();
    x+=1;
}

int main(int argc, char** argv)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Surface *screen;
	// screen = SDL_SetVideoMode(1360, 760, 32, SDL_SWSURFACE|SDL_OPENGL | SDL_FULLSCREEN);
	screen = SDL_SetVideoMode(1344, 768, 32, SDL_SWSURFACE|SDL_OPENGL | SDL_FULLSCREEN);
	// screen = SDL_SetVideoMode(1344, 768, 32, SDL_SWSURFACE|SDL_OPENGL );
	// screen = SDL_SetVideoMode(640, 480, 8, SDL_SWSURFACE|SDL_OPENGL);
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
                    }
                    break;
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
