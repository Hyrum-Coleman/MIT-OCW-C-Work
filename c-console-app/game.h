#pragma once
#include "hand.h"
#include "deck.h"


class Game
{
public:
    Game();
    ~Game() = default;

public:
    void play_blackjack();
    void game_loop();
    bool place_bet();
    void payout();
    void double_down();
    void hit(std::string& player_choice) const;
    void stand();
    void handle_dealer();
    void determine_winner();
    static bool get_initial_choice(std::string& player_choice);
    static bool get_hit_choice(std::string& player_choice);
    static bool get_continue_choice(std::string& continue_choice);
    
private:
    Deck *m_game_deck;
    Hand *m_player_hand;
    Hand *m_dealer_hand;
    int m_player_score;
    int m_dealer_score;
    double m_players_childrens_college_fund;
    double m_player_bet;
};