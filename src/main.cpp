//
// @author Liam Boogaart <liam.boogaart@uleth.ca>, Justin ALho <alhoj@uleth.ca>
// @date 2022-01
//

#include "Player.h"
#include "AIPlayer.h"
#include "HumanPlayer.h"
#include "Event.h"
#include "Board.h"
#include <string>
#include <random>
#include <ctime>
#include <iostream>
#include <fstream>

//Demoing player classes so I remember how they work
//More or less all of this should be in the board class? - Liam
int main() {
  Board gameBoard;

  gameBoard.runGame();

  return 0;
}
