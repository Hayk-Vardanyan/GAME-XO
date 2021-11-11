#include <iostream>

class Game
{
public:
Game();
void print();
void check(char ch);
void set(int, int, char);
bool legal_move(int, int);
bool endgame;

private:
char arr[3][3];

};

Game::Game()
{
 endgame = false;

for(int i = 0; i < 3; ++i)
 {
 for(int j = 0; j < 3; ++j)
{
 arr[i][j] = ' ';

}
 }

}
bool Game::legal_move(int x, int y)
{
if(x < 1 || x > 3 || y < 1 || y > 3)
{
 std::cout << " WRONG INDEX  DO YOUR STEP AGAIN  ";
 return false;

}

   if(arr[x - 1][y - 1] == 'x' || arr[x - 1][y - 1] == 'o')
{
    return false;
} 

return true;

}

void Game::set(int x, int y, char ch)
{
 
 arr[x - 1][y - 1] = ch;
}

void Game::check(char ch)
{
if((arr[0][0] == ch && arr[0][1] == ch && arr[0][2] == ch) || (arr[0][0] == ch && arr[1][0] == ch && arr[2][0] == ch) || (arr[2][0] == ch && arr[2][1] == ch && arr[2][2] == ch) || (arr[0][2] == ch && arr[1][2] == ch && arr[2][2] == ch) || (arr[0][0] == ch && arr[1][1] == ch && arr[2][2] == ch) || (arr[0][2]== ch && arr[1][1] == ch && arr[2][0] == ch) || (arr[1][0] == ch && arr[1][1] == ch && arr[1][2] == ch || arr[0][1] == ch && arr[1][1] == ch && arr[2][1] == ch))
{
 endgame = true;

}

}
void Game::print()
{
std::cout << "_______";
std::cout << std::endl;
int m = 0;

for(int i = 0; i < 3; ++i)
{
 for(int j = 0; j < 3; ++j)
{
 std::cout << "|" << arr[i][j];

}
std::cout << '|';
std::cout << std::endl;
}

std::cout << "_______";
std::cout << std::endl;
}

int main()
{
Game game;
int x,y;
int i = 0;
char ch;

while(game.endgame != true)
{
system("cls");	

++i;

again:

if(i % 2 == 0)
{
 ch = 'o';
} 
else ch = 'x';

game.print();
std::cin >> x >> y;
if(!std::cin.good())
{
	std::cout << "BAD INPUT";
	exit(8);
}

if(!game.legal_move(x, y))
{
 goto again;
}

game.set(x, y, ch);
game.check(ch);

if(i == 9 && game.endgame == false)
{
 std::cout << "there is no winner";
 break;
}
 
}
game.print();
if( game.endgame == true)
std::cout << "the winner is\t" << ch; 

}

