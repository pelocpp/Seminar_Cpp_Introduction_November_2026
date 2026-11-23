#include <iostream>  // cout: character output

#include "Time.h"

// Konstruktoren / c'tor(s)
//Time::Time()
//{
//	m_hours = 0;
//	m_minutes = 0;
//	m_seconds = 0;
//}

Time::Time() : m_hours(0), m_minutes(0), m_seconds(0)
{}

Time::Time(int hours, int minutes, int seconds) : Time ()
{
    // Instanzvariablen
	//m_hours = 0;
	//m_minutes = 0;
	//m_seconds = 0;

	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}

void Time::print()
{
	std::cout << m_hours << ":" << m_minutes << ":" << m_seconds << std::endl;
}

void Time::reset()
{
	m_hours = 0;
	m_minutes = 0;
	m_seconds = 0;
}

void Time::increment()
{
	// ein erster Ansatz - fast immer falsch
	m_seconds = m_seconds + 1;
}

void Time::setHours(int hours)
{
	// C++:    &&    ||,  !
	// Python: and,  or,  not
	if (hours >= 0 && hours < 24)
	{
		m_hours = hours;
	}
	else
	{
		std::cout << "Falscher Stundenwert: " << hours << std::endl;
	}
}

void Time::setMinutes(int minutes)
{
	if (minutes >= 0 && minutes < 60)
	{
		m_minutes = minutes;
	}
	else
	{
		std::cout << "Falscher Minutenwert: " << minutes << std::endl;
	}
}

// Erste Variante in einer guten Benennung von Variablen und Attributen:
// Gute Lesbarkeit 
// Aufläsung von Mehrdeutigkeiten: this
// Java-Stilistik
//
//void Time::setSeconds(int seconds)
//{
//	if (seconds >= 0 && seconds < 60)   // passt
//	{
//		this->seconds = seconds;        //   links: passt jetzt !!! = rechts: passt
//	}
//	else
//	{
//		std::cout << "Falscher Sekundenwert: " << seconds << std::endl;
//	}
//}


void Time::setSeconds(int seconds)
{
	if (seconds >= 0 && seconds < 60)   // passt
	{
		m_seconds = seconds;        //   links: passt jetzt !!! = rechts: passt
	}
	else
	{
		std::cout << "Falscher Sekundenwert: " << seconds << std::endl;
	}
}


int Time::getHours()
{
	return m_hours;
}

int Time::getMinutes()
{
	return m_minutes;
}

int Time::getSeconds()
{
	return m_seconds;
}



