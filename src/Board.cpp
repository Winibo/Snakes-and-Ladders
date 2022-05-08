/**
* @author Liam Boogaart <liam.boogaart@uleth.ca>, Justin Alho <alhoj@uleth.ca>
* @date 2022-01
*/

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

Board::Board
(int players, int humanPlayers, int startSpace, bool custom,
int minimumRoll, int maximumRoll, int boardMax)
:playerList(new Player*[players]), eventList(new Event*[4]), eventListSize(4),
finalEvent(0), finalPlayer(players), gameOver(false), minRoll(minimumRoll),
maxRoll(maximumRoll), finalSpace(boardMax), startSpace(startSpace) {
  initPlayer(players, humanPlayers, startSpace, custom);
  createEvents();
  engine.seed(time(0));
}

Board::~Board() {
  //Delete all the pointers that have been made

  //Delete all the Players
  for (int i = 0; i < finalPlayer; i++) {
    delete playerList[i];
  }
  delete [] playerList;
  //Delete all the events
  for (int i = 0; i < finalEvent; i++) {
    delete eventList[i];
  }
  delete [] eventList;
}

void Board::runGame() {
  std::uniform_int_distribution<int> distribution(minRoll, maxRoll);
  //Run the game until there is a winner
  do {
    //Run player's turns in order
    for (int i = 0; i < finalPlayer; i++) {
      int position = playerList[i]->takeTurn(distribution(engine), finalSpace);

      //Event logic
      for (int j = 0; j < finalEvent; j++) {
        eventList[j]->runEvent(playerList[i]);
      }
      //When somebody has landed on the final board space
      if (position == finalSpace) {
        std::cout << playerList[i]->getName() << " Has won, Congratulations "
        << playerList[i]->getName() << '!' << std::endl;
        std::cout << "Would you like to play again?" << std::endl;
        std::cout << "Type \"yes\" to play again, anything else to quit.";
        if (!askReset()) {
          gameOver = true; //This is the end of the game
        }
        break; //Exit the for loop, since a player has won the game
      }
      std::cout << std::endl;
    }
  } while (!gameOver);
  //display a message, then exit
  std::cout << "Thanks for playing!";
  return;
}

void Board::createEvents() {
  //Testing creating events, then displaying their properties
  const std::string EVENT_FILE = "include/events.txt";
  std::ifstream eventFile;
  eventFile.open(EVENT_FILE);
  //If we can't open the event file, display an error and exit
  if (eventFile.fail()) {
    std::cout << "Couldn't open the event file, sorry." << std::endl;
    return;
  }
  //Otherwise, we should read the file and create events
  int start;
  int end;
  bool ladder;
  eventFile >> start;
  eventFile >> end;
  if (start < end) {
    ladder = true;
  } else {
    ladder = false;
  }
  do {
    //Check we have space to add a new event
    if (finalEvent == eventListSize) {
      expandEventList(); //If not, create more space
    }
    eventList[finalEvent] = new Event(start, end, ladder);
    finalEvent++;
    eventFile >> start;
    eventFile >> end;
    if (start < end) {
      ladder = true;
    } else {
      ladder = false;
    }
  } while (!eventFile.eof());
}

void Board::initPlayer
(int players, int humanPlayers, int startSpace, bool custom) {
  //Error checking
  if (humanPlayers > players) {
    humanPlayers = players;
  }
  //Create all the human players
  for (int i = 0; i < humanPlayers; i++) {
    std::string name = "Player " + std::to_string(i+1);
    if (custom) name = getName(name);
    playerList[i] = new HumanPlayer(startSpace, name);
  }
  //Create all the AI Players
  for (int i = humanPlayers; i < players; i++) {
    //Starts with AI 1 and increments for each AI
    std::string name = "AI " + std::to_string((i - humanPlayers + 1));
    playerList[i] = new AIPlayer(startSpace, name);
  }
}

void Board::expandEventList() {
  Event** temp = new Event*[eventListSize*2];
  //Copy over all the events
  for (int i = 0; i < eventListSize; i ++) {
    temp[i] = eventList[i];
  }
  //reassign the eventList
  delete [] eventList;
  eventList = temp;
  eventListSize *= 2;
}

std::string Board::getName(std::string name) {
  std::cout << name << " please input your name" << std::endl;
  std::string input;
  std::getline(std::cin, input);
  return input;
}

std::string Board::convertToLowercase(std::string input) {
  //Iterate over every character
  for (int i = 0; i < input.length(); i++) {
    //Convert to lowercase
    input[i] = std::tolower(input[i]);
  }
  return input;
}

bool Board::askReset() {
  std::string input;
  // Read the input
  std::getline(std::cin, input);
  input = convertToLowercase(input); // Convert the input to lowercase
  if (input == "yes") { // If user wants to play again, reset the game
    reset();
    return true;
  } else {
    return false;
  }
}

//resets the game by setting each player's position to Starting space
void Board::reset() {
  for (int i = 0; i < finalPlayer; i++) {
    playerList[i]->setPosition(startSpace);
  }
}
