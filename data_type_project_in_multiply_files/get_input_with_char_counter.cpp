# include <iostream>
# include <conio.h>
# include <Windows.h>
# include <thread>
# include <vector>
# include <algorithm>
# include "daclaration_for_get_input.hpp"
# include "prototype_for_windows_file.hpp"


bool is_empty_line( std::string& string_from_vec ) {
    
	for (int counter{ 0 }; counter < string_from_vec.size(); ++counter) {
		
		if (string_from_vec[ counter ] != ' ' ) {
			return false;
		}
	}

	return true;
}

void terminals_empty_line_remover(std::vector<std::string>& terminal_content) {
	int empty_line_counter{ 0 };

	for (int counter{ 0 }; counter < terminal_content.size(); ++counter) {

		if (is_empty_line(terminal_content[counter])) {
			++empty_line_counter;
		}
	}

	terminal_content.resize(terminal_content.size() - (empty_line_counter ));


}


void erase_the_empty_chars(std::vector<std::string>& input_terminal_content ) {

	for (int counter{ 0 }; counter < input_terminal_content.size(); ++counter) {
		int empty_char_counter{ 0 };
        
		for (int nested_counter{ 0 }; nested_counter < input_terminal_content[counter].size(); ++nested_counter) {

			if (input_terminal_content[ counter ][ nested_counter ] == ' ' ) {
				++empty_char_counter;
			}

			else {
				empty_char_counter = 0;
			}

		}

		input_terminal_content[counter].resize(input_terminal_content[counter].size() - empty_char_counter);
	}
}


void erase_the_output_in_consol(std::vector<std::string>& input_consol_content, unsigned long long progeramer_requst_size) {
	saved_terminal_content(input_consol_content);

	for (int counter{ 0 }; counter < progeramer_requst_size; ++counter) {
		input_consol_content[0].erase(input_consol_content[counter].begin());
	}

	terminals_empty_line_remover(input_consol_content);
	erase_the_empty_chars(input_consol_content);

	change_xy(0, 10);

	for (int counter{ 0 }; counter < input_consol_content.size(); ++counter) {
		std::cout << input_consol_content[counter] << '\n';

	}

	std::cout << '\n';
	std::cout << "Size of the terminal : " << input_consol_content.size() << '\n';

	std::cout << '\n';
	std::cout << '\n';

	for (int counter{ 0 }; counter < input_consol_content.size(); ++counter) {
		std::cout << input_consol_content[counter].size() << '\n';
	}


}

void back_space_in_pipe_position_condition(int& users_input_in_ascii_code, unsigned long long progeramer_requst_size, unsigned long long& pipe_position_in_output_size, int& cursor_x_position,
	int& cursor_y_position, unsigned long long& char_counter_value, unsigned long long& line_counter, std::string& output , bool&is_pipe_condition_true) {

	if (users_input_in_ascii_code == 8 && pipe_position_in_output_size != output.size() && pipe_position_in_output_size != 0) {
		
		if (!is_pipe_condition_true) {
			is_pipe_condition_true = true;
			erase_the_strings_char_counter(0, line_counter + 1, char_counter_value);
		}
		
		--cursor_x_position;
		--pipe_position_in_output_size;
		cursor_y_position -= ((cursor_x_position == 0) ? 1 : 0);
		cursor_x_position += ((cursor_x_position == 0) ? terminals_lenght_in_run_time() : 0);
		output.erase(output.begin() + pipe_position_in_output_size);
		std::vector<std::string> terminal_content{};
		erase_the_output_in_consol(terminal_content, progeramer_requst_size);
		
		change_xy(cursor_x_position, cursor_y_position);
	}


}

void get_input_from_user(std::string programer_request ) {
	std::cout << programer_request;
	static std::string output{};
	std::vector<std::string> vec_full_terminal_line_in_run_time{};
	std::string str_of_terminal_content_in_end_of_the_line {};
	static int cursor_x_position_in_run_time{ static_cast<int>( programer_request.size() ) };
	static int cursor_y_position_in_run_time{ 0 };
	unsigned long long output_size_for_pipe_position_in_run_time{};
	unsigned long long pipe_position_in_size_of_the_output{ 0 };
    unsigned long long char_counter{ 0 };
	bool is_back_space_key_pressed_in_run_time{ false };
	bool is_pipe_condition_true{ false };
	int test_value{ 0 };
	bool is_arrow_key_pressed_in_run_time{false};
    unsigned long long line_counter{ 0 };

	while (true) {
    
		if (_kbhit()) {;
			auto get_the_char_input_from_key_board_instently{ _getch() };
		    
			if (!is_arrow_key()) {

				if ((isdigit(get_the_char_input_from_key_board_instently) || std::isalpha(get_the_char_input_from_key_board_instently) || std::ispunct(get_the_char_input_from_key_board_instently) || get_the_char_input_from_key_board_instently == ' ') && get_the_char_input_from_key_board_instently != '\b'
					&& get_the_char_input_from_key_board_instently != '\t' && !is_arrow_key() && cursor_x_position_in_run_time != terminals_lenght_in_run_time() ) {
					is_pipe_condition_true = false;
					str_of_terminal_content_in_end_of_the_line.push_back(static_cast<char>(get_the_char_input_from_key_board_instently));
					change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
					std::cout << static_cast<char>(get_the_char_input_from_key_board_instently);
					++cursor_x_position_in_run_time;
					++char_counter;
					++pipe_position_in_size_of_the_output;
				    show_the_char_counter(cursor_x_position_in_run_time, cursor_y_position_in_run_time);

					if (cursor_x_position_in_run_time == terminals_lenght_in_run_time()) {
						vec_full_terminal_line_in_run_time.push_back(str_of_terminal_content_in_end_of_the_line);
						str_of_terminal_content_in_end_of_the_line.clear();
					}

					show_char_counter_value(char_counter, cursor_x_position_in_run_time, cursor_y_position_in_run_time);
					change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
					line_counter += ((cursor_x_position_in_run_time == terminals_lenght_in_run_time()) ? 1 : 0);
					cursor_y_position_in_run_time += ((cursor_x_position_in_run_time == terminals_lenght_in_run_time()) ? 1 : 0);
					erase_the_str_of_char_counter_in_run_time(cursor_x_position_in_run_time, cursor_y_position_in_run_time, char_counter, is_back_space_key_pressed_in_run_time);
					cursor_x_position_in_run_time -= ((cursor_x_position_in_run_time == terminals_lenght_in_run_time()) ? terminals_lenght_in_run_time() : 0);
					output.push_back(static_cast<char>(get_the_char_input_from_key_board_instently));
					output_size_for_pipe_position_in_run_time = output.size();
				}

				else if (get_the_char_input_from_key_board_instently == '\b' && !output.empty() && cursor_x_position_in_run_time <= terminals_lenght_in_run_time() && pipe_position_in_size_of_the_output != 0 && pipe_position_in_size_of_the_output == output.size()) {
					is_pipe_condition_true = false;
					is_back_space_key_pressed_in_run_time = true;
					std::cout << "\b \b";
					--cursor_x_position_in_run_time;
					--char_counter;
					--pipe_position_in_size_of_the_output;
					line_counter -= ((cursor_x_position_in_run_time == 0) ? 1 : 0);
					show_the_char_counter(cursor_x_position_in_run_time, cursor_y_position_in_run_time);

					if (cursor_x_position_in_run_time == terminals_lenght_in_run_time() - 1) {
						change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
						std::cout << ' ';
					}
					
					change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
					show_char_counter_value(char_counter, cursor_x_position_in_run_time, cursor_y_position_in_run_time);
					change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
					cursor_y_position_in_run_time -= ((cursor_x_position_in_run_time == 0) ? 1 : 0);
					erase_the_str_of_char_counter_in_run_time(cursor_x_position_in_run_time, cursor_y_position_in_run_time, char_counter, is_back_space_key_pressed_in_run_time);
					cursor_x_position_in_run_time += ((cursor_x_position_in_run_time == 0) ? terminals_lenght_in_run_time() : 0);
					output.pop_back();
					output_size_for_pipe_position_in_run_time = output.size();
					is_back_space_key_pressed_in_run_time = false;

				}

				else if (get_the_char_input_from_key_board_instently == '\r') {
					break;
				}
			}

			/*
			back_space_in_pipe_position_condition(get_the_char_input_from_key_board_instently, programer_request.size(), pipe_position_in_size_of_the_output,
				cursor_x_position_in_run_time, cursor_y_position_in_run_time, char_counter, line_counter, output, is_pipe_condition_true);
			*/

			
			
			if (pipe_position_in_size_of_the_output != output.size() && pipe_position_in_size_of_the_output != 0 && get_the_char_input_from_key_board_instently == 8) {

				if (!is_pipe_condition_true) {
					is_pipe_condition_true = true;
					erase_the_strings_char_counter(0, line_counter + 1, char_counter);
				}

				
				std::vector<std::string> vec_of_terminal_content{};
				--cursor_x_position_in_run_time;
				--pipe_position_in_size_of_the_output;
				--char_counter;
				cursor_y_position_in_run_time -= ((cursor_x_position_in_run_time == 0) ? 1 : 0);
				cursor_x_position_in_run_time += ((cursor_x_position_in_run_time == 0) ? terminals_lenght_in_run_time() : 0);
				output.erase(output.begin() + pipe_position_in_size_of_the_output );
				saved_terminal_content(vec_of_terminal_content);
				terminals_empty_line_remover(vec_of_terminal_content );

				for (int counter{ 0 }; counter < programer_request.size(); ++counter) {
					vec_of_terminal_content[0].erase(vec_of_terminal_content[0].begin());
				}

				erase_the_empty_chars(vec_of_terminal_content);

				for (int counter{ 0 }; counter < vec_of_terminal_content.size(); ++counter) {
					std::fill(vec_of_terminal_content[counter].begin(), vec_of_terminal_content[counter].end(), ' ');
				}


				change_xy(programer_request.size(), 0);

				for (int counter{ 0 }; counter < vec_of_terminal_content.size(); ++counter) {
					std::cout << vec_of_terminal_content[counter]; 
				}

				change_xy(programer_request.size(), 0);
				std::cout << output;

				line_counter -= (((output.size() + programer_request.size()) % terminals_lenght_in_run_time() == 0) ? 1 : 0);
				change_xy(0, line_counter + 1);
				std::cout << "Strings char counter : ";
				show_char_counter_value(char_counter, cursor_x_position_in_run_time, line_counter);

				if ((output.size() + programer_request.size()) % terminals_lenght_in_run_time() == 0) {
					change_xy(0, line_counter + 2);
                    
					for (int counter{ 0 }; counter < 24 + std::to_string(char_counter).size(); ++counter) {
						std::cout << ' ';
					}

				}

				change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
			}
			

			if (is_arrow_key()) {
				is_arrow_key_pressed_in_run_time = true;

				if (get_the_char_input_from_key_board_instently == 75 && pipe_position_in_size_of_the_output != 0 ) {
					--pipe_position_in_size_of_the_output;
					--cursor_x_position_in_run_time;
					cursor_y_position_in_run_time -= ((cursor_x_position_in_run_time == 0 ) ? 1 : 0);
					cursor_x_position_in_run_time += ((cursor_x_position_in_run_time == 0 )? terminals_lenght_in_run_time() : 0);
					change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
				}

				else if (get_the_char_input_from_key_board_instently == 77 && pipe_position_in_size_of_the_output != output.size() ) {
					++pipe_position_in_size_of_the_output;
					++cursor_x_position_in_run_time;
					cursor_y_position_in_run_time += ((cursor_x_position_in_run_time == terminals_lenght_in_run_time() )? 1 : 0 );
					cursor_x_position_in_run_time -= ((cursor_x_position_in_run_time == terminals_lenght_in_run_time()) ? terminals_lenght_in_run_time() : 0);
					change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
				}
			}   

			



		}
	}

	change_xy(0, 20);
    
	/*
	std::cout << "output char size : " << output.size() << '\n';
	std::cout << "pipe l : " << output_size_for_pipe_position_in_run_time << '\n';
	std::cout << "x : " << cursor_x_position_in_run_time << '\n';
	std::cout << "y : " << cursor_y_position_in_run_time << '\n';
	*/
//	std::cout << "ascii : " << ge << '\n';


	/*

	std::cout << "pipe position in output size : " << pipe_position_in_size_of_the_output << '\n';
	std::cout << "output size : " << output.size() << '\n';
	std::cout << "Line counter : " << line_counter << '\n';
	std::cout << "cursor x position : " << cursor_x_position_in_run_time << '\n';
	std::cout << "cursor y position : " << cursor_y_position_in_run_time << '\n';
    
	*/

	std::cout <<"output : " << output << '\n';

}

//# endif