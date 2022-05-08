//
// @author Liam Boogaart <liam.boogaart@uleth.ca>
// @date 2022-01
//

#include "Player.h"

#include <string>

Player::Player(int startPosition = 0, std::string name = ""):
  boardPosition(startPosition), Playername(name) {
}

void Player::setPosition(int position) {
  boardPosition = position;
}

int Player::getPosition() {
  return boardPosition;
}

std::string Player::getName() {
  return Playername;
}
