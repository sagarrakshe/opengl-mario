#ifndef __TEXTURES_H__
#define __TEXTURES_H__

#include <iostream>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>

class Textures{

    unsigned int loadTexture(const char *filename);

    public:

    void drawMario(int , int );
    void drawBaseWall(int , int );
    void drawBrick(int , int );
    void drawQuestion(int , int );
    void drawCloud(int , int );
    void drawBush(int , int );
    void drawHill(int , int );
    void drawPipe(int , int );
    void drawEnemy(int , int );
};

#endif /* !__TEXTURES_H__ */

