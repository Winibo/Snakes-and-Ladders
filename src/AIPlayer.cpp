//
// @author Liam Boogaart <liam.boogaart@uleth.ca>
// @date 2022-01
//

#include "AIPlayer.h"

#include <iostream>
#include <string>

#include "Player.h"

AIPlayer::AIPlayer(int startPosition = 0, std::string name = ""):
  Player(startPosition, name) {
}

int AIPlayer::takeTurn(int roll, int boardMax) {
  // Get the players name
  std::string name = getName();

  // Declare what the player rolled
  std::cout << name << " rolled a " << roll << std::endl;

  // Get the players current position on the board
  int position = getPosition();
  if (position + roll <= boardMax) {  // Move the player if they can be moved
    std::cout << name << " landed on space "
     << position + roll << "!" << std::endl;

    position = position + roll;
    setPosition(position);
  } else { // Otherwise, no movement occurs
    std::cout << name << " rolled too high to move" << std::endl;
  }
  return position;
}
