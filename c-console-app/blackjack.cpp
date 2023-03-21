#include "blackjack.h"

#include <algorithm>
#include <random>
#include <utility>
#include <chrono>
#include <iostream>

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
    m_players_childrens_college_fund = 1000;
    m_player_bet = 0;
}


void Game::print_deck() const { m_game_deck->print_deck(); }

void Game::play_blackjack()
{
    bool player_busted = false;
    bool dealer_busted = false;
    bool blackjack = false;
    bool draw = false;

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
        m_players_childrens_college_fund+=m_player_bet;
        return void();
    }

    if (player_choice == "d") // Right now doubling down works great, except you can double down when you don't have enough money to double down
    {
        m_players_childrens_college_fund-=m_player_bet;
        m_player_bet*=2;
        m_player_hand->draw(1);
        std::cout << "Final Hand: " << std::endl;
        m_player_hand->print_hand();
    }

    while (player_choice == "h")
    {

        m_player_hand->draw(1);
        m_player_hand->print_hand();
        std::cout << std::endl;
        if (m_player_hand->sum_hand() >= 21)
        {
            break;
        }
        std::cout << "Will you hit or stand? (h,s)";
        std::cin >> player_choice;
    }

    if (m_player_hand->sum_hand() > 21)
    {
        std::cout << "Bust!" << std::endl;
        player_busted = true;
    }
    else if (m_player_hand->sum_hand() == 21)
    {
        std::cout << "Blackjack!" << std::endl;
        blackjack = true;
    }
    // if we're here we have an invalid input or "s"

    std::cout << std::endl << "Revealing the Dealer's Hand... " << std::endl;
    m_dealer_hand->print_hand();

    if (player_busted)
    {
        std::cout << std::endl << "The dealer wins" << std::endl;
        return void();
    }

    while((m_dealer_hand->sum_hand() < 17) && (m_dealer_hand->sum_hand() < m_player_hand->sum_hand()) )
    {
        m_dealer_hand->draw(1);
        m_dealer_hand->print_top_card();
    }
    std::cout << std::endl;

    if (m_dealer_hand->sum_hand() > 21)
    {
        std::cout << "The dealer busts!" << std::endl;
        dealer_busted = true;
    }

    if (dealer_busted)
    {
        std::cout << "The player wins" << std::endl;
        payout(blackjack, draw);
        return void();
    }

    if(m_player_hand->sum_hand() > m_dealer_hand->sum_hand() )
    {
        std::cout << "The player wins" << std::endl;
        payout(blackjack, draw);
    }
    else if (m_player_hand->sum_hand() < m_dealer_hand->sum_hand() )
    {
        std::cout << "The dealer wins" << std::endl;
    }
    else if (m_player_hand->sum_hand() == m_dealer_hand->sum_hand() )
    {
        std::cout << "Draw" << std::endl;
        draw = true;
        payout(blackjack, draw);
    }
}

void Game::game_loop()
{
    std::string game_continue;
    int num_games = 0;

    do
    {
        if(m_players_childrens_college_fund <= 0)
        {
            std::cout << "You spent the entire college fund, and you're out of money" << std::endl;
            break;
        }

        if ((num_games != 0) && (m_game_deck->get_num_cards() >= 10))
        {
            delete m_player_hand;
            delete m_dealer_hand;

            m_player_hand = new Hand(m_game_deck, 2);
            m_dealer_hand = new Hand(m_game_deck, 2);
        }
        if (m_game_deck->get_num_cards() < 10)
        {
            std::cout << "Resetting game deck!" << std::endl;

            delete m_player_hand;
            delete m_dealer_hand;
            delete m_game_deck;
            m_game_deck = new Deck();
            m_game_deck->shuffle();

            m_player_hand = new Hand(m_game_deck, 2);
            m_dealer_hand = new Hand(m_game_deck, 2);
        }

        place_bet();
        play_blackjack();
        num_games++;

        std::cout << std::endl << "Would you like to play again? (y/n) ";
        std::cin >> game_continue;
    }
    while(game_continue == "y");
}

void Game::place_bet()
{
    std::cout << "How much money do you want to bet?" << std::endl;
    std::cout << "Current Balance:   $" << m_players_childrens_college_fund << std::endl;
    std::cin >> m_player_bet;


    if (m_player_bet > m_players_childrens_college_fund)
    {
        std::cout << "You don't have the funds to place that bet" << std::endl;
        place_bet();
    }

    m_players_childrens_college_fund-=m_player_bet;
}

void Game::payout(bool blackjack, bool draw)
{
    if ( draw )
    {
        m_players_childrens_college_fund+= m_player_bet;
        return void();
    }

    if ( blackjack )
    {
        m_players_childrens_college_fund+= (m_player_bet * 2.5);
        return void();
    }

    m_players_childrens_college_fund+= (m_player_bet * 2);
}
