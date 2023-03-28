/**
 * This class represents a single card that will be existed in a player's stack.
 * 
 * @author Osama M. Ghaliah
*/

#ifndef card_hpp
#define card_hpp

#include <iostream>
using namespace std;

class Card {
    private:
        char rank;
        string symbol;

    public:
        // Non-default constructor.
        Card(char rank, string symbol);
        // Default constructor.
        Card();
        // Copy constructor.
        Card(Card &card);
        // Destructor.
        ~Card();
        // Getters for this card's attributes.
        char getRank();
        string getSymbol();
        // Setters for this card's attributes.
        void setRank(char new_rank);
        void setSymbol(string new_symbol);
};

#endif