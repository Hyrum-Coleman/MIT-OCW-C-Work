#include "blackjack.h"

#include <algorithm>
#include <random>
#include <utility>
#include <vector>
#include <chrono>
#include <iostream>

unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

/*
 
Card Class 
 
 */

Card::Card(int card_val, std::string card_suit)
{
	m_card_val = card_val;
	m_card_suit = std::move(card_suit);
}

void Card::print_card() const
{
    std::cout << "Card Val: " << get_string_card_val() << " Card Suit: " << get_card_face() << std::endl;
}

std::string Card::get_string_card_val() const {
    switch (m_card_val)
    {
        case 11:
            return "Jack";
        case 12:
            return "Queen";
        case 13:
            return "King";
        case 14:
            return "Ace";
    }
    return std::to_string(m_card_val);
}



/*

Deck Class
 
 */

Deck::Deck()
{
	for(int i = 0; i < 13; i++)
	{
		m_card_array.emplace_back((i + 2), "clubs");
        m_card_array.emplace_back((i + 2), "diamonds");
        m_card_array.emplace_back((i + 2), "spades");
        m_card_array.emplace_back((i + 2), "hearts");
	}
}

void Deck::shuffle()
{
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


/*

Hand Class
 
 */

Hand::Hand(Deck * deck, int hand_size)
{
    m_deck = deck;
	for(int i = 0; i < hand_size; i++)
	{
		draw();
	}
}

void Hand::draw()
{
    m_hand_array.push_back(m_deck->get_next_card());
}

void Hand::print_hand() const
{
	for (auto& i : m_hand_array)
	{
		i.print_card();
	}
}


