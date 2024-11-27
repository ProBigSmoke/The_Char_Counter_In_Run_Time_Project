
# ifndef PROTOTYPE_FOR_WINDOWS_FILE
# define PROTOTYPE_FOR_WINDOWS_FILE
# include <vector>

void change_xy(int, int);
int terminals_lenght_in_run_time();
int terminals_width_in_run_time();
void saved_terminal_content ( std::vector<std::string>&);
void fill_the_buffer(char char_to_fill, int x_coordinate, int y_coordinate, int char_number_to_fill_in_each_line);

#endif 
