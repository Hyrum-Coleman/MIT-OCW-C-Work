#pragma once
#include <string>
#include <vector>


class Card
{
public:
	Card(int card_val, std::string card_suit);
	[[nodiscard]] int get_card_val() const { return m_card_val; }
	[[nodiscard]] std::string get_card_face() const { return m_card_suit; }

public:
    void print_card() const;
    [[nodiscard]] std::string get_string_card_val() const;

private: //private variables
	int m_card_val; // 2-14 2 through Ace (not value added in game of blackjack, just raw value)
	std::string m_card_suit; // "clubs", "diamonds" "spades" "hearts"

};


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


class Hand
{
public:
	Hand(Deck * deck, int hand_size);


public:
	void draw(int hand_size);
	void print_hand() const;
    void print_top_card() const;
    int sum_hand();

private:
	std::vector<Card> m_hand_array;
    Deck * m_deck;
};


class Game
{
public:
    Game();
    ~Game() = default;

public:
    void play_blackjack();
    void game_loop();
    void print_deck() const;
    
private:
    Deck *m_game_deck;
    Hand *m_player_hand;
    Hand *m_dealer_hand;
    bool m_player_busted = false;
    bool m_dealer_busted = false;
};