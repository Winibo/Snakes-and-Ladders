/**
* @author Liam Boogaart <liam.boogaart@uleth.ca>
* @date 2022-01
*/

#ifndef HUMANPLAYER_H
#define HUMANPLAYER_H

#include <iostream>
#include <string>
#include <fstream>

#include "Player.h"
/**
* @class HumanPlayer HumanPlayer.h "HumanPlayer.h"
* @details Implementation of a human player for a board game
*/
class HumanPlayer : public Player {
 public:
  /**
  * Default constructor
  * @param startPosition The position for the player to start on
  * @param name The name of the player
  */
  HumanPlayer(int startPosition, std::string name);

  /**
  * @details Moves the player forward a by the amount roll.
  * Does not move if it would put the player farther than boardMax.
  * @param roll The amount the player rolled
  * @param boardMax The highest space on the board, player won't go past it
  * @return The position of the player on the board
  */
  int takeTurn(int roll, int boardMax);

 private:
  /**
  * Converts a string to all lowercase
  * @param input The string to convert
  * @return The input string in lowercase
  */
  std::string convertToLowercase(std::string input);

  /**
  * Displays the Games help message (located in help.txt)
  */
  void displayHelp();

  /**
  * Reads user input, if they want to roll, or get help
  */
  void getInput();
};

#endif
