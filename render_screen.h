#pragma once
#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL_vulkan.h>
#include <vulkan/vulkan.h>

int createScreen();
void drawPoints(SDL_Renderer *renderer, SDL_Window *screen, int pointX,
                int pointY);
int handleInputs(SDL_Window *screen);
