

#include <iostream>

#include "Time.h"

void test_dynamic_memory_01()
{
	// 100 int-Werte: 
	// benötige Daten aus dem Stegreif
	// new / delete
	// 2 Varianten

	// 1. Variante: Singular / eine Variable
	int* ptr = new int(123);

	// ..............

	delete ptr;
}

// ===================================================

void tuewas(int* ip) {

	std::cout << "Wert: " <<  * ip << std::endl;

	// delete ip;  // ???
}

void test_dynamic_memory_02()
{
	int* ptr = new int(123);

	int* feld = new int[10] { 0 };

	Time* uhrzeiten = new Time[10];

	for (int i = 0; i != 10; ++i) {

		// ausführlich: Das machen wir in der Regel so nicht ....
		(*(uhrzeiten + i)).setHours(15);

		uhrzeiten[i].setMinutes(30 + i);
	}


	tuewas(ptr);

	delete ptr;   //  ????

	delete[] feld;

	// std::cout << "Wert: " << *ptr << std::endl;

	delete[] uhrzeiten;
}



void test_dynamic_memory()
{
	test_dynamic_memory_02();
}
