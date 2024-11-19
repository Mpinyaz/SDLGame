
#include <SDL2/SDL.h>
#include <stdio.h>

int main() {
  if (SDL_Init(SDL_INIT_VIDEO) != 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }
  SDL_Quit();
  printf("SDL Initialized Successfully!\n");
  return 0;
}
