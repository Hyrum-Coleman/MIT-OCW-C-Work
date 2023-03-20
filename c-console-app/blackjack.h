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
	void draw();
	void print_hand() const;

private:
	std::vector<Card> m_hand_array;
    Deck * m_deck;
};


class Game
{

};