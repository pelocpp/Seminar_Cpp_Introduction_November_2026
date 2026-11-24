#include <iostream>

// Datei "02_Speicherbereiche.cpp"

// DEFINITION einer globalen Variablen // EINMAL // MIT Vorbelegungswert
static int counter = 100;

void incrementAnotherCounter()
{
	static int anotherCounter = 0;

	anotherCounter++;

	std::cout << "anotherCounter: " << anotherCounter << std::endl;
}

void printCounter()
{
	std::cout << counter << std::endl;
	//std::cout << "anotherCounter: " << anotherCounter << std::endl;   // NEIN
}
