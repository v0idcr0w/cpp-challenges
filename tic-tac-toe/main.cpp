#include <iostream>
#include <vector>
#include <string>
#include "fn.hpp"

int main() {
  /*
  Description: two-player tic-tac-toe with a 3x3 board 
  */
  char board[3][3]; //3x3 array of characters
  initialize_board(board);

  int coords[9][2]; // array of mappings of board locations (index 0 to 8) to coordinates
  initialize_coords(coords); 

  // initialize player symbols
  char player1_symbol = 'X'; 
  char player2_symbol = 'O'; 

  int player1_location, player2_location; 
  int player1_coord[2], player2_coord[2]; 
  // there are, at most, 9 possible plays until the game is over
  int num_plays = 0; 
  bool player1_win, player2_win; // tracks if one of the player has won
  // show the board
  display_board(board);
  while (!player1_win && !player2_win) {
   // player1 turn
   // ask the player1 for a valid location in the board 
   std::cout << "\nPlayer 1 turn\n"; 
   prompt_player(board, coords,     player1_location, player1_coord); 
   num_plays++; 
   // update the board according to the player's location
   update_board(board, player1_coord, player1_symbol); 
   // render the board again 
   display_board(board);
   // check for win 
   player1_win = check_win(board, coords, player1_symbol); 
   // check for draws or player1 winning
   if ((num_plays == 9 && !player1_win && !player2_win) || player1_win) {
    break; 
   }

   // likewise for player2 
   std::cout << "\nPlayer 2 turn\n"; 
   prompt_player(board, coords, player2_location, player2_coord); 
   num_plays++; 
   update_board(board, player2_coord, player2_symbol); 
   display_board(board);
   player2_win = check_win(board, coords, player2_symbol); 
  }


 // print final message
 if (player1_win) {
  std::cout << "Player 1 wins!\n"; 
 } else if (player2_win) {
  std::cout << "Player 2 wins!\n"; 
 } else {
  std::cout << "Game ended in a draw - no one wins.\n"; 
 }

  return 0; 
}