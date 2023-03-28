/**
 * This class represents a cards game that will be played between two rivals.
 * 
 * @author Osama M. Ghaliah
*/

#ifndef game_hpp
#define game_hpp

#include "player.hpp"
#include "namespace.hpp"

using namespace std;

class Game {
    private:
        Player first_player;
        Player second_player;
        int current_round;
        bool isDone;

    public:
        // Non-default constructor.
        Game(Player first_player, Player second_player);
        // Default constructor.
        Game();
        // Copy constructor
        Game(Game &game);
        // Destructor.
        ~Game();
        // Getters for this game's attributes.
        Player get_first_player();
        Player get_second_player();
        int get_current_round();
        bool get_isDone();
        // Setters for this game's attributes.
        void set_first_player(Player new_player);
        void set_second_player(Player new_player);
        void set_current_round(int new_round);
        void set_isDone(bool isDone);
        // This method let the two players play a one single round.
        void playTurn();
        // This method prints what has happened in the latest round that was played.
        void printLastTurn();
        // This method plays the rounds left so the game ends.
        void playAll();
        // This method prints the name of the winner.
        void printWiner();
        // This method prints whatever happened in each round that was played.
        void printLog();
        // This method prints final summarized-statistics of each player once the game ends.
        void printStats();
};

#endif