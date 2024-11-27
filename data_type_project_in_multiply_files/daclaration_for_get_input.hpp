# ifndef DECALARATION_FOR_GET_INPUT
# define DECALARATION_FOR_GET_INPUT
# include <string>
# include <string_view>
# include <array>
# include <vector>
# include <unordered_map>

std::string get_the_input_from_user(std::string progeramer_request);

namespace removed_the_std_output  {
	bool is_empty_line(std::string& string_from_vec);
	void terminals_empty_line_remover(std::vector<std::string>& terminal_content);
	void erase_the_empty_chars(std::vector<std::string>& input_terminal_content);
	void erase_the_output_in_consol(std::vector<std::string>& input_consol_content, unsigned long long progeramer_requst_size);
	void erasing_the_terminal_content(const unsigned long long requst_str_size);
}

namespace string_info_in_run_time {
	//std::array<unsigned long long, 19> array_of_nines();
//	bool is_char_counter_value_equal_to_array_of_nines(unsigned long long char_counter_value, std::array< unsigned long long, 19> array_of_nines);
	void show_char_counter_value(unsigned long long char_counter_value, int cursor_x_position, int cursor_y_position);
	void erase_the_strings_char_counter(int x_position, int y_position, unsigned long long char_counter_value);
	void back_space(unsigned long long char_counter_value);
	void show_the_strings_char_value_2(std::string& output, const unsigned long long requst_size, int& cursor_x_position, int& cursor_y_position, bool& is_adding, std::vector<unsigned long long>& terminal_lenght_coefficients);

	void show_the_strings_char_value(unsigned long long& line_counter, int& cursor_x_position, int cursor_y_position, bool& is_adding
		, std::string& output, const unsigned long long  requst_str_size);

}

namespace pipe_conditions {
	bool is_arrow_key();
	
	void show_pipe_position_in_arrow_key_condition_in_run_time(bool is_arrow_key, unsigned long long& pipe_position_in_size_of_the_output, int& input_in_ascii_code,
		unsigned long long output_size, int& cursor_x_position, int& cursor_y_position);
}

void add_char_in_users_input(bool& is_adding, bool is_correct_input, std::string& output, unsigned long long& line_counter, char the_input_char,
	unsigned long long& pipe_position_in_output_size, const unsigned long long requst_str_size, int& cursor_x_position, int& cursor_y_position, std::vector<unsigned long long>& terminals_coefficients, bool& is_increasing);

void pop_char_in_users_input(bool& is_adding, bool condition_for_function, std::string& output, const unsigned long long requst_str_size,
	unsigned long long& pipe_position_in_output_size, int& cursor_x_position, int& cursor_y_position, unsigned long long& line_counter, std::vector<unsigned long long>& terminals_coefficients);

void terminal_content_in_condition(bool& erase_once, int& default_lenght, int lenght_in_run_time, int& cursor_x_position, int& cursor_y_position, unsigned long long& line_counter,
	unsigned long long& pipe_position, const unsigned long long requst_size, unsigned long long& pipe_position_in_output_size, std::string& output, std::string& progeram_requst, std::vector<unsigned long long>& terminals_lenght_coefficients);

std::string getting_input_with_char_counter(std::string progeramer_requst, std::string error_text);

std::unordered_map<std::string, std::array<short, 4> > map_str_to_bitset();

std::array<short, 4> return_to_bitset(std::string& input_string, std::unordered_map<std::string, std::array<short, 4> > bitset_map);


#endif 

