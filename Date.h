#pragma once

ref class Date
{
public:
	bool SetDay(short aDay);
	short GetDay();

	bool SetMonth(short aMonth);
	short GetMonth();

	bool SetYear(short aYear);
	short GetYear();

	bool SetDate(short aDay, short aMonth, short aYear);
private:
	short m_Day = 0;
	short m_Month = 0;
	short m_Year = 0;
};