void greet(); 
void end_game(std::string answer, std::string codeword); 
void display_misses(int misses);
void display_status(std::string answer, std::vector<char> incorrect); 
std::string init_answer(std::string codeword); 
void check_letter(char &letter, std::vector<char> incorrect); 
void update_answer(char letter, std::string codeword, std::string &answer, bool &guess); 