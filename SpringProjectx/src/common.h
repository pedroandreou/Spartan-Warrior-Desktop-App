#ifndef COMMON_H_
#define COMMON_H_

#ifdef __cplusplus
extern "C" {
#endif 

#include <ctype.h>
#include <math.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#include <defs.h>
#include <structs.h>


int variable73;
char * global_dir;
App app;
Entity *player;
Stage stage;
Entity *self;

char *readFile(const char *filename);
int collision(int x1, int y1, int w1, int h1, int x2, int y2, int w2, int h2);
int isInsideMap(int x, int y);
SDL_Texture *loadTexture(char *filename);
void blitRect(SDL_Texture *texture, SDL_Rect *src, int x, int y);
void blit(SDL_Texture *texture, int x, int y, int center);
void calcSlope(int x1, int y1, int x2, int y2, float *dx, float *dy);
void cleanup(void);
void doCamera(void);
void doEntities(void);
void doInput(void);     
void doPlayer(int variable73);
void drawEntities(void);
void drawMap(void);
void drawText(int x, int y, int r, int g, int b, int align, char *format, ...);
void initBlock(char *line);
void initEntities(void);
void initFonts(void);
void initGame(void);
void initWedding(void);
void initMap(void);
void initBlacksoup(char *line);
void initKey(char* line);
void initHazard(char* line);
void initPrincess(char* line);
void initPlatform(char *line);
void initDoor1(char* line);
void initDoor2(char* line);
void initChurch(char* line);
void initCastle(char* line);
void initShip(char* line);
void initPlayer(void);
void initSDL(void);
void initSounds(void);
void initStage(void);
void loadMusic(char *filename);
void playMusic(int loop);
void playSound(int id, int channel);
void prepareScene(void);
void presentScene(void);

#ifdef __cplusplus
}
#endif
#endif


