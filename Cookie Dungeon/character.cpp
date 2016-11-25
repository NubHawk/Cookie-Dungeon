#include "character.h"
#include "fireball.h"
#include "windows.h"


Character::Character(Level *l, DrawEngine *de, int s_index, float x, float y, int lives,
	char u, char d, char left, char r, char sp) : Sprite(l, de, s_index, x, y, lives)
{
	upKey = u;
	downKey = d;
	leftKey = left;
	rightKey = r;
	spellKey = sp;

	l = l;

	classID = CHARACTER_CLASSID;
}

bool Character::keyPress(char c)
{
	bool flag;
	if (c == upKey)
	{	
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		flag = move(0, -1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		return flag;

	}
	else if (c == downKey)
	{
		//return move(0, 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		flag = move(0, 1);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		return flag;
	}
	else if (c == rightKey)
	{
		//return move(1, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		flag = move(1, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		return flag;
	}
	else if (c == leftKey)
	{
		//return move(-1, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
		flag = move(-1, 0);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);

		return flag;
	}
	else if (c== spellKey)
	{
		castSpell();
		return true;
	}
	return false;

}

void Character::addLives(int num)
{
	Sprite::addLives(num);

	if (Sprite::isAlive())
	{
		pos.x = 1;
		pos.y = 1;
		move(0, 0);

	}

}
/*
bool Character::keyPress(char c)
{
	bool val = Character::keyPress(c);

	if (val == false)
	{
		if (c == spellKey)
		{
			castSpell();
			return true;
		}
	}
	return val;
}

*/

void Character::castSpell(void)
{
	if (level->level[(int)pos.x + (int)facingDirection.x][(int)pos.y + (int)facingDirection.y] != TILE_WALL)

	{

		Fireball *temp = new Fireball(level, drawArea, SPRITE_FIREBALL,
			(int)pos.x + facingDirection.x, (int)pos.y + facingDirection.y,
			facingDirection.x, facingDirection.y);

		level->addNPC((Sprite *)temp);
	}

}