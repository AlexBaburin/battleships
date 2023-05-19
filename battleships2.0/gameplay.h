#pragma once
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <SDL_image.h>
#include <math.h>
#include <SDL_TTF.h>
#include <SDL_Mixer.h>
#include <time.h>
#include "visuals.h"
#include "gameplay.h"

void auto_generation(int(*field)[10]);
bool check_one(int i, int j, int(*field)[10]);
bool check_two(int i, int j, int(*field)[10], int turn);
bool check_three(int i, int j, int(*field)[10], int turn);
bool check_four(int i, int j, int(*field)[10], int turn);
bool destroyed_check(int i, int j, int(*field)[10]);
int opponent(int(*field)[10], bool &first, int& prev_i, int& prev_ii, int& prev_j, int& prev_jj, int& k);