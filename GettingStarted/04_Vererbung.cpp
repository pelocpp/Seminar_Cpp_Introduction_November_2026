#include <vector>
#include <iostream>

class Rectangle
{
private:
	int m_x;
	int m_y;
	int m_width;
	int m_height;

public:
	// c'tor
	Rectangle() : Rectangle (0, 0, 0, 0)
	{
	}

	Rectangle(int x, int y, int width, int height)
		: m_x(x), m_y(y), m_width(width), m_height(height)
	{
	}

	void print() {
		std::cout << "Rectangle" << std::endl;
	}
};

class ColoredRectangle : public Rectangle
{
private:
	//int m_x;
	//int m_y;
	//int m_width;
	//int m_height;
	int m_color;  // Detail: RGB => int

public:
	ColoredRectangle () : m_color(0) {}

	ColoredRectangle(int x, int y, int width, int height, int color)
		: Rectangle (x, y, width, height), m_color (color)
	{
	}
};

void test_vererbung()
{
	Rectangle r(1, 1, 20, 30);

	ColoredRectangle cr;
	cr.print();

	ColoredRectangle cr2 (2, 2, 40, 50, 99);
	cr.print();
}