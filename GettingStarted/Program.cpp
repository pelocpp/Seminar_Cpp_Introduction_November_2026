#include <iostream>

#include "Time.h"

int main() {

	std::cout << "Hallo Seminar\n";

	// Objekte der Klasse Time anlegen

	Time now(9999, 44, 40);

//	now.hours = 12;         // Zugriff auf Daten
	now.setHours(9999);

	//now.minutes = 8;
	now.setMinutes(8);
	//now.seconds = 30;
	now.setSeconds(30);

	Time pause;

//	pause.hours = 12;
	pause.setHours(12);

	//pause.minutes = 30;
	pause.setMinutes(30);
	//pause.seconds = 0;
	pause.setSeconds(0);

	int h = now.getHours();

	now.print();            // Zugriff auf Methoden

	pause.print();
}