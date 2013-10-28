/*
 * Author:  Sagar Rakshe <sagarrakshe2@gmail.com>
 * Date:    2013-10-25 12:33
 */

#include "textures.h"

unsigned int Textures::loadTexture(const char* filename)
{
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

void Textures::drawMario(int x, int y){

    glBindTexture(GL_TEXTURE_2D, this->loadTexture("../media/bmps/mario.bmp"));
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

void Textures::drawBaseWall(int x, int y)
{
    glBindTexture(GL_TEXTURE_2D, this->loadTexture("../media/bmps/newbase.bmp"));
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

void Textures::drawBrick(int x, int y){
    glBindTexture(GL_TEXTURE_2D, this->loadTexture("../media/bmps/brick.bmp"));
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

void Textures::drawQuestion(int x, int y){
    glBindTexture(GL_TEXTURE_2D, this->loadTexture("../media/bmps/question.bmp"));
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

void Textures::drawCloud(int x, int y){
    glBindTexture(GL_TEXTURE_2D, this->loadTexture("../media/bmps/cloud.bmp"));
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

void Textures::drawBush(int x, int y){
    glBindTexture(GL_TEXTURE_2D, this->loadTexture("../media/bmps/bush.bmp"));
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

void Textures::drawHill(int x, int y){
    glBindTexture(GL_TEXTURE_2D, this->loadTexture("../media/bmps/hill.bmp"));
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

void Textures::drawPipe(int x, int y){
    glBindTexture(GL_TEXTURE_2D, this->loadTexture("../media/bmps/pipe.bmp"));
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

void Textures::drawEnemy(int x, int y){
    glBindTexture(GL_TEXTURE_2D, this->loadTexture("../media/bmps/enemy.bmp"));
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
