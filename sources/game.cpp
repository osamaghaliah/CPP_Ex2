#include "game.hpp"

Game::Game() {
    /* To be continued in part B... */
}

Game::Game(Player first_player, Player second_player) {
    /* To be continued in part B... */
}

Game::Game(Game &game) {
    /* To be continued in part B... */
}

Game::~Game() {
    /* To be continued in part B... */
}

Player Game::get_first_player() {
    /* To be continued in part B... */

    return *(new Player());
}

Player Game::get_second_player() {
    /* To be continued in part B... */

    return *(new Player());
}

int Game::get_current_round() {
    /* To be continued in part B... */

    return 0;
}

bool Game::get_isDone() {
    /* To be continued in part B... */

    return true;
}
        
void Game::set_first_player(Player new_player) {
    /* To be continued in part B... */
}

void Game::set_second_player(Player new_player) {
    /* To be continued in part B... */
}

void Game::set_current_round(int new_round) {

}

void Game::set_isDone(bool isDone) {
    /* To be continued in part B... */
}

void Game::playTurn() {
    /* To be continued in part B... */
}

void Game::printLastTurn() {
    /* To be continued in part B... */
}

void Game::playAll() {
    /* To be continued in part B... */
}

void Game::printWiner() {
    /* To be continued in part B... */
}

void Game::printLog() {
    /* To be continued in part B... */
}

void Game::printStats() {
    /* To be continued in part B... */
}