#include "gameplay.h"

void auto_generation(int(*field)[10])
{
	int ship, turn, k = 0; //turn = 1 - vertical, turn = 0 - horizontal
	bool flag = false;
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			field[i][j] = 0;

	while (k != 4) // 1-square ships
	{
		ship = rand() % 100;
		for (int i = 0; i < 10; i++)
		{
			if (flag)
			{
				flag = false;
				break;
			}
			for (int j = 0; j < 10; j++)
			{
				if (ship == (j + i * 10) && field[i][j] == 0)
				{
					if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0)
					{
						field[i][j] = 1;
						k++;
						flag = true;
						break;
					}
					if (i == 9 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0)
					{
						field[i][j] = 1;
						k++;
						flag = true;
						break;
					}
					if (i == 0 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j - 1] == 0)
					{
						field[i][j] = 1; k++;
						flag = true;
						break;
					}
					if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0)
					{
						field[i][j] = 1; k++;
						flag = true;
						break;
					}
					if (i != 0 && i != 9 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0)
					{
						field[i][j] = 1; k++;
						flag = true;
						break;
					}
					if (j != 0 && j != 9 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
						field[i + 1][j] == 0)
					{
						field[i][j] = 1; k++;
						flag = true;
						break;
					}
					if (j != 0 && j != 9 && i == 9 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
						field[i - 1][j] == 0)
					{
						field[i][j] = 1; k++;
						flag = true;
						break;
					}
					if (j == 9 && i == 9 && field[i][j-1]==0 && field[i-1][j]==0 && field[i-1][j-1]==0)
					{
						field[i][j] = 1; k++;
						flag = true;
						break;
					}
					if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
						&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0)
					{
						field[i][j] = 1; k++;
						flag = true;
						break;
					}
				}
			}
		}
	}

	k = 0;
	while (k != 3) // 2-square ships
	{
		ship = rand() % 100;
		turn = rand() % 2;
		for (int i = 0; i < 10; i++)
		{
			if (flag)
			{
				flag = false;
				break;
			}
			for (int j = 0; j < 10; j++)
			{
				if (j < 9 && ship == (j + i * 10) && field[i][j] == 0 && turn == 0 && field[i][j + 1] == 0) //horizontal
				{
					if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (i == 9 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i - 1][j + 2] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i != 9 && j == 8 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j < 8 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
						field[i + 1][j] == 0 && field[i][j + 2]==0 && field[i + 1][j + 2]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j < 8 && i == 9 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 2]==0 && field[i - 1][j + 2]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (i == 9 && j == 8 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (i == 0 && j == 8 && field[i][j-1]==0 && field[i+1][j-1]==0 && field[i+1][j]==0 && field[i+1][j+1]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
						&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
				}
				if (i < 9 && ship == (j + i * 10) && field[i][j] == 0 && turn == 1 && field[i + 1][j] == 0) //vertical
				{
					if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						flag = true;
						break;
					}
					if (i == 8 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i < 8 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i <8 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j - 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j != 9 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
						field[i + 1][j] == 0 && field[i + 2][j]==0 && field[i + 2][j + 1]==0 && field[i + 2][j - 1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j != 9 && i == 8 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
						field[i - 1][j] == 0 && field[i + 1][j]==0 && field[i + 1][j + 1]==0 && field[i + 2][j - 1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						flag = true;
						break;
					}
					if (i == 8 && j == 9 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j - 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (i == 0 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 2][j-1] == 0 && field[i + 2][j] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						flag = true;
						break;
					}
					if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
						&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						flag = true;
						break;
					}
				}
			}
		}
	}

	k = 0;
	while (k != 2) // 3-square ships
	{
		ship = rand() % 100;
		turn = rand() % 2;
		for (int i = 0; i < 10; i++)
		{
			if (flag)
			{
				flag = false;
				break;
			}
			for (int j = 0; j < 10; j++)
			{
				if (j < 8 && ship == (j + i * 10) && field[i][j] == 0 && turn == 0 && field[i][j + 1] == 0 && field[i][j + 2] == 0) //horizontal
				{
					if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0
						&& field[i][j+3] == 0 && field[i+1][j+3] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						flag = true;
						break;
					}
					if (i == 9 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && 
						field[i - 1][j + 2] == 0 && field[i][j+3] ==0 && field[i-1][j+3] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0 && field[i][j+3]==0 && field[i-1][j+3] == 0 &&
						field[i+1][j+3] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i != 9 && j == 7 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j+2]==0 && field[i+1][j+2] == 0 &&
						field[i-1][j+2]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j < 7 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
						field[i + 1][j] == 0 && field[i][j + 2]==0 && field[i + 1][j + 2]==0 && field[i][j+3] == 0 && field[i+1][j+3] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j < 7 && i == 9 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 2]==0 && field[i - 1][j + 2]==0 && field[i][j+3]==0 && field[i-1][j+3]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						flag = true;
						break;
					}
					if (i == 9 && j == 7 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i-1][j+2]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						flag = true;
						break;
					}
					if (i == 0 && j == 7 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j+2]==0 && 
						field[i+1][j+2]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						flag = true;
						break;
					}
					if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
						&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0 &&
						field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 && field[i - 1][j + 3] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						flag = true;
						break;
					}
				}
				if (i < 9 && ship == (j + i * 10) && field[i][j] == 0 && turn == 1 && field[i + 1][j] == 0 && field[i + 2][j]==0) //vertical
				{
					if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 &&
						field[i + 3][j] == 0 && field[i + 3][j + 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i+2][j] = 1;
						flag = true;
						break;
					}
					if (i == 7 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 &&
						field[i + 2][j + 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i < 7 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 3][j] == 0 && field[i + 3][j + 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i < 7 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j - 1] == 0 && field[i + 3][j] == 0 && field[i + 3][j - 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j != 9 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
						field[i + 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 3][j] == 0 && field[i + 3][j - 1] == 0 && 
						field[i + 3][j + 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j != 9 && i == 7 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
						field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 &&
						field[i+1][j+1]==0 && field[i+1][j-1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						flag = true;
						break;
					}
					if (i == 7 && j == 9 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i+2][j-1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						flag = true;
						break;
					}
					if (i == 0 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 2][j] == 0 && field[i+3][j]==0 && 
						field[i+3][j-1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						flag = true;
						break;
					}
					if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
						&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 &&
						field[i + 3][j] == 0 && field[i + 3][j + 1] == 0 && field[i + 3][j - 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						flag = true;
						break;
					}
				}
			}
		}
	}

	k = 0;
	while (k != 1) // 4-square ships
	{
		ship = rand() % 100;
		turn = rand() % 2;
		for (int i = 0; i < 10; i++)
		{
			if (flag)
			{
				flag = false;
				break;
			}
			for (int j = 0; j < 10; j++)
			{
				if (j < 7 && ship == (j + i * 10) && field[i][j] == 0 && turn == 0 && field[i][j + 1] == 0 && field[i][j + 2] == 0 && field[i][j + 3] == 0) //horizontal
				{
					if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0
						&& field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 && field[i][j+4]==0 && field[i+1][j+4==0])
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						field[i][j + 3] = 1;
						flag = true;
						break;
					}
					if (i == 9 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 &&
						field[i - 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i - 1][j + 3] == 0 && field[i][j+4]==0 && field[i-1][j+4]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						field[i][j + 3] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i - 1][j + 3] == 0 &&
						field[i + 1][j + 3] == 0 && field[i][j+4]==0 && field[i+1][j+4]==0 && field[i-1][j+4]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						field[i][j + 3] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i != 9 && j == 6 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 &&
						field[i - 1][j + 3] == 0 && field[i+1][j+2]==0 && field[i][j+2]==0 && field[i-1][j+2]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						field[i][j + 3] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j < 6 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
						field[i + 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 && field[i][j+4]==0 && 
						field[i+1][j+4]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						field[i][j + 3] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j < 6 && i == 9 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i - 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i - 1][j + 3] == 0 && field[i][j+4]==0 &&
						field[i-1][j+4]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						field[i][j + 3] = 1;
						flag = true;
						break;
					}
					if (i == 9 && j == 6 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i - 1][j + 2] == 0 &&
						field[i - 1][j + 3] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						field[i][j + 3] = 1;
						flag = true;
						break;
					}
					if (i == 0 && j == 6 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j + 2] == 0 &&
						field[i + 1][j + 2] == 0 && field[i+1][j+3]==0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						field[i][j + 3] = 1;
						flag = true;
						break;
					}
					if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
						&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0 &&
						field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 && field[i - 1][j + 3]==0 && field[i][j + 4] == 0 && field[i + 1][j + 4] == 0 && field[i - 1][j + 4] == 0)
					{
						field[i][j] = 1; k++;
						field[i][j + 1] = 1;
						field[i][j + 2] = 1;
						field[i][j + 3] = 1;
						flag = true;
						break;
					}
				}
				if (i < 9 && ship == (j + i * 10) && field[i][j] == 0 && turn == 1 && field[i + 1][j] == 0 && field[i + 2][j]==0 && field[i+3][j]==0) //vertical
				{
					if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 &&
						field[i + 3][j] == 0 && field[i + 3][j + 1] == 0 && field[i+4][j] == 0 && field[i+4][j+1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						field[i + 3][j] = 1;
						flag = true;
						break;
					}
					if (i == 6 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 &&
						field[i + 2][j + 1] == 0 && field[i+3][j+1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						field[i + 3][j] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i < 6 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 3][j] == 0 && field[i + 3][j + 1] == 0 &&
						field[i+4][j]==0 && field[i+4][j+1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						field[i + 3][j] = 1;
						flag = true;
						break;
					}
					if (i != 0 && i < 6 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
						field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j - 1] == 0 && field[i + 3][j] == 0 && field[i + 3][j - 1] == 0 && field[i+4][j]==0 && 
						field[i+4][j-1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						field[i + 3][j] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j != 9 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
						field[i + 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 3][j] == 0 && field[i + 3][j - 1] == 0 &&
						field[i + 3][j + 1]==0 && field[i+4][j]==0 && field[i+4][j-1]==0 && field[i+4][j+1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						field[i + 3][j] = 1;
						flag = true;
						break;
					}
					if (j != 0 && j != 9 && i == 6 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
						field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 &&
						field[i+3][j+1]==0 && field[i+3][j-1]==0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						field[i + 3][j] = 1;
						flag = true;
						break;
					}
					if (i == 6 && j == 9 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 2][j - 1] == 0 &&
						field[i+3][j-1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						field[i + 3][j] = 1;
						flag = true;
						break;
					}
					if (i == 0 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 2][j] == 0 && field[i + 3][j] == 0 &&
						field[i + 3][j - 1] == 0 && field[i+4][j]==0 && field[i+4][j-1]==0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						field[i + 3][j] = 1;
						flag = true;
						break;
					}
					if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
						&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 &&
						field[i + 3][j] == 0 && field[i + 3][j + 1] == 0 && field[i + 3][j - 1] == 0 && field[i + 4][j] == 0 && field[i + 4][j + 1] == 0 && field[i + 4][j - 1] == 0)
					{
						field[i][j] = 1; k++;
						field[i + 1][j] = 1;
						field[i + 2][j] = 1;
						field[i + 3][j] = 1;
						flag = true;
						break;
					}
				}
			}
		}
	}
}

bool check_one(int i, int j, int(*field)[10])
{
	if (field[i][j] == 0)
	{
		if (j == 9 && i == 9 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0)
		{
			field[i][j] = 1;
			return true;
		}
		if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0)
		{
			field[i][j] = 1;
			return true;
		}
		if (i == 9 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0)
		{
			field[i][j] = 1;
			return true;
		}
		if (i == 0 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j - 1] == 0)
		{
			field[i][j] = 1;
			return true;
		}
		if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0)
		{
			field[i][j] = 1;
			return true;
		}
		if (i != 0 && i != 9 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0)
		{
			field[i][j] = 1;
			return true;
		}
		if (j != 0 && j != 9 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
			field[i + 1][j] == 0)
		{
			field[i][j] = 1;
			return true;
		}
		if (j != 0 && j != 9 && i == 9 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
			field[i - 1][j] == 0)
		{
			field[i][j] = 1;
			return true;
		}
		if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
			&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0)
		{
			field[i][j] = 1;
			return true;
		}
	}
	return false;
}

bool check_two(int i, int j, int(*field)[10], int turn)
{
	if (j < 9 && turn == 0 && field[i][j + 1] == 0 && field[i][j] == 0) //horizontal
	{
		if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			return true;
		}
		if (i == 9 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i - 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			return true;
		}
		if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			return true;
		}
		if (i != 0 && i != 9 && j == 8 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			return true;
		}
		if (j != 0 && j < 8 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
			field[i + 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			return true;
		}
		if (j != 0 && j < 8 && i == 9 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i - 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			return true;
		}
		if (i == 9 && j == 8 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			return true;
		}
		if (i == 0 && j == 8 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			return true;
		}
		if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
			&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			return true;
		}
	}
	if (i < 9 && field[i][j] == 0 && turn == 1 && field[i + 1][j] == 0) //vertical
	{
		if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			return true;
		}
		if (i == 8 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			return true;
		}
		if (i != 0 && i < 8 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			return true;
		}
		if (i != 0 && i < 8 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			return true;
		}
		if (j != 0 && j != 9 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
			field[i + 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			return true;
		}
		if (j != 0 && j != 9 && i == 8 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
			field[i - 1][j] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			return true;
		}
		if (i == 8 && j == 9 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			return true;
		}
		if (i == 0 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 2][j] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			return true;
		}
		if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
			&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			return true;
		}
	}
	return false;
}

bool check_three(int i, int j, int(*field)[10], int turn)
{
	if (j < 8 && field[i][j] == 0 && turn == 0 && field[i][j + 1] == 0 && field[i][j + 2] == 0) //horizontal
	{
		if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0
			&& field[i][j + 3] == 0 && field[i + 1][j + 3] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			return true;
		}
		if (i == 9 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 &&
			field[i - 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i - 1][j + 3] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			return true;
		}
		if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i - 1][j + 3] == 0 &&
			field[i + 1][j + 3] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			return true;
		}
		if (i != 0 && i != 9 && j == 7 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 &&
			field[i - 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			return true;
		}
		if (j != 0 && j < 7 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
			field[i + 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i + 1][j + 3] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			return true;
		}
		if (j != 0 && j < 7 && i == 9 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i - 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i - 1][j + 3] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			return true;
		}
		if (i == 9 && j == 7 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i - 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			return true;
		}
		if (i == 0 && j == 7 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j + 2] == 0 &&
			field[i + 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			return true;
		}
		if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
			&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0 &&
			field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 && field[i - 1][j + 3] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			return true;
		}
	}
	if (i < 9 && field[i][j] == 0 && turn == 1 && field[i + 1][j] == 0 && field[i + 2][j] == 0) //vertical
	{
		if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 &&
			field[i + 3][j] == 0 && field[i + 3][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			return true;
		}
		if (i == 7 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 &&
			field[i + 2][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			return true;
		}
		if (i != 0 && i < 7 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 3][j] == 0 && field[i + 3][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			return true;
		}
		if (i != 0 && i < 7 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j - 1] == 0 && field[i + 3][j] == 0 && field[i + 3][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			return true;
		}
		if (j != 0 && j != 9 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
			field[i + 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 3][j] == 0 && field[i + 3][j - 1] == 0 && 
			field[i + 3][j + 1]==0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			return true;
		}
		if (j != 0 && j != 9 && i == 7 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
			field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 &&
			field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			return true;
		}
		if (i == 7 && j == 9 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 2][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			return true;
		}
		if (i == 0 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 2][j] == 0 && field[i + 3][j] == 0 &&
			field[i + 3][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			return true;
		}
		if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
			&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 &&
			field[i + 3][j] == 0 && field[i + 3][j + 1] == 0 && field[i + 3][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			return true;
		}
	}
	return false;
}

bool check_four(int i, int j, int(*field)[10], int turn)
{
	if (j < 7 && field[i][j] == 0 && turn == 0 && field[i][j + 1] == 0 && field[i][j + 2] == 0 && field[i][j + 3] == 0) //horizontal
	{
		if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0
			&& field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 && field[i][j + 4] == 0 && field[i + 1][j + 4 == 0])
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			field[i][j + 3] = 1;
			return true;
		}
		if (i == 9 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 &&
			field[i - 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i - 1][j + 3] == 0 && field[i][j + 4] == 0 && field[i - 1][j + 4] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			field[i][j + 3] = 1;
			return true;
		}
		if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i - 1][j + 3] == 0 &&
			field[i + 1][j + 3] == 0 && field[i][j + 4] == 0 && field[i + 1][j + 4] == 0 && field[i - 1][j + 4] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			field[i][j + 3] = 1;
			return true;
		}
		if (i != 0 && i != 9 && j == 6 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 &&
			field[i - 1][j + 3] == 0 && field[i + 1][j + 2] == 0 && field[i][j + 2] == 0 && field[i - 1][j + 2] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			field[i][j + 3] = 1;
			return true;
		}
		if (j != 0 && j < 6 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
			field[i + 1][j] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 && field[i][j + 4] == 0 &&
			field[i + 1][j + 4] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			field[i][j + 3] = 1;
			return true;
		}
		if (j != 0 && j < 6 && i == 9 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i - 1][j + 2] == 0 && field[i][j + 3] == 0 && field[i - 1][j + 3] == 0 && field[i][j + 4]==0 &&
			field[i - 1][j + 4]==0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			field[i][j + 3] = 1;
			return true;
		}
		if (i == 9 && j == 6 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i - 1][j + 2] == 0 &&
			field[i - 1][j + 3] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			field[i][j + 3] = 1;
			return true;
		}
		if (i == 0 && j == 6 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i][j + 2] == 0 &&
			field[i + 1][j + 2] == 0 && field[i + 1][j + 3] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			field[i][j + 3] = 1;
			return true;
		}
		if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
			&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i][j + 2] == 0 && field[i + 1][j + 2] == 0 && field[i - 1][j + 2] == 0 &&
			field[i][j + 3] == 0 && field[i + 1][j + 3] == 0 && field[i - 1][j + 3] == 0 && field[i][j + 4] == 0 && field[i + 1][j + 4] == 0 && field[i - 1][j + 4] == 0)
		{
			field[i][j] = 1;
			field[i][j + 1] = 1;
			field[i][j + 2] = 1;
			field[i][j + 3] = 1;
			return true;
		}
	}
	if (i < 9 && field[i][j] == 0 && turn == 1 && field[i + 1][j] == 0 && field[i + 2][j] == 0 && field[i + 3][j] == 0) //vertical
	{
		if (i == 0 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 &&
			field[i + 3][j] == 0 && field[i + 3][j + 1] == 0 && field[i + 4][j] == 0 && field[i + 4][j + 1] == 0)
		{
			field[i][j] = 1; 
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			field[i + 3][j] = 1;
			return true;
		}
		if (i == 6 && j == 0 && field[i][j + 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 && field[i + 1][j + 1] == 0 &&
			field[i + 2][j + 1] == 0 && field[i + 3][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			field[i + 3][j] = 1;
			return true;
		}
		if (i != 0 && i < 6 && j == 0 && field[i][j + 1] == 0 && field[i + 1][j + 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i][j + 2] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 3][j] == 0 && field[i + 3][j + 1] == 0 &&
			field[i + 4][j] == 0 && field[i + 4][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			field[i + 3][j] = 1;
			return true;
		}
		if (i != 0 && i < 6 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j] == 0 &&
			field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j - 1] == 0 && field[i + 3][j] == 0 && field[i + 3][j - 1] == 0 && field[i + 4][j] == 0 &&
			field[i + 4][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			field[i + 3][j] = 1;
			return true;
		}
		if (j != 0 && j != 9 && i == 0 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j + 1] == 0 &&
			field[i + 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 3][j] == 0 && field[i + 3][j - 1] == 0 &&
			field[i + 3][j + 1]==0 && field[i + 4][j] == 0 && field[i + 4][j - 1] == 0 && field[i + 4][j + 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			field[i + 3][j] = 1;
			return true;
		}
		if (j != 0 && j != 9 && i == 6 && field[i][j - 1] == 0 && field[i][j + 1] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 &&
			field[i - 1][j] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 &&
			field[i + 3][j + 1] == 0 && field[i + 3][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			field[i + 3][j] = 1;
			return true;
		}
		if (i == 6 && j == 9 && field[i][j - 1] == 0 && field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 2][j - 1] == 0 &&
			field[i + 3][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			field[i + 3][j] = 1;
			return true;
		}
		if (i == 0 && j == 9 && field[i][j - 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 2][j - 1] == 0 && field[i + 2][j] == 0 && field[i + 3][j] == 0 &&
			field[i + 3][j - 1] == 0 && field[i + 4][j] == 0 && field[i + 4][j - 1] == 0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			field[i + 3][j] = 1;
			return true;
		}
		if (field[i][j + 1] == 0 && field[i][j - 1] == 0 && field[i + 1][j + 1] == 0 && field[i + 1][j - 1] == 0 && field[i + 1][j] == 0
			&& field[i - 1][j] == 0 && field[i - 1][j - 1] == 0 && field[i - 1][j + 1] == 0 && field[i + 2][j] == 0 && field[i + 2][j + 1] == 0 && field[i + 2][j - 1] == 0 &&
			field[i + 3][j] == 0 && field[i + 3][j + 1] == 0 && field[i + 3][j - 1] == 0 && field[i + 4][j] == 0 && field[i + 4][j + 1] == 0 && field[i + 4][j - 1]==0)
		{
			field[i][j] = 1;
			field[i + 1][j] = 1;
			field[i + 2][j] = 1;
			field[i + 3][j] = 1;
			return true;
		}
	}
	return false;
}

bool destroyed_check(int i, int j, int(*field)[10])
{
	if (field[i][j] == 2)
	{
		//one
		if (j == 9 && i == 9 && field[i][j - 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0)
		{
			field[i][j] = 3;
			field[i][j - 1] = -1;
			field[i-1][j - 1] = -1;
			field[i-1][j] = -1;
			return true;
		}
		if (i == 0 && j == 0 && field[i][j + 1] <= 0 && field[i + 1][j] <= 0 && field[i + 1][j + 1] <= 0)
		{
			field[i][j] = 3;
			field[i][j + 1] = -1;
			field[i+1][j + 1] = -1;
			field[i+1][j] = -1;
			return true;
		}
		if (i == 9 && j == 0 && field[i][j + 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j + 1] <= 0)
		{
			field[i][j] = 3;
			field[i][j + 1] = -1;
			field[i-1][j + 1] = -1;
			field[i-1][j] = -1;
			return true;
		}
		if (i == 0 && j == 9 && field[i][j - 1] <= 0 && field[i + 1][j] <= 0 && field[i + 1][j - 1] <= 0)
		{
			field[i][j] = 3;
			field[i][j - 1] = -1;
			field[i+1][j - 1] = -1;
			field[i+1][j] = -1;
			return true;
		}
		if (i != 0 && i != 9 && j == 0 && field[i][j + 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] <= 0 &&
			field[i - 1][j] <= 0)
		{
			field[i][j] = 3;
			field[i][j + 1] = -1;
			field[i+1][j + 1] = -1;
			field[i-1][j + 1] = -1;
			field[i+1][j] = -1;
			field[i-1][j] = -1;
			return true;
		}
		if (i != 0 && i != 9 && j == 9 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j] <= 0 &&
			field[i - 1][j] <= 0)
		{
			field[i][j] = 3;
			field[i][j - 1] = -1;
			field[i + 1][j - 1] = -1;
			field[i - 1][j - 1] = -1;
			field[i + 1][j] = -1;
			field[i - 1][j] = -1;
			return true;
		}
		if (j != 0 && j != 9 && i == 0 && field[i][j - 1] <= 0 && field[i][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j + 1] <= 0 &&
			field[i + 1][j] <= 0)
		{
			field[i][j] = 3;
			field[i][j + 1] = -1;
			field[i][j - 1] = -1;
			field[i + 1][j + 1] = -1;
			field[i + 1][j - 1] = -1;
			field[i + 1][j] = -1;
			return true;
		}
		if (j != 0 && j != 9 && i == 9 && field[i][j - 1] <= 0 && field[i][j + 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 &&
			field[i - 1][j] <= 0)
		{
			field[i][j] = 3;
			field[i][j + 1] = -1;
			field[i][j - 1] = -1;
			field[i - 1][j + 1] = -1;
			field[i - 1][j - 1] = -1;
			field[i - 1][j] = -1;
			return true;
		}
		if (field[i][j + 1] <= 0 && field[i][j - 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] <= 0
			&& field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0)
		{
			field[i][j] = 3;
			field[i][j + 1] = -1;
			field[i][j - 1] = -1;
			field[i + 1][j + 1] = -1;
			field[i + 1][j - 1] = -1;
			field[i + 1][j] = -1;
			field[i - 1][j + 1] = -1;
			field[i - 1][j - 1] = -1;
			field[i - 1][j] = -1;
			return true;
		}

		//two
		if (j < 9 && field[i][j + 1] == 2 && field[i][j] == 2) //horizontal
		{
			if (i == 0 && j == 0 && field[i][j + 1] == 2 && field[i + 1][j] <= 0 && field[i + 1][j + 1] <= 0 && field[i][j + 2] <= 0 && field[i + 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j] = -1;
				return true;
			}
			if (i == 9 && j == 0 && field[i][j + 1] == 2 && field[i - 1][j] <= 0 && field[i - 1][j + 1] <= 0 && field[i][j + 2] <= 0 && field[i - 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j] = -1;
				return true;
			}
			if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 2 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] <= 0 &&
				field[i - 1][j] <= 0 && field[i][j + 2] <= 0 && field[i + 1][j + 2] <= 0 && field[i - 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j] = -1;
				return true;
			}
			if (i != 0 && i != 9 && j == 8 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j] <= 0 &&
				field[i - 1][j] <= 0 && field[i][j + 1] == 2 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j -1] = -1;
				field[i + 1][j -1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j] = -1;
				field[i - 1][j -1] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j] = -1;
				return true;
			}
			if (j != 0 && j < 8 && i == 0 && field[i][j - 1] <= 0 && field[i][j + 1] == 2 && field[i + 1][j - 1] <= 0 && field[i + 1][j + 1] <= 0 &&
				field[i + 1][j] <= 0 && field[i][j + 2] <= 0 && field[i + 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j - 1] = -1;
				field[i][j + 2] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				return true;
			}
			if (j != 0 && j < 8 && i == 9 && field[i][j - 1] <= 0 && field[i][j + 1] ==2 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 &&
				field[i - 1][j] <= 0 && field[i][j + 2] <= 0 && field[i - 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j - 1] = -1;
				field[i][j + 2] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j + 2] = -1;
				return true;
			}
			if (i == 9 && j == 8 && field[i][j - 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] =3;
				field[i][j - 1] = -1;
				field[i-1][j + 1] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j-1] = -1;
				return true;
			}
			if (i == 0 && j == 8 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] <= 0 && field[i + 1][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j] = -1;
				field[i + 1][j - 1] = -1;
				return true;
			}
			if (field[i][j + 1] == 2 && field[i][j - 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] <= 0
				&& field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i][j + 2] <= 0 && field[i + 1][j + 2] <= 0 && field[i - 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j - 1] = -1;
				field[i][j + 2] = -1;
				field[i + 1][j] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j + 2] = -1;
				return true;
			}
		}
		if (i < 9 && field[i][j] == 2 && field[i + 1][j] == 2) //vertical
		{
			if (i == 0 && j == 0 && field[i][j + 1] <= 0 && field[i + 1][j] == 2 && field[i + 1][j + 1] <= 0 && field[i + 2][j] <= 0 && field[i + 2][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 2][j] = -1;
				return true;
			}
			if (i == 8 && j == 0 && field[i][j + 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] == 2 && field[i + 1][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i -1][j + 1] = -1;
				field[i -1][j] = -1;
				return true;
			}
			if (i != 0 && i < 8 && j == 0 && field[i][j + 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] == 2 &&
				field[i - 1][j] <= 0 && field[i][j + 2] <= 0 && field[i + 2][j + 1] <= 0 && field[i + 2][j] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 2][j] = -1;
				field[i -1][j+1] = -1;
				field[i -1][j] = -1;
				return true;
			}
			if (i != 0 && i < 8 && j == 9 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j] == 2 &&
				field[i - 1][j] <= 0 && field[i + 2][j] <= 0 && field[i + 2][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 2][j] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				return true;
			}
			if (j != 0 && j != 9 && i == 0 && field[i][j - 1] <= 0 && field[i][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j + 1] <= 0 &&
				field[i + 1][j] == 2 && field[i + 2][j] <= 0 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i][j - 1] = -1;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 2][j - 1] = -1;
				return true;
			}
			if (j != 0 && j != 9 && i == 8 && field[i][j - 1] <= 0 && field[i][j + 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 &&
				field[i - 1][j] <= 0 && field[i + 1][j] == 2 && field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i][j - 1] = -1;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i -1][j] = -1;
				field[i -1][j + 1] = -1;
				field[i -1][j - 1] = -1;
				return true;
			}
			if (i == 8 && j == 9 && field[i][j - 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j - 1] = -1;
				return true;
			}
			if (i == 0 && j == 9 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 2][j - 1] <= 0 && field[i + 2][j] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j] = -1;
				field[i + 2][j - 1] = -1;
				return true;
			}
			if (field[i][j + 1] <= 0 && field[i][j - 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] == 2
				&& field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 2][j] <= 0 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i][j - 1] = -1;
				field[i][j + 1] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j - 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 2][j + 1] = -1;
				return true;
			}
		}
		//three
		if (j < 8 && field[i][j] == 2 && field[i][j + 1] == 2 && field[i][j + 2] == 2) //horizontal
		{
			if (i == 0 && j == 0 && field[i][j + 1] == 2 && field[i + 1][j] <= 0 && field[i + 1][j + 1] <= 0 && field[i][j + 2] == 2 && field[i + 1][j + 2] <= 0
				&& field[i][j + 3] <= 0 && field[i + 1][j + 3] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = -1;
				field[i + 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 3] = -1;
				return true;
			}
			if (i == 9 && j == 0 && field[i][j + 1] == 2 && field[i - 1][j] <= 0 && field[i - 1][j + 1] <= 0 && field[i][j + 2] == 2 &&
				field[i - 1][j + 2] <= 0 && field[i][j + 3] <= 0 && field[i - 1][j + 3] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 3] = -1;
				return true;
			}
			if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 2 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] <= 0 &&
				field[i - 1][j] <= 0 && field[i][j + 2] == 2 && field[i + 1][j + 2] <= 0 && field[i - 1][j + 2] <= 0 && field[i][j + 3] <= 0 && field[i - 1][j + 3] <= 0 &&
				field[i + 1][j + 3] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = -1;
				field[i + 1][j] = -1;
				field[i - 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i - 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				field[i - 1][j + 2] = -1;
				field[i + 1][j + 3] = -1;
				field[i - 1][j + 3] = -1;
				return true;
			}
			if (i != 0 && i != 9 && j == 7 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j] <= 0 &&
				field[i - 1][j] <= 0 && field[i][j + 1] == 2 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i][j + 2] == 2 && field[i + 1][j + 2] <= 0 &&
				field[i - 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j -1] = -1;
				field[i + 1][j] = -1;
				field[i - 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i - 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				field[i - 1][j + 2] = -1;
				field[i + 1][j -1] = -1;
				field[i - 1][j -1] = -1;
				return true;
			}
			if (j != 0 && j < 7 && i == 0 && field[i][j - 1] <= 0 && field[i][j + 1] == 2 && field[i + 1][j - 1] <= 0 && field[i + 1][j + 1] <= 0 &&
				field[i + 1][j] <= 0 && field[i][j + 2] == 2 && field[i + 1][j + 2] <= 0 && field[i][j + 3] <= 0 && field[i + 1][j + 3] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j - 1] = -1;
				field[i][j + 3] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 3] = -1;
				return true;
			}
			if (j != 0 && j < 7 && i == 9 && field[i][j - 1] <= 0 && field[i][j + 1] == 2 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 &&
				field[i - 1][j] <= 0 && field[i][j + 2] == 2 && field[i - 1][j + 2] <= 0 && field[i][j + 3] <= 0 && field[i - 1][j + 3] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j - 1] = -1;
				field[i][j + 3] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 3] = -1;
				return true;
			}
			if (i == 9 && j == 7 && field[i][j - 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i - 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j - 1] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j + 2] = -1;
				return true;
			}
			if (i == 0 && j == 7 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] <= 0 && field[i + 1][j + 1] <= 0 && field[i][j + 2] == 2 &&
				field[i + 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				return true;
			}
			if (field[i][j + 1] == 2 && field[i][j - 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] <= 0
				&& field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i][j + 2] == 2 && field[i + 1][j + 2] <= 0 && field[i - 1][j + 2] <= 0 &&
				field[i][j + 3] <= 0 && field[i + 1][j + 3] <= 0 && field[i - 1][j + 3] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = -1;
				field[i + 1][j] = -1;
				field[i - 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i - 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				field[i - 1][j + 2] = -1;
				field[i + 1][j + 3] = -1;
				field[i - 1][j + 3] = -1;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i - 1][j - 1] = -1;
				return true;
			}
		}
		if (i < 9 && field[i][j] == 2 && field[i + 1][j] == 2 && field[i + 2][j] == 2) //vertical
		{
			if (i == 0 && j == 0 && field[i][j + 1] <= 0 && field[i + 1][j] == 2 && field[i + 1][j + 1] <= 0 && field[i + 2][j] == 2 && field[i + 2][j + 1] <= 0 &&
				field[i + 3][j] <= 0 && field[i + 3][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 3][j + 1] = -1;
				field[i + 3][j] = -1;
				return true;
			}
			if (i == 7 && j == 0 && field[i][j + 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] == 2 && field[i + 1][j + 1] <= 0 &&
				field[i + 2][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] =3;
				field[i + 2][j] = 3;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i -1][j + 1] = -1;
				field[i -1][j] = -1;
				return true;
			}
			if (i != 0 && i < 7 && j == 0 && field[i][j + 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] == 2 &&
				field[i - 1][j] <= 0 && field[i][j + 2] <= 0 && field[i + 2][j + 1] <= 0 && field[i + 2][j] == 2 && field[i + 3][j] <= 0 && field[i + 3][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i][j + 1] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 3][j + 1] = -1;
				field[i + 3][j] = -1;
				return true;
			}
			if (i != 0 && i < 7 && j == 9 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j] == 2 &&
				field[i - 1][j] <= 0 && field[i + 2][j] == 2 && field[i + 2][j - 1] <= 0 && field[i + 3][j] <= 0 && field[i + 3][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i][j - 1] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				field[i + 3][j] = -1;
				return true;
			}
			if (j != 0 && j != 9 && i == 0 && field[i][j - 1] <= 0 && field[i][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j + 1] <= 0 &&
				field[i + 1][j] == 2 && field[i + 2][j] == 2 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0 && field[i + 3][j] <= 0 && field[i + 3][j - 1] <= 0 &&
				field[i + 3][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i][j - 1] = -1;
				field[i][j + 1] = -1;
				field[i + 1][j+1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 3][j + 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				field[i + 3][j] = -1;
				
				return true;
			}
			if (j != 0 && j != 9 && i == 7 && field[i][j - 1] <= 0 && field[i][j + 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 &&
				field[i - 1][j] <= 0 && field[i + 2][j] == 2 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0 &&
				field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i][j - 1] = -1;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i -1][j + 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i -1][j - 1] = -1;
				field[i -1][j] = -1;
				return true;
			}
			if (i == 7 && j == 9 && field[i][j - 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 2][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i][j - 1] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				return true;
			}
			if (i == 0 && j == 9 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 2][j - 1] <= 0 && field[i + 2][j] == 2 && field[i + 3][j] <= 0 &&
				field[i + 3][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				field[i + 3][j] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				return true;
			}
			if (field[i][j + 1] <= 0 && field[i][j - 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] == 2
				&& field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 2][j] <= 2 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0 &&
				field[i + 3][j] <= 0 && field[i + 3][j + 1] <= 0 && field[i + 3][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i][j - 1] = -1;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i - 1][j + 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i + 3][j - 1] = -1;
				field[i + 3][j + 1] = -1;
				field[i + 3][j] = -1;
				return true;
			}
		}

		//four
		if (j < 7 && field[i][j] == 2 && field[i][j + 1] == 2 && field[i][j + 2] == 2 && field[i][j + 3] == 2) //horizontal
		{
			if (i == 0 && j == 0 && field[i][j + 1] == 2 && field[i + 1][j] <= 0 && field[i + 1][j + 1] <= 0 && field[i][j + 2] == 2 && field[i + 1][j + 2] <= 0
				&& field[i][j + 3] == 2 && field[i + 1][j + 3] <= 0 && field[i][j + 4] <= 0 && field[i + 1][j + 4 <= 0])
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = 3;
				field[i][j + 4] = -1;
				field[i + 1][j + 4] = -1;
				field[i + 1][j + 3] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j] = -1;
				return true;
			}
			if (i == 9 && j == 0 && field[i][j + 1] == 2 && field[i - 1][j] <= 0 && field[i - 1][j + 1] <= 0 && field[i][j + 2] == 2 &&
				field[i - 1][j + 2] <= 0 && field[i][j + 3] == 2 && field[i - 1][j + 3] <= 0 && field[i][j + 4] <= 0 && field[i - 1][j + 4] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = 3; 
				field[i][j + 4] = -1;
				field[i - 1][j + 4] = -1;
				field[i - 1][j + 3] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j] = -1;
				return true;
			}
			if (i != 0 && i != 9 && j == 0 && field[i][j + 1] == 2 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] <= 0 &&
				field[i - 1][j] <= 0 && field[i][j + 2] == 2 && field[i + 1][j + 2] <= 0 && field[i - 1][j + 2] <= 0 && field[i][j + 3] == 2 && field[i - 1][j + 3] <= 0 &&
				field[i + 1][j + 3] <= 0 && field[i][j + 4] <= 0 && field[i + 1][j + 4] <= 0 && field[i - 1][j + 4] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = 3;
				field[i][j + 4] = -1;
				field[i - 1][j + 4] = -1;
				field[i - 1][j + 3] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j] = -1;
				field[i + 1][j + 4] = -1;
				field[i + 1][j + 3] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j] = -1;
				return true;
			}
			if (i != 0 && i != 9 && j == 6 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j] <= 0 &&
				field[i - 1][j] <= 0 && field[i][j + 1] == 2 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i][j + 3] == 2 && field[i + 1][j + 3] <= 0 &&
				field[i - 1][j + 3] <= 0 && field[i + 1][j + 2] <= 0 && field[i][j + 2] == 2 && field[i - 1][j + 2] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = 3;
				field[i][j -1] = -1;
				field[i - 1][j -1 ] = -1;
				field[i - 1][j + 3] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j] = -1;
				field[i + 1][j -1] = -1;
				field[i + 1][j + 3] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j] = -1;
				return true;
			}
			if (j != 0 && j < 6 && i == 0 && field[i][j - 1] <= 0 && field[i][j + 1] == 2 && field[i + 1][j - 1] <= 0 && field[i + 1][j + 1] <= 0 &&
				field[i + 1][j] <= 0 && field[i][j + 2] == 2 && field[i + 1][j + 2] <= 0 && field[i][j + 3] == 2 && field[i + 1][j + 3] <= 0 && field[i][j + 4] <= 0 &&
				field[i + 1][j + 4] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = 3;
				field[i][j - 1] = -1;
				field[i][j + 4] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 3] = -1;
				field[i + 1][j + 4] = -1;
				return true;
			}
			if (j != 0 && j < 6 && i == 9 && field[i][j - 1] <= 0 && field[i][j + 1] == 2 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 &&
				field[i - 1][j] <= 0 && field[i][j + 2] == 2 && field[i - 1][j + 2] <= 0 && field[i][j + 3] ==2 && field[i - 1][j + 3] <= 0 && field[i][j + 4] <= 0 &&
				field[i - 1][j + 4] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = 3;
				field[i][j - 1] = -1;
				field[i][j + 4] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 3] = -1;
				field[i - 1][j + 4] = -1;
				return true;
			}
			if (i == 9 && j == 6 && field[i][j - 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i - 1][j + 2] <= 0 &&
				field[i - 1][j + 3] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = 3;
				field[i][j - 1] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 3] = -1;
				return true;
			}
			if (i == 0 && j == 6 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] <= 0 && field[i + 1][j + 1] <= 0 && field[i][j + 2] == 2 &&
				field[i + 1][j + 2] <= 0 && field[i + 1][j + 3] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 1][j] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 3] = -1;
				return true;
			}
			if (field[i][j + 1] == 2 && field[i][j - 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] <= 0
				&& field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i][j + 2] == 2 && field[i + 1][j + 2] <= 0 && field[i - 1][j + 2] == 0 &&
				field[i][j + 3] == 2 && field[i + 1][j + 3] <= 0 && field[i - 1][j + 3] <= 0 && field[i][j + 4] <= 0 && field[i + 1][j + 4] <= 0 && field[i - 1][j + 4] <= 0)
			{
				field[i][j] = 3;
				field[i][j + 1] = 3;
				field[i][j + 2] = 3;
				field[i][j + 3] = 3;
				field[i][j - 1] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j + 3] = -1;
				field[i - 1][j + 2] = -1;
				field[i - 1][j + 1] = -1;
				field[i - 1][j] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 1][j + 3] = -1;
				field[i + 1][j + 2] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 1][j] = -1;
				field[i][j + 4] = -1;
				field[i + 1][j + 4] = -1;
				field[i - 1][j + 4] = -1;
				return true;
			}
		}
		if (i < 9 && field[i][j] == 2 && field[i + 1][j] == 2 && field[i + 2][j] == 2 && field[i + 3][j] == 2) //vertical
		{
			if (i == 0 && j == 0 && field[i][j + 1] <= 0 && field[i + 1][j] == 2 && field[i + 1][j + 1] <= 0 && field[i + 2][j] == 2 && field[i + 2][j + 1] <= 0 &&
				field[i + 3][j] == 2 && field[i + 3][j + 1] <= 0 && field[i + 4][j] <= 0 && field[i + 4][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i + 3][j] = 3;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 3][j + 1] = -1;
				field[i + 4][j + 1] = -1;
				field[i + 4][j] = -1;
				return true;
			}
			if (i == 6 && j == 0 && field[i][j + 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] == 2 && field[i + 1][j + 1] <= 0 &&
				field[i + 2][j + 1] <= 0 && field[i + 3][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i + 3][j] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				field[i + 4][j - 1] = -1;
				field[i + 4][j] = -1;
				return true;
			}
			if (i != 0 && i < 6 && j == 0 && field[i][j + 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 1][j] == 2 &&
				field[i - 1][j] <= 0 && field[i][j + 2] <= 0 && field[i + 2][j + 1] <= 0 && field[i + 2][j] == 2 && field[i + 3][j] == 2 && field[i + 3][j + 1] <= 0 &&
				field[i + 4][j] <= 0 && field[i + 4][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i + 3][j] = 3;
				field[i - 1][j] = -1;
				field[i - 1][j + 1] = -1;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 3][j + 1] = -1;
				field[i + 4][j + 1] = -1;
				field[i+4][j] = -1;
				return true;
			}
			if (i != 0 && i < 6 && j == 9 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j] == 2 &&
				field[i - 1][j] <= 0 && field[i + 2][j] == 2 && field[i + 2][j - 1] <= 0 && field[i + 3][j] == 2 && field[i + 3][j - 1] <= 0 && field[i + 4][j] <= 0 &&
				field[i + 4][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i + 3][j] = 3;
				field[i - 1][j] = -1;
				field[i - 1][j - 1] = -1;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				field[i + 4][j - 1] = -1;
				field[i + 4][j] = -1;
				return true;
			}
			if (j != 0 && j != 9 && i == 0 && field[i][j - 1] <= 0 && field[i][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j + 1] <= 0 &&
				field[i + 1][j] == 2 && field[i + 2][j] == 2 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0 && field[i + 3][j] == 2 && field[i + 3][j - 1] <= 0 &&
				field[i + 3][j + 1] <= 0 && field[i + 4][j] <= 0 && field[i + 4][j - 1] <= 0 && field[i + 4][j + 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i + 3][j] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				field[i + 4][j - 1] = -1;
				field[i + 4][j] = -1;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 3][j + 1] = -1;
				field[i + 4][j + 1] = -1;
				return true;
			}
			if (j != 0 && j != 9 && i == 6 && field[i][j - 1] <= 0 && field[i][j + 1] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 &&
				field[i - 1][j] <= 0 && field[i + 2][j] == 2 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0 &&
				field[i + 3][j + 1] <= 0 && field[i + 3][j - 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i + 3][j] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				field[i -1][j - 1] = -1;
				field[i -1][j] = -1;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 3][j + 1] = -1;
				field[i -1][j + 1] = -1;
				return true;
			}
			if (i == 6 && j == 9 && field[i][j - 1] <= 0 && field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 2][j - 1] <= 0 &&
				field[i + 3][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i + 3][j] = 3;
				field[i - 1][j] = -1;
				field[i - 1][j - 1] = -1;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				return true;
			}
			if (i == 0 && j == 9 && field[i][j - 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 2][j - 1] <= 0 && field[i + 2][j] == 2 && field[i + 3][j] == 2 &&
				field[i + 3][j - 1] <= 0 && field[i + 4][j] <= 0 && field[i + 4][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i + 3][j] = 3;
				field[i +4][j] = -1;
				field[i +4][j - 1] = -1;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				return true;
			}
			if (field[i][j + 1] <= 0 && field[i][j - 1] <= 0 && field[i + 1][j + 1] <= 0 && field[i + 1][j - 1] <= 0 && field[i + 1][j] == 2
				&& field[i - 1][j] <= 0 && field[i - 1][j - 1] <= 0 && field[i - 1][j + 1] <= 0 && field[i + 2][j] == 2 && field[i + 2][j + 1] <= 0 && field[i + 2][j - 1] <= 0 &&
				field[i + 3][j] == 2 && field[i + 3][j + 1] <= 0 && field[i + 3][j - 1] <= 0 && field[i + 4][j] <= 0 && field[i + 4][j + 1] <= 0 && field[i + 4][j - 1] <= 0)
			{
				field[i][j] = 3;
				field[i + 1][j] = 3;
				field[i + 2][j] = 3;
				field[i + 3][j] = 3;
				field[i][j - 1] = -1;
				field[i + 1][j - 1] = -1;
				field[i + 2][j - 1] = -1;
				field[i + 3][j - 1] = -1;
				field[i - 1][j - 1] = -1;
				field[i - 1][j] = -1;
				field[i][j + 1] = -1;
				field[i + 1][j + 1] = -1;
				field[i + 2][j + 1] = -1;
				field[i + 3][j + 1] = -1;
				field[i - 1][j + 1] = -1;
				field[i + 4][j + 1] = -1;
				field[i + 4][j] = -1;
				field[i + 4][j - 1] = -1;
				return true;
			}
		}
	}
	return false;
}

int opponent(int(*field)[10], bool& first, int& prev_i, int& prev_ii, int& prev_j, int& prev_jj, int& k) //k = 0 - вправо, 1 - влево, 2 - вниз, 3 - вверх
{
	bool move = false;
	int shot;
	while (!move)
	{
		shot = rand() % 100;
		if (prev_i >= 0 && prev_j >= 0)
		{
			if (field[prev_i][prev_j] == 3)
			{
				prev_i = -1;
				prev_j = -1;
				prev_ii = -1;
				prev_jj = -1;
				k = 0;
			}
			else if (field[prev_i][prev_j] == -1)
			{
				prev_i = prev_ii;
				prev_j = prev_jj;
				switch (k)
				{
				case 0: k = 1; break;
				case 1: k = 2; break;
				case 2: k = 3; break;
				default: k = 0;
				}
			}
			if (field[prev_i][prev_j] != 3)
			{
				if ((prev_j == 9 || field[prev_i][prev_j + 1] == -1) && k == 0)
				{
					k = 1;
				}
				if ((prev_j == 0 || field[prev_i][prev_j - 1] == -1) && k == 1)
				{
					k = 2;
				}
				if ((prev_i == 9 || field[prev_i + 1][prev_j] == -1) && k == 2)
				{
					k = 3;
				}
				if ((prev_i == 0 || field[prev_i - 1][prev_j] == -1) && k == 3)
				{
					k = 0;
				}
				if (prev_j != 9 && (field[prev_i][prev_j+1] == 0 || field[prev_i][prev_j + 1] == 1) && k == 0)
				{
					prev_ii = prev_i;
					prev_jj = prev_j;
					prev_j++;
					shot = (prev_i) * 10 + prev_j;
				}
				if (prev_j != 0 && (field[prev_i][prev_j - 1] == 0 || field[prev_i][prev_j - 1] == 1) && k == 1)
				{
					prev_ii = prev_i;
					prev_jj = prev_j;
					prev_j--;
					shot = (prev_i) * 10 + prev_j;
				}
				if (prev_i != 9 && (field[prev_i+1][prev_j] == 0 || field[prev_i+1][prev_j] == 1) && k == 2)
				{
					prev_ii = prev_i;
					prev_jj = prev_j;
					prev_i++;
					shot = (prev_i) * 10 + prev_j;
				}
				if (prev_i != 0 && (field[prev_i-1][prev_j] == 0 || field[prev_i-1][prev_j] == 1) && k == 3)
				{
					prev_ii = prev_i;
					prev_jj = prev_j;
					prev_i--;
					shot = (prev_i) * 10 + prev_j;
				}
			}

		}


		for (int i = 0; i < 10; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				if ((field[i][j] == 0 || field[i][j] == 1) && shot == i * 10 + j)
				{
					move = true;
					if (field[i][j] == 0)
					{
						field[i][j] = -1;
						return 0;
					}
					if (field[i][j] == 1)
					{
						first = true;
						field[i][j] = 2;
						prev_ii = prev_i;
						prev_jj = prev_j;
						prev_i = i;
						prev_j = j;
						return 1;
					}
				}
			}
		}
	}
	return 0;
}