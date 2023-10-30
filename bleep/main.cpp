#include <iostream>
#include <string> 
#include "fn.hpp"

int main() {
  /* 
  Write a bleep() function that takes in word and text strings and replaces each word occurrence in the text with a '*' 
  */

  std::string word = "broccoli"; 
  std::string text = "My favorite vegetable is broccoli. In particular, steamed broccoli is the best way to serve broccoli."; 

  bleep(word, text);  

  std::cout << text << "\n"; 

  return 0; 
}