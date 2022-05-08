/**
* @author Liam Boogaart <liam.boogaart@uleth.ca>, Justin Alho <alhoj@uleth.ca>
* @date 2022-01
*/

#ifndef EVENT_H
#define EVENT_H

#include <iostream>
#include <string>

#include "Player.h"

/**
* @class Event Event.h "Event.h"
* @details Implementation of chutes/ladders, collectively known as events, for a board game.
*/
class Event {
 public:
  /**
  * Default constructor.
  * @param eventStart space the event starts on, where players have to land to trigger the event.
  * @param eventEnd space the event ends on, where players get put after the event.
  * @param isLadder, true if event is a ladder, false if it is a chute.
  \*/
  Event(int eventStart, int eventEnd, bool isLadder);

  /**
  * Returns the starting space of the event
  * @return the number space the event starts on
  */
  int getStart();

  /**
  * Returns the ending space of the event
  * @return the number space the event ends on
  */
  int getEnd();

  /**
  * Returns the type of event
  * @return the type of event as a string
  */
  std::string getType();

  /**
  * Runs the event if the player is on it's starting space
  * @param player the player to run the event on
  */
  void runEvent(Player* player);

 private:
  int eventStart;
  int eventEnd;
  bool isLadder;
};

#endif
