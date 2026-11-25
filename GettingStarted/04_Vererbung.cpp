#include <vector>
#include <iostream>

// Schnittstelle
struct IShape
{
	virtual void print() = 0;
};

struct IRectangle
{
	virtual int area() = 0;
	virtual int circumference() = 0;
};

// Abstrakte Klasse
class Rectangle : public IRectangle, public IShape
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

	// Bereitstellung einer Funktionalität
	// Sollte von Kindklasse nicht verändert werden : Kein virtual
	void clearBackground() {}

	int area() override { return m_height * m_width; };
	int circumference() override { return 2 * (m_height + m_width); };
};

//Rectangle : Object
//Image: Object

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

    void print() override {
		std::cout << "ColoredRectangle" << std::endl;
	}
};

class BlackWhiteRectangle : public Rectangle
{
private:
	double m_grade;  

public:
	BlackWhiteRectangle() : m_grade(0.0) {}

	BlackWhiteRectangle(int x, int y, int width, int height, double grade)
		: Rectangle(x, y, width, height), m_grade(grade)
	{
	}

	void print() override {
		std::cout << "BlackWhiteRectangle" << std::endl;
	}
};


void test_vererbung_01()
{
	ColoredRectangle cr;
	cr.print();

	ColoredRectangle cr2 (2, 2, 40, 50, 99);
	cr.print();
}

void test_vererbung_02()
{
	Rectangle* rectPtr = nullptr;

	ColoredRectangle* cr = new ColoredRectangle(2, 2, 40, 50, 99);

	// cr->print();

	// Container / Arrays von Basisklassenzeigern

	rectPtr = cr;

	rectPtr->print();
}

void main_vererbung()
{
	ColoredRectangle* cr1 = new ColoredRectangle(2, 2, 40, 50, 99);
	ColoredRectangle* cr2 = new ColoredRectangle(2, 2, 40, 50, 99);
	ColoredRectangle* cr3 = new ColoredRectangle(2, 2, 40, 50, 99);

	BlackWhiteRectangle* bwr1 = new BlackWhiteRectangle(2, 2, 40, 50, 1.0);
	BlackWhiteRectangle* bwr2 = new BlackWhiteRectangle(2, 2, 40, 50, 1.0);

	//IRectangle* ir = cr1;
	//ir->

	IRectangle* rectangles[5] = { cr1, bwr1, cr2, bwr2, cr2 };

	// berechne Gesamtfläche aller Figuren
	int totalArea = 0;
	for (int i = 0; i < 5; ++i) {
		totalArea += rectangles[i]->area();   // <========== Polymorphie
	}

	IShape* shapes[5] = { cr1, bwr1, cr2, bwr2, cr2 };

	// berechne Gesamtfläche aller Figuren
	for (int i = 0; i < 5; ++i) {
		shapes[i]->print();  // <========== Polymorphie
	}


}

