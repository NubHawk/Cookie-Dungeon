#include "verticalUntouchable.h"
#include "character.h"
#include "level.h"
#include "windows.h"

#define GAME_SPEED 66.66

VerticalUntouchable::VerticalUntouchable(Level *l, DrawEngine* de, int s_index, float x, float y,
	float xDir, float yDir,int i_lives) : Sprite(l, de, s_index, x, y, i_lives)
{
	facingDirection.x = xDir;
	facingDirection.y = yDir;
	goal = 0;
	classID = VERTICAL_UNTOUCHABLE_CLASSID;

}

void VerticalUntouchable::idleUpdate(void)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	int xpos = pos.x;
	int ypos = pos.y + facingDirection.y;
	lastTime = 0;
	flag = true;
	while (flag)
		timerUpdate();

	if (Sprite::move(facingDirection.x, facingDirection.y))
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		if ((int)goal->getX() == xpos && (int)goal->getY() == ypos)
		{
			goal->addLives(-1);
		}
	}
	else
	{
		facingDirection.y = -facingDirection.y;
	}
	
	
}

void VerticalUntouchable::timerUpdate(void)
{

		double currentTime = timeGetTime() - lastTime;

		//timerUpdate function will run for 33.333 milliseconds
		if (currentTime < GAME_SPEED)
			return;


		lastTime = timeGetTime();
		flag = false;


}

