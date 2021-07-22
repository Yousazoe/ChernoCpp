#include <iostream>

class String {
private:
	char* buffer;
	unsigned int size;

public:
	String(const char* string) {
		size = strlen(string);
		buffer = new char[size + 1];

		memcpy(buffer, string, size);
		buffer[size] = 0;
	}

	String(const String& other) : size(other.size) {
		std::cout << "Copy String!" << std::endl;

		buffer = new char[size + 1];
		memcpy(buffer, other.buffer, size + 1);
		buffer[size] = 0;
	}

	~String() {
		delete[] buffer;
	}

	char& operator[](unsigned int index) {
		return buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);
};

std::ostream& operator<<(std::ostream& stream, const String& string) {
	stream << string.buffer;
	return stream;
}

void printString(const String& string) {
	std::cout << string << std::endl;
}

int main() {
	String string = "Yousazoe";
	String second = string;

	printString(string);
	printString(second);

	std::cin.get();
}