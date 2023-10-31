void initialize_board(char (*board)[3]); 
void initialize_coords(int coords[9][2]); 
void display_board(char (*board)[3]); 
void update_board(char board[3][3], int player_coord[2], char player_symbol); 
void prompt_player(char board[3][3], int coords[9][2], int &player_location, int player_coord[2]); 
bool check_horizontal_win(char board[3][3], int coords[9][2], char player_symbol); 
bool check_vertical_win(char board[3][3], int coords[9][2], char player_symbol); 
bool check_diagonal_win(char board[3][3], int coords[9][2], char player_symbol); 
bool check_win(char board[3][3], int coords[9][2], char player_symbol); 