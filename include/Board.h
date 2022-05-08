/**
* @author Liam Boogaart <liam.boogaart@uleth.ca>, Justin Alho <alhoj@uleth.ca>
* @date 2022-01
*/

#ifndef BOARD_H
#define BOARD_H

#include "Player.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "Event.h"
#include <string>
#include <random>
#include <ctime>
#include <iostream>
#include <fstream>

/**
* @class Board Board.h "Board.h"
* @details Implementation of the "board" for Chutes & Ladders.
*/
class Board {
 public:
  /**
  * Default constructor
  * @param players The total number of players in the game. Defaults to 3.
  * @param humanPlayers The number of human players in the game. Defaults to 1.
  * @param startSpace The space to start the game on. Defaults to 0.
  * @param custom if true, human players get custom names, Defaults to false.
  * @param minimumRoll The min amount that can be rolled. Defaults to 1.
  * @param maximumRoll The max amount that can be rolled. Defaults to 6.
  * @param boardMax The final space on the board. Defaults to 50.
  */
  Board(int players = 3, int humanPlayers = 1, int startSpace = 0,
  bool custom = false, int minimumRoll = 1, int maximumRoll = 6,
  int boardMax = 50);

  /**
  * Destructor
  */
  ~Board();

  /**
  * Runs the game until a player has won by landing on the final space.
  */
  void runGame();

  /**
  * Creates board events from the events.txt file.
  */
  void createEvents();

 private:
  Event** eventList;
  Player** playerList;
  int finalPlayer;
  int eventListSize;
  int finalEvent;
  bool gameOver;
  std::default_random_engine engine;
  int minRoll;
  int maxRoll;
  int startSpace;
  int finalSpace;
  /**
  * Initializes the list of players on the board.
  * @param players The total number of players on the board.
  * @param humanPlayers The number of human players if > players, set = players.
  * @param startSpace The space for every player to start the game on.
  * @param custom If true, asks human players to name themselves.
  */
  void initPlayer(int players, int humanPlayers, int startSpace, bool custom);

  /**
  * Increases the capacity of eventList.
  */
  void expandEventList();

  /**
  * Gets a name from the user(s). used by initPlayer if custom is true.
  * @param name The player that should input their name.
  * @return The name the player entered that should be used.
  */
  std::string getName(std::string name);

  /**
  * Converts a string to all lowercase.
  * @param input The string to convert.
  * @return The input string in lowercase.
  */
  std::string convertToLowercase(std::string input);

  /**
  * Asks the player if they want to play again.
  * Runs reset function if player wants to play again.
  * @return True if the player wants to play again, false otherwise.
  */
  bool askReset();

  /**
  * Resets player positions so the game can be played again.
  */
  void reset();
};

#endif
