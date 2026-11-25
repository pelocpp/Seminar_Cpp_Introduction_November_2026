
#include <vector>
#include <list>
#include <print>

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
    // auto pos = vec.begin();

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




void main_stl()
{
	main_stl_05();
}
