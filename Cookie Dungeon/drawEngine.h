#ifndef DRAW_ENGINE_H
#define DRAW_ENGINE_H

class DrawEngine
{
public:
	DrawEngine(int xSize = 80, int ySize = 30);
	~DrawEngine();

	int createSprite(int index, char c);
	void deleteSprite(int index);

	void eraseSprite(int posx, int posy);
	void drawSprite(int index, int posx, int posy);

	void createBackgroundTile(int index, char c);

	void setMap(char **c);
	void drawBackground(void);

	void gotoxy(int x, int y);

protected:
	char **map;
	int screenWidth, screenHeight;
	char spriteImage[16];
	char tileImage[16];


private:
	
	void cursorVisibility(bool visibility);
	

};











#endif