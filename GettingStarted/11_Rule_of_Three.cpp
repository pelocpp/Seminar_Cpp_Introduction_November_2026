

#include <array>
#include <map>
#include <unordered_map>
#include <vector>
#include <list>
#include <print>
#include <algorithm> 
#include <string>
#include <execution>
#include <span>

class BigData
{
private:
	std::size_t m_size;
	int*        m_data;

public:
	BigData() : m_size (0), m_data(nullptr) {}

	BigData(std::size_t size) : m_size(size) {

		m_data = new int[size];
		
		std::fill(
			m_data,
			m_data + size,
			1
		);
	}

	// Konstuktor: Kopier-Konstruktor / Copy-Constructor
	BigData( const BigData& other ) {

		m_size = other.m_size;
		m_data = new int[other.m_size];

		std::copy(
			other.m_data,
			other.m_data+other.m_size,
			m_data
		);
	}

	// Operator
	BigData& operator = (const BigData& other) {

		if (this != &other) {

			// release current data
			delete[] m_data;

			// allocate new buffer for object from right side
			m_data = new int[other.m_size];

			// copy contents of buffer from right side to left side
			std::copy(other.m_data, other.m_data + other.m_size, m_data);

			// adjust new size
			m_size = other.m_size;
		}

		return *this;
	}

	//void release() {
	//	delete[] m_data;
	//}

	// Destruktor
	~BigData() {
		delete[] m_data;
	}

};

void main_rule_of_three_01()
{
	BigData data(10);
}

void main_rule_of_three_02()
{
	BigData data(10);

	BigData data2 (data);  // Kopie
}

void main_rule_of_three_03()
{
	BigData data(10);

	BigData data2;

	data2 = data;    // Wertzuweisung

	BigData data3;

	data3 = (data2 = data);  // Mehrfachwertzuweisung

	int a, b, c;

	a = (b = (c = 1));
}

void main_rule_of_three()
{
	// main_rule_of_three_01();
	// main_rule_of_three_02();
	main_rule_of_three_03();
}

