#include <iostream>

void initialize_board(char (*board)[3]) {
  int coord = 0;  
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      board[i][j] = static_cast<char>(coord + '0'); 
      coord++; 
    }
  }
}

void initialize_coords(int coords[9][2]) {
  for (int i = 0; i < 9; i++) {
    coords[i][0] = i / 3; 
    coords[i][1] = i % 3; 
  }
}

void display_board(char (*board)[3]) {
    for (int i = 0; i < 3; i++) {
    std::cout << "     |     |     \n";
    for (int j = 0; j < 3; j++) {
      std::cout << "  " << board[i][j]; 
      if (j != 2) {
        std::cout << "  |";  
      }
    }
    std::cout << "\n"; 
    if (i != 2) {
      std::cout << "_____|_____|_____\n";
    } else {
      std::cout << "     |     |    \n";
    }
    
  }
}

void update_board(char board[3][3], int player_coord[2], char player_symbol) {
  board[player_coord[0]][player_coord[1]] = player_symbol; 
}

void prompt_player(char board[3][3], int coords[9][2], int &player_location, int player_coord[2]) {
  bool is_valid_location, is_valid_coord;
  is_valid_location = false;
  is_valid_coord = false;  
  std::cout << "Choose a location from 0 to 8 according to what is available in the board: ";
  
  while (true) 
  {
  std::cin >> player_location;  

  is_valid_location = player_location <= 8 && player_location >= 0; 
  if (!is_valid_location) {
    std::cout << "Invalid position. Please provide a valid position: "; 
    continue; 
  }

  // location has to be valid (from 0 to 8)
  player_coord[0] = coords[player_location][0];
  player_coord[1] = coords[player_location][1]; 
  
  // check if coords are available 
  is_valid_coord = board[player_coord[0]][player_coord[1]] != 'X' && board[player_coord[0]][player_coord[1]] != 'O'; 

  if (!is_valid_coord) {
    std::cout << "Position already occupied. Please provide a valid position: "; 
  } else {
    break; 
  }

  }
}

bool check_horizontal_win(char board[3][3], int coords[9][2], char player_symbol) {
  int offset = 0; 
  bool horizontal_win = false;   
  for (int offset = 0; offset < 9; offset += 3) // outer loop controls the row that is being checked  
  {
    for (int i = 0; i < 3; i++) { 
    // inner loop controls the column
    horizontal_win = board[coords[offset+i][0]][coords[offset+i][1]] == player_symbol; 
    if (!horizontal_win) {
      break; // skip checking this row 
    }
    }
    if (horizontal_win) {
      break; 
    }
  }
return horizontal_win; 
}


bool check_vertical_win(char board[3][3], int coords[9][2], char player_symbol) {
  int offset = 0; 
  bool vertical_win = false;   
  for (int offset = 0; offset < 3; offset ++) // outer loop controls the column that is being checked
  {
    for (int i = 0; i < 9; i+=3) { 
    // inner loop controls the row
    vertical_win = board[coords[offset+i][0]][coords[offset+i][1]] == player_symbol; 
    if (!vertical_win) {
      break; // skip checking this column 
    }
    }
    if (vertical_win) {
      break; 
    }
  }
return vertical_win; 
}

bool check_diagonal_win(char board[3][3], int coords[9][2], char player_symbol) {

  bool main_diagonal_win, sec_diagonal_win;
  main_diagonal_win = false; 
  sec_diagonal_win = false; 

  // check for a win across the main diagonal
  for (int i = 0; i <= 8; i+=4) {
    main_diagonal_win = board[coords[i][0]][coords[i][1]] == player_symbol; 
    if (!main_diagonal_win) {
      break; // skip checking this diagonal  
    }
  }

  // check for win across the secondary diagonal 
  for (int i = 2; i <= 6; i+=2) {
    sec_diagonal_win = board[coords[i][0]][coords[i][1]] == player_symbol; 
    if (!sec_diagonal_win) {
      break; // skip checking this diagonal  
    }
  }

  return main_diagonal_win || sec_diagonal_win; //returns true if either of these is true
}

bool check_win(char board[3][3], int coords[9][2], char player_symbol) {
  // calls all of the other functions 
  bool horizontal_win = check_horizontal_win(board, coords, player_symbol);
  bool vertical_win = check_vertical_win(board, coords, player_symbol); 
  bool diagonal_win = check_diagonal_win(board, coords, player_symbol);
  // returns true if any of these are satisfied
  return horizontal_win || vertical_win || diagonal_win; 
}