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
#include <locale.h>


int main(int argc, char** argv)
{
	setlocale(LC_ALL, "Russian");

	srand(time(NULL));
	visuals_menu();

	return 0;
}