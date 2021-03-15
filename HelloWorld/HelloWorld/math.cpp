#include <iostream>
#include "Log.h"

void Log(const char* message);

static int Multiply(int a,int b) {
	Log("Multiply");
	return a * b;
}

int main() {
	std::cout << Multiply(5, 8) <<std::endl;
	std::cin.get();
}