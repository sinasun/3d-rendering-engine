#include "render_screen.h"

int createScreen() {
  SDL_Window *screen = NULL;
  SDL_Surface *surfaceScreen = NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Unable to initialize SDL!! error: %s", SDL_GetError());
    return -1;
  }

  screen = SDL_CreateWindow("3D Rendering Engine", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, 840, 680,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

  if (!screen) {
    printf("Unable to create SDL window error: %s", SDL_GetError());
    return -1;
  }

  surfaceScreen = SDL_GetWindowSurface(screen);  // create surface for rendering

  if (!surfaceScreen) {
    printf("Unable to get the surface error: %s", SDL_GetError());
    return -1;
  }

  SDL_FillRect(surfaceScreen, NULL, SDL_MapRGB(surfaceScreen->format, 0, 0, 0));

  SDL_UpdateWindowSurface(screen);

  SDL_Event event;
  bool run = true;

  const unsigned delay = 20;  // timer
  
  while (run) {
    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
        
        case SDL_QUIT:

          printf("sdl quit\n");
          run = false;
          break;
      }
    }

    SDL_Delay(delay);
  }

  // free resources
  SDL_DestroyWindow(screen);
  SDL_Quit();

  return 0;
}
