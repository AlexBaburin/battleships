#pragma once
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <SDL_image.h>
#include <math.h>
#include <SDL_TTF.h>
#include <SDL_Mixer.h>
#include "gameplay.h"

void visuals_menu();
void visuals_game_start(SDL_Renderer* renderer, SDL_Event event, bool& quit, int& gamestate);
int visuals_settings(SDL_Renderer* renderer, SDL_Event event, bool& quit, int& gamestate, Mix_Music* fon);
void visuals_manual(SDL_Renderer* renderer, SDL_Event event, bool& quit, int& gamestate, int(*player_field)[10]);
void visuals_game(SDL_Renderer* renderer, SDL_Event event, bool& quit, int& gamestate, int(*player_field)[10], int(*enemy_field)[10], int mode);
SDL_Texture* get_text_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font);