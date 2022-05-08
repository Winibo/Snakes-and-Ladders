/**
* @author Liam Boogaart <liam.boogaart@uleth.ca>
* @date 2022-01
*/

#ifndef AIPLAYER_H
#define AIPLAYER_H


#include <string>

#include "Player.h"

/**
* @class AIPlayer AIPlayer.h "AIPlayer.h"
* @details Implementation of an AI player for a board game
*/
class AIPlayer : public Player {
 public:
  /**
  * Default constructor.
  * @param startPosition Position for the player to start at
  * @param name Name of the player
  */
  AIPlayer(int startPosition, std::string name);
  /**
  * @details Moves the player forward a by the amount roll.
  * Does not move if it would put the player farther than boardMax.
  * @param roll Amount the player rolled
  * @param boardMax highest space on board, player won't move past this
  * @return The position of the player on the board
  */
  int takeTurn(int roll, int boardMax);
 private:
};

#endif
