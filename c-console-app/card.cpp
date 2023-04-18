#include "Card.h"

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