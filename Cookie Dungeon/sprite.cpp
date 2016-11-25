#include "sprite.h"

Sprite::Sprite(Level *l, DrawEngine *de, int s_index, float x, float y, int i_lives)
{
	drawArea = de;

	pos.x = x;
	pos.y = y;

	spriteIndex = s_index;

	numLives = i_lives;

	classID = SPRITE_CLASSID;

	facingDirection.x = 1;
	facingDirection.y = 0;

	level = l;

}

Sprite::~Sprite()
{
	//erase the dying sprite
	erase(pos.x, pos.y);
}


vector Sprite::getPosition(void)
{
	return pos;
}

float Sprite::getX(void)
{
	return pos.x;
}

float Sprite::getY(void)
{
	return pos.y;
}

void Sprite::addLives(int num)
{
	numLives += num;
}
int Sprite::getLives(void)
{
	return numLives;
}
bool Sprite::isAlive(void)
{
	return (numLives > 0);
}

bool Sprite::move(float x, float y)
{
	previousPos.x = pos.x;
	previousPos.y = pos.y;
	int xpos = (int)(pos.x + x);
	int ypos = (int)(pos.y + y);

	if (isValidLevelMove(xpos, ypos))
	{


		//erase with draw engine

		erase(pos.x, pos.y);

		pos.x += x;
		pos.y += y;

		facingDirection.x = x;
		facingDirection.y = y;

		//draw sprite

		draw(pos.x, pos.y);

		return true;
	}

	return false;


}


void Sprite::draw(float x, float y)
{
	drawArea->drawSprite(spriteIndex, (int)x, (int)y);

}
void Sprite::erase(float x, float y)
{
	drawArea->eraseSprite((int)x, (int)y);
}

bool Sprite::isValidLevelMove(int xpos, int ypos)
{
	if (level->level[xpos][ypos] != TILE_WALL)
		return true;

	return false;
}

void Sprite::idleUpdate(void)
{
	//this is for inherited classes
}

float Sprite::getPrevX(void)
{
	return previousPos.x;
}

float Sprite::getPrevY(void)
{
	return previousPos.y;
}