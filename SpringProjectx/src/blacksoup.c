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

static void tick(void);
static void touch(Entity* other);

void initBlacksoup(char* line)
{
	Entity* e;

	e = malloc(sizeof(Entity));
	memset(e, 0, sizeof(Entity));
	stage.entityTail->next = e;
	stage.entityTail = e;

	sscanf(line, "%*s %f %f", &e->x, &e->y);

	e->health = 1;

	e->texture = loadTexture("gfx/blacksoup.png");
	SDL_QueryTexture(e->texture, NULL, NULL, &e->w, &e->h);
	e->flags = EF_WEIGHTLESS;
	e->tick = tick;
	e->touch = touch;

	stage.blacksoupTotal++;
}

static void tick(void)
{
	self->value += 0.1;

	self->y += sin(self->value);
}

static void touch(Entity* other)
{
	if (self->health > 0 && other == player)
	{
		self->health = 0;

		stage.blacksoupFound++;

		if (stage.blacksoupFound == stage.blacksoupTotal)
		{
			playSound(SND_BLACKSOUP_DONE, CH_BLACKSOUP); 
		}
		else
		{
			playSound(SND_BLACKSOUP, CH_BLACKSOUP);
		}
	}
}