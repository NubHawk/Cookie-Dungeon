#include "drawEngine.h"
#include <windows.h>
#include <iostream>


using namespace std;


DrawEngine::DrawEngine(int xSize, int ySize)
{
	screenWidth = xSize;
	screenHeight = ySize;

	//set Cursor visibility to false
	cursorVisibility(false);
	//fullScreen(true);

	map = 0;
}

DrawEngine::~DrawEngine()
{
	//set cursor Visibility to true
	cursorVisibility(true);
	//fullScreen(false);
	gotoxy(0, screenHeight);
}

int DrawEngine::createSprite(int index, char c)
{
	if (index >= 0 && index < 16)
	{
		spriteImage[index] = c;
		return index;
	}

	return -1;
}

void DrawEngine::deleteSprite(int index)
{
	//no need
}

void DrawEngine::eraseSprite(int posx, int posy)
{
	gotoxy(posx, posy);
	cout << ' ';
}

void DrawEngine::drawSprite(int index, int posx, int posy)
{
	//goto correct location
	gotoxy(posx, posy);
	//draw the sprite
	cout << spriteImage[index];


}

void DrawEngine::setMap(char **data)
{
	map = data;
}
void DrawEngine::createBackgroundTile(int index, char c)
{
	if (index >= 0 && index < 16)
		tileImage[index] = c;
}
void DrawEngine::drawBackground(void)
{
	if (map)
	{
		for (int y = 0; y < screenHeight; y++)
		{
			gotoxy(0, y);
			for (int x = 0; x < screenWidth; x++)
			{
				
				cout << tileImage[map[x][y]];
			}
		}
	}
}

void DrawEngine::gotoxy(int x, int y)
{
	HANDLE output_handle;
	COORD pos;

	pos.X = x;
	pos.Y = y;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);


	SetConsoleCursorPosition(output_handle, pos);

}

void DrawEngine::cursorVisibility(bool visibility)
{
	HANDLE output_handle;

	CONSOLE_CURSOR_INFO cciInfo;
	cciInfo.bVisible = visibility;
	cciInfo.dwSize = 1;

	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo(output_handle, &cciInfo);
}


