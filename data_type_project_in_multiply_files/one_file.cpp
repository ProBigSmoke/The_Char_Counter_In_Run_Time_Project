# if 0
# include


bool is_equal(std::array< std::string, 19> array_of_nines, long current_position) {

	for (int counter{ 0 }; counter < array_of_nines.size(); ++counter) {

		if (std::to_string(current_position) == array_of_nines[counter]) {
			return true;
		}

	}

	return false;
}



bool is_arrow_key() {

	if (GetAsyncKeyState(VK_UP) & 0x8000) {
		return true;
	}

	else if (GetAsyncKeyState(VK_DOWN) & 0x8000) {
		return true;
	}

	else if (GetAsyncKeyState(VK_LEFT) & 0x8000) {
		return true;
	}

	else if (GetAsyncKeyState(VK_RIGHT) & 0x8000) {
		return true;
	}

	return false;
}

void str_string_char_counter(int terminals_lenght_size_in_run_time, unsigned long long x_position, unsigned long long y_position, unsigned char_counter) {
	std::string char_counter_in_string_type{ std::to_string(char_counter) };

	if (x_position == terminals_lenght_size_in_run_time - 1) {
		gotoxy(0, y_position);

		for (short counter{ 0 }; counter < 24 + char_counter_in_string_type.size(); ++counter) {
			std::cout << ' ';
		}
	}

	if (x_position == 0) {
		gotoxy(0, 8);
		gotoxy(0, y_position + 2);

		for (short counter{ 0 }; counter < 24 + char_counter_in_string_type.size(); ++counter) {
			std::cout << ' ';
		}
	}

}

void show_something(unsigned long long x_position, unsigned long long y_position) {
	gotoxy(0, y_position + 1);
	std::cout << "Strings char counter : ";
	gotoxy(x_position, y_position);

}

void erasing_the_value_of_the_char_counter(unsigned long long char_counter) {
	std::string char_counter_in_string_type{ std::to_string(char_counter) };

	for (size_t counter{ 0 }; counter < char_counter_in_string_type.size(); ++counter) {
		std::cout << '\b';
	}
}

bool is_nine_digit(unsigned long long char_counter, std::array<std::string, 19> array_of_nines) {

	for (short counter{ 0 }; counter < array_of_nines.size(); ++counter) {

		if (char_counter == std::stoull(array_of_nines[counter])) {
			return true;
		}
	}

	return false;
}

void show_the_char_counter_in_run_time(unsigned long long char_counter, unsigned long long y_position) {
	std::cout << char_counter;
	std::this_thread::sleep_for(std::chrono::microseconds(20));

	if (is_nine_digit(char_counter, array_of_nines())) {
		std::cout << ' ';
		gotoxy(23, y_position);
	}

	else {
		erasing_the_value_of_the_char_counter(char_counter);

	}
}

auto terminals_length_size_in_run_time() {
	HANDLE handle;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	return csbi.srWindow.Right - csbi.srWindow.Left + 1;
}


int line_number_when_default_lenght_is_change(int default_terminals_lenght, unsigned long long x_position, unsigned long long char_counter) {
	unsigned long long output{};

	if (default_terminals_lenght != terminals_length_size_in_run_time() && terminals_length_size_in_run_time() < x_position) {
		output = char_counter / terminals_length_size_in_run_time();
		std::cout << output << '\n';
	}

	return output;
}

bool is_terminals_lenght_increasing(int current_lenght, int& saved_lenght) {

	if (current_lenght > saved_lenght) {
		saved_lenght = current_lenght;
		return true;

	}

	if (current_lenght < saved_lenght) {
		saved_lenght = current_lenght;
		return false;
	}

	return false;

}


bool is_same_char(std::string);

void resizeing_terminals_content(std::string& input_string) {
	short member_number_whrere_the_empty_char_is{ 0 };
again:
	char empty_char{ 0 };
	short empty_char_counter{ 0 };

	for (int counter{ member_number_whrere_the_empty_char_is }; counter < input_string.size(); ++counter) {

		if (input_string[counter] == ' ') {
			member_number_whrere_the_empty_char_is = counter;
			break;
		}

	}

	for (int counter{ member_number_whrere_the_empty_char_is }; counter < input_string.size(); ++counter) {

		if (input_string[member_number_whrere_the_empty_char_is] == input_string[counter]) {
			++empty_char_counter;
		}

		else {
			member_number_whrere_the_empty_char_is = counter;
			empty_char_counter = 0;
			goto again;
		}
	}

	input_string.resize(input_string.size() - empty_char_counter);

}

void erase_the_strings(std::string output) {
	unsigned long long new_size{};
	std::vector<std::string> terminal_content{};
	saved_terminal_content(terminal_content);

	for (int counter{ 0 }; counter < 17; ++counter) {
		terminal_content[0].erase(terminal_content[0].begin());
	}

	for (int counter{ 0 }; counter < terminal_content.size(); ++counter) {
		new_size += ((terminal_content[counter][0] == ' ' && is_same_char(terminal_content[counter])) ? 0 : 1);
	}

	terminal_content.resize(new_size - 1);

	for (int counter{ 0 }; counter < terminal_content.size(); ++counter) {
		resizeing_terminals_content(terminal_content[counter]);
	}


	for (int counter{ 0 }; counter < terminal_content.size(); ++counter) {

		for (int nested_counter{ 0 }; nested_counter < terminal_content[counter].size(); ++nested_counter) {
			gotoxy(((counter == 0) ? nested_counter + 17 : nested_counter), counter);
			std::cout << ' ';
		}

	}



}


std::vector<int> vec_char_if_terminals_lenght_increase(int line_counter) {
	std::vector<int> vec_output{};
	int number_two{ 0 };

	for (int counter{ 0 }; counter < line_counter; ++counter) {
		vec_output.push_back((line_counter * 2) - number_two);
		number_two += 2;
	}

	return vec_output;
}

void saved_terminal_content(std::vector<std::string>& input_string) {
	HANDLE handle{ GetStdHandle(STD_OUTPUT_HANDLE) };
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(handle, &csbi);
	int width{ csbi.srWindow.Right - csbi.srWindow.Left + 1 };
	int lenght{ csbi.srWindow.Bottom - csbi.srWindow.Top + 1 };

	CHAR_INFO* buffer{ new CHAR_INFO[width * lenght] };
	COORD buffer_size{ SHORT(width) ,SHORT(lenght) };
	COORD buffer_coord{ 0 , 0 };
	SMALL_RECT read_reigon{ csbi.srWindow };


	ReadConsoleOutput(handle, buffer, buffer_size, buffer_coord, &read_reigon);

	input_string.clear();

	for (int counter{ 0 }; counter < lenght; ++counter) {
		std::string line;

		for (int nested_counter{ 0 }; nested_counter < width; ++nested_counter) {
			line += buffer[counter * width + nested_counter].Char.AsciiChar;
		}

		input_string.push_back(line);

	}

	delete[]buffer;


}


bool is_same_char(std::string input_string_from_terminal_content) {
	char first_char{ input_string_from_terminal_content[0] };

	for (int counter{ 1 }; counter < input_string_from_terminal_content.size(); ++counter) {

		if (first_char != input_string_from_terminal_content[counter]) {
			return false;
		}

	}

	return true;
}


bool is_all_empty_char(std::string& input_from_terminal_content) {

	for (int counter{ 0 }; counter < input_from_terminal_content.size(); ++counter) {

		if (input_from_terminal_content[counter] != ' ') {
			return false;
		}
	}

	return true;
}

void correcting_the_terminal_content(std::vector<std::string>& terminal_content) {
	std::vector<std::string> new_terminal_content{};

	for (int counter{ 0 }; counter < terminal_content.size(); ++counter) {

		if (!is_all_empty_char(terminal_content[counter])) {
			terminal_content = new_terminal_content;
		}
	}
}

int main() {


	/*

	std::cout << std::boolalpha;

	std::cout << std::setprecision(10000);


	//std::cout << std::numeric_limits<long long>::max() << '\n';

	//std::cout << ones(63) << '\n';
	auto value{ bitset_and_value< std::bitset<4> , short >( "Enter a bitset value : ", 1)};
	std::cout << value << '\n';
	*/




	std::cout << "Enter an intger : " << '\n';

	std::vector<std::string> terminal_content{};
	static std::string output{};
	unsigned long long line_counter{ 0 };
	unsigned long long terminal_empty_line_counter{ 0 };
	static unsigned long long x_position{ 17 };
	unsigned long long y_position{ 0 };
	unsigned long long char_counter{ 0 };
	auto default_terminals_length_in_run_time{ terminals_length_size_in_run_time() };
	int saved_lenght{ default_terminals_length_in_run_time };
	int get_the_char_from_the_key_board{};


	//# if 0

	while (true) {

		if (_kbhit()) {
			saved_terminal_content(terminal_content);
			auto get_the_char_from_key_board_instently{ _getch() };
			show_something(x_position, y_position);

			if ((isdigit(get_the_char_from_key_board_instently) || std::isalpha(get_the_char_from_key_board_instently) || std::ispunct(get_the_char_from_key_board_instently)
				|| get_the_char_from_key_board_instently == ' ') && !is_arrow_key() && get_the_char_from_key_board_instently != '\b' && get_the_char_from_key_board_instently != '\r' && x_position != terminals_length_size_in_run_time() - 1) {
				output.push_back(get_the_char_from_key_board_instently);
				gotoxy(x_position, y_position);
				std::cout << static_cast<char>(get_the_char_from_key_board_instently);
				++x_position;
				++char_counter;
				line_counter += ((x_position == terminals_length_size_in_run_time() - 1) ? 1 : 0);
				gotoxy(23, y_position + 1);
				show_the_char_counter_in_run_time(char_counter, y_position);
				y_position += ((x_position == terminals_length_size_in_run_time() - 1) ? 1 : 0);
				str_string_char_counter(terminals_length_size_in_run_time(), x_position, y_position, char_counter);
				x_position -= ((x_position == terminals_length_size_in_run_time() - 1) ? terminals_length_size_in_run_time() - 1 : 0);
			}

			else if (get_the_char_from_key_board_instently == '\b' && x_position <= terminals_length_size_in_run_time() - 1) {

				if (!output.empty()) {
					output.pop_back();
					gotoxy(x_position, y_position);
					std::cout << "\b \b";
					--x_position;
					--char_counter;
					gotoxy(23, y_position + 1);
					show_the_char_counter_in_run_time(char_counter, y_position);
					y_position -= ((x_position == 0) ? 1 : 0);
					str_string_char_counter(terminals_length_size_in_run_time(), x_position, y_position, char_counter);
					x_position += ((x_position == 0) ? terminals_length_size_in_run_time() - 1 : 0);
					gotoxy(x_position, y_position);
				}
			}

			else if (get_the_char_from_key_board_instently == '\r') {
				break;
			}

		}


		if (terminals_length_size_in_run_time() != default_terminals_length_in_run_time) {

			if (!output.empty()) {
				erase_the_strings(output);
				gotoxy(17, 0);
				std::cout << output;
			}

			if (is_terminals_lenght_increasing(terminals_length_size_in_run_time(), default_terminals_length_in_run_time) || !is_terminals_lenght_increasing(terminals_length_size_in_run_time(), default_terminals_length_in_run_time)) {
				saved_terminal_content(terminal_content);
				unsigned long long new_size{ 0 };

				for (int counter{ 0 }; counter < terminal_content.size(); ++counter) {

					if (terminal_content[counter][0] == ' ' && is_same_char(terminal_content[counter])) {
						++new_size;

					}
				}

				terminal_content.resize(terminal_content.size() - (new_size + 1));
				short member_of_terminals_contents_strings_when_its_empty{ 0 };

				for (int counter{ 0 }; counter < terminal_content.size(); ++counter) {
					short terminals_content_strings_size{ 0 };
					short empty_char_for_terminals_strings{ 0 };
					short empty_chars{ 0 };

					for (int nested_counter{ 0 }; nested_counter < terminal_content[counter].size(); ++nested_counter) {

						if (terminal_content[counter][nested_counter] != ' ') {
							++terminals_content_strings_size;
							terminals_content_strings_size += ((empty_char_for_terminals_strings != 0) ? empty_char_for_terminals_strings : 0);
							empty_char_for_terminals_strings = 0;
							empty_chars = 0;

						}

						else if (terminal_content[counter][nested_counter] == ' ') {
							++empty_chars;
							++empty_char_for_terminals_strings;

						}

					}

					terminal_content[counter].resize(terminals_content_strings_size);

				}
			}

			line_counter += ((x_position == terminals_length_size_in_run_time() - 1) ? 1 : 0);
			y_position = terminal_content.size() - 1;
			x_position = terminal_content[terminal_content.size() - 1].size();
			saved_terminal_content(terminal_content);
			//correcting_the_terminal_content(terminal_content);
			default_terminals_length_in_run_time = terminals_length_size_in_run_time();
		}










	}

	gotoxy(0, 20);

	for (int counter{ 0 }; counter < terminal_content.size(); ++counter) {
		std::cout << terminal_content[counter] << '\n';
	}


	//	correcting_the_terminal_content(terminal_content);




		/*
		std::cout << "String from terminal conternt : " << string_from_terminal_content << '\n';
		std::cout << "x_position : " << x_position << '\n';
		std::cout << "y_position : " << y_position << '\n';
		*/


		//std::cout << "line counter : " << line_counter << '\n';

		/*


		std::cout << string_from_terminal_content << '\n';
		std::cout << "string size : " << string_from_terminal_content.size() << '\n';
		std::cout << "uncomplete string : " << uncomplete_string << '\n';
		std::cout << "uncomplete string size :  "<< uncomplete_string.size() << '\n';

		*/


		//#endif

	return 0;
}


# endif