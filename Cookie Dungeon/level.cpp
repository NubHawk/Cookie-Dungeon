#include "level.h"
#include <iostream>
#include "windows.h"

#include <conio.h>
#include "enemy.h"
#include "character.h"
#include "verticalUntouchable.h"

using namespace std;


#define GAME_SPEED 33.33
//class Mage;

Level::Level(DrawEngine *de, int w, int h)
{
	gamesDrawEngineObjPtr = de;

	width = w;
	height = h;

	
	//allocate necessary memory
	level = new char *[width];

	for (int x = 0; x < width; x++)
		level[x] = new char[height];

}

Level::~Level()
{
	for (int x = 0; x < width; x++)
		delete[] level[x];

	delete[] level;



}

bool Level::keyPress(char *c)
{
	if (kbhit())
	{
		*c = getch();
		return true;
	}

	return false;
}



void Level::createIntroLevel(void)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{


			if (((x == 0 || x == width-20) && y <= height - 5) || (y==0 || y == height-5) && x <= width-20)
				level[x][y] = TILE_WALL;
			else
				level[x][y] = TILE_EMPTY;

		}
	}
	gamesDrawEngineObjPtr->setMap(level);
	gamesDrawEngineObjPtr->drawBackground();

	gamesDrawEngineObjPtr->gotoxy(23, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	
	string temp1 = "COOKIE DUNGEON";
	for (int i = 0; i < temp1.length(); i++)
	{
		cout << temp1[i];
		Sleep(100);
	}

	gamesDrawEngineObjPtr->gotoxy(13, 15);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "<<Press any key to start the game>>";
	temp1 = "<<Press any key to start the game>>";
	for (int i = 0; i < temp1.length(); i++)
	{
		cout << temp1[i];
		Sleep(50);
	}

	gamesDrawEngineObjPtr->gotoxy(51, 22);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	//cout << "<<Press any key to start the game>>";
	temp1 = "NubHawk";
	for (int i = 0; i < temp1.length(); i++)
	{
		cout << temp1[i];
		Sleep(50);
	}
	

	c = 0;
	while (!c)
	{
		keyPress(&c);
	}
	createFirstLevel();




}

void Level::createFirstLevel(void)
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{


			if (((x == 0 || x == width - 20) && y <= height - 5) || (y == 0 || y == height - 5) && x <= width - 20)
				level[x][y] = TILE_WALL;
			else
				level[x][y] = TILE_EMPTY;

		}
	}
	lives = 3;
	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();

	gamesDrawEngineObjPtr->gotoxy(15, 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "CookieTappa -> ";
	cout << (char)153;


	gamesDrawEngineObjPtr->gotoxy(13, 23);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "Mr.CookieLover -> ";
	cout << (char)1;

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 10);
	gamesDrawEngineObjPtr->gotoxy(5, 7);
	string temp = "Help! Help! Help!";
	bool flag = false;

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
		 Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;
	gamesDrawEngineObjPtr->gotoxy(5, 8);
	temp="The Evil Monkeys stole my cookie!!";
	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	gamesDrawEngineObjPtr->gotoxy(5, 9);
	temp = "They took it back to their Dungeon..";
	flag = false;
	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	gamesDrawEngineObjPtr->gotoxy(5, 10);
	temp = "Will you be kind enough to bring it back?";
	flag = false;
	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}


	gamesDrawEngineObjPtr->gotoxy(5, 11);
	temp = "We can share the cookie, I promise...";
	flag = false;
	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	Sleep(1000);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	gamesDrawEngineObjPtr->gotoxy(13, 15);
	temp = "As you are a great cookie lover";
	flag = false;
	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	gamesDrawEngineObjPtr->gotoxy(13, 16);
	temp = "You Immediately head out to the dungeon";
	flag = false;
	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	
	c = 0;
	while (!c)
	{
		keyPress(&c);
	}
	createFirst_2Level();

}

void Level::createFirst_2Level()
{
	gunOn = false;
	untouchablesOn = false;
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{


			if (((x == 0 || x == width - 20) && y <= height - 5) || (y == 0 || y == height - 5) && x <= width - 20)
				level[x][y] = TILE_WALL;
			else
				level[x][y] = TILE_EMPTY;

			if (y == 10 && x <= width - 25)
				level[x][y] = TILE_WALL;
			if (y == 20 && x > 5  && x <= width-20)
				level[x][y] = TILE_WALL;
			if (x % 5 == 0 && x % 10 != 0 && y <= 8 && x <= width-20)
				level[x][y] = TILE_WALL;
			if ( x % 10 == 0 && y >= 2 && y <= 10 && x <=width-20)
				level[x][y] = TILE_WALL;



		}
	}
	gamesDrawEngineObjPtr->createSprite(SPRITE_PLAYER, 1);
	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

	player = new Character(this, gamesDrawEngineObjPtr, SPRITE_PLAYER,1,1,lives);

	addPlayer(player);
	player->move(0, 0);

	gamesDrawEngineObjPtr->gotoxy(57, 23);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << (char)219 << endl;


	gamesDrawEngineObjPtr->gotoxy(65, 7);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	cout << "Use W,A,S,D";

	gamesDrawEngineObjPtr->gotoxy(67, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 1);
	cout << "to move";

	gamesDrawEngineObjPtr->gotoxy(65, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Stairs: " << (char)219 << endl;
	//add lives, info

	gamesDrawEngineObjPtr->gotoxy(20, 28);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Make your way to the stairs";


	player->move(0, 0);

	char key = ' ';
	lastTime = 0;
	frameCount = 0;
	timerUpdateCount = 0;
	while (player->isAlive())
	{
		//keep looping as long as a key is not pressed
		while (!keyPress(&key))
		{
			
			timerUpdate();
		}

		if (player)
			player->keyPress(key);
		if (player->getX() == 57 && player->getY() == 23)
			break;
		if (key == 'k')
		{
			player->move(50, 23);
		}


	}
	if (player->isAlive())
	{
		lives = player->getLives();
		createFirst_3Level();
	}
	else
	{
		gamesDrawEngineObjPtr->gotoxy(80, 30);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << endl << "GAME OVER";
		Sleep(1000);
		gamesDrawEngineObjPtr->gotoxy(60, 27);
		createIntroLevel();
	}


}

void Level::createFirst_3Level()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			level[x][y] = TILE_EMPTY;
		}
	}
	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();

	gamesDrawEngineObjPtr->gotoxy(3, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "As Mr. CookieLover makes his way down the stairs";
	string temp = "As Mr. CookieLover makes his way down the stairs";
	bool flag = false;

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "Thud Thud Thud..";
	temp = "Kachink!";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "Thud Thud Thud..";
	temp = "\"Is that a lever sound?\"";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;


	gamesDrawEngineObjPtr->gotoxy(3, 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "Thud Thud Thud..";
	temp = "Screech Screech Thud Thud Thud..";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 14);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "He hears something, banging the walls with a rythmic sound";
	temp = "He hears something moving and banging the walls with a loud rythmic sound";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 16);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "THUD THUD THUD..";
	temp = "THUD THUD THUD..";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;


	gamesDrawEngineObjPtr->gotoxy(3, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "THUD THUD THUD..";
	temp = "As he reaches the end of the stairs, he can feel the vibrations through";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 19);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "THUD THUD THUD..";
	temp = "the walls.";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;


	Sleep(500);

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			level[x][y] = TILE_EMPTY;
			if (y == 0 && x <= 4)
				level[x][y] = TILE_WALL;
			
			if (x == 4 && y < height)
				level[x][y] = TILE_WALL;

			if (x == 1 && y < height && y>2)
				level[x][y] = TILE_WALL;
			if (x <= 5 && x >1 && y == height - 1)
				level[x][y] = TILE_WALL;

		}
	}
	level[0][1] = TILE_WALL;
	level[0][2] = TILE_WALL;
	level[1][2] = TILE_WALL;
	level[4][height - 2] = TILE_EMPTY;
	level[5][height - 1] = TILE_WALL;
	level[5][height - 2] = TILE_WALL;
	level[5][height - 3] = TILE_WALL;
	level[1][10] = TILE_EMPTY;
	level[1][9] = TILE_WALL;
	level[1][11] = TILE_WALL;
	level[0][10] = TILE_WALL;
	level[0][11] = TILE_WALL;
	level[1][12] = TILE_EMPTY;
	level[1][11] = TILE_EMPTY;
	level[1][13] = TILE_WALL;
	level[0][12] = TILE_WALL;

	level[1][13] = TILE_EMPTY; 
	level[1][14] = TILE_EMPTY;
	level[1][15] = TILE_EMPTY;
	level[1][16] = TILE_EMPTY;
	level[1][17] = TILE_EMPTY;

	level[0][13] = TILE_WALL;
	level[0][14] = TILE_WALL;
	level[0][15] = TILE_WALL;
	level[0][16] = TILE_WALL;
	level[0][17] = TILE_WALL;

	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 2);

	player = new Character(this, gamesDrawEngineObjPtr, SPRITE_PLAYER,1,1,lives);


	gamesDrawEngineObjPtr->gotoxy(45,5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "The Evil Monkeys have turned"; 
	gamesDrawEngineObjPtr->gotoxy(45, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "on the traps!";
	gamesDrawEngineObjPtr->gotoxy(45, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Make your way through";
	gamesDrawEngineObjPtr->gotoxy(45, 9);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "the dungeon";


	untouchablesOn = true;

	gamesDrawEngineObjPtr->createSprite(SPRITE_VERTICAL_UNTOUCHABLE, 219);
	
	
		VerticalUntouchable *tempUntouch = new VerticalUntouchable(this, gamesDrawEngineObjPtr,
			SPRITE_VERTICAL_UNTOUCHABLE, 2, 1, 0, 1);
		tempUntouch->goal = player;
		addUntouchables((Sprite *)tempUntouch);

		tempUntouch = new VerticalUntouchable(this, gamesDrawEngineObjPtr,
			SPRITE_VERTICAL_UNTOUCHABLE, 3, height-2, 0, -1);
		tempUntouch->goal = player;
		addUntouchables((Sprite *)tempUntouch);

		player->move(0, 0);

		gamesDrawEngineObjPtr->gotoxy(4, height-2);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
		cout << (char)219 << endl;


		char key = ' ';
		lastTime = 0;
		frameCount = 0;
		timerUpdateCount = 0;
		while (player->isAlive())
		{
			//keep looping as long as a key is not pressed
			while (!keyPress(&key))
			{
				timerUpdate();
			}

			if (player)
				player->keyPress(key);
			if (player->getX() == 4 && player->getY() == height-2)
				break;
			if (key == 'k')
				goto cheat;


		}
		if (player->isAlive())
		{

		cheat:
			lives = player->getLives();
			clearUntouchables();
			createFirst_4Level();


		}

		else
		{
			gamesDrawEngineObjPtr->gotoxy(80, 30);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
			cout << endl << "GAME OVER";
			Sleep(1000);
			gamesDrawEngineObjPtr->gotoxy(60, 27);
			createIntroLevel();
		}

	
}

void Level::createFirst_4Level()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			level[x][y] = TILE_EMPTY;
		}
	}
	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();
	gunOn = false;

	gamesDrawEngineObjPtr->gotoxy(34, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "Evil Monkey -> $";

	gamesDrawEngineObjPtr->gotoxy(20, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	//cout << "As Mr. CookieLover makes his way down the stairs";
	string temp = "Screech Screech";
	bool flag = false;

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(20, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	temp = "You hear the screeching sounds made by Evil Monkeys!";
	flag = false;

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(20, 20);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	temp = "Oh shit! There seems to be atleast, 10 Evil Monkeys!";
	flag = false;

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	Sleep(500);

	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{


			if (((x == 0 || x == width - 20) && y <= height - 5) || (y == 0 || y == height - 5) && x <= width - 20)
				level[x][y] = TILE_WALL;
			else
				level[x][y] = TILE_EMPTY;

		}
	}
	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();
	gamesDrawEngineObjPtr->createSprite(SPRITE_ENEMY, '$');
	gamesDrawEngineObjPtr->createSprite(SPRITE_FIREBALL, '*');

	player = new Character(this, gamesDrawEngineObjPtr, SPRITE_PLAYER,1,1,lives);
	player->move(1, 1);

	Enemy *tempEnemy;
	for (int i = 3; i < 24; i++)
	{
		tempEnemy = new Enemy(this, gamesDrawEngineObjPtr, SPRITE_ENEMY, 58, i);

		tempEnemy->addGoal(player);

		//enemy is a sprite
		addNPC((Sprite *)tempEnemy);
	}


	gamesDrawEngineObjPtr->gotoxy(40, 18);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << (char)201;

	gamesDrawEngineObjPtr->gotoxy(5, 27);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "Quickly pick up the gun!";

	gamesDrawEngineObjPtr->gotoxy(5, 29);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	cout << "They are getting closer!";

	gamesDrawEngineObjPtr->gotoxy(62, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "Gun : " << (char)201;

	player->move(0, 0);
	char key = ' ';
	lastTime = 0;
	frameCount = 0;
	timerUpdateCount = 0;
	while (player->isAlive())
	{
		//keep looping as long as a key is not pressed
		while (!keyPress(&key))
		{
			timerUpdate();
		}

		if (player)
			player->keyPress(key);
		if (player->getX() == 40 && player->getY() == 18)
		{
			gunOn = true;
			gamesDrawEngineObjPtr->gotoxy(5, 27);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "                         ";
			
			gamesDrawEngineObjPtr->gotoxy(5, 29);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "                           ";

			Sleep(500);
			gamesDrawEngineObjPtr->gotoxy(5, 27);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "Kill them all!";

			

			gamesDrawEngineObjPtr->gotoxy(63, 7);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "Press Space";
			gamesDrawEngineObjPtr->gotoxy(63, 8);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << "to shoot";
			
		}
		if (npc.empty())
		{

			gamesDrawEngineObjPtr->gotoxy(58, 23);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << (char)219;

			gamesDrawEngineObjPtr->gotoxy(5, 27);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "                ";

			gamesDrawEngineObjPtr->gotoxy(5, 27);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "Get to the stairs";

		}

		if (player->getX() == 58 && player->getY() == 23 && npc.empty())
			break;
		if (key == 'k')
			goto cheat1;

	}
	if (player->isAlive())
	{
	cheat1:
		lives = player->getLives();
		clearNPC();
		createSecondLevel();

	}

	else
	{
		gamesDrawEngineObjPtr->gotoxy(80, 30);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << endl << "GAME OVER";
		Sleep(1000);
		gamesDrawEngineObjPtr->gotoxy(60, 27);
		createIntroLevel();
	}

}

void Level::createSecondLevel()
{

	
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{


			if (((x == 0 || x == width - 20) && y <= height - 5) || (y == 0 || y == height - 5) && x <= width - 20)
				level[x][y] = TILE_WALL;
			else
				level[x][y] = TILE_EMPTY;

			if (y == 10 && x <= width-20)
				level[x][y] = TILE_WALL;
			

		}
	}

	

	

	gamesDrawEngineObjPtr->createSprite(SPRITE_PLAYER, 1);
	gamesDrawEngineObjPtr->createSprite(SPRITE_VERTICAL_UNTOUCHABLE, 219);

	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),2);

	player = new Character(this, gamesDrawEngineObjPtr, SPRITE_PLAYER,1,1,lives);
	


	untouchablesOn = true;
	addPlayer(player);
	addVerticalUntouchables();

	gamesDrawEngineObjPtr->gotoxy(59, 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << (char)219;

	//add lives, info
	


	player->move(0, 0);
	char key = ' ';
	lastTime = 0;
	frameCount = 0;
	timerUpdateCount = 0;
	while (key != 'q' && player->isAlive())
	{
		//keep looping as long as a key is not pressed
		while (!keyPress(&key))
		{
			timerUpdate();
		}

		if (player)
			player->keyPress(key);
		if (player->getX() == 59 && player->getY() == 5)
			break;
		if (key == 'k')
			player->move(50, 0);


	}
	if (player->isAlive())
	{
		lives = player->getLives();
		createLastLevel();
	}
	else
	{
		gamesDrawEngineObjPtr->gotoxy(80, 30);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << endl << "GAME OVER";
		Sleep(1000);
		gamesDrawEngineObjPtr->gotoxy(60, 27);
		createIntroLevel();
	}

}



//defeat the evil monkeys!
void Level::createLastLevel()
{
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			int random = rand() % 100;

			if (random < 90 || (x < 3 && y < 3) || (x > width-20) || (y > height -5))
				level[x][y] = TILE_EMPTY;
			else
				level[x][y] = TILE_WALL;

			if (((x == 0 || x == width - 20) && y <= height - 5) || (y == 0 || y == height - 5) && x <= width - 20)
				level[x][y] = TILE_WALL;

		}
	}
	level[59][23] = TILE_EMPTY;
	gamesDrawEngineObjPtr->createSprite(SPRITE_PLAYER, 1);
	gamesDrawEngineObjPtr->createSprite(SPRITE_ENEMY, '$');
	gamesDrawEngineObjPtr->createSprite(SPRITE_FIREBALL, '*');

	gamesDrawEngineObjPtr->setMap(level);
	gamesDrawEngineObjPtr->drawBackground();

	player = new Character(this, gamesDrawEngineObjPtr, SPRITE_PLAYER,1,1,lives);

	addPlayer(player);
	addEnemies(3);

	player->move(0, 0);
	char key = ' ';
	lastTime = 0;
	frameCount = 0;
	while (true)
	{
		//keep looping as long as a key is not pressed
		while (!keyPress(&key))
		{
			timerUpdate();
		}

		if (player)
			player->keyPress(key);
		if (npc.empty())
		{
			gamesDrawEngineObjPtr->gotoxy(59, 23);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
			cout << (char)219;

			gamesDrawEngineObjPtr->gotoxy(63, 10);
			SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
			cout << "Get to the stairs";
		}
		if (player->getX() == 59 && player->getY() == 23 && npc.empty())
		{
			break;
		}
		if (key == 'k')
			goto cheat3;
		if (key == 'q')
		{
			break;
		}
	}
	if (player->isAlive())
	{
	cheat3:
		lives = player->getLives();
		clearUntouchables();
		clearNPC();
		createOutroLevel();
	}
	else
	{
		gamesDrawEngineObjPtr->gotoxy(80, 30);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << endl << "GAME OVER";
		Sleep(1000);
		gamesDrawEngineObjPtr->gotoxy(60, 27);
		createIntroLevel();
	}

}

void Level::createOutroLevel(void)
{	
	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			level[x][y] = TILE_EMPTY;
		}
	}
	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();

	gamesDrawEngineObjPtr->gotoxy(3, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "As Mr. CookieLover makes his way down the stairs";
	string temp = "Mr. CookieLover reaches the last room in the dungeon";
	bool flag = false;

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "Thud Thud Thud..";
	temp = "But he cannot find the cookie!";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "Thud Thud Thud..";

	temp = "Suddenly, he hears footsteps behind him";
	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;


	gamesDrawEngineObjPtr->gotoxy(3, 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "Thud Thud Thud..";
	temp = "Clip Clop Clip Clop";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;








	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{


			if (((x == 0 || x == width - 20) && y <= height - 5) || (y == 0 || y == height - 5) && x <= width - 20)
				level[x][y] = TILE_WALL;
			else
				level[x][y] = TILE_EMPTY;

		}
	}

	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();



	gamesDrawEngineObjPtr->gotoxy(15, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "CookieTappa -> ";
	cout << (char)153;

	Sleep(500);
	gamesDrawEngineObjPtr->gotoxy(15, 1);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "                  ";


	gamesDrawEngineObjPtr->gotoxy(15, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "CookieTappa -> ";
	cout << (char)153;

	Sleep(500);
	gamesDrawEngineObjPtr->gotoxy(15, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "                  ";

	gamesDrawEngineObjPtr->gotoxy(15, 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "CookieTappa -> ";
	cout << (char)153;




	gamesDrawEngineObjPtr->gotoxy(13, 23);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
	cout << "Mr.CookieLover -> ";
	cout << (char)1;


	gamesDrawEngineObjPtr->gotoxy(3, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	//cout << "As Mr. CookieLover makes his way down the stairs";
	temp = " Mr. CookieLover, Are you looking for a cookie?";
    flag = false;

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 8);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	//cout << "Thud Thud Thud..";
	temp = "Too bad for you.. The Cake...";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	//cout << "Thud Thud Thud..";

	temp = "*cough cough* The Cookie is a Lie";
	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;


	gamesDrawEngineObjPtr->gotoxy(3, 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	//cout << "Thud Thud Thud..";
	temp = "Whistle!";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;



	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{


			if (((x == 1 || x == width - 21) && y <= height - 6) || (y == 1 || y == height - 6) && x <= width - 21)
			{
				gamesDrawEngineObjPtr->gotoxy(x, y);
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
				//cout << "Thud Thud Thud..";
				cout << "$";
				Sleep(30);
			}


		}
	}

	Sleep(1000);


	for (int x = 0; x < width; x++)
	{
		for (int y = 0; y < height; y++)
		{
			level[x][y] = TILE_EMPTY;
		}
	}
	gamesDrawEngineObjPtr->setMap(level);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	gamesDrawEngineObjPtr->drawBackground();

	gamesDrawEngineObjPtr->gotoxy(3, 6);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "As Mr. CookieLover makes his way down the stairs";
	temp = "THE END";
	flag = false;

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	Sleep(3000);
	/*
	gamesDrawEngineObjPtr->gotoxy(3, 10);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "Thud Thud Thud..";
	temp = "But why did the CookieTappa kill Mr. Cookie Lover?";

	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	gamesDrawEngineObjPtr->gotoxy(3, 12);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
	//cout << "Thud Thud Thud..";

	temp = "Find out in Cookie Dungeon 2";
	for (int i = 0; i < temp.length(); i++)
	{
		cout << temp[i];
		if (!flag)
			Sleep(100);

		if (keyPress(&c))
			flag = true;
	}
	flag = false;

	Sleep(1000);
*/
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
//	createIntroLevel();
	exit(0);
}

void Level::timerUpdate(void)
{
	double currentTime = timeGetTime() - lastTime;

	//timerUpdate function will run for 33.333 milliseconds
	if (currentTime < GAME_SPEED)
		return;



	update();

	frameCount++;

	lastTime = timeGetTime();

}



void Level::update(void)
{
	//call idleUpdate depending on whether it is a fireball or an enemy
	//npc = fireball + enemy
//	if (!npc.empty())
//	{
	timerUpdateCount++;
	gamesDrawEngineObjPtr->gotoxy(63, 2);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	cout << "Lives: ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << player->getLives();




	if (gunOn)
	{

		for (Iter = npc.begin(); Iter != npc.end();)
		{
			(*Iter)->idleUpdate();


			if ((*Iter)->isAlive() == false)
			{
				Sprite* temp;
				temp = *Iter;
				Iter = npc.erase(Iter);
				delete temp;
			}
			else
			{
				++Iter;
			}
		}
	}
	if (untouchablesOn)
	{

		if (timerUpdateCount == 1)
		{

			for (Iter = untouchables.begin(); Iter != untouchables.end(); Iter++)
			{
				(*Iter)->idleUpdate();
			}
			timerUpdateCount = 0;
		}
		//	}
	}
	if (!player->isAlive())
	{
		gamesDrawEngineObjPtr->gotoxy(80, 30);
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << endl << "GAME OVER";
		Sleep(1000);
	
		createIntroLevel();
	}

}

void Level::addPlayer(Character *p)
{
	player = p;
}


void Level::addEnemies(int num)
{
	int i = num;
	while (i > 0)
	{
		int xpos = (int)((float(rand() % 100) / 100)* (width - 21) + 1);
		int ypos = (int)((float(rand() % 100) / 100) * (height - 6) + 1);

		if (level[xpos][ypos] != TILE_WALL)
		{
			Enemy *temp = new Enemy(this, gamesDrawEngineObjPtr, SPRITE_ENEMY, (float)xpos, (float)ypos);

			temp->addGoal(player);

			//enemy is a sprite
			addNPC((Sprite *)temp);

			i--;

		}
	}
}

void Level::addVerticalUntouchables()
{	
	int y;
	for (int x = 4; x < 44; x += 2)
	{
		if (x % 4 == 0)
			y = 1;
		else
			y = 9;
		int y_dir;
		if (y == 9)
			y_dir = -1;
		else
			y_dir = 1;
		VerticalUntouchable *temp = new VerticalUntouchable(this, gamesDrawEngineObjPtr,
			SPRITE_VERTICAL_UNTOUCHABLE, (float)x, (float)y, 0, y_dir);
		temp->goal = player;
		addUntouchables((Sprite *)temp);
		
	}
}

void Level::addNPC(Sprite *spr)
{
	npc.push_back(spr);

}

void Level::clearNPC()
{
	npc.erase(npc.begin(), npc.end());
}

void Level::addUntouchables(Sprite *spr)
{
	untouchables.push_back(spr);
}

void Level::clearUntouchables()
{
	untouchables.erase(untouchables.begin(), untouchables.end());
}


