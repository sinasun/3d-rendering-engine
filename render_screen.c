#include "render_screen.h"

int createScreen() {
  SDL_Window *screen = NULL;
  SDL_Surface *surfaceScreen = NULL;

  if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
    printf("Unable to initialize SDL!! error: %s", SDL_GetError());
    return -1;
  }

  int width = 840;
  int height = 680;

  screen = SDL_CreateWindow("3D Rendering Engine", SDL_WINDOWPOS_CENTERED,
                            SDL_WINDOWPOS_CENTERED, width, height,
                            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_VULKAN);

  if (!screen) {
    printf("Unable to create SDL window error: %s", SDL_GetError());
    return -1;
  }

  // free resources
  handleInputs(screen);

  //SDL_FreeSurface(surfaceScreen);
  SDL_DestroyWindow(screen);
  SDL_Quit();

  return 0;
}

int handleInputs(SDL_Window * screen) {
  bool run = true;
  const unsigned delay = 20;
  SDL_Event event;
  SDL_Renderer *renderer = NULL;

  while (run) {
    while (SDL_PollEvent(&event) != 0) {
      switch (event.type) {
        case SDL_QUIT:
          printf("SDL quit\n");
          run = false;
          return -1;
          break;

        case SDL_WINDOWEVENT:
          // handel window resize
          break;
      }
    }

    drawPoints(renderer, screen, 200,100);
  }

  return 0;
}

void drawPoints(SDL_Renderer *renderer, SDL_Window *screen, int pointX, int pointY) {
  //define a rectangle
  SDL_Rect rectangle;

  rectangle.x= pointX;
  rectangle.y = pointY;
  rectangle.h = 60;
  rectangle.w = 60;

  renderer = SDL_CreateRenderer(screen, -1, SDL_RENDERER_ACCELERATED);
   SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
  
  // clear the renderer
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 225, 225, 225, SDL_ALPHA_OPAQUE);

  //SDL_RenderDrawLine(renderer, 5, 4, 100, 120);

  SDL_RenderDrawRect(renderer, &rectangle);

  // display the drawing
  SDL_RenderPresent(renderer);
}
