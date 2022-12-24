#include <iostream>

#define SDL_MAIN_HANDLED

#include "../Dependencies/include/SDL2/SDL.h"
#include "../Dependencies/include/SDL2/SDL_image.h"

#include "include/global.h"
#include "include/entity.h"
#include "include/Vector2.h"


#define WIDTH 680
#define HEIGHT 480

SDL_Renderer *renderer;

int main(int argc, char** argv) {

	SDL_Init(SDL_INIT_VIDEO);
	IMG_Init(IMG_INIT_PNG);

    SDL_Window *window;
    SDL_CreateWindowAndRenderer(WIDTH, HEIGHT, 0, &window, &renderer);

	bool quit = false;
	SDL_Event event;

	Entity egg(5, 5, 100, 100); 
    egg.loadTexture("res/egg.png");

	while (!quit){
		SDL_RenderClear(renderer);

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

		egg.render();

		SDL_RenderPresent(renderer);
	}

	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();

	return 0;
}
