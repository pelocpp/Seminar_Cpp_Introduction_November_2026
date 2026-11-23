#pragma once

//namespace UI
//{
//	class Time
//	{
//	};
//}
//
//namespace Backend
//{
//
//}


class Time
{
private:  // data  // m ... member
	int m_hours;
	int m_minutes;
	int m_seconds;


// public interface
public:
	// Konstruktoren / c'tor(s)
	Time();
	Time(int hours, int minutes, int seconds);

	// getter
//	int getHours() { return hours; }

	int getHours();
	int getMinutes();
	int getSeconds();

	// setter
	void setHours(int);
	void setMinutes(int);
	void setSeconds(int seconds);

	void print();
	void reset();
	void increment();  // eine Sekunde dazu zählen 
};

