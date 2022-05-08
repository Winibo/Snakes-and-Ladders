/**
* @author Liam Boogaart <liam.boogaart@uleth.ca>
* @date 2022-01
*/

#ifndef PLAYER_H
#define PLAYER_H

#include <string>

/**
* @class Player Player.h "Player.h"
* @details Abstract class implementing a player for a board game
*/
class Player {
 public:
  /**
  * Default constructor, player will start on space specified.
  * Player's name will be the name specified.
  * @param startPosition the space the player starts on.
  * @param name the name of the player.
  */
  Player(int startPosition, std::string name);

  /**
  * Moves player to specified position
  * @param position the position to move the player to.
  */
  void setPosition(int position);

  /**
  * Returns the player's position on the board
  * @return the position the player is on
  */
  int getPosition();

  /**
  * Returns the player's name
  * @return The name of the player
  */
  std::string getName();

  /**
  * Takes a turn, moving forward the number of spaces specified by roll.
  * Returns the space the player is on.
  * Returns -1 if the players turn was not completed.
  * @param roll amount for the player to move.
  * @param boardMax maximum space on the board, player can't move past it.
  * @return The position the player is on
  */
  virtual int takeTurn(int roll, int boardMax) = 0;

 private:
  int boardPosition;
  std::string Playername;
};


#endif
