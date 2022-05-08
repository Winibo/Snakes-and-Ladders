//
// @author Justin Alho <alhoj@uleth.ca>, Liam Boogaart <liam.boogaart@uleth.ca>
// @date 2022-01
//

#include "Event.h"

#include <iostream>
#include <string>

#include "Player.h"

Event::Event(int start = 0, int end = 0, bool ladder = true):
  eventStart(start), eventEnd(end), isLadder(ladder) {
}

int Event::getStart() {
  return eventStart;
}

int Event::getEnd() {
  return eventEnd;
}

std::string Event::getType() {
  if (isLadder) {
    return "ladder";
  } else {
    return "chute";
  }
}

void Event::runEvent(Player* player) {
  int position = player->getPosition();
  if (position == eventStart) {
    std::cout << player->getName() << " landed on a ";
    //Only difference is the language used
    if (isLadder) {
      std::cout << "ladder, they climb up to space ";
    } else {
      std::cout << "chute, they fall down to space ";
    }
    std::cout << eventEnd << '!' << std::endl;
    //Update the player's location
    player->setPosition(eventEnd);
  }
}
