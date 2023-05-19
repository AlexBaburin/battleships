#include "visuals.h"
#include <SDL.h>
#include <stdlib.h>
#include <iostream>
#include <SDL_image.h>
#include <math.h>
#include <SDL_TTF.h>
#include <SDL_Mixer.h>
#include "gameplay.h"
#include <fstream>

void visuals_game_start(SDL_Renderer* renderer, SDL_Event event, bool& quit, int& gamestate)
{
	SDL_Surface* decision_image = IMG_Load("decision.bmp");
	SDL_Texture* decision = SDL_CreateTextureFromSurface(renderer, decision_image);
	SDL_FreeSurface(decision_image);
	SDL_Rect auto_button = { 425, 208, 128, 64 };
	SDL_Rect manual_button = { 167, 208, 128, 64 };
	SDL_Rect screen = { 0, 0, 720, 480 };

	while (SDL_PollEvent(&event))
	{
		if (event.type == SDL_QUIT)
		{
			quit = true;
			gamestate = 0;
		}

		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && event.button.x >= auto_button.x &&
			event.button.x <= auto_button.x + auto_button.w && event.button.y >= auto_button.y && event.button.y <= auto_button.y + auto_button.h)
		{
			gamestate = 3;
		}

		if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && event.button.x >= manual_button.x &&
			event.button.x <= manual_button.x + manual_button.w && event.button.y >= manual_button.y && event.button.y <= manual_button.y + manual_button.h)
		{
			gamestate = 4;
		}
	}

	SDL_RenderCopy(renderer, decision, NULL, &screen);
	SDL_RenderPresent(renderer);
	SDL_DestroyTexture(decision);
}

int visuals_settings(SDL_Renderer* renderer, SDL_Event event, bool& quit, int& gamestate, Mix_Music* fon)
{
	char score[100];

	std::ifstream f;
	f.open("score.txt");

	int num;
	f >> num;
	f.close();
	_itoa_s(num, score, 10);

	TTF_Init();
	TTF_Font* my_font = TTF_OpenFont("Text.ttf", 100);
	SDL_Texture* score_text = get_text_texture(renderer, score, my_font);

	SDL_Surface* settings_image = IMG_Load("settings_menu.bmp");
	SDL_Texture* settings = SDL_CreateTextureFromSurface(renderer, settings_image);
	SDL_FreeSurface(settings_image);

	SDL_Rect mus_1 = {168, 248, 128, 62};
	SDL_Rect mus_2 = { 297, 248, 128, 62 };
	SDL_Rect mus_3 = { 426, 248, 128, 62 };

	SDL_Rect mode_1 = { 168, 91, 128, 62 };
	SDL_Rect mode_2 = { 297, 91, 128, 62 };
	SDL_Rect mode_0 = { 426, 91, 128, 62 };

	SDL_Rect score_pos = { 288, 388, 119, 44 };

	SDL_Rect screen = { 0, 0, 720, 480 };

	bool exit = false;
	int mode = 0;
	
	while (!exit)
	{
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
				exit = true;
				gamestate = 0;
			}

			if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_e))
			{
				exit = true;
				gamestate = 0;
			}

			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			{
				if (event.button.x >= mus_1.x && event.button.x <= mus_1.x + mus_1.w && event.button.y >= mus_1.y && event.button.y <= mus_1.y + mus_1.h)
				{
					fon = Mix_LoadMUS("bg_1.mp3");
					Mix_PlayMusic(fon, -1);
				}
				if (event.button.x >= mus_2.x && event.button.x <= mus_2.x + mus_2.w && event.button.y >= mus_2.y && event.button.y <= mus_2.y + mus_2.h)
				{
					fon = Mix_LoadMUS("bg_2.mp3");
					Mix_PlayMusic(fon, -1);
				}
				if (event.button.x >= mus_3.x && event.button.x <= mus_3.x + mus_3.w && event.button.y >= mus_3.y && event.button.y <= mus_3.y + mus_3.h)
				{
					fon = Mix_LoadMUS("bg_3.mp3");
					Mix_PlayMusic(fon, -1);
				}
				if (event.button.x >= mode_1.x && event.button.x <= mode_1.x + mode_1.w && event.button.y >= mode_1.y && event.button.y <= mode_1.y + mode_1.h)
				{
					mode = 1;
				}
				if (event.button.x >= mode_2.x && event.button.x <= mode_2.x + mode_2.w && event.button.y >= mode_2.y && event.button.y <= mode_2.y + mode_2.h)
				{
					mode = 2;
				}
				if (event.button.x >= mode_0.x && event.button.x <= mode_0.x + mode_0.w && event.button.y >= mode_0.y && event.button.y <= mode_0.y + mode_0.h)
				{
					mode = 0;
				}
			}
		}
		SDL_RenderCopy(renderer, settings, NULL, &screen);
		SDL_RenderCopy(renderer, score_text, NULL, &score_pos);


		SDL_RenderPresent(renderer);
	}
	return mode;
}

void visuals_manual(SDL_Renderer* renderer, SDL_Event event, bool& quit, int& gamestate, int(*player_field)[10])
{
	SDL_Surface* manual_image = IMG_Load("manual.bmp");
	SDL_Texture* manual = SDL_CreateTextureFromSurface(renderer, manual_image);
	SDL_FreeSurface(manual_image);

	SDL_Surface* ship_image = IMG_Load("ship.bmp");
	SDL_Texture* ship = SDL_CreateTextureFromSurface(renderer, ship_image);
	SDL_FreeSurface(ship_image);

	SDL_Surface* button_image = IMG_Load("start_button.bmp");
	SDL_Texture* start_button = SDL_CreateTextureFromSurface(renderer, button_image);
	SDL_FreeSurface(button_image);

	SDL_Rect screen = { 0, 0, 720, 480 };
	SDL_Rect ship4 = { 473, 55, 157, 40 };
	SDL_Rect ship4_1 = {473, 55, 41, 41 };
	SDL_Rect ship4_2 = { 512, 55, 41, 41 };
	SDL_Rect ship4_3 = { 551, 55, 41, 41 };
	SDL_Rect ship4_4 = { 590, 55, 41, 41 };

	SDL_Rect ship3_1 = { 473, 98, 118, 40 };
	SDL_Rect ship3_1_1 = {473, 98, 41, 41 };
	SDL_Rect ship3_1_2 = { 512, 98, 41, 41 };
	SDL_Rect ship3_1_3 = { 551, 98, 41, 41 };
	SDL_Rect ship3_2 = { 473, 141, 118, 40 };
	SDL_Rect ship3_2_1 = {473, 141, 41, 41 };
	SDL_Rect ship3_2_2 = { 512, 141, 41, 41 };
	SDL_Rect ship3_2_3 = { 551, 141, 41, 41 };

	SDL_Rect ship2_1 = {473, 184, 79, 40};
	SDL_Rect ship2_1_1 = { 473, 184, 41, 41 };
	SDL_Rect ship2_1_2 = { 512, 184, 41, 41 };
	SDL_Rect ship2_2 = {473, 227, 79, 40};
	SDL_Rect ship2_2_1 = { 473, 227, 41, 41 };
	SDL_Rect ship2_2_2 = { 512, 227, 41, 41 };
	SDL_Rect ship2_3 = {473, 270, 79, 40};
	SDL_Rect ship2_3_1 = { 473, 270, 41, 41 };
	SDL_Rect ship2_3_2 = { 512, 270, 41, 41 };
	
	SDL_Rect ship1_1 = {473, 313, 41, 41 };
	SDL_Rect ship1_2 = { 518, 313, 41, 41 };
	SDL_Rect ship1_3 = { 563, 313, 41, 41 };
	SDL_Rect ship1_4 = { 608, 313, 41, 41 };;

	SDL_Rect button_place = { 525, 415, 116, 37 };

	bool hold = false, exit = false, placed1_1 = false, placed1_2 = false, placed1_3 = false, placed1_4 = false, placed2_1 = false, placed2_2 = false, placed2_3 = false,
		placed3_1 = false, placed3_2 = false, placed4 = false;
	bool hold1_1 = false, hold1_2 = false, hold1_3 = false, hold1_4 = false, hold2_1 = false, hold2_2 = false, hold2_3 = false,
		hold3_1 = false, hold3_2 = false, hold4 = false;

	int turn = 0; //0 - horiz, 1 - vert
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			player_field[i][j] = 0;

	while (!exit)
	{
		while (SDL_PollEvent(&event))
		{

			if (event.type == SDL_QUIT)
			{
				quit = true;
				exit = true;
				gamestate = 0;
			}

			if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_e))
			{
				if (turn == 0)
					turn = 1;
				else
					turn = 0;
			}

			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT)
			{
				if (hold)
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
					{
						if (event.button.x >= (59 + 40 * j) && event.button.x <= (99 + 40 * j) && event.button.y >= (55 + 40 * i) && event.button.y <= (95 + 40 * i))
						{
							if (hold1_1 || hold1_2 || hold1_3 || hold1_4)
							if (check_one(i, j, player_field))
							{
								if (hold1_1)
								{
									ship1_1.w = 41;
									ship1_1.h = 41;
									ship1_1.x = 59 + 40 * j;
									ship1_1.y = 55 + 40 * i;
									hold = false;
									placed1_1 = true;
									hold1_1 = false;
								}
								if (hold1_2)
								{
									ship1_2.w = 41;
									ship1_2.h = 41;
									ship1_2.x = 59 + 40 * j;
									ship1_2.y = 55 + 40 * i;
									hold = false;
									placed1_2 = true;
									hold1_2 = false;
								}
								if (hold1_3)
								{
									ship1_3.w = 41;
									ship1_3.h = 41;
									ship1_3.x = 59 + 40 * j;
									ship1_3.y = 55 + 40 * i;
									hold = false;
									placed1_3 = true;
									hold1_3 = false;
								}
								if (hold1_4)
								{
									ship1_4.w = 41;
									ship1_4.h = 41;
									ship1_4.x = 59 + 40 * j;
									ship1_4.y = 55 + 40 * i;
									hold = false;
									placed1_4 = true;
									hold1_4 = false;
								}
							}
							if (hold2_1 || hold2_2 || hold2_3)
							if (check_two(i, j, player_field, turn))
							{
								if (hold2_1)
								{
									if (!turn)
									{
										ship2_1_1.w = 41;
										ship2_1_1.h = 41;
										ship2_1_1.x = 59 + 40 * j;
										ship2_1_1.y = 55 + 40 * i;
										ship2_1_2.w = 41;
										ship2_1_2.h = 41;
										ship2_1_2.x = 59 + 40 * (j+1);
										ship2_1_2.y = 55 + 40 * i;
									}
									else
									{
										ship2_1_1.w = 41;
										ship2_1_1.h = 41;
										ship2_1_1.x = 59 + 40 * j;
										ship2_1_1.y = 55 + 40 * i;
										ship2_1_2.w = 41;
										ship2_1_2.h = 41;
										ship2_1_2.x = 59 + 40 * j;
										ship2_1_2.y = 55 + 40 * (i+1);
									}
									hold = false;
									placed2_1 = true;
									hold2_1 = false;
								}
								if (hold2_2)
								{
									if (!turn)
									{
										ship2_2_1.w = 41;
										ship2_2_1.h = 41;
										ship2_2_1.x = 59 + 40 * j;
										ship2_2_1.y = 55 + 40 * i;
										ship2_2_2.w = 41;
										ship2_2_2.h = 41;
										ship2_2_2.x = 59 + 40 * (j + 1);
										ship2_2_2.y = 55 + 40 * i;
									}
									else
									{
										ship2_2_1.w = 41;
										ship2_2_1.h = 41;
										ship2_2_1.x = 59 + 40 * j;
										ship2_2_1.y = 55 + 40 * i;
										ship2_2_2.w = 41;
										ship2_2_2.h = 41;
										ship2_2_2.x = 59 + 40 * j;
										ship2_2_2.y = 55 + 40 * (i + 1);
									}
									hold = false;
									placed2_2 = true;
									hold2_2 = false;
								}
								if (hold2_3)
								{
									if (!turn)
									{
										ship2_3_1.w = 41;
										ship2_3_1.h = 41;
										ship2_3_1.x = 59 + 40 * j;
										ship2_3_1.y = 55 + 40 * i;
										ship2_3_2.w = 41;
										ship2_3_2.h = 41;
										ship2_3_2.x = 59 + 40 * (j + 1);
										ship2_3_2.y = 55 + 40 * i;
									}
									else
									{
										ship2_3_1.w = 41;
										ship2_3_1.h = 41;
										ship2_3_1.x = 59 + 40 * j;
										ship2_3_1.y = 55 + 40 * i;
										ship2_3_2.w = 41;
										ship2_3_2.h = 41;
										ship2_3_2.x = 59 + 40 * j;
										ship2_3_2.y = 55 + 40 * (i + 1);
									}
									hold = false;
									placed2_3 = true;
									hold2_3 = false;
								}
							}
							if (hold3_1 || hold3_2)
								if (check_three(i, j, player_field, turn))
								{
									if (hold3_1)
									{
										if (!turn)
										{
											ship3_1_1.w = 41;
											ship3_1_1.h = 41;
											ship3_1_1.x = 59 + 40 * j;
											ship3_1_1.y = 55 + 40 * i;
											ship3_1_2.w = 41;
											ship3_1_2.h = 41;
											ship3_1_2.x = 59 + 40 * (j + 1);
											ship3_1_2.y = 55 + 40 * i;
											ship3_1_3.w = 41;
											ship3_1_3.h = 41;
											ship3_1_3.x = 59 + 40 * (j + 2);
											ship3_1_3.y = 55 + 40 * i;
										}
										else
										{
											ship3_1_1.w = 41;
											ship3_1_1.h = 41;
											ship3_1_1.x = 59 + 40 * j;
											ship3_1_1.y = 55 + 40 * i;
											ship3_1_2.w = 41;
											ship3_1_2.h = 41;
											ship3_1_2.x = 59 + 40 * j;
											ship3_1_2.y = 55 + 40 * (i + 1);
											ship3_1_3.w = 41;
											ship3_1_3.h = 41;
											ship3_1_3.x = 59 + 40 * j;
											ship3_1_3.y = 55 + 40 * (i + 2);
										}
										hold = false;
										placed3_1 = true;
										hold3_1 = false;
									}
									if (hold3_2)
									{
										if (!turn)
										{
											ship3_2_1.w = 41;
											ship3_2_1.h = 41;
											ship3_2_1.x = 59 + 40 * j;
											ship3_2_1.y = 55 + 40 * i;
											ship3_2_2.w = 41;
											ship3_2_2.h = 41;
											ship3_2_2.x = 59 + 40 * (j + 1);
											ship3_2_2.y = 55 + 40 * i;
											ship3_2_3.w = 41;
											ship3_2_3.h = 41;
											ship3_2_3.x = 59 + 40 * (j + 2);
											ship3_2_3.y = 55 + 40 * i;
										}
										else
										{
											ship3_2_1.w = 41;
											ship3_2_1.h = 41;
											ship3_2_1.x = 59 + 40 * j;
											ship3_2_1.y = 55 + 40 * i;
											ship3_2_2.w = 41;
											ship3_2_2.h = 41;
											ship3_2_2.x = 59 + 40 * j;
											ship3_2_2.y = 55 + 40 * (i + 1);
											ship3_2_3.w = 41;
											ship3_2_3.h = 41;
											ship3_2_3.x = 59 + 40 * j;
											ship3_2_3.y = 55 + 40 * (i + 2);
										}
										hold = false;
										placed3_2 = true;
										hold3_2 = false;
									}
								}
							if (hold4)
								if (check_four(i, j, player_field, turn))
								{
									if (!turn)
									{
										ship4_1.w = 41;
										ship4_1.h = 41;
										ship4_1.x = 59 + 40 * j;
										ship4_1.y = 55 + 40 * i;
										ship4_2.w = 41;
										ship4_2.h = 41;
										ship4_2.x = 59 + 40 * (j + 1);
										ship4_2.y = 55 + 40 * i;
										ship4_3.w = 41;
										ship4_3.h = 41;
										ship4_3.x = 59 + 40 * (j + 2);
										ship4_3.y = 55 + 40 * i;
										ship4_4.w = 41;
										ship4_4.h = 41;
										ship4_4.x = 59 + 40 * (j + 3);
										ship4_4.y = 55 + 40 * i;
									}
									else
									{
										ship4_1.w = 41;
										ship4_1.h = 41;
										ship4_1.x = 59 + 40 * j;
										ship4_1.y = 55 + 40 * i;
										ship4_2.w = 41;
										ship4_2.h = 41;
										ship4_2.x = 59 + 40 * j;
										ship4_2.y = 55 + 40 * (i + 1);
										ship4_3.w = 41;
										ship4_3.h = 41;
										ship4_3.x = 59 + 40 * j;
										ship4_3.y = 55 + 40 * (i + 2);
										ship4_4.w = 41;
										ship4_4.h = 41;
										ship4_4.x = 59 + 40 * j;
										ship4_4.y = 55 + 40 * (i + 3);
									}
									hold = false;
									placed4 = true;
									hold4 = false;
								}
						}
					}

				if (event.button.x >= ship1_1.x &&
					event.button.x <= ship1_1.x + ship1_1.w && event.button.y >= ship1_1.y && event.button.y <= ship1_1.y + ship1_1.h && !hold && !placed1_1)
				{
					hold = true;
					hold1_1 = true;

					ship1_1.w = 0;
					ship1_1.h = 0;
				}

				if (event.button.x >= ship1_2.x &&
					event.button.x <= ship1_2.x + ship1_2.w && event.button.y >= ship1_2.y && event.button.y <= ship1_2.y + ship1_2.h && !hold && !placed1_2)
				{
					hold = true;
					hold1_2 = true;

					ship1_2.w = 0;
					ship1_2.h = 0;
				}

				if (event.button.x >= ship1_3.x &&
					event.button.x <= ship1_3.x + ship1_3.w && event.button.y >= ship1_3.y && event.button.y <= ship1_3.y + ship1_3.h && !hold && !placed1_3)
				{
					hold = true;
					hold1_3 = true;

					ship1_3.w = 0;
					ship1_3.h = 0;
				}

				if (event.button.x >= ship1_4.x &&
					event.button.x <= ship1_4.x + ship1_4.w && event.button.y >= ship1_4.y && event.button.y <= ship1_4.y + ship1_4.h && !hold && !placed1_4)
				{
					hold = true;
					hold1_4 = true;

					ship1_4.w = 0;
					ship1_4.h = 0;
				}

				if (event.button.x >= ship2_1.x &&
					event.button.x <= ship2_1.x + ship2_1.w && event.button.y >= ship2_1.y && event.button.y <= ship2_1.y + ship2_1.h && !hold && !placed2_1)
				{
					hold = true;
					hold2_1 = true;

					ship2_1_1.w = 0;
					ship2_1_1.h = 0;
					ship2_1_2.w = 0;
					ship2_1_2.h = 0;
				}

				if (event.button.x >= ship2_2.x &&
					event.button.x <= ship2_2.x + ship2_2.w && event.button.y >= ship2_2.y && event.button.y <= ship2_2.y + ship2_2.h && !hold && !placed2_2)
				{
					hold = true;
					hold2_2 = true;

					ship2_2_1.w = 0;
					ship2_2_1.h = 0;
					ship2_2_2.w = 0;
					ship2_2_2.h = 0;
				}

				if (event.button.x >= ship2_3.x &&
					event.button.x <= ship2_3.x + ship2_3.w && event.button.y >= ship2_3.y && event.button.y <= ship2_3.y + ship2_3.h && !hold && !placed2_3)
				{
					hold = true;
					hold2_3 = true;

					ship2_3_1.w = 0;
					ship2_3_1.h = 0;
					ship2_3_2.w = 0;
					ship2_3_2.h = 0;
				}

				if (event.button.x >= ship3_1.x &&
					event.button.x <= ship3_1.x + ship3_1.w && event.button.y >= ship3_1.y && event.button.y <= ship3_1.y + ship3_1.h && !hold && !placed3_1)
				{
					hold = true;
					hold3_1 = true;

					ship3_1_1.w = 0;
					ship3_1_1.h = 0;
					ship3_1_2.w = 0;
					ship3_1_2.h = 0;
					ship3_1_3.w = 0;
					ship3_1_3.h = 0;
				}

				if (event.button.x >= ship3_2.x &&
					event.button.x <= ship3_2.x + ship3_2.w && event.button.y >= ship3_2.y && event.button.y <= ship3_2.y + ship3_2.h && !hold && !placed3_2)
				{
					hold = true;
					hold3_2 = true;

					ship3_2_1.w = 0;
					ship3_2_1.h = 0;
					ship3_2_2.w = 0;
					ship3_2_2.h = 0;
					ship3_2_3.w = 0;
					ship3_2_3.h = 0;
				}

				if (event.button.x >= ship4.x &&
					event.button.x <= ship4.x + ship4.w && event.button.y >= ship4.y && event.button.y <= ship4.y + ship4.h && !hold && !placed4)
				{
					hold = true;
					hold4 = true;

					ship4_1.w = 0;
					ship4_1.h = 0;
					ship4_2.w = 0;
					ship4_2.h = 0;
					ship4_3.w = 0;
					ship4_3.h = 0;
					ship4_4.w = 0;
					ship4_4.h = 0;
				}

				if (placed1_1 && placed1_2 && placed1_3 && placed1_4 && placed2_1 && placed2_2 && placed2_3 && placed3_1 && placed3_2 && placed4 && event.button.x >= button_place.x &&
					event.button.x <= button_place.x + button_place.w && event.button.y >= button_place.y && event.button.y <= button_place.y + button_place.h)
				{
					exit = true;
					gamestate = 5;
				}
			}

			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT)
			{
				hold = false;
				turn = 0;

				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
					{
						player_field[i][j] = 0;
					}

				ship4_1 = { 473, 55, 41, 41 };
				ship4_2 = { 512, 55, 41, 41 };
				ship4_3 = { 551, 55, 41, 41 };
				ship4_4 = { 590, 55, 41, 41 };

				ship3_1_1 = { 473, 98, 41, 41 };
				ship3_1_2 = { 512, 98, 41, 41 };
				ship3_1_3 = { 551, 98, 41, 41 };
				ship3_2_1 = { 473, 141, 41, 41 };
				ship3_2_2 = { 512, 141, 41, 41 };
				ship3_2_3 = { 551, 141, 41, 41 };

				ship2_1_1 = { 473, 184, 41, 41 };
				ship2_1_2 = { 512, 184, 41, 41 };
				ship2_2_1 = { 473, 227, 41, 41 };
				ship2_2_2 = { 512, 227, 41, 41 };
				ship2_3_1 = { 473, 270, 41, 41 };
				ship2_3_2 = { 512, 270, 41, 41 };

				ship1_1 = { 473, 313, 41, 41 };
				ship1_2 = { 518, 313, 41, 41 };
				ship1_3 = { 563, 313, 41, 41 };
				ship1_4 = { 608, 313, 41, 41 };

				placed1_1 = false; placed1_2 = false; placed1_3 = false; placed1_4 = false; placed2_1 = false; placed2_2 = false; placed2_3 = false;
				placed3_1 = false; placed3_2 = false; placed4 = false;

				hold1_1 = false; hold1_2 = false; hold1_3 = false; hold1_4 = false; hold2_1 = false; hold2_2 = false; hold2_3 = false;
				hold3_1 = false; hold3_2 = false; hold4 = false;
			}
		}

		SDL_RenderCopy(renderer, manual, NULL, &screen);

		if (placed1_1 && placed1_2 && placed1_3 && placed1_4 && placed2_1 && placed2_2 && placed2_3 && placed3_1 && placed3_2 && placed4)
		{
			SDL_RenderCopy(renderer, start_button, NULL, &button_place);
		}

		SDL_RenderCopy(renderer, ship, NULL, &ship1_1);
		SDL_RenderCopy(renderer, ship, NULL, &ship1_2);
		SDL_RenderCopy(renderer, ship, NULL, &ship1_3);
		SDL_RenderCopy(renderer, ship, NULL, &ship1_4);

		SDL_RenderCopy(renderer, ship, NULL, &ship4_1);
		SDL_RenderCopy(renderer, ship, NULL, &ship4_2);
		SDL_RenderCopy(renderer, ship, NULL, &ship4_3);
		SDL_RenderCopy(renderer, ship, NULL, &ship4_4);

		SDL_RenderCopy(renderer, ship, NULL, &ship3_1_1);
		SDL_RenderCopy(renderer, ship, NULL, &ship3_1_2);
		SDL_RenderCopy(renderer, ship, NULL, &ship3_1_3);
		SDL_RenderCopy(renderer, ship, NULL, &ship3_2_1);
		SDL_RenderCopy(renderer, ship, NULL, &ship3_2_2);
		SDL_RenderCopy(renderer, ship, NULL, &ship3_2_3);

		SDL_RenderCopy(renderer, ship, NULL, &ship2_1_1);
		SDL_RenderCopy(renderer, ship, NULL, &ship2_1_2);
		SDL_RenderCopy(renderer, ship, NULL, &ship2_2_1);
		SDL_RenderCopy(renderer, ship, NULL, &ship2_2_2);
		SDL_RenderCopy(renderer, ship, NULL, &ship2_3_1);
		SDL_RenderCopy(renderer, ship, NULL, &ship2_3_2);

		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(manual);
	SDL_DestroyTexture(start_button);
	SDL_DestroyTexture(ship);
}

SDL_Texture* get_text_texture(SDL_Renderer*& renderer, char* text, TTF_Font* font)
{
	SDL_Surface* textSurface = NULL;
	SDL_Color fore_color = { 0,0,0 };
	SDL_Color back_color = { 255, 255, 255 };
	textSurface = TTF_RenderText_Shaded(font, text, fore_color, back_color);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textSurface);
	SDL_FreeSurface(textSurface);
	return texture;
}

void visuals_game(SDL_Renderer* renderer, SDL_Event event, bool& quit, int& gamestate, int(*player_field)[10], int(*enemy_field)[10], int mode)
{
	char score[100], *move;
	const char* aah = "";
	move = (char*)aah;
	_itoa_s(0, score, 10);

	TTF_Init();
	TTF_Font* my_font = TTF_OpenFont("Text.ttf", 75);
	SDL_Texture* score_text = get_text_texture(renderer, score, my_font);
	SDL_Texture* move_text = get_text_texture(renderer, move, my_font);

	SDL_Surface* game_image = IMG_Load("game.bmp");
	SDL_Texture* game = SDL_CreateTextureFromSurface(renderer, game_image);
	SDL_FreeSurface(game_image);

	SDL_Surface* miss_image = IMG_Load("miss.bmp");
	SDL_Texture* miss= SDL_CreateTextureFromSurface(renderer, miss_image);
	SDL_FreeSurface(miss_image);

	SDL_Surface* ship_image = IMG_Load("ship.bmp");
	SDL_Texture* ship = SDL_CreateTextureFromSurface(renderer, ship_image);
	SDL_FreeSurface(ship_image);

	SDL_Surface* hit_ship_image = IMG_Load("hit_ship.bmp");
	SDL_Texture* hit_ship = SDL_CreateTextureFromSurface(renderer, hit_ship_image);
	SDL_FreeSurface(hit_ship_image);

	SDL_Surface* sunk_ship_image = IMG_Load("sunk_ship.bmp");
	SDL_Texture* sunk_ship = SDL_CreateTextureFromSurface(renderer, sunk_ship_image);
	SDL_FreeSurface(sunk_ship_image);

	SDL_Surface* victory_image = IMG_Load("victory.bmp");
	SDL_Texture* victory = SDL_CreateTextureFromSurface(renderer, victory_image);
	SDL_FreeSurface(victory_image);
	
	SDL_Surface* loss_image = IMG_Load("loss.bmp");
	SDL_Texture* loss = SDL_CreateTextureFromSurface(renderer, loss_image);
	SDL_FreeSurface(loss_image);

	SDL_Surface* flag_image = IMG_Load("flag.bmp");
	SDL_Texture* flag = SDL_CreateTextureFromSurface(renderer, flag_image);
	SDL_FreeSurface(flag_image);

	SDL_Rect coord = { 0,0,0,0 };
	SDL_Rect screen = { 0, 0, 720, 480 };
	SDL_Rect score_pos = { 365, 413, 27, 27 }; // w = 85
	SDL_Rect move_pos = { 298, 366, 128, 34 };
	SDL_Rect win_pos = { 298, 366, 200, 34 };


	bool exit = false, first, game_over = false;
	if (mode == 0)
	{
		mode = rand() % 2 + 1;
	}
	if (mode == 1)
		first = false;
	else
		first = true;

	int prev_i = -1, prev_j = -1, prev_ii = -1, prev_jj = -1, k = 0, combo = 0, int_score = 0, p_alive_count = 0, e_alive_count = 0, flags[10][10];

	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			flags[i][j] = 0;

	while (!exit) // field state: 0 - epmpty, 1 - ship, 2 - hit, 3 - sunk, -1 - miss
	{
		while (SDL_PollEvent(&event))
		{
			_itoa_s(int_score, score, 10);
			score_text = get_text_texture(renderer, score, my_font);
			if (int_score >= 100)
				score_pos.w = 85;

			if (event.type == SDL_QUIT)
			{
				quit = true;
				exit = true;
				gamestate = 0;
			}

			if (first)
			{
				SDL_Delay(200);
				first = false;
				int is_hit = opponent(player_field, first, prev_i, prev_ii, prev_j, prev_jj,k);
				if (is_hit)
				{
					const char* idk = "ENEMY: HIT";
					move = (char*)idk;
				}
				else
				{
					const char* idc = "ENEMY: MISS";
					move = (char*)idc;
				}
			}

			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_RIGHT && !first && !game_over)
			{
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
					{
						coord = { 396 + 30 * j, 62 + 30 * i, 31, 31 };
						if (event.button.x >= coord.x && event.button.x <= coord.x + coord.w - 1 && event.button.y >= coord.y && event.button.y <= coord.y + coord.h - 1 &&
							(enemy_field[i][j] == 1 || enemy_field[i][j] == 0))
						{
							if (flags[i][j] == 0)
								flags[i][j] = 1;
							else
								flags[i][j] = 0;
						}
					}
			}

			if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && !first && !game_over)
			{
				for (int i = 0; i < 10; i++)
					for (int j = 0; j < 10; j++)
					{
						coord = { 396 + 30 * j, 62 + 30 * i, 31, 31 };
						if (event.button.x >= coord.x && event.button.x <= coord.x + coord.w - 1 && event.button.y >= coord.y && event.button.y <= coord.y + coord.h - 1 && 
							(enemy_field[i][j] == 1 || enemy_field[i][j] == 0))
						{
							first = true;
							if (enemy_field[i][j] == 1)
							{
								enemy_field[i][j] = 2;
								first = false;
								combo++;
								int_score += combo * 100;
								const char* hate_chars = u8"YOU: HIT";
								move = (char*)hate_chars;
							}
							if (enemy_field[i][j] == 0)
							{
								enemy_field[i][j] = -1;
								combo = 0;
								const char* god_why = u8"YOU: MISS";
								move = (char*)god_why;
							}
							break;
						}
					}
			}
			if ((event.type == SDL_KEYDOWN) && (event.key.keysym.sym == SDLK_e))
			{
				exit = true;
				gamestate = 0;
			}
		}

		move_text = get_text_texture(renderer, move, my_font);
		SDL_RenderCopy(renderer, game, NULL, &screen);
		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if (destroyed_check(i, j, player_field))
				{
					const char* just_why = "ENEMY: KILL";
					move = (char*)just_why;
				}
				if (destroyed_check(i, j, enemy_field))
				{
					const char* just_please = "YOU: KILL";
					move = (char*)just_please;
				}
				
				if (flags[i][j] == 1)
				{
					coord = { 396 + 30 * j, 62 + 30 * i, 31, 31 };
					SDL_RenderCopy(renderer, flag, NULL, &coord);
				}

				if (enemy_field[i][j] == 1 && game_over)
				{
					coord = { 396 + 30 * j, 62 + 30 * i, 31, 31 };
					SDL_RenderCopy(renderer, ship, NULL, &coord);
				}


				if (player_field[i][j] == 1)
				{
					coord = { 58 + 30 * j, 62 + 30 * i, 31, 31};
					SDL_RenderCopy(renderer, ship, NULL, &coord);
				}
				if (player_field[i][j] == 2)
				{
					coord = { 58 + 30 * j, 62 + 30 * i, 31, 31 };
					SDL_RenderCopy(renderer, hit_ship, NULL, &coord);
				}
				if (player_field[i][j] == 3)
				{
					coord = { 58 + 30 * j, 62 + 30 * i, 31, 31 };
					SDL_RenderCopy(renderer, sunk_ship, NULL, &coord);
				}
				if (player_field[i][j] == -1)
				{
					coord = { 58 + 30 * j, 62 + 30 * i, 31, 31 };
					SDL_RenderCopy(renderer, miss, NULL, &coord);
				}
				
				if (enemy_field[i][j] == 2)
				{
					coord = { 396 + 30 * j, 62 + 30 * i, 31, 31 };
					SDL_RenderCopy(renderer, hit_ship, NULL, &coord);
				}
				if (enemy_field[i][j] == 3)
				{
					coord = { 396 + 30 * j, 62 + 30 * i, 31, 31 };
					SDL_RenderCopy(renderer, sunk_ship, NULL, &coord);
				}
				if (enemy_field[i][j] == -1)
				{
					coord = { 396 + 30 * j, 62 + 30 * i, 31, 31 };
					SDL_RenderCopy(renderer, miss, NULL, &coord);
				}

				if (player_field[i][j] == 1)
					p_alive_count++;
				if (enemy_field[i][j] == 1)
					e_alive_count++;
			}
		}

		SDL_RenderCopy(renderer, score_text, NULL, &score_pos);
		SDL_RenderCopy(renderer, move_text, NULL, &move_pos);

		if (p_alive_count == 0)
		{
			SDL_RenderCopy(renderer, loss, NULL, &win_pos);
			game_over = true;
		}
		if (e_alive_count == 0)
		{
			SDL_RenderCopy(renderer, victory, NULL, &win_pos);
			game_over = true;
		}

		p_alive_count = 0;
		e_alive_count = 0;

		
		SDL_RenderPresent(renderer);
	}
	SDL_DestroyTexture(ship);
	SDL_DestroyTexture(flag);
	SDL_DestroyTexture(game);
	SDL_DestroyTexture(miss);
	SDL_DestroyTexture(score_text);
	SDL_DestroyTexture(move_text);
	SDL_DestroyTexture(sunk_ship);
	SDL_DestroyTexture(hit_ship);
	SDL_DestroyTexture(victory);
	SDL_DestroyTexture(loss);

	std::ifstream f;
	int max;
	f.open("score.txt");
	f >> max;
	max = (int_score > max) ? int_score : max;
	f.close();

	std::ofstream file;
	file.open("score.txt");
	file << max;
	file.close();
}

void visuals_menu() //gamestates: 0 - main menu, 1 - start menu, 2 - settings, 3 - auto mode, 4 -manual mode, 5 -game
{
	int gamestate = 0;

	Mix_Init(0);
	Mix_OpenAudio(22050, MIX_DEFAULT_FORMAT, 2, 1024);
	Mix_VolumeMusic(30);
	Mix_Music* fon = NULL;
	fon = Mix_LoadMUS("bg_1.mp3");
	Mix_PlayMusic(fon, -1);

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow("battleships",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
		720, 480, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

	SDL_Surface* start_image = IMG_Load("start.bmp");
	SDL_Texture* start = SDL_CreateTextureFromSurface(renderer, start_image);
	SDL_FreeSurface(start_image);
	SDL_Rect start_button = { 100, 240, 128, 64 };

	SDL_Surface* title_image = IMG_Load("title.bmp");
	SDL_Texture* title = SDL_CreateTextureFromSurface(renderer, title_image);
	SDL_FreeSurface(title_image);
	SDL_Rect title_screen = { 720 / 2 - 128, 100, 256, 64 };

	SDL_Surface* settings_image = IMG_Load("settings.bmp");
	SDL_Texture* settings = SDL_CreateTextureFromSurface(renderer, settings_image);
	SDL_FreeSurface(settings_image);
	SDL_Rect settings_button = { 720 - 128 - 100, 240, 128, 64 };

	bool quit = false;
	SDL_Event event;

	int mode = 0; // 0 - random, 1 - player first, 2 - enemy first
	int player_field[10][10];
	int enemy_field[10][10];

	while (!quit)
	{
		switch (gamestate)
		{
		case 0:
		{
			SDL_SetRenderDrawColor(renderer, 110, 110, 110, 0);
			SDL_RenderClear(renderer);
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					quit = true;
				}

				if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && event.button.x >= start_button.x &&
					event.button.x <= start_button.x + start_button.w && event.button.y >= start_button.y && event.button.y <= start_button.y + start_button.h)
				{
					gamestate = 1;
				}

				if (event.type == SDL_MOUSEBUTTONDOWN && event.button.button == SDL_BUTTON_LEFT && event.button.x >= settings_button.x &&
					event.button.x <= settings_button.x + settings_button.w && event.button.y >= settings_button.y &&
					event.button.y <= settings_button.y + settings_button.h)
				{
					gamestate = 2;
				}
			}

			SDL_RenderCopy(renderer, start, NULL, &start_button);
			SDL_RenderCopy(renderer, settings, NULL, &settings_button);
			SDL_RenderCopy(renderer, title, NULL, &title_screen);
			SDL_RenderPresent(renderer);
		}
		break;
		case 1:
		{
			visuals_game_start(renderer, event, quit, gamestate);
		}
		break;
		case 2:
		{
			mode = visuals_settings(renderer, event, quit, gamestate, fon);
		}
		break;
		case 3:
		{
			auto_generation(player_field);
			/*
			gamestate = 0;
			for (int i = 0; i < 10; i++)
			{
				for (int j = 0; j < 10; j++)
				{
					std::cout << arr[i][j];
				}
				std::cout << std::endl;
			}
			*/
			gamestate = 5;
		}
		break;
		case 4:
		{
			visuals_manual(renderer, event, quit, gamestate, player_field);
		}
		break;
		case 5:
		{
			auto_generation(enemy_field);
			visuals_game(renderer, event, quit, gamestate, player_field, enemy_field, mode);
		}
		break;
		default:
		{
			quit = true;
		}
		}
	}

	SDL_DestroyTexture(start);
	SDL_DestroyTexture(title);
	SDL_DestroyTexture(settings);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}