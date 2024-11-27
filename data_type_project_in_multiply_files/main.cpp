//# if 0 

# include <iostream>
# include <array>
# include <vector>
# include <windows.h>
# include <string>
# include <string_view>
# include <conio.h>
# include <algorithm>
# include <bitset>
# include <unordered_map>
# include <cctype>
# include <sstream>
# include <thread>
# include <random>
# include <chrono>
# include <thread>
# include <condition_variable>
# include <mutex>
# include "prototype_for_windows_file.hpp"
# include "daclaration_for_get_input.hpp"


void ExtendConsoleBufferOneLine() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_SCREEN_BUFFER_INFO csbi;

    // Get the current console screen buffer info
    if (!GetConsoleScreenBufferInfo(hConsole, &csbi)) {
        std::cerr << "Error getting console screen buffer info." << std::endl;
        return;
    }

    // Calculate new buffer size
    COORD newSize;
    newSize.X = csbi.dwSize.X;
    newSize.Y = csbi.dwSize.Y + 1; // Increase buffer height by one line

    // Set new screen buffer size
    if (!SetConsoleScreenBufferSize(hConsole, newSize)) {
        std::cerr << "Error setting console screen buffer size." << std::endl;
        return;
    }

	
    // Fill the new line with spaces
    DWORD charsWritten;
    COORD startCoord = { 0, csbi.dwSize.Y }; // Start at the beginning of the new line
    DWORD length = csbi.dwSize.X; // Length of one line (number of characters in a line)

    if (!FillConsoleOutputCharacter(hConsole, ' ', length, startCoord, &charsWritten)) {
        std::cerr << "Error filling console output character." << std::endl;
        return;
    }

    if (!FillConsoleOutputAttribute(hConsole, csbi.wAttributes, length, startCoord, &charsWritten)) {
        std::cerr << "Error filling console output attribute." << std::endl;
        return;
    }
	
}





int terminal_width_in_run_time() {
	HANDLE consol_handle{ GetStdHandle(STD_OUTPUT_HANDLE) };
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(consol_handle, &csbi);

	return csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
}



std::unordered_map<std::string, std::array<short, 4> > map_str_to_bitset() {
	std::unordered_map<std::string, std::array<short, 4> > str_to_binary{
		{ "black", {0,0,0,0} } , { "blue" , {0,0,0,1} } , { "green", {0,0,1,0} } , { "aque", {0,0,1,1} } , { "red", {0,1,0,0} } , { "purple", {0,1,0,1} } , { "darkyellow" , {0,1,1,0} }
		, { "darkwhite", {0,1,1,1} } , { "gray", {1,0,0,0} } , { "lightblue" , {1,0,0,1} } , { "lightgreen", {1,0,1,0} } , { "lightaque" , {1,0,1,1} } , { "lightred", {1,1,0,0} }
		, { "lightpurple", {1,1,0,1} } , {"lightyellow" , {1,1,1,0} } , { "brightwhite" , {1,1,1,1} }

	};

	return str_to_binary;
}


std::array<short , 4> return_to_bitset( std::string& input_string , std::unordered_map<std::string , std::array<short ,4> > bitset_map) {

	auto it{ bitset_map.find(input_string) };

	if (it != bitset_map.end()) {
		return it->second;
	}

	return { -1 , -1 , -1 , -1 };
}


std::bitset<4> array_to_4_bits ( std::array<short , 4> array_of_binary_value) {
	std::bitset<4> binary_color_code{};

	for (int counter{ 0 }; counter < array_of_binary_value.size(); ++counter) {
		binary_color_code[counter] = array_of_binary_value[(array_of_binary_value.size() - 1) - counter];
	}
    
	return binary_color_code;
}


std::array<std::bitset<4> , 2> get_the_fore_and_back_ground_color() {
	std::array<std::bitset<4>, 2> output_array{};
	std::string foreground_color {getting_input_with_char_counter("Enter the foreground color : " , "Enter a valid color")};
	std::string background_color { getting_input_with_char_counter("Enter the background color : " , "Enter a valid color") };
	std::array<short, 4> text_in_binary{ return_to_bitset(foreground_color , map_str_to_bitset()) };
	std::array<short, 4> background_in_binary{ return_to_bitset(background_color , map_str_to_bitset()) };
	std::bitset<4> text_color_bitset{ array_to_4_bits(text_in_binary) };
	std::bitset<4> texts_background_color_bitset{ array_to_4_bits(background_in_binary) };
	output_array[0] = text_color_bitset;
	output_array[1] = texts_background_color_bitset;

	return output_array;
}


unsigned long color_code_in_intger_type(std::array<std::bitset<4>, 2> text_and_background_code) {
	std::bitset<8> backgorund_and_foreground_color{ 0b0000'1101 };

	for (int counter{ 0 }; counter < 2; ++counter) {
		int value_for_initialization{ 0 };

		for (int nested_counter{ ((counter == 0) ? 0 : 4) }; nested_counter < ((counter == 0) ? 4 : 8); ++nested_counter) {
			backgorund_and_foreground_color[nested_counter] = ((counter == 0) ? text_and_background_code[0][value_for_initialization] : text_and_background_code[1][value_for_initialization] );
			++value_for_initialization;
		}
	}

	return backgorund_and_foreground_color.to_ulong();
}




int main() {




//# if 0 
	std::string str{ get_the_input_from_user("Enter a str type :") };


	std::cout << '\n';
	std::cout << '\n';

	std::cout << str << '\n';

	std::cout << str.size() << '\n'; 


//# endif
	
	/*
	int nigger{ terminals_lenght_in_run_time() };

	while (true) {


		if ( terminals_lenght_in_run_time() != nigger ) {
			std::cout << terminals_lenght_in_run_time();
			nigger = terminals_lenght_in_run_time();
		}
    }
	*/



# if 0 

	std::cout << "Enter a str : " << '\n';
	std::string input{};
	std::getline(std::cin >> std::ws, input);


	std::cout << '\n';
	std::cout << "The input : " << input << '\n';
	std::cout << '\n';
	std::cout << '\n';
	std::cout << "The input size : " << input.size() << '\n';
# endif


	return 0;
}

// attribute



/*
	
	std::string output{};
	std::cout << "Enter a str type : " << '\n';
	unsigned long long x_position{ 19 };
	unsigned long long y_position{ 0 };
	gotoxy(x_position, y_position);

	

	while (true) {

		if (_kbhit()) {
			
			auto get_the_char_from_user{ _getch() };

			if ( ( isdigit( get_the_char_from_user) || !isdigit( get_the_char_from_user ) ) && static_cast<char>(get_the_char_from_user) != '\r' ) {
				std::cout <<  static_cast<char>( get_the_char_from_user);
				

			}

			else if (static_cast<char>(get_the_char_from_user) == '\r') {
			   


				x_position = 0;
				++y_position;
				gotoxy(x_position, y_position);
				//ExtendConsoleBufferOneLine();

			}
		}
	}
	

	

	std::cout << "Enter an intger : " << '\n';
	std::string input{};
	std::getline(std::cin >> std::ws, input);


	//auto value{ get_the_input_from_user("Enter a str value :") };





	return 0;
}

	*/

