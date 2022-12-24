#include <iostream>

#define SDL_MAIN_HANDLED

#include "../Dependencies/include/SDL2/SDL.h"
#include "../Dependencies/include/SDL2/SDL_image.h"

#include "include/global.h"
#include "include/entity.h"
#include "include/Vector2.h"


#define WIDTH 680
#define HEIGHT 480

SDL_Renderer** rendererPointer;
SDL_Renderer*** rendererPtrPtr = &rendererPointer;

int main(int argc, char** argv) {

	bool quit = false;
	SDL_Event event;

	SDL_Init(SDL_INIT_VIDEO);

	IMG_Init(IMG_INIT_PNG);

	SDL_Window* window = SDL_CreateWindow("Hello", SDL_WINDOWPOS_UNDEFINED,
			SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	rendererPointer = &renderer;

	Entity egg(5, 5, 100, 100); 

	while (!quit){
		SDL_RenderClear(renderer);

		egg.render();

		SDL_PollEvent(&event);
		switch (event.type){
			case SDL_QUIT:
				quit = true;
				break;
			case SDL_KEYDOWN:
				switch (event.key.keysym.sym){
					case SDLK_DOWN:
					egg.getPosition() -> x += 10;
				}
		}
		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
