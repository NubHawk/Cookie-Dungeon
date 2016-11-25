#include "game.h"
#include <conio.h>
#include <iostream>
#include <windows.h>

using namespace std;

#define GAME_SPEED 33.33




bool Game::run(void)
{
	levelObjectPtr = new Level(&gamesDrawEngineObject,80,30);

	gamesDrawEngineObject.createBackgroundTile(TILE_WALL, 219);
	gamesDrawEngineObject.createBackgroundTile(TILE_EMPTY, ' ');

	levelObjectPtr->createIntroLevel();






	char key = ' ';



	


	//loop until game ends
	frameCount = 0;
	lastTime = 0;
	startTime = timeGetTime();

	while (key != 'q')
	{
		//keep looping as long as a key is not pressed
		while (!getInput(&key))
		{
			timerUpdate();
		}

		//cout << "You pressed " << key << endl;


	}


	cout << "YOU QUIT";


	cout << frameCount / ((timeGetTime() - startTime) / 1000) << " Frames per second " << endl;
	//cout << "End of the game" << endl;

	return true;
}

bool Game::getInput(char *c)
{
	if (kbhit())
	{
		*c = getch();
		return true;
	}

	return false;
}


void Game::timerUpdate(void)
{
	double currentTime = timeGetTime() - lastTime;

	//timerUpdate function will run for 33.333 milliseconds
	if (currentTime < GAME_SPEED)
		return;



	//increased every 33 milliseconds 
	frameCount++;

	lastTime = timeGetTime();

}