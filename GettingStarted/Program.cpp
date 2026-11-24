#include <iostream>

extern void test_references_pointer();
extern void test_time();
extern void printCounter();
extern void incrementAnotherCounter();
extern void test_dynamic_memory();

// extern-DEKLARATION einer globalen Variablen // Überall dort, wo ich die glob. Var. verwenden möchte
// extern int counter;

int main()
{
//	std::cout << counter << std::endl;
	
	test_dynamic_memory();

	return 0;
}
