#include "poker.h"

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

card::card(int card_val, std::string card_suit)
{
	m_card_val = card_val;
	m_card_suit = std::move(card_suit);
}




/*

Deck Class
 
 */

deck::deck()
{
	for(int i = 0; i < 13; i++)
	{
		m_card_array.emplace_back((i + 2), "clubs");
	}
	for(int i = 0; i < 13; i++)
	{
		m_card_array.emplace_back((i + 2), "diamonds");
	}
	for (int i = 0; i < 13; i++)
	{
		m_card_array.emplace_back((i + 2), "spades");
	}
	for (int i = 0; i < 13; i++)
	{
		m_card_array.emplace_back((i + 2), "hearts");
	}
	set_num_cards(m_card_array.size());
}

void deck::set_num_cards(int num_cards)
{
	m_num_cards_in_deck = num_cards;
}

void deck::shuffle()
{
	std::shuffle(m_card_array.begin(), m_card_array.end(), std::default_random_engine(seed));
}

void deck::print_deck() const
{
	for (auto& i : m_card_array)
	{
		std::cout << "Card Val: " << i.get_card_val() << " Card Suit: " << i.get_card_face() << std::endl;
	}
}


/*

Hand Class
 
 */

hand::hand(int num_cards)
{
	for(int i = 0; i < num_cards; i++)
	{
		draw();
	}
}

void hand::draw()
{
	m_hand_array.push_back(m_card_array[m_card_array.size() - 1]);
	m_card_array.pop_back();
	m_num_cards_in_deck--;
}

void hand::print_hand() const
{
	for (auto& i : m_hand_array)
	{
		std::cout << "Card Val: " << i.get_card_val() << " Card Suit: " << i.get_card_face() << std::endl;
	}
}


