# include <iostream>
# include <thread>
# include <string>
# include <array>
# include <Windows.h>
# include "prototype_for_windows_file.hpp"
# include "daclaration_for_get_input.hpp"


void erase_the_strings_char_counter( int x_position , int y_position , unsigned long long char_counter_value ) {  
	change_xy(x_position, y_position);

	for (int counter{ 0 }; counter < 24 + std::to_string(char_counter_value).size(); ++counter) {
		std::cout << ' ';
	}

}


void show_the_char_counter( int cursor_x_position , int cursor_y_position ) {
	change_xy(0 , cursor_y_position + 1 );
	std::cout << "Strings char counter : ";
	change_xy(cursor_x_position , cursor_y_position );
}


void back_space(unsigned long long char_counter_value) {
	std::string char_counter_value_to_string_type{std::to_string(char_counter_value)};
	
	for (int counter{ 0 }; counter < char_counter_value_to_string_type.size(); ++counter) {
		std::cout << '\b';
	}

}


std::array<unsigned long long, 19> array_of_nines() {
	std::array<unsigned long long, 19> output_array{};
	std::array<std::string, 19> output_array_in_string_type{};

	for (short counter{ 0 }; counter < output_array.size(); ++counter) {
		std::string str_of_nines{};

		for (short nested_counter{ 0 }; nested_counter < counter + 1; ++nested_counter) {
			str_of_nines.push_back('9');
		}

		output_array_in_string_type[counter] = str_of_nines;
		output_array[counter] = std::stoull(output_array_in_string_type[counter]);
	}

	return output_array;
}


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


bool is_char_counter_value_equal_to_array_of_nines( unsigned long long char_counter_value , std::array< unsigned long long , 19> array_of_nines ) {

	for (short counter{ 0 }; counter < array_of_nines.size(); ++counter) {

		if (array_of_nines[counter] == char_counter_value ) {
			return true;
		}
	}
    
	return false;
}



void show_char_counter_value( unsigned long long char_counter_value , int cursor_x_position , int cursor_y_position ) {
	change_xy(23 , cursor_y_position + 1 );
	std::cout << char_counter_value;
	std::this_thread::sleep_for(std::chrono::microseconds(20));

	if (is_char_counter_value_equal_to_array_of_nines(char_counter_value , array_of_nines() ) ) {
		std::cout << ' ';
		change_xy(23, cursor_y_position + 1);
	}

	back_space(char_counter_value);

}



void erase_the_str_of_char_counter_in_run_time(int cursor_x_position , int cursor_y_position , unsigned long long char_counter_value , bool is_back_space_pressed ) {
	std::string char_counter_in_value_in_string_type{ std::to_string(char_counter_value) };
 
	if (!is_back_space_pressed && cursor_x_position == terminals_lenght_in_run_time() ) {
		change_xy(0, cursor_y_position );

		for (int counter{ 0 }; counter < 25 + char_counter_in_value_in_string_type.size(); ++counter) {
			std::cout << ' ';
		}

	}

	else if ( is_back_space_pressed && cursor_x_position == 0 ) {
		change_xy(0, cursor_y_position + 2);

		for (int counter{ 0 }; counter < 25 + char_counter_in_value_in_string_type.size(); ++counter) {
			std::cout << ' ';
		}
	}
}

