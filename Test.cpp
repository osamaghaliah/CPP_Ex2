/**
 * This file represents a complete test which tests correctness of a cards game that will be played between two rivals.
 * It includes 3 essential cases:
 *  1. Testing correctness of objects initializations.
 *  2. Testing a game that HAD NO DRAWS OCCURED.
 *  3. Testing a game that HAD DRAWS OCCURED.
 * 
 * @author Osama M. Ghaliah
*/

#include "doctest.h"
#include "sources/game.hpp"
#include "sources/player.hpp"
#include "sources/card.hpp"

/*
    This test case tests if the instances creation of each class works perfectly. 
*/
TEST_CASE("Testing correctness of objects initializations") {
    // Identifying two players.
    Player first_player("Khabib Nurmagomedov");
    Player second_player("Connor McGregor");
    
    // Making sure that the given names were successfully assigned to the suitable players.
    CHECK((first_player.getName() == "Khabib Nurmagomedov" && second_player.getName() == "Connor McGregor"));
    
    // Making sure that the constructor has given each player 26 cards as an intitial number of cards.
    CHECK((first_player.stacksize() == 26 && second_player.stacksize() == 26));

    // Making sure that before starting the game, each player has NOT won any cards yet.
    CHECK((first_player.cardesTaken() == 0 && second_player.cardesTaken() == 0));

    // Identifying a game: Khabib vs. Connor McGregor
    Game game(first_player, second_player);

    // Making sure that the two rivals have successfully joined the game.
    CHECK((game.get_first_player().getName() == "Khabib Nurmagomedov" && game.get_second_player().getName() == "Connor McGregor"));

    // Identifying two cards.
    Card Queen('Q', "Hearts");
    Card King('K', "Diamonds");

    // Making sure that the given attributes were successfully assigned to the suitable cards.
    CHECK((Queen.getRank() == 'Q' && Queen.getSymbol() == "Hearts"));
    CHECK((King.getRank() == 'K' && King.getSymbol() == "Diamonds"));
}

/*
    This test case tests a complete game that had no draws with various scenarios.
*/
TEST_CASE("Testing a game that HAD NO DRAWS OCCURED") {
    // Setting up a game with the rivals.
    Player player1("Alex");
    Player player2("Jack");
    Game game_without_draws(player1, player2);
    
    // Playing first 10 rounds.
    for (int i = 1; i <= 10; i++) {
        game_without_draws.playTurn();
    }
    
    // Making sure that the current round of this game is actually 11 (10th round is already done).
    CHECK(game_without_draws.get_current_round() == 11);

    // Making sure that the game has NOT ended yet and that NONE of the players stack has ran out of cards.
    CHECK(game_without_draws.get_isDone() == false);
    CHECK((game_without_draws.get_first_player().stacksize() > 0 && game_without_draws.get_second_player().stacksize() > 0));
    
    // Checking whether both players are now holding the same amount of cards in their stacks. (26 - 10 = 16).
    CHECK(player1.stacksize() == player2.stacksize());

    // Playing another 6 rounds.
    for (int i = 1; i <= 6; i++) {
        game_without_draws.playTurn();
    }

    // Making sure that the current round of this game is actually 17 (16th round is already done).
    CHECK(game_without_draws.get_current_round() == 17);

    // Checking whether both players are now holding the same amount of cards in their stacks after another 6 rounds. (16 - 6 = 10).
    CHECK(player1.stacksize() == player2.stacksize());

    // Continuing the game till the end.
    game_without_draws.playAll();

    // Since the game ended, both players should be holding 0 cards left.
    CHECK(((player1.stacksize() == 0) && (player2.stacksize() == 0)));

    // Making sure that the game has actually ended.
    CHECK(game_without_draws.get_isDone() == true);

    // Determining the winner.
    CHECK(game_without_draws.get_first_player().cardesTaken() < game_without_draws.get_second_player().cardesTaken());
    CHECK(game_without_draws.get_first_player().cardesTaken() > game_without_draws.get_second_player().cardesTaken());
}

/*
    This test case tests a complete game that had draws with various scenarios.
*/
TEST_CASE("Testing a game that HAD DRAWS OCCURED") {
    // Setting up a new game with new rivals.
    Player player1("Andrew");
    Player player2("Tristan");
    Game game_with_draws(player1, player2);

    // Since the game has NOT started yet, the current round should be 0.
    CHECK(game_with_draws.get_current_round() == 0);

    // Playing first 7 rounds.
    for (int i = 1; i <= 7; i++) {
        game_with_draws.playTurn();
    }

    // Making sure that the game has NOT ended yet and that NONE of the players stack has ran out of cards.
    CHECK(game_with_draws.get_isDone() == false);
    CHECK((game_with_draws.get_first_player().stacksize() > 0 && game_with_draws.get_second_player().stacksize() > 0));
    
    // Making sure that the current round of this game is actually 8 (7th round is already done).
    CHECK(game_with_draws.get_current_round() == 8);

    // Checking whether any draws has occured in the first 7 rounds. If so, each player should be holding AT MOST 18 cards in his stack.
    CHECK(game_with_draws.get_first_player().stacksize() <= 18);
    CHECK(game_with_draws.get_second_player().stacksize() <= 18);

    // Determining the CURRENT leading winner of the first 7 rounds.
    CHECK(game_with_draws.get_first_player().cardesTaken() < game_with_draws.get_second_player().cardesTaken());
    CHECK(game_with_draws.get_first_player().cardesTaken() > game_with_draws.get_second_player().cardesTaken());

    // Playing another 3 rounds such that in each round a draw has actually occured.
    for (int i = 1; i <= 3; i++) {
        game_with_draws.playTurn();
    }

    // After 3 rounds of draw, checking if each player is currently holding AT MOST 13 cards left in his stack.
    CHECK(game_with_draws.get_first_player().stacksize() <= 13);
    CHECK(game_with_draws.get_second_player().stacksize() <= 13);

    // Making sure that the current round of this game is actually 11 (10th round is already done).
    CHECK(game_with_draws.get_current_round() == 11);

    // Continuing the match till the end.
    game_with_draws.playAll();

    // Since the game ended, both players should be holding 0 cards left.
    CHECK(((player1.stacksize() == 0) && (player2.stacksize() == 0)));

    // Making sure that the game has actually ended.
    CHECK(game_with_draws.get_isDone() == true);

    // Determining the winner.
    CHECK(game_with_draws.get_first_player().cardesTaken() < game_with_draws.get_second_player().cardesTaken());
    CHECK(game_with_draws.get_first_player().cardesTaken() > game_with_draws.get_second_player().cardesTaken());
}