# include <iostream>
# include <string>
# include <vector>
# include <conio.h>
# include <thread>
# include <cctype>
# include <algorithm>
# include <windows.h>
# include "daclaration_for_get_input.hpp"
# include "prototype_for_windows_file.hpp"
# include "command_code_prototype.hpp"


bool is_all_space( std::string& output ) {
     
	for (int counter{ 0 }; counter < output.size(); ++counter) {

		if (output[counter] != ' ') {
			return false;
		}
	}


	return true;
}

char the_first_char_position( std::string& output , int& first_char_position) {

	for (int counter{ 0 }; counter < output.size(); ++counter) {
		
		if (output[counter] != ' ' ) {
			first_char_position = counter;
			
			for (int nested_counter{ 0 }; nested_counter < first_char_position; ++nested_counter) {
				output.erase(output.begin());
			}

			break;
		}

	}
	

	
	return output[0];
}

void data_changer_in_run_time(int& x_value_position, int& y_value_position, unsigned long long& pipe_position_in_ouptut_str, unsigned long long& line_counter) {
	--pipe_position_in_ouptut_str;
	--x_value_position;
	y_value_position -= ((x_value_position == 0) ? 1 : 0);
	line_counter -= ((x_value_position == 0) ? 1 : 0);
	x_value_position += ((x_value_position == 0) ? terminals_lenght_in_run_time() : 0);

}

void erasing_word_by_word_in_back_and_control_condition(std::string& output_str_type, const unsigned long long requst_size, int& cursor_x_position, int& cursor_y_position, unsigned long long& pipe_position_in_ouptut_str,
	unsigned long long& line_counter , std::vector<unsigned long long>& terminal_lenght_coefficients) {


	while (!output_str_type.empty() && output_str_type.back() == ' ') {
		output_str_type.pop_back();
		data_changer_in_run_time(cursor_x_position, cursor_y_position, pipe_position_in_ouptut_str, line_counter);
	}

	while (!output_str_type.empty() && output_str_type.back() != ' ') {
		output_str_type.pop_back();
		data_changer_in_run_time(cursor_x_position, cursor_y_position, pipe_position_in_ouptut_str, line_counter);
	}

	removed_the_std_output::erasing_the_terminal_content(requst_size);
	change_xy(requst_size, 0);
	std::cout << output_str_type;
}

void erasing_word_by_word_in_pipe_condition(std::string& output_str_type, const unsigned long long requst_size, int& cursor_x_position, int& cursor_y_position, unsigned long long pipe_position_in_ouptut_str , 
	unsigned long long& current_pipe_position_output_size , unsigned long long& line_counter, std::vector<unsigned long long>& terminal_lenght_coefficients) {
	

	while ( !output_str_type.empty() && current_pipe_position_output_size != 0 && output_str_type[ current_pipe_position_output_size - 1 ] == ' ') {
		output_str_type.erase(output_str_type.begin() + (current_pipe_position_output_size - 1));
		data_changer_in_run_time(cursor_x_position, cursor_y_position, current_pipe_position_output_size, line_counter);
	}
	

	
	while (!output_str_type.empty() && current_pipe_position_output_size != 0 && output_str_type[current_pipe_position_output_size - 1] != ' ') {
		output_str_type.erase(output_str_type.begin() + current_pipe_position_output_size);
		data_changer_in_run_time(cursor_x_position, cursor_y_position, current_pipe_position_output_size, line_counter);
	}
	
	removed_the_std_output::erasing_the_terminal_content(requst_size);
	change_xy(requst_size, 0);
	std::cout << output_str_type;


}

		
std::string get_the_input_from_user(std::string progeramer_request) {
	//std::cout << std::boolalpha;
	std::string output{};
	std::vector<unsigned long long> terminals_lenght_coefficients{};
	const unsigned long long progeramer_request_str_size{ progeramer_request.size() };
	unsigned long long pipe_position_size_of_the_output{ 0 };
	unsigned long long line_counter{ 0 };
	unsigned long long char_counter{};
	int default_terminal_lenght{ terminals_lenght_in_run_time() };
	int cursor_x_position_in_run_time{ static_cast<int>(progeramer_request_str_size) };
	int cursor_y_position_in_run_time{};
	bool is_user_anding_char_in_input{ false };
	bool bool_type_for_erasing_onece{ false };
	bool is_increasing{ false };
	int first_alpha_char_in_output_string{ 0 };
	std::cout << progeramer_request << '\n';
	change_xy(progeramer_request_str_size, 0);

	while (true) {

		if (_kbhit()) {
			auto get_the_input_in_ascii_code{ _getch() };
			bool is_corrent_input_to_add_in_users{ (isdigit(get_the_input_in_ascii_code) || std::isalpha(get_the_input_in_ascii_code) || std::ispunct(get_the_input_in_ascii_code) || get_the_input_in_ascii_code == ' ')
			&& get_the_input_in_ascii_code != '\b' && get_the_input_in_ascii_code != '\t' && !pipe_conditions::is_arrow_key() };

			if (!pipe_conditions::is_arrow_key()) {

				if (cursor_x_position_in_run_time != terminals_lenght_in_run_time()) {
					add_char_in_users_input(is_user_anding_char_in_input, is_corrent_input_to_add_in_users, output, line_counter, static_cast<char>(get_the_input_in_ascii_code),
						pipe_position_size_of_the_output, progeramer_request_str_size, cursor_x_position_in_run_time, cursor_y_position_in_run_time, terminals_lenght_coefficients, is_increasing);
				}

				if (cursor_x_position_in_run_time != 0) {
					pop_char_in_users_input(is_user_anding_char_in_input, static_cast<char>(get_the_input_in_ascii_code) == '\b' && !output.empty(), output, progeramer_request_str_size, pipe_position_size_of_the_output,
						cursor_x_position_in_run_time, cursor_y_position_in_run_time, line_counter, terminals_lenght_coefficients);
				}

				string_info_in_run_time::show_the_strings_char_value_2(output, progeramer_request_str_size, cursor_x_position_in_run_time, cursor_y_position_in_run_time, is_user_anding_char_in_input, terminals_lenght_coefficients);
				change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);


				if (static_cast<char>(get_the_input_in_ascii_code) == '\r') {

					/*
					char first_outputs_char{ the_first_char_position(output, first_alpha_char_in_output_string) };

					if (first_alpha_char_in_output_string == 0 && (first_outputs_char == ' ' || output.empty())) {
						output.clear();
						cursor_x_position_in_run_time = 0;
						++cursor_y_position_in_run_time;
						++line_counter;
						string_info_in_run_time::erase_the_strings_char_counter(0, line_counter, char_counter);
						change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
					}
                    
					*/
					//else {
						break;
					//}
				}
			}

			pipe_conditions::show_pipe_position_in_arrow_key_condition_in_run_time(pipe_conditions::is_arrow_key(), pipe_position_size_of_the_output, get_the_input_in_ascii_code, output.size(),
				cursor_x_position_in_run_time, cursor_y_position_in_run_time);
		}

		if (GetAsyncKeyState(VK_CONTROL) & 0x8000 && GetAsyncKeyState(VK_MENU) & 0x8000 ) {

			if (output.size() == pipe_position_size_of_the_output) {
				is_user_anding_char_in_input = false;
				erasing_word_by_word_in_back_and_control_condition(output, progeramer_request_str_size, cursor_x_position_in_run_time, cursor_y_position_in_run_time, pipe_position_size_of_the_output,
					line_counter, terminals_lenght_coefficients);

				string_info_in_run_time::show_the_strings_char_value_2(output, progeramer_request_str_size, cursor_x_position_in_run_time, cursor_y_position_in_run_time, is_user_anding_char_in_input, terminals_lenght_coefficients);
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);
			}

			else {
				is_user_anding_char_in_input = false;
				erasing_word_by_word_in_pipe_condition(output, progeramer_request_str_size, cursor_x_position_in_run_time, cursor_y_position_in_run_time, pipe_position_size_of_the_output,
					pipe_position_size_of_the_output, line_counter, terminals_lenght_coefficients);

				string_info_in_run_time::show_the_strings_char_value_2(output, progeramer_request_str_size, cursor_x_position_in_run_time, cursor_y_position_in_run_time, is_user_anding_char_in_input, terminals_lenght_coefficients);
				std::this_thread::sleep_for(std::chrono::milliseconds(100));
				change_xy(cursor_x_position_in_run_time, cursor_y_position_in_run_time);

			}
		}

		terminal_content_in_condition(bool_type_for_erasing_onece, default_terminal_lenght, terminals_lenght_in_run_time(), cursor_x_position_in_run_time, cursor_y_position_in_run_time, line_counter,
			pipe_position_size_of_the_output, progeramer_request_str_size, pipe_position_size_of_the_output, output, progeramer_request, terminals_lenght_coefficients);

	}

	change_xy(0, 10);

	std::cout << "cursor x position : " << cursor_x_position_in_run_time << '\n';
	std::cout << "cursor y position : " << cursor_y_position_in_run_time << '\n';

	if (!terminals_lenght_coefficients.empty()) {
		std::cout << '\n';
		std::cout << '\n';

		for (int counter{ 0 }; counter < terminals_lenght_coefficients.size(); ++ counter ) {
			std::cout << terminals_lenght_coefficients[ counter ]<< '\t';
		}

	}


//	change_xy(0, cursor_y_position_in_run_time + 2);

	return output;
}


bool is_correct_color(std::string& input_from_user) {
	input_from_user.erase(std::remove(input_from_user.begin(), input_from_user.end(), ' '), input_from_user.end());
	std::transform(input_from_user.begin(), input_from_user.end(), input_from_user.begin(), std::tolower);
	std::array<short, 4> array_of_one_and_zero{ return_to_bitset(input_from_user , map_str_to_bitset()) };

	if ( array_of_one_and_zero[ 0 ] == -1 ) {
		return false;
	}

	return true;
}

std::string getting_input_with_char_counter(std::string progeramer_requst, std::string error_text ) {
	const unsigned long long requst_size{ progeramer_requst.size() };
	std::string final_output{};

	while (true) {
		auto output_str{ get_the_input_from_user(progeramer_requst) };

		if (is_corect_for_command_code(output_str)) {
			std::vector<std::string> terminal_content{};
			saved_terminal_content(terminal_content);
			removed_the_std_output::terminals_empty_line_remover(terminal_content);
		
			change_xy(0 , 10);

			for (int counter{ 0 }; counter < terminal_content.size(); ++counter) {
				std::cout << terminal_content[counter] << '\n';
			}

			std::cout << '\n';
			std::cout << '\n';

			std::cout << terminal_content.size() << '\n';

			while (true) {
				//get_the_input_from_user("Enter your command : ");

				break;
			}
		}
		

		bool condition{ true };

		if (condition) {
			final_output = output_str;
			std::string empty_chars{};
			auto buffer_lines{ ((output_str.size() + requst_size) / terminals_lenght_in_run_time()) + 1 };

			for (int counter{ 0 }; counter < (terminals_lenght_in_run_time() * (buffer_lines + 3)) - requst_size; ++counter) {
				empty_chars.push_back(' ');
			}

			change_xy(0, 0);
			std::cout << empty_chars;
			change_xy(0, 0);
			return final_output;
		}

		else {
			auto buffer_lines{ ((output_str.size() + requst_size) / terminals_lenght_in_run_time()) + 1 };
			change_xy(0, buffer_lines + 2);
			std::cout << error_text;
			change_xy(requst_size, 0);

			while (true) {

				if (_kbhit()) {
					std::string empty_chars{};

					for (int counter{ 0 }; counter < (terminals_lenght_in_run_time() * (buffer_lines + 3)) - requst_size; ++counter) {
						empty_chars.push_back(' ');
					}

					change_xy(requst_size, 0);
					std::cout << empty_chars;

					break;
				}
			}

			output_str.clear();
			change_xy(0, 0);
		}

	}

	return final_output;
}

	
