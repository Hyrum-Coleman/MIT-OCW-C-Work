#include <iostream>

#include "blackjack.h"

using namespace std;

int main()
{
	auto blackjack_game = new Game();
    blackjack_game->game_loop();


    delete blackjack_game;

	return 0;
}