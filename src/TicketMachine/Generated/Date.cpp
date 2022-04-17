#include "pch.h"
#include "Date.h"
#include "Date.g.cpp"

namespace winrt::TicketMachine::implementation
{
  hstring Date::DateToString()
  {
    hstring tmpDate = winrt::to_hstring(m_month) + L"/" +
      to_hstring(m_day) + L"/" + to_hstring(m_year);
    return tmpDate;
  }
  hstring Date::TimeToString()
  {
    hstring tmpTime = L"";
    tmpTime = Format(m_hh) + L":" + Format(m_mm) + L":" + Format(m_ss);
    return tmpTime;
  }

  hstring implementation::Date::Format(int32_t t)
  {
    hstring tmpTime = to_hstring(t);

    switch (tmpTime.size())
    {
    case 1:tmpTime = L"0" + tmpTime; break;
    }
    return tmpTime;
  }

  int32_t Date::Year()
  {
    return m_year;
  }
  void Date::Year(int32_t value)
  {
    m_year = value;
  }
  int32_t Date::Month()
  {
    return m_month;
  }
  void Date::Month(int32_t value)
  {
    m_month = value;
  }
  int32_t Date::Day()
  {
    return m_day;
  }
  void Date::Day(int32_t value)
  {
    m_day = value;
  }
  int32_t Date::Hh()
  {
    return m_hh;
  }
  void Date::Hh(int32_t value)
  {
    m_hh = value;
  }
  int32_t Date::Mm()
  {
    return m_mm;
  }
  void Date::Mm(int32_t value)
  {
    m_mm = value;
  }
  int32_t Date::Ss()
  {
    return m_ss;
  }
  void Date::Ss(int32_t value)
  {
    m_ss = value;
  }
}
