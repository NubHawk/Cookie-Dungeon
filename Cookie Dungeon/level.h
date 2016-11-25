#ifndef LEVEL_H
#define LEVEL_H

#include "drawEngine.h"
#include <list>

using std::list;

enum{
	SPRITE_PLAYER,
	SPRITE_ENEMY,
	SPRITE_FIREBALL,
	SPRITE_VERTICAL_UNTOUCHABLE
};

enum{
	TILE_EMPTY,
	TILE_WALL
};

class Character;



class Level
{
public:
	Level(DrawEngine *de, int width = 80, int height = 30);
	~Level();


	friend class Sprite;
	void update(void);
	bool keyPress(char *c);

	void addPlayer(Character *p);

	void timerUpdate(void);

	void createIntroLevel(void);
	void createFirstLevel(void);
	void createFirst_2Level(void);
	void createFirst_3Level(void);
	void createFirst_4Level(void);

	void createSecondLevel(void);

	void createLastLevel(void);
	void createOutroLevel(void);
	char **level;


	//-----------------------//
	void addEnemies(int num);
	void addNPC(Sprite *spr);
	void clearNPC();
	void addVerticalUntouchables();
	
	void addHorizontalUntouchables();
	void addUntouchables(Sprite *spr);
	void clearUntouchables();

	list <Sprite *> npc;
	list <Sprite *>::iterator Iter;

	list <Sprite *> untouchables;
	
	int lives;

	//Sprite* p;

	double lastTime;
	double frameCount;
	Character *player;
	int timerUpdateCount;
	bool gunOn;
	bool untouchablesOn;
	

private:
	int width;
	int height;
	char c;
	

	DrawEngine *gamesDrawEngineObjPtr;
	

};





#endif