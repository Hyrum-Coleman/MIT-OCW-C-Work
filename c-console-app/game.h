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
    void print_deck() const;
    bool place_bet();
    void payout(bool blackjack, bool draw);
    
private:
    Deck *m_game_deck;
    Hand *m_player_hand;
    Hand *m_dealer_hand;
    double m_players_childrens_college_fund;
    double m_player_bet;
};