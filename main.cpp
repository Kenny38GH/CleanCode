#include <iostream>
#include "lib/ball.hpp"
#include "lib/render.hpp"

int main(int argc, char * argv[]){

	SDL_Window* window = NULL;

	if( SDL_Init( SDL_INIT_VIDEO ) < 0 ){
		printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
	} else {
		window = SDL_CreateWindow( "Bouncing Balls", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 500, 500, SDL_WINDOW_SHOWN|SDL_WINDOW_OPENGL);
		if( window == NULL ){
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );

		} else {

			SDL_GLContext glcont = SDL_GL_CreateContext(window);
            bool quit = false;
			Uint32 lastUpdate = SDL_GetTicks();
            SDL_Event e;

			std::list<Ball*> objects;

            while(!quit){

                Uint64 start = SDL_GetPerformanceCounter();

                while(SDL_PollEvent(&e) != 0){
					switch(e.type){
					case SDL_QUIT:
						quit=true;
						break;
					case SDL_MOUSEBUTTONDOWN: {
						int x;
						int y;
						SDL_GetMouseState(&x,&y);
						std::cout << x << ", " << y << std::endl;
						Ball* nb = new Ball(std::rand() % 40 + 20,
											 Vector((std::rand() % 100)/100.,(std::rand() % 100)/100.,(std::rand() % 100)/100.), 
											 Vector(x, y, 0));
						objects.push_front(nb);
						break;
						}
					default:
						break;
					}
                }

                Uint64 event = SDL_GetPerformanceCounter();

                /* PHYSIQUE LOOP */

				Uint32 current = SDL_GetTicks();
				float dT = (current - lastUpdate) / 1000.0f;
				for(Ball* physc : objects){
					//Movement update and collision check
					physc->collision();
					physc->update(dT);

				}
				lastUpdate = current;
                Uint64 phys = SDL_GetPerformanceCounter();


                /* RENDERING LOOP */

				initGL();

				for(Ball* rendc : objects){
					rendc->render();
				}
				SDL_GL_SwapWindow(window);

                Uint64 rend = SDL_GetPerformanceCounter();
				Uint64 end  = SDL_GetPerformanceCounter();

            }

			//Destroy context
			SDL_GL_DeleteContext(glcont);
		}
	}


	//Destroy window
	SDL_DestroyWindow( window );

	//Quit SDL subsystems
	SDL_Quit();

	return 0;
}
