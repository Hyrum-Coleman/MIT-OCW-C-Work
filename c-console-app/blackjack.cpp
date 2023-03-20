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
    std::cout << get_string_card_val() << " of " << get_card_face() << std::endl;
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
		m_card_array.emplace_back((i + 2), "Clubs");
        m_card_array.emplace_back((i + 2), "Diamonds");
        m_card_array.emplace_back((i + 2), "Spades");
        m_card_array.emplace_back((i + 2), "Hearts");
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
	draw(hand_size);
}

void Hand::draw(int hand_size)
{
    for(int i = 0; i < hand_size; i++)
    {
        m_hand_array.push_back(m_deck->get_next_card());
    }
}

void Hand::print_hand() const
{
	for (auto& i : m_hand_array)
	{
		i.print_card();
	}
}

void Hand::print_top_card() const
{
    m_hand_array.back().print_card();
}

int Hand::sum_hand() // Technically this algo is now O(n^2) for no reason whatsoever, but my input of cards is so low I'm dealing with it.
// I was going to try and sort it, but standard sorting algorithms didn't like my card class as input, and the time it'll take to write my own will be longer than the extra time
// for being O(n^2)
{
    int ret_sum = 0;
    for(auto &i : m_hand_array)
    {
        if (i.get_string_card_val() == "Ace") // ignore aces until all other cards are summed
        {
            continue;
        }
        if ((i.get_card_val() > 10) && (i.get_card_val() < 14)) // These are all the face cards except the ace
        {
            ret_sum += 10;
            continue;
        }
        ret_sum += i.get_card_val();
    }

    for(auto &i : m_hand_array) // now handle the aces
    {
        if ((i.get_string_card_val() == "Ace") && ((ret_sum + 11) <= 21))
        {
            ret_sum += 11;
            continue;
        }
        else if (i.get_string_card_val() == "Ace")
        {
            ret_sum += 1;
            continue;
        }
    }

    return ret_sum;
}

/*

 Game class

 */

Game::Game()
{
    m_game_deck = new Deck();
    m_game_deck->shuffle();
    m_player_hand = new Hand(m_game_deck, 2);
    m_dealer_hand = new Hand(m_game_deck, 2);
}


void Game::print_deck() const { m_game_deck->print_deck(); }
void Game::print_player_hand() const { m_player_hand->print_hand(); }
void Game::print_dealer_hand() const { std::cout << m_dealer_hand; }

void Game::play_blackjack()
{
    std::cout << "Dealer's Card: ";
    m_dealer_hand->print_top_card();
    std::cout << std::endl;

    std::cout << "Your cards: " << std::endl;
    m_player_hand->print_hand();
    std::cout << std::endl;

    std::string player_choice;

    std::cout << "Will you hit, stand, or double down? (h,s,d)";
    std::cin >> player_choice;
    std::tolower(player_choice[0]);

    if( (player_choice != "h") && (player_choice != "s") && (player_choice != "d"))
    {
        std::cout << "Not a valid input!" << std::endl;
    }

    if (player_choice == "h")
    {
        m_player_hand->draw(1);
        m_player_hand->print_hand();
        std::cout << std::endl;
    }

    if (player_choice == "d")
    {
        m_player_hand->draw(1);
        std::cout << "Final Hand: " << std::endl;
        m_player_hand->print_hand();
    }

    while (player_choice == "h")
    {

        if (m_player_hand->sum_hand() > 21)
        {
            std::cout << "You busted" << std::endl;
            break;
        }
        if (m_player_hand->sum_hand() == 21)
        {
            std::cout << "BLACKJACK" << std::endl;
            break;
        }

        std::cout << "Will you hit or stand? (h,s)";
        std::cin >> player_choice;
        if (player_choice == "h")
        {
            m_player_hand->draw(1);
            m_player_hand->print_hand();
            std::cout << std::endl;
        }
    }
    // if we're here we have an invalid input or "s"

    std::cout << std::endl << "Revealing the Dealer's Hand... " << std::endl;
    m_dealer_hand->print_hand();

    while(m_dealer_hand->sum_hand() < 17)
    {
        m_dealer_hand->draw(1);
        m_dealer_hand->print_top_card();
    }

    if (m_player_hand->sum_hand() > 21)
    {
        std::cout << "You busted!" << std::endl;
        m_player_busted = true;
    }
    if (m_dealer_hand->sum_hand() > 21)
    {
        std::cout << "The dealer busted!" << std::endl;
        m_dealer_busted = true;
    }


}