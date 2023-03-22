#include "game.h"

#include <algorithm>
#include <random>
#include <iostream>

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

void Game::play_blackjack() // Simplify simplify simplify
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
        if (m_game_deck->get_num_cards() < 10) // fix this by using a function to add new cards to the same deck at draw time
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

        while (!place_bet());
        play_blackjack();
        num_games++;

        std::cout << std::endl << "Would you like to play again? (y/n) ";
        std::cin >> game_continue;
    }
    while(game_continue == "y");
}

bool Game::place_bet()
{
    std::cout << "How much money do you want to bet?" << std::endl;
    std::cout << "Current Balance:   $" << m_players_childrens_college_fund << std::endl;
    std::cin >> m_player_bet;

    // fix this by inputting into string, and try catch std::stoi()


    if (m_player_bet > m_players_childrens_college_fund)
    {
        std::cout << "You don't have the funds to place that bet" << std::endl;
        return false;
    }

    m_players_childrens_college_fund-=m_player_bet;
    return true;
}

void Game::payout(bool blackjack, bool draw)
{
    if ( draw )
    {
        m_players_childrens_college_fund+= m_player_bet;
        return;
    }

    if ( blackjack )
    {
        m_players_childrens_college_fund+= (m_player_bet * 2.5);
        return;
    }

    m_players_childrens_college_fund+= (m_player_bet * 2);
}
