//# if 0 

# include <iostream>
# include <array>
# include <vector>
# include <Windows.h>
# include "prototype_for_windows_file.hpp"
# include "daclaration_for_get_input.hpp"
# include <string>
# include <conio.h>
# include <limits>
# include <algorithm>
# include <iomanip>


int main() {
	std::cout << std::boolalpha;
	std::cout << std::setprecision(20);

	get_input_from_user("Enter an intger :");

	/*
	std::string str{ "aavvvggffr  r44" };

	auto s{ str.size() };

	str.erase(std::remove( str.begin() , str.end(), ' '), str.end());

	std::cout << '\n';
	std::cout << str << '\n'; 
	*/


    
	/*
	std::cout << "Enter an intger : " << '\n';
	std::string input{};
	std::getline(std::cin >> std::ws, input);

	*/
	
	
	

	
	/*
	std::cout << "Enter an intger : " << '\n';

	while (true) {

		if (_kbhit() ) {
			auto get_the_char{ _getch() };
			std::cout << get_the_char << ' '; 


		}


	}

	std::string str{ "h e l l o w o r d ! " };
	char empty{ 'l' };
	
	std::cout << "String before : " << str << '\n';


    
	for (int counter{ 0 }; counter < str.size(); ++counter) {
		auto it{ std::find(str.begin() , str.end() , ' ') };

		if (it != str.end()) {
			str.erase(it);
		}

	}

	std::cout << "String after : " << str << '\n';

	
	std::string str = "Hello World! World is beautiful!";
	std::string toReplace = "World";
	std::string replacement = "Universe";

	size_t pos = str.find(toReplace);

	while (pos != std::string::npos) {
		str.replace(pos, toReplace.length(), replacement);
		pos = str.find(toReplace, pos + replacement.length());
	}

	std::cout << str << std::endl;

	*/





	return 0;
}

//# endif
