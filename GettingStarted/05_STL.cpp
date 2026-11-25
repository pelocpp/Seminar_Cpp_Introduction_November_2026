#include <vector>
#include <list>
#include <print>
#include <algorithm>
#include <string>

void main_stl_01()
{
	std::vector<int> vec;

	vec.reserve(80);

	for (int i = 0; i < 100; ++i) {
		vec.push_back(2 * i);
		std::println("Size: {} - Capacity: {}", vec.size(), vec.capacity());
	}

	// ... fertig ...
	vec.shrink_to_fit();
	std::println("Size: {} - Capacity: {}", vec.size(), vec.capacity());
}

void main_stl_02()
{
	std::vector<int> vec;
	//std::list<int> vec;

	for (int i = 0; i < 20; ++i) {
		vec.push_back(2 * i);
	}

	// Inhalt des Containers ausgeben
	for (int i = 0; i < vec.size(); ++i) {
		std::println("Index: {} - Wert: {}", i, vec[i]);
	}
}

void main_stl_03()
{
	// std::vector<int> vec{ 1, 2, 3 };
	std::list<int> vec{ 1, 2  };

    // std::vector<int>::iterator pos = vec.begin();
    std::list<int>::iterator pos = vec.begin();

    auto pos2 = vec.begin();

	if (pos == vec.end()) {
		std::println("Fertig");
		return;
	}

	int value = *pos;
	std::println("Value: {}", value);

	++pos;
	if (pos == vec.end()) {
		std::println("Fertig");
		return;
	}

	value = *pos;
	std::println("Value: {}", value);

	++pos;
	if (pos == vec.end()) {
		std::println("Fertig");
		return;
	}

	value = *pos;
	std::println("Value: {}", value);

	++pos;
	if (pos == vec.end()) {
		std::println("Fertig");
		return;
	}

	value = *pos;
	std::println("Value: {}", value);

}


void main_stl_04()
{
	std::vector<int> vec{ 1, 2, 3 };

	std::vector<int>::iterator pos = vec.begin();
	std::vector<int>::iterator end = vec.end();

	for ( ; pos != end ;  ++ pos  ) {

		int value = *pos;
		std::println("Value: {}", value);
	}
}

void main_stl_05()
{
	std::vector<int> vec{ 1, 2, 3, 5, 6, 7 };

	// Range-based for-Loop:   for_each

	for ( int value : vec ) {
		std::println("Value: {}", value);
	}
}

void print(int value) {

	std::println("Value: {}", value);
}

void main_stl_06()
{
	std::vector<int> vec{ 1, 2, 3, 5, 6, 7 };

	std::for_each(
		vec.begin(),
		vec.end(),
		print
	);
}

// ==============================================

// Was ist ein Callable

class Printer
{
private:
	std::string m_header;

public:
	// c'tor(s)
	Printer() : m_header("==> ") {}

	Printer(const std::string& header) : m_header(header) {}

	void operator () (int value) {
		std::println("{} {}", m_header, value);
	}

	int operator () (int a, int b) {
		return a + b;
	}

	void tueWas() {}
};

void main_stl_07() {

	// extern Printer myPrinter();
	Printer myPrinter (">>> ");

	myPrinter.tueWas();
	myPrinter(123);

	int result = myPrinter(10, 11);
}


void main_stl_08()
{
	std::vector<int> vec{ 1, 2, 3, 5, 6, 7 };

	Printer myPrinter(" >>>>: ");

	std::for_each(
		vec.begin(),
		vec.end(),
		myPrinter
	);
}

// how to use the STL / how to work with the STL

void verdoppleWert(int& value) {

	value = 2 * value;
}

int belegeVor()
{
	std::println("bin hier ...");

	static int value = 0;
	value++;
	return value;
}

void main_stl_10()
{
	std::vector<int> zahlen;

	zahlen.resize(5);

	std::fill(
		zahlen.begin(),
		zahlen.end(),
		123
	);

	std::for_each(
		zahlen.begin(),
		zahlen.end(),
		print
	);

	std::for_each(
		zahlen.begin(),
		zahlen.end(),
		verdoppleWert
	);

	std::for_each(
		zahlen.begin(),
		zahlen.end(),
		print
	);

	// vorbelegen mit 1, 2, 3, 4, 5
	std::generate(
		zahlen.begin(),
		zahlen.end(),
		belegeVor
	);

	// suchen: Ist der Wert 4 im Container enthalten ????
	// Das ist NICHT STL - like
	for (int i = 0; i != zahlen.size(); ++i) {
		if (zahlen[i] == 4) {
			std::println("4 gefunden ...");
		}
	}

	std::vector<int>::iterator pos = std::find(
		zahlen.begin(),
		zahlen.end(),
		4
	);

	if (pos == zahlen.end()) {
		std::println("nicht gefunden ...");
	}
	else {
		std::println("Gefunden: {}", *pos);
	}


}


void main_stl()
{
	main_stl_10();
}
