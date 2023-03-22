#include "hand.h"


/*

Hand Class

 */

Hand::Hand(Deck* deck, int hand_size)
{
    m_deck = deck;
    draw(hand_size);
}

void Hand::draw(int hand_size)
{
    for (int i = 0; i < hand_size; i++)
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

int Hand::sum_hand()
{
    int ret_sum = 0;
    for (auto& i : m_hand_array) // sums card vals except aces
    {
        if (i.get_string_card_val() == "Ace") // ignore aces until all other cards are summed
        {
            continue;
        }
        if ((i.get_card_val() > 10) && (i.get_card_val() < 14)) // These are all the face cards except the ace
        {
            ret_sum += 10;
        }
        else
        {
            ret_sum += i.get_card_val();
        }
    }

    for (auto& i : m_hand_array) // now handle the aces
    {
        if ((i.get_string_card_val() == "Ace") && ((ret_sum + 11) <= 21))
        {
            ret_sum += 11;
        }
        else if (i.get_string_card_val() == "Ace")
        {
            ret_sum += 1;
        }
    }

    return ret_sum;
}