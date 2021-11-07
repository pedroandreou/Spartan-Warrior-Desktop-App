/*
Copyright (C) 2015-2018 Parallel Realities

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

See the GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.

*/

#include "common.h"

static SDL_Texture *warrior[3];
static void touch(Entity* other);
static void tick(void);

void initPlayer(void)
{
	player = malloc(sizeof(Entity));
	memset(player, 0, sizeof(Entity));
	stage.entityTail->next = player;
	stage.entityTail = player;

	player->health = 1;
	player->tick = tick;

	warrior[0] = loadTexture("gfx/warrior01.png");
	warrior[1] = loadTexture("gfx/warrior02.png");
	warrior[2] = loadTexture("gfx/warrior03.png");

	player->texture = warrior[0];

	SDL_QueryTexture(player->texture, NULL, NULL, &player->w, &player->h);

	
		player->x = 200;
		player->y = 200;
	
}

void doPlayer(int variable73){
	
	player->dx = 0;


	if (variable73 == 0) {
		if (app.keyboard[SDL_SCANCODE_LEFT])
		{
			player->dx = -PLAYER_MOVE_SPEED;

			player->texture = warrior[1];
		}

		if (app.keyboard[SDL_SCANCODE_RIGHT])
		{
			player->dx = PLAYER_MOVE_SPEED;

			player->texture = warrior[0];
		}

		if (app.keyboard[SDL_SCANCODE_SPACE] && player->isOnGround)
		{
			player->riding = NULL;

			player->dy = -20;

			//playSound(SND_JUMP, CH_PLAYER);
		}

		if (app.keyboard[SDL_SCANCODE_Q])
		{
			player->x = player->y = 0;

			app.keyboard[SDL_SCANCODE_Q] = 0;
		}
	}
	else {
			player->dx = -1;

			player->texture = warrior[2];
	}
	// Player died
	if (player != NULL && player->health <= 0)
	{
		exit(1);
	}
	
	
}

static void tick(void)
{
	
	if (player->texture == warrior[2]) {
		if (player->x == 450.000000 && player->y == 1488.00000)
		{
			exit(1);
		}
	
	}

}