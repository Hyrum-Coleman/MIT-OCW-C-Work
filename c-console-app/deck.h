#pragma once
#include <vector>

#include "card.h"

class Deck
{
public:
	Deck();

	[[nodiscard]] int get_num_cards() { return m_card_array.size(); }

public: // public methods
	void shuffle();
	void print_deck() const;
	Card get_next_card();

protected:
	std::vector<Card> m_card_array;
};
