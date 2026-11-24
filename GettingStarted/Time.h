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
	friend bool operator== (const Time& left, const Time& right);

private:  // data  // m ... member
	int m_hours;
	int m_minutes;
	int m_seconds;


// public interface
public:
	// Konstruktoren / c'tor(s)
	Time();
	Time(int hours, int minutes, int seconds);

	~Time();

	// getter
//	int getHours() { return hours; }

	// Vorsichtsmaßnahme: lesender Zugriff

	int getHours() const;
	int getMinutes() const;
	int getSeconds() const;

	// setter
	void setHours(int);
	void setMinutes(int);
	void setSeconds(int seconds);

	void print() const;
	void reset();
	void increment();  // eine Sekunde dazu zählen 

	// Vergleiche / Comparison
	bool equals( const Time& other ) const;
	bool unequals(const Time& other) const;

	// Operators
	// bool operator== (const Time& other) const;
};

// ================================================
// Außerhalb der Klasse

// bool operator== (const Time& left, const Time& right);

