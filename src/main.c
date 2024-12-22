#include <SDL2/SDL.h>
#include <SDL_render.h>
#include <SDL_surface.h>
#include <SDL_timer.h>
#include <SDL_video.h>
#include <math.h>
#include <stdio.h>
#define WIDTH 640
#define HEIGHT 480

void DrawCircle(SDL_Renderer *render, int centerX, int centerY, int radius) {
  int x = radius;
  int y = 0;
  int decision = 1 - x;

  while (y <= x) {
    SDL_RenderDrawPoint(render, centerX + x, centerY + y);
    SDL_RenderDrawPoint(render, centerX + x, centerY - y);
    SDL_RenderDrawPoint(render, centerX - x, centerY + y);
    SDL_RenderDrawPoint(render, centerX - x, centerY - y);
    SDL_RenderDrawPoint(render, centerX + x, centerY + y);
    SDL_RenderDrawPoint(render, centerX + x, centerY - y);
    SDL_RenderDrawPoint(render, centerX - x, centerY + y);
    SDL_RenderDrawPoint(render, centerX - x, centerY - y);
    y++;

    if (decision <= 0) {
      decision += 2 * y * 1;
    } else {
      x--;
      decision += 2 * (y - x) + 1;
    }
  }
}

int main() {
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
    printf("SDL_Init Error: %s\n", SDL_GetError());
    return 1;
  }
  SDL_Window *window =
      SDL_CreateWindow("Hello SDL", SDL_WINDOWPOS_CENTERED,
                       SDL_WINDOWPOS_CENTERED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
  if (!window) {
    printf("Failed to create window: %s\n", SDL_GetError());
    SDL_Quit();
    return 1;
  }

  SDL_Renderer *renderer =
      SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);

  // Set draw color to white
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

  // Draw a circle at the center of the window with radius 100
  DrawCircle(renderer, 400, 300, 100);

  // Update screen
  SDL_RenderPresent(renderer);

  // Wait for 5 seconds
  SDL_Delay(5000);

  // Cleanup
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
  return 0;
}
