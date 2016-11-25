#include "fireball.h"
#include "windows.h"

Fireball::Fireball(Level *lev, DrawEngine* de, int s_index, float x, float y,
	float xDir, float yDir, int i_lives) : Sprite(lev, de, s_index, x, y, i_lives)
{
	facingDirection.x = xDir;
	facingDirection.y = yDir;

	classID = FIREBALL_CLASSID;

}

void Fireball::idleUpdate(void)
{
	list <Sprite *>::iterator Iter;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
	if (Sprite::move(facingDirection.x, facingDirection.y))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	
		for (Iter = level->npc.begin(); Iter != level->npc.end(); Iter++)
		{
			//if ((*Iter)->classID == FIREBALL_CLASSID && (int)(*Iter)->getX() == (int)(*Iter)->getPrevX() && (int)(*Iter)->getY() == (int)(*Iter)->getPrevY())
				//(*Iter)->addLives(-1);

			//1: make sure the npc is not fireball 2: if position of enemy == fireball postion
			if ((*Iter)->classID != classID && (int)(*Iter)->getX() == (int)pos.x && (int)(*Iter)->getY() == (int)pos.y)
			{
				//enemy life
				(*Iter)->addLives(-1);
				//fireball life
				addLives(-1);
			}
		}
	}
	else
	{
		//if ((int)(*Iter)->getX() == (int))
		addLives(-1);
	}
		//remove life for invalid move i.e hits walls
}