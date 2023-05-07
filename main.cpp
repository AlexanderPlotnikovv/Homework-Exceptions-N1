#include <iostream>

class Forbidden_length : public std::exception {
public:
	const char* what() const override { return "Forbidden lenght! Bye!"; }
};

int function(std::string str, int forbidden_length) {
	if (strlen(str.c_str()) == forbidden_length) throw Forbidden_length();
	return strlen(str.c_str());
}

int main()
{
	int forbidden_len;
	std::string str;
	std::cout << "Enter forbidden length: ";
	std::cin >> forbidden_len;
	for (;;) {
		try {
			std::cout << "Enter string: ";
			std::cin >> str;
			std::cout << "Length of your string: " << function(str, forbidden_len) << std::endl;
		}
		catch (const Forbidden_length& exception) {
			std::cout << exception.what();
			break;
		}
	}
}