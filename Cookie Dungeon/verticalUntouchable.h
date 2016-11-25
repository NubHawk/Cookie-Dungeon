#ifndef VERTICAL_UNTOUCHABLE_H
#define VERTICAL_UNTOUCHABLE_H

#include "sprite.h"




class VerticalUntouchable : public Sprite
{
public:
	VerticalUntouchable(Level *l, DrawEngine* de, int s_index, float x = 1, float y = 1,
		float xDir = 0, float yDir = 0, int i_lives=100);
	
	void timerUpdate(void);
	void idleUpdate(void);
	Character* goal;
	bool flag;
	double lastTime;
	
};


#endif