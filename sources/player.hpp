/**
 * This class represents a card player.
 * 
 * @author Osama M. Ghaliah
*/

#ifndef player_hpp
#define player_hpp

#include <iostream>
using namespace std;

class Player {
    private:
        string name;
        int current_stack_size;
        int cards_won;

    public:
        // No-default contructor.
        Player(string name);
        // Default constructor.
        Player();
        // Copy constructor.
        Player(Player &player);
        // Destructor.
        ~Player();
        // This method returns how many cards this player has won so far.
        int cardesTaken();
        // This method returns how mnay cards are left in this player's stack.
        int stacksize();
        // This is a getter for this player's name.
        string getName();
        // This is a setter for this player's name.
        void setName(string name);
};

#endif