#include "enemy.h"
#include "character.h"
#include "level.h"

#include <math.h>
#include <stdlib.h>
#include <Windows.h>




Enemy::Enemy(Level *l, DrawEngine *de, int s_index, float x, float y, int i_lives)
: Sprite(l, de, s_index, x, y, i_lives)
{
	goal = 0;
	classID = ENEMY_CLASSID;
}

bool Enemy::move(float x, float y)
{
	int xpos = (int)(pos.x + x);
	int ypos = (int)(pos.y + y);

	if (isValidLevelMove(xpos, ypos))
	{

		//make sure we don't run in to any other enemies 
		list <Sprite *>::iterator Iter;

		for (Iter = level->npc.begin(); Iter != level->npc.end(); Iter++)
		{
			//not bump into oneself 'this' and not bump into others
			if ((*Iter) != this && (int)(*Iter)->getX() == xpos && (int)(*Iter)->getY() == ypos)
			{
				return false;
			}
		}


		//goal is the character

		//erase present pos
		erase(pos.x, pos.y);

		pos.x += x;
		pos.y += y;

		facingDirection.x = x;
		facingDirection.y = y;

		//draw at new pos
		draw(pos.x, pos.y);


		//if new position has Player, life--
		if ((int)goal->getX() == xpos && (int)goal->getY() == ypos)
			goal->addLives(-1);


		return true;
	}

	return false;
}

void Enemy::idleUpdate(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	if (goal)
		simulateAI();

}

void Enemy::simulateAI(void)
{
	vector goal_pos = goal->getPosition();
	vector direction;

	direction.x = goal_pos.x - pos.x;
	direction.y = goal_pos.y - pos.y;

	float mag = sqrt(direction.x*direction.x + direction.y*direction.y);

	direction.x /= (mag * 10);
	direction.y /= (mag * 10);

	if (!move(direction.x, direction.y))
	{
		while (!move((float)(rand() % 3 - 1), (float)(rand() % 3 - 1)))
		{

		}
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

}

void Enemy::addGoal(Character *g)
{
	goal = g;
}