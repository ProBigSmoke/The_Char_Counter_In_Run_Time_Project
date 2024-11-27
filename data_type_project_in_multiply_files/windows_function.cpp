
# include <iostream>
# include <Windows.h>
# include <vector>
# include <string>
# include "prototype_for_windows_file.hpp"

void change_xy(int x_position , int y_position ) {
	COORD coord;
	coord.X = x_position;
	coord.Y = y_position;

	SetConsoleCursorPosition( GetStdHandle(STD_OUTPUT_HANDLE), coord);

}

int terminals_lenght_in_run_time() {
	HANDLE handle{GetStdHandle(STD_OUTPUT_HANDLE)};
	CONSOLE_SCREEN_BUFFER_INFO C_S_B_I;
	GetConsoleScreenBufferInfo( handle , &C_S_B_I );

	return C_S_B_I.srWindow.Right - C_S_B_I.srWindow.Left + 1;
}

int terminals_width_in_run_time() {
	HANDLE handle{ GetStdHandle(STD_OUTPUT_HANDLE) };
	CONSOLE_SCREEN_BUFFER_INFO C_S_B_I;
	GetConsoleScreenBufferInfo(handle, &C_S_B_I);

	return C_S_B_I.dwSize.Y;
}

void saved_terminal_content(std::vector<std::string>& input_string ) {
	HANDLE handle{ GetStdHandle(STD_OUTPUT_HANDLE)};
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo( handle , &csbi);
	int width{ csbi.srWindow.Right - csbi.srWindow.Left + 1 };
    int lenght{ csbi.srWindow.Bottom - csbi.srWindow.Top + 1 };
	CHAR_INFO* buffer{ new CHAR_INFO [ width * lenght ] };
	COORD buffer_size{ SHORT(width) , SHORT(lenght)};
	COORD buffer_coord{ 0 , 0 };
	SMALL_RECT read_region{csbi.srWindow};
	ReadConsoleOutput(handle, buffer , buffer_size , buffer_coord , &read_region );
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

void fill_the_buffer(char char_to_fill , int x_coordinate , int y_coordinate , int char_number_to_fill_in_each_line) {
	HANDLE consol_handle{ GetStdHandle(STD_OUTPUT_HANDLE) };

	if (consol_handle == INVALID_HANDLE_VALUE) {
		std::cout << "Error to get buffer handle " << '\n';
	}

	CONSOLE_SCREEN_BUFFER_INFO C_S_B_I;
	
	if (!GetConsoleScreenBufferInfo(consol_handle, &C_S_B_I)) {
		std::cout << "Error to get buffer info " << '\n';
	}

	COORD coordinate;
	DWORD chars_written;

	coordinate.X = x_coordinate;
	coordinate.Y = y_coordinate;
	int lenght{ C_S_B_I.dwSize.X };

	FillConsoleOutputCharacter(consol_handle, char_to_fill, lenght, coordinate, &chars_written);

}


void add_buffer_to_scroll() {
	CONSOLE_SCREEN_BUFFER_INFO C_S_B_I;
	HANDLE consol_handle{ GetStdHandle(STD_OUTPUT_HANDLE) };

	if (!GetConsoleScreenBufferInfo(consol_handle, &C_S_B_I)) {
		return;
	}

	COORD new_buffer_size;
	new_buffer_size.X = C_S_B_I.dwSize.X;
	new_buffer_size.Y = C_S_B_I.dwSize.Y + 1;

	if (SetConsoleScreenBufferSize( consol_handle , new_buffer_size) ) {
		return;
	}

	DWORD char_written;
	COORD star_coord{ 0 , C_S_B_I.dwSize.Y };

}
