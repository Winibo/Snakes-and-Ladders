//
// @author Liam Boogaart <liam.boogaart@uleth.ca>
// @date 2022-01
//

#include "HumanPlayer.h"

#include <iostream>
#include <string>
#include <fstream>

#include "Player.h"

HumanPlayer::HumanPlayer(int startPosition = 0, std::string name = ""):
  Player(startPosition, name) {
}

int HumanPlayer::takeTurn(int roll, int boardMax) {
  // Get the player's position
  int position = getPosition();
  //Inform the player it is their turn
  std::cout << getName() << ", it is your turn." << std::endl;

  // Get the player's input
  getInput();

  // Now we can roll the dice!
  std::cout << "You rolled a " << roll << std::endl;
  // Move the player forward on the board
  if (position + roll <= boardMax) {  // Move the player if they can be moved
    std::cout << "You landed on space " << position + roll << "!" << std::endl;
    position = position + roll;
    setPosition(position);
  } else { // Otherwise, no movement occurs
    std::cout << "You rolled too high to move" << std::endl;
  }
  return position;
}

std::string HumanPlayer::convertToLowercase(std::string input) {
  //Iterate over every character
  for (int i = 0; i < input.length(); i++) {
    //Convert to lowercase
    input[i] = std::tolower(input[i]);
  }
  return input;
}

void HumanPlayer::displayHelp() {
  //Location of the help file
  const std::string FILE_LOCATION = "include/help.txt";
  std::ifstream helpFile;
  helpFile.open(FILE_LOCATION);
  //If we can't open the help file, display an error and exit
  if (helpFile.fail()) {
    std::cout << "Couldn't open the help file, sorry." << std::endl;
    return;
  }
  //Otherwise, we should print the help file to the user
  std::string currentline;
  getline(helpFile, currentline);
  do {
    std::cout << currentline << std::endl;
    getline(helpFile, currentline);
  } while (!helpFile.eof());
  //Close the file now that we're done with it
  helpFile.close();
}

void HumanPlayer::getInput() {
  std::string input;
  do {
    // Output what we want the user to do
    std::cout << "Type help for help, type anything else to roll the dice";
    std::cout << std::endl;
    // Read the input
    std::getline(std::cin, input);
    input = convertToLowercase(input); // Convert the input to lowercase
    if (input == "help") { // Display help if requested
      displayHelp();
    }
  } while (input == "help"); // We can't continue until the user rolls the dice
}
