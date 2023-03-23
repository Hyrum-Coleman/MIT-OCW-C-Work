#include "deck.h"

#include <algorithm>
#include <chrono>
#include <random>


/*

Deck Class

 */

Deck::Deck()
{
    populate_deck_and_shuffle();
}

void Deck::populate_deck_and_shuffle() {

    for (int i = 0; i < 13; i++)
    {
        m_card_array.emplace_back((i + 2), "Clubs");
        m_card_array.emplace_back((i + 2), "Diamonds");
        m_card_array.emplace_back((i + 2), "Spades");
        m_card_array.emplace_back((i + 2), "Hearts");
    }

    shuffle();
}

void Deck::shuffle()
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::shuffle(m_card_array.begin(), m_card_array.end(), std::default_random_engine(seed));
}

void Deck::print_deck() const
{
	for (auto& i : m_card_array)
	{
		i.print_card();
	}
}

Card Deck::get_next_card() {
	Card ret_val = m_card_array.back();
	m_card_array.pop_back();
	return ret_val;
}


