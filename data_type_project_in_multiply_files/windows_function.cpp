
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
