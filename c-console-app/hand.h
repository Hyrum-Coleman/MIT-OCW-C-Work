#pragma once
#include "card.h"
#include "deck.h"

class Hand
{
public:
	Hand(Deck* deck, int hand_size);


public:
	void draw(int hand_size);
	void print_hand() const;
	void print_top_card() const;
	int sum_hand();

private:
	std::vector<Card> m_hand_array;
	Deck* m_deck;
};
