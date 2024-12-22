
#include <SDL2/SDL.h>
#include <SDL_audio.h>
#include <SDL_stdinc.h>
#include <stdio.h>
int main() {
  SDL_AudioSpec want, have;
  SDL_memset(&want, 0, sizeof(want));
  want = {.freq = 44100};
}
