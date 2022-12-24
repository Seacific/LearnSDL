#pragma once

#include <iostream>

#include "../../Dependencies/include/SDL2/SDL.h"
#include "../../Dependencies/include/SDL2/SDL_image.h"
#include "Vector2.h"

class Entity {

private:
	Vector2 position;
	Vector2 dimension;

	SDL_Rect rect;

	int health;
	SDL_Texture* texture;
public:
	Entity(int p_x, int p_y, int p_width, int p_height);
	~Entity();
	int getHealth();
	Vector2* getPosition();
	void loadTexture(char* p_filePath);
	void render();
	SDL_Rect getRect();
};
