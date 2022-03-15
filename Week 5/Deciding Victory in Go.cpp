#include <iostream>

char board[9][10];
int dir[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

int getWhite = 0, getBlack = 0, count = 0;

void spaceCount(int x, int y)
{
	if (x < 0 || x >= 9 || y < 0 || y >= 9) 
		return ;
	if (board[x][y] == '.')
	{
		count ++;
		board[x][y] = ' ';
	}
	else
	{
		getWhite = getWhite || (board[x][y] == 'O');
		getBlack = getBlack || (board[x][y] == 'X');
		return ;
	}
	for (int i=0; i<4; i++)
		spaceCount(x+dir[i][0], y+dir[i][1]);
}

int main()
{
	int testcase;
	std::cin >> testcase;
	while (testcase --)
	{
		int white = 0, black = 0;
		for (int i=0; i<9; i++){
			for (int j=0; j<9; j++){
				std::cin >> board[i][j];
				white += (board[i][j] == 'O');
				black += (board[i][j] == 'X');
			}		
		}
		for (int i=0; i<9; i++){
			for (int j=0; j<9; j++)
			{
				if (board[i][j] == '.')
				{
					getWhite = 0, getBlack = 0, count = 0;
					spaceCount(i, j);
					white += count * (getWhite && !getBlack);
					black += count * (!getWhite && getBlack);
				}
			}
		}
		std::cout << "Black " << black << " White " << white << std::endl;

	}
}
