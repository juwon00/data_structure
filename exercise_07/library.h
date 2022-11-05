// 테스트 데이터 모두 통과했습니다.

#pragma once // ifndef과 동일한 기능

#ifndef LIBRARY_H
#define LIBRARY_H

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

typedef struct song Song;
typedef struct snode Snode;
typedef struct artist Artist;



struct song
{
    Artist *artist;
    char *title;
    char *path;
    int index;
};



struct snode
{
    Snode *next, *prev;
    Song *song;
};



struct artist
{
    char *name;
    Artist *next;
    Snode *head, *tail;

};




void add_song(char *artist, char *title, char *path);
void initialize();
void status();
void load(FILE *fp);
void search_song(char *artist, char *title);
void play(int index);
void save(FILE *fp);
void remove_song(int index);



#endif // LIBRARY_H