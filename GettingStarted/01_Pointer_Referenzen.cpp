#include "Time.h"

#include <iostream>

void test_references_pointer_01()
{
	// Zeiger (Pointer)

	// Deklaration / Declaration: Speicher für eine Variable reservieren / Vorbelegung
	int n = 999;

	// int s = sizeof(int);

	// Deklaration / Declaration: Speicher für eine Variable reservieren / Vorbelegung
	int* ptr = nullptr; // NULL

	ptr = &n;   // &:  Adresse-von // Anweisung

	// Anweisung / Statement
	n = 123;

	// Mini-Übung: Der Variablen n den Wert 456 zuweisen, ohne den Namen 'n' zu verwenden
	* ptr = 456;       // Indirekter Zugriff lesend / schreiben

	ptr++;   // Dieser Speicher gehört mir erstmal nicht - Debug: Absturz
	
	*ptr = 888;       // Indirekter Zugriff lesend / schreiben
} 

void test_references_pointer_02()
{
	int n = 123;

	// Alias-Name / hinter den Kulissen: Adresse des Originals
	// Datentyp: int&  <===> Referenz auf int
	int& rn = n;

	// Mini-Übung: Der Variablen n den Wert 456 zuweisen, ohne den Namen 'n' zu verwenden
	rn = 456;

	rn++;

	int x = 999;

	rn = x;
}

//  Hmmmm: Time&: gut, weil schnell: 
//  Vorsicht: Zugriff auf das Original
//  Option: Man kann das Original schützen

// "Methode ohne Objekt":   freie Funktion

void printTime(const Time& t)
{
	// t.setHours(23);  // für eine Ausgabe: Unsinnig ... nur der Demo halber

	std::cout << t.getHours() << ":" << t.getMinutes() << ":" << t.getSeconds() << std::endl;
}

void resetTime(Time t)
{
	Time tmp = t;     // Kopie in tmp

	t.setHours(0);
	t.setMinutes(0);
	t.setSeconds(0);
}

int feld[100000000];

void tueWas(const Time& t) {


	int feld[100000000]{};   // schlecht ..

}


void resetTimeEx(Time& t)
{
	Time tmp = t;    // Kopie in tmp

	t.setHours(0);
	t.setMinutes(0);
	t.setSeconds(0);
}

void test_references_pointer_03()
{
	Time now(9, 17, 0);
	//now.print();
	printTime(now);

	resetTime(now);
	//now.print();
	printTime(now);

	resetTimeEx(now);
	//now.print();
	printTime(now);
}

void malZwei(int n)
{
	int tmp = n;

	n = 2 * n;
}

void malZweiEx(int* ptr)
{
	// n = 2 * n;
	int tmp = *ptr;

	tmp = 2 * tmp;

	*ptr = tmp;
}

void malZweiExEx(int& ri)
{
	int tmp = ri;

	ri = 2 * ri;
}

void test_references_pointer_04()
{
	int x = 10;
	std::cout << x << std::endl;

	malZwei(x);
	std::cout << x << std::endl;

	malZweiEx(&x);
	std::cout << x << std::endl;

	malZweiExEx(x);
	std::cout << x << std::endl;
}

void main_references_pointer()
{
	 //test_references_pointer_01();
	 //test_references_pointer_02();
	 test_references_pointer_03();
	 //test_references_pointer_04();
}
