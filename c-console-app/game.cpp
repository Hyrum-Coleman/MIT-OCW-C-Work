#include "game.h"

#include <algorithm>
#include <iostream>


/*

 Game class

*/

Game::Game()
{
    m_game_deck = new Deck();
    m_player_hand = new Hand(m_game_deck, 2);
    m_dealer_hand = new Hand(m_game_deck, 2);
    m_players_childrens_college_fund = 1000;
    m_player_bet = 0;
    m_player_score = 0;
    m_dealer_score = 0;
}

void Game::play_blackjack()
{
    std::cout << "Dealer's Card: ";
    m_dealer_hand->print_top_card();
    std::cout << std::endl;

    std::cout << "Your cards: " << std::endl;
    m_player_hand->print_hand();
    std::cout << std::endl;

    std::string player_choice;

    while(!get_initial_choice(player_choice));

    switch(player_choice[0])
    {
        case 'd':
            double_down();
            stand();
            break;
        case 'h':
            hit(player_choice);
            stand();
            break;
        case 's':
            stand();
            break;
    }

    handle_dealer();
    determine_winner();
}

void Game::game_loop()
{
    std::string game_continue;

    do
    {
        while (!place_bet());
        play_blackjack();

        if(m_players_childrens_college_fund <= 0)
        {
            std::cout << "You spent the entire college fund, and you're out of money" << std::endl;
            return;
        }

        delete m_player_hand;
        delete m_dealer_hand;
        m_player_hand = new Hand(m_game_deck, 2);
        m_dealer_hand = new Hand(m_game_deck, 2);

        while(!get_continue_choice(game_continue));
    }
    while(game_continue == "y");
}

bool Game::place_bet()
{
    std::string input_string;


    std::cout << "How much money do you want to bet?" << std::endl;
    std::cout << "Current Balance:   $" << m_players_childrens_college_fund << std::endl;
    std::cout << "  > ";
    std::cin >> input_string;

    try
    {
        m_player_bet = std::stod(input_string);

        if (m_player_bet < 1)
        {
            std::cout << "Invalid bet amount, please enter a positive number greater than 1" << std::endl;
            return false;
        }

        if (m_player_bet > m_players_childrens_college_fund)
        {
            std::cout << "You don't have the funds to place that bet" << std::endl;
            return false;
        }

        m_players_childrens_college_fund-=m_player_bet;
        return true;
    }
    catch(std::invalid_argument&)
    {
        std::cout << "Invalid input, please enter an number" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        return false;
    }
}

void Game::payout()
{
    if ( m_player_score == 21 )
    {
        m_players_childrens_college_fund+= (m_player_bet * 2.5);
        return;
    }

    m_players_childrens_college_fund+= (m_player_bet * 2);
}

void Game::double_down()
{
    m_players_childrens_college_fund-=m_player_bet;
    m_player_bet*=2;
    m_player_hand->draw(1);
    std::cout << "Final Hand: " << std::endl;
    m_player_hand->print_hand();
}

void Game::hit(std::string& player_choice) {

    while (player_choice[0] == 'h')
    {

        m_player_hand->draw(1);
        m_player_hand->print_hand();
        std::cout << std::endl;
        if (m_player_hand->sum_hand() >= 21)
        {
            break;
        }
        while(!get_hit_choice(player_choice));
    }
}

void Game::stand() {

    if (m_player_hand->sum_hand() > 21)
    {
        std::cout << "The player busts" << std::endl;
        m_player_score  = -1;
        return;
    }
    m_player_score = m_player_hand->sum_hand();
}

void Game::handle_dealer() {

    std::cout << std::endl << "Revealing the Dealer's Hand... " << std::endl;
    m_dealer_hand->print_hand();
    m_dealer_score = m_dealer_hand->sum_hand();

    while((m_dealer_score < 17) && (m_dealer_score < m_player_score))
    {
        m_dealer_hand->draw(1);
        m_dealer_hand->print_top_card();
        m_dealer_score = m_dealer_hand->sum_hand();
    }
    std::cout << std::endl;

    if (m_dealer_score > 21)
    {
        std::cout << "The dealer busts" << std::endl;
        m_dealer_score = -1;
    }
}

void Game::determine_winner() {

    if(m_player_score > m_dealer_score )
    {
        std::cout << "The player wins" << std::endl;
        payout();
    }
    else if (m_player_score < m_dealer_score )
    {
        std::cout << "The dealer wins" << std::endl;
    }
    else if (m_player_score == m_dealer_score )
    {
        std::cout << "Draw" << std::endl;
        m_players_childrens_college_fund+=m_player_bet;
    }
}

bool Game::get_initial_choice(std::string & player_choice)
{
    std::cout << "Will you hit, stand, or double down? (h,s,d)" << std::endl;
    std::cout << "  > ";
    std::cin >> player_choice;

    switch(player_choice[0])
    {
        case 'h':
        case 's':
        case 'd':
            return true;
        default:
            std::cout << "Not a valid input... try again" << std::endl;
            return false;
    }
}

bool Game::get_hit_choice(std::string &player_choice) {
    std::cout << "Will you hit or stand? (h,s)" << std::endl;
    std::cout << "  > ";
    std::cin >> player_choice;

    switch(player_choice[0])
    {
        case 'h':
        case 's':
            return true;
        default:
            std::cout << "Not a valid input... try again" << std::endl;
            return false;
    }
}

bool Game::get_continue_choice(std::string &continue_choice) {
    std::cout << std::endl << "Would you like to play again? (y/n) " << std::endl;
    std::cout << "  > ";
    std::cin >> continue_choice;

    switch(continue_choice[0])
    {
        case 'y':
        case 'n':
            return true;
        default:
            std::cout << "Not a valid input... try again" << std::endl;
            return false;
    }
}


