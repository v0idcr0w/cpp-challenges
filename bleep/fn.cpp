#include <iostream>
#include <string> 

void bleep(std::string word, std::string &text) {

  int idx_stop, idx_start; 
  std::string current_word = ""; 
  for (int i = 0; i < text.length(); i++) {

    if (text[i] != ' ' && text[i] != '.' && text[i] != ',') {
      // building the current word in text 
      current_word += text[i];

    } else {

      if (word == current_word) {
        // time to make the replacement  
        idx_stop = i - 1; 
        idx_start = i - word.length();

        for (int k = idx_start; k <= idx_stop; k++) {
          // replace by asterisks
          text[k] = '*'; 
        }
      }
      current_word = ""; 
    }
  
  }

}