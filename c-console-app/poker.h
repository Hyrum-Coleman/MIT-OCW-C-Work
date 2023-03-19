#pragma once
#include <string>
#include <vector>


class card
{
public:
	card(int card_val, std::string card_suit);
	[[nodiscard]] int get_card_val() const { return m_card_val; }
	[[nodiscard]] std::string get_card_face() const { return m_card_suit; }

private: //private variables
	int m_card_val; // 2-14 2 through Ace (not value added in game of blackjack, just raw value)
	std::string m_card_suit; // "clubs", "diamonds" "spades" "hearts"

};


class deck
{
public:
	deck();

	static void set_num_cards(int num_cards);
	[[nodiscard]] int get_num_cards() const { return m_num_cards_in_deck; }

public: // public methods
	void shuffle();
	void print_deck() const;

protected:
	std::vector<card> m_card_array;
	static int m_num_cards_in_deck;
};


class hand : public deck
{
public:
	hand(int num_cards);


public:
	void draw();
	void print_hand() const;

private:
	std::vector<card> m_hand_array;
};