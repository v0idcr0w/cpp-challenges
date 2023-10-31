#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include "fn.hpp" 

int main() {
  greet(); 
  // Initialization of game variables
  char play = 'y'; 
  std::string codeword, answer; 
  int misses, random_index; 
  // tracks whether the play has made a correct guess 
  bool guess; 
  // stores current player guess
  char letter; 
  // keeps track of the player's incorrect guesses 
  std::vector<char> incorrect; 
  // possible codewords to select from 
  std::vector<std::string> codewords = {"alien", "broccoli", "sparrow", "nautilus"};


while (play == 'y') {
  // set seed
  srand(time(NULL));
  random_index = rand() % codewords.size();
  codeword = codewords[random_index]; 
  answer = init_answer(codeword); 
  misses = 0; 
  guess = false; 

  while (answer != codeword && misses < 7) {
    std::cout << "Enter your guess: "; 
    std::cin >> letter; 
    // make user input case-insensitive
    letter = std::tolower(letter);
    // check if letter is already a part of the incorrectly guessed letters to give the player another chance to guess
    check_letter(letter, incorrect); 
    
    // update the answer string based on the user input
    update_answer(letter, codeword, answer, guess); 
    
    if (!guess) {
      // add letter to incorrect list
      incorrect.push_back(letter); 
      std::cout << "Incorrect! The tractor beam pulls the person in further.\n"; 
      misses++;
    } else {
      std::cout << "Correct!\n";
      guess = false; 
    }
    display_misses(misses); 
    display_status(answer, incorrect); 

  }

  end_game(answer, codeword); 

  std::cout << "Do you want to play again? (y/n): ";
  std::cin >> play; 
  // reset the incorrect vector 
  incorrect.clear(); 
}   

return 0; 
}