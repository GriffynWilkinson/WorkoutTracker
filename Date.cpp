#include "Date.h"

// Returns true if the day set is between 1 and 31
bool Date::SetDay(short aDay)
{
	if (aDay >= 1 && aDay <= 31)
	{
		m_Day = aDay;
		return true;
	}

	return false;
}

short Date::GetDay()
{
	return m_Day;
}

// Returns true if the month set is between 1 and 12
bool Date::SetMonth(short aMonth)
{
	if (aMonth >= 1 && aMonth <= 12)
	{
		m_Month = aMonth;
		return true;
	}

	return false;
}

short Date::GetMonth()
{
	return m_Month;
}

// Returns true if the year set is between 2017 and 2020
bool Date::SetYear(short aYear)
{
	if (aYear >= 2017 && aYear <= 2020)
	{
		m_Year = aYear;
		return true;
	}

	return false;
}

short Date::GetYear()
{
	return m_Year;
}

bool Date::SetDate(short aDay, short aMonth, short aYear)
{
	if (SetDay(aDay))
	{
		if (SetMonth(aMonth))
		{
			if (SetYear(aYear))
			{
				return true;
			}
		}
	}

	return false;
}