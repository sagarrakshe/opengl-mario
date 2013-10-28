/*
 * game.h
 * Copyright (C) 2013 sagar <sagar@sagar-liquid>
 *
 */

#ifndef __GAME_H__
#define __GAME_H__

class Level{

    public:
        int baseWall[22];
        int pipe[22];
};

class Mario{
    public:
        int mariox;
        int marioy;
        int base;
};

#endif /* !__GAME_H__ */

