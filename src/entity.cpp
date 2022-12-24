#include "../Dependencies/include/SDL2/SDL.h"
#include "../Dependencies/include/SDL2/SDL_image.h"
#include "include/global.h"

#include "include/Vector2.h"
#include "include/entity.h"

Entity::Entity(int p_x, int p_y, int p_width, int p_height) {
	texture = NULL;
	position = Vector2(p_x, p_y);
	dimension = Vector2(p_width, p_height);

	rect = {position.x, position.y, dimension.x, dimension.y};
}

Entity::~Entity() {
	SDL_DestroyTexture(texture);
}

void Entity::loadTexture(char* p_filePath){
	texture = IMG_LoadTexture(renderer, p_filePath);
	if (texture == NULL){
		std::cout << "Texture failed to load" << std::endl;
	}
}

Vector2* Entity::getPosition(){
	return &position;
}

void Entity::render() {
	rect = {position.x, position.y, dimension.x, dimension.y};
	
	SDL_RenderCopy(renderer, texture, NULL, &rect);
}
