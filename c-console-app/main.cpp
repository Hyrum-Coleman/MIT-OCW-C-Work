#include <iostream>

#include "poker.h"

using namespace std;

int main()
{
	auto game_deck = new deck();
	game_deck->print_deck();
	game_deck->shuffle();

	cout << endl << endl << endl;

	game_deck->print_deck();

	cout << endl << endl << endl;
	cout << game_deck->get_num_cards();
	

	auto player_hand = new hand(2);
	cout << endl << endl << "gaming" << endl;

	player_hand->print_hand();

	cout << endl << endl << endl << game_deck->get_num_cards() << endl;

	return 0;
}