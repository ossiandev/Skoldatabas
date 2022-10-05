#include "ConsoleCF.h"

template <typename T>

// Thought it would work didn't no clue why

void ConsoleCF::Print(T t)
{
	std::cout << t << "\n";
}

template <typename T>
void ConsoleCF::Read(T t)
{
	std::cin.ignore();
	std::getline(std::cin, t);
}