# include <iostream>
# include <thread>
# include <string>
# include <array>
# include <Windows.h>
# include <conio.h>
# include "prototype_for_windows_file.hpp"
# include "daclaration_for_get_input.hpp"


namespace removed_the_std_output {

	bool is_empty_line(std::string& string_from_vec) {

		for (int counter{ 0 }; counter < string_from_vec.size(); ++counter) {

			if (string_from_vec[counter] != ' ') {
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

		terminal_content.resize(terminal_content.size() - (empty_line_counter));
	}


	void erase_the_empty_chars(std::vector<std::string>& input_terminal_content) {

		for (int counter{ 0 }; counter < input_terminal_content.size(); ++counter) {
			int empty_char_counter{ 0 };

			for (int nested_counter{ 0 }; nested_counter < input_terminal_content[counter].size(); ++nested_counter) {

				if (input_terminal_content[counter][nested_counter] == ' ') {
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
			input_consol_content[0].erase(input_consol_content[0].begin());
		}

		terminals_empty_line_remover(input_consol_content);
		erase_the_empty_chars(input_consol_content);

		for (int counter{ 0 }; counter < input_consol_content.size(); ++counter) {
			std::fill(input_consol_content[counter].begin(), input_consol_content[counter].end(), ' ');
		}

		change_xy(progeramer_requst_size, 0);

		for (int counter{ 0 }; counter < input_consol_content.size(); ++counter) {
			std::cout << input_consol_content[counter];
		}

		change_xy(progeramer_requst_size, 0);

	}
	

	void erasing_the_terminal_content(const unsigned long long requst_str_size) {
		std::vector<std::string> terminal_content{};
		saved_terminal_content(terminal_content);
		terminals_empty_line_remover(terminal_content);
		erase_the_empty_chars(terminal_content);
		erase_the_output_in_consol(terminal_content, requst_str_size);
	}



}

namespace string_info_in_run_time {

	void back_space(unsigned long long char_counter_value) {
		std::string char_counter_value_to_string_type{ std::to_string(char_counter_value) };

		for (int counter{ 0 }; counter < char_counter_value_to_string_type.size(); ++counter) {
			std::cout << '\b';
		}

	}

	void show_char_counter_value(unsigned long long char_counter_value, int cursor_x_position, int cursor_y_position) {
		change_xy(23, cursor_y_position + 1);
		std::cout << char_counter_value;

		for (int counter{ 0 }; counter < std::to_string(char_counter_value).size(); ++counter) {
			std::cout << ' ';
			change_xy(22, cursor_y_position + 1);
		}

		back_space(char_counter_value);

	}

	void show_char_counter_value_2(std::string& output , const unsigned long long requst_size) {
		change_xy(23, static_cast<int> ((output.size() + requst_size) / terminals_lenght_in_run_time()) + 1);
		std::cout << output.size();

		for (int counter{ 0 }; counter < std::to_string(output.size()).size(); ++counter) {
			std::cout << ' ';
			change_xy(22, static_cast<int>( (output.size() + requst_size) / terminals_lenght_in_run_time()) + 1 );
		}

	}

	void erase_the_strings_char_counter(int x_position, int y_position, unsigned long long char_counter_value) {
		change_xy(x_position, y_position);
		int counter{ 0 };

		while (counter < 24 + std::to_string(char_counter_value).size()) {
			std::cout << ' ';
			++counter;
		}
	}



	void show_the_strings_char_value_2(std::string& output, const unsigned long long requst_size, int& cursor_x_position, int& cursor_y_position, bool& is_adding,
		std::vector<unsigned long long>& terminal_lenght_coefficients) {
		std::cout << std::boolalpha;

		unsigned long long lines_value{ terminal_lenght_coefficients.size() };
		change_xy(0, ((output.size() + requst_size) / terminals_lenght_in_run_time()) + 1);
		std::cout << "Strings char counter : ";
		show_char_counter_value_2(output, requst_size);

		if (is_adding && (output.size() + requst_size) % terminals_lenght_in_run_time() == 0) {			
			erase_the_strings_char_counter(0, ((output.size() + requst_size) / terminals_lenght_in_run_time()) , output.size());
		}

		else if (!is_adding && (output.size() + requst_size) % terminals_lenght_in_run_time() == 0) {
			erase_the_strings_char_counter(0, ((output.size() + requst_size) / terminals_lenght_in_run_time()) + 1, output.size());
		}

		if (!terminal_lenght_coefficients.empty() && !is_adding) {

			if ((output.size() + requst_size) < terminal_lenght_coefficients.back() || (output.size() + requst_size) == terminal_lenght_coefficients.back()) {
				erase_the_strings_char_counter(0, terminal_lenght_coefficients.size() + 1, output.size());
				terminal_lenght_coefficients.pop_back();
			}
		}

	}


	void show_the_strings_char_value(unsigned long long& line_counter, int& cursor_x_position, int cursor_y_position, bool& is_adding
		, std::string& output, const unsigned long long  requst_str_size) {

		change_xy(0, line_counter + 1);
		std::cout << "Strings char counter : ";
		show_char_counter_value(output.size(), cursor_x_position, line_counter);

		if ((output.size() + requst_str_size) % terminals_lenght_in_run_time() == 0) {
			change_xy(0, ((is_adding) ? (output.size() + requst_str_size) / terminals_lenght_in_run_time() : 1 + (output.size() + requst_str_size) / terminals_lenght_in_run_time()));
			erase_the_strings_char_counter(0, ((is_adding) ? (output.size() + requst_str_size) / terminals_lenght_in_run_time() : 1 + (output.size() + requst_str_size) / terminals_lenght_in_run_time()), output.size());
		}

		change_xy(cursor_x_position, cursor_y_position);
	}
}



namespace pipe_conditions {

	bool is_arrow_key() {

		if (GetAsyncKeyState(VK_UP) & 0x8000) {
			return true;
		}

		else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
			return true;
		}

		else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
			return true;
		}

		else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
			return true;
		}

		return false;
	}

	void show_pipe_position_in_arrow_key_condition_in_run_time(bool is_arrow_key, unsigned long long& pipe_position_in_size_of_the_output, int& input_in_ascii_code,
		unsigned long long output_size, int& cursor_x_position, int& cursor_y_position) {

		if (input_in_ascii_code == 75 && pipe_position_in_size_of_the_output != 0 && is_arrow_key) {
			--pipe_position_in_size_of_the_output;
			--cursor_x_position;
			cursor_y_position -= ((cursor_x_position == 0) ? 1 : 0);
			cursor_x_position += ((cursor_x_position == 0) ? terminals_lenght_in_run_time() : 0);
			change_xy(cursor_x_position, cursor_y_position);
		}

		else if (input_in_ascii_code == 77 && pipe_position_in_size_of_the_output != output_size && is_arrow_key) {
			++pipe_position_in_size_of_the_output;
			++cursor_x_position;
			cursor_y_position += ((cursor_x_position == terminals_lenght_in_run_time()) ? 1 : 0);
			cursor_x_position -= ((cursor_x_position == terminals_lenght_in_run_time()) ? terminals_lenght_in_run_time() : 0);
			change_xy(cursor_x_position, cursor_y_position);
		}
	}
}






void add_char_in_users_input(bool& is_adding, bool is_correct_input, std::string& output, unsigned long long& line_counter, char the_input_char,
	unsigned long long& pipe_position_in_output_size, const unsigned long long requst_str_size, int& cursor_x_position, int& cursor_y_position,
	std::vector<unsigned long long>& terminals_coefficients, bool& is_increasing) {

	if (is_correct_input && pipe_position_in_output_size == output.size()) {
		is_adding = true;
		output.push_back(the_input_char);
		change_xy(cursor_x_position, cursor_y_position);
		std::cout << the_input_char;
		++cursor_x_position;
		++pipe_position_in_output_size;
		line_counter += ((cursor_x_position == terminals_lenght_in_run_time()) ? 1 : 0);
		cursor_y_position += ((cursor_x_position == terminals_lenght_in_run_time()) ? 1 : 0);
		cursor_x_position -= ((cursor_x_position == terminals_lenght_in_run_time()) ? terminals_lenght_in_run_time() : 0);

	}

	else if (is_correct_input && pipe_position_in_output_size != output.size()) {
		is_adding = true;
		output.insert(output.begin() + pipe_position_in_output_size, the_input_char);
		++cursor_x_position;
		++pipe_position_in_output_size;
		line_counter += (((output.size() + requst_str_size) % terminals_lenght_in_run_time() == 0) ? 1 : 0);
		cursor_y_position += ((cursor_x_position == terminals_lenght_in_run_time()) ? 1 : 0);
		cursor_x_position -= ((cursor_x_position == terminals_lenght_in_run_time()) ? terminals_lenght_in_run_time() : 0);
		removed_the_std_output::erasing_the_terminal_content(requst_str_size);
		std::cout << output;

	}

	if ((output.size() + requst_str_size) % terminals_lenght_in_run_time() == 0 && is_adding) {
		terminals_coefficients.push_back(output.size() + requst_str_size);
		is_increasing = true;
	}

}

void pop_char_in_users_input(bool& is_adding, bool condition_for_function, std::string& output, const unsigned long long requst_str_size,
	unsigned long long& pipe_position_in_output_size, int& cursor_x_position, int& cursor_y_position, unsigned long long& line_counter ,
	std::vector<unsigned long long>& terminals_coefficients) {

	if (condition_for_function) {

		if (output.size() == pipe_position_in_output_size) {
			is_adding = false;
			output.pop_back();
			--cursor_x_position;
			--pipe_position_in_output_size;
			line_counter -= ((cursor_x_position == 0) ? 1 : 0);
			cursor_y_position -= ((cursor_x_position == 0) ? 1 : 0);
			cursor_x_position += ((cursor_x_position == 0) ? terminals_lenght_in_run_time() : 0);
			removed_the_std_output::erasing_the_terminal_content(requst_str_size);
			std::cout << output;
			change_xy(cursor_x_position, cursor_y_position);

		}

		else if (output.size() != pipe_position_in_output_size && pipe_position_in_output_size != 0) {
			is_adding = false;
			--cursor_x_position;
			--pipe_position_in_output_size;
			line_counter -= (((output.size() + requst_str_size) % terminals_lenght_in_run_time() == 0) ? 1 : 0);
			cursor_y_position -= ((cursor_x_position == 0) ? 1 : 0);
			cursor_x_position += ((cursor_x_position == 0) ? terminals_lenght_in_run_time() : 0);
			output.erase(output.begin() + pipe_position_in_output_size);
			removed_the_std_output::erasing_the_terminal_content(requst_str_size);
			std::cout << output;
			change_xy(cursor_x_position, cursor_y_position);

		}

	}
}


void terminal_content_in_condition(bool& erase_once, int& default_lenght, int lenght_in_run_time, int& cursor_x_position, int& cursor_y_position, unsigned long long& line_counter,
	unsigned long long& pipe_position, const unsigned long long requst_size, unsigned long long& pipe_position_in_output_size, std::string& output, std::string& progeram_requst, std::vector<unsigned long long>& terminals_lenght_coefficients) {

	if (default_lenght != lenght_in_run_time) {
		terminals_lenght_coefficients.clear();

		std::vector<std::string> terminal_content{};
		saved_terminal_content(terminal_content);
		removed_the_std_output::terminals_empty_line_remover(terminal_content);
		terminal_content.pop_back();
		
		int terminal_coefficients{};
		for (int counter{ 0 }; counter < (output.size() + requst_size ) / terminals_lenght_in_run_time(); ++counter) {
			terminal_coefficients += terminals_lenght_in_run_time();
			terminals_lenght_coefficients.push_back(terminal_coefficients);
		}

		cursor_x_position = (output.size() + requst_size) % terminals_lenght_in_run_time();
		cursor_y_position = (((output.size() + requst_size) - ((output.size() + requst_size) % terminals_lenght_in_run_time())) / terminals_lenght_in_run_time());
		line_counter = (((output.size() + requst_size) - ((output.size() + requst_size) % terminals_lenght_in_run_time())) / terminals_lenght_in_run_time());

		if (output.size() != pipe_position_in_output_size) {

			for (int counter{ 0 }; counter < output.size() - pipe_position_in_output_size; ++counter) {
				--cursor_x_position;
				cursor_y_position -= ((cursor_x_position == 0) ? 1 : 0);
				cursor_x_position += ((cursor_x_position == 0) ? terminals_lenght_in_run_time() : 0);
			}
		}

		for (int counter{ 0 }; counter < terminals_width_in_run_time(); ++counter) {
			fill_the_buffer(' ', ((counter == 0) ? requst_size : 0), counter, ((counter == 0) ? terminals_lenght_in_run_time() - requst_size : terminals_lenght_in_run_time()));
		}
		

		change_xy(requst_size, 0);
		std::cout << output;
		change_xy(cursor_x_position, cursor_y_position);
		default_lenght = lenght_in_run_time;
	}

}

