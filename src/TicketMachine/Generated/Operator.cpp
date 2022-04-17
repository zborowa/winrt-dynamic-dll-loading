#include "pch.h"
#include "Operator.h"
#include "Operator.g.cpp"

namespace winrt::TicketMachine::implementation
{
  hstring Operator::BadgeCode()
  {
    return m_badgeCode;
  }
  void Operator::BadgeCode(hstring const& value)
  {
    m_badgeCode = value;
  }

  Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<TicketMachine::Operator>> Operator::GetCollection()
  {
    winrt::TicketMachine::Operator opr[4];
    m_operators = winrt::single_threaded_vector<winrt::TicketMachine::Operator>();

    int i = 0;
    while (i <= 4)
    {
      opr[i] = winrt::make<winrt::TicketMachine::implementation::Operator>();

      switch (i)
      {
      case 0:  opr[i].BadgeCode(L"8C8882D9-5BDE-4FDA-86C7-DB9926DB75AE");
        opr[i].FirstName(L"Mario");
        opr[i].LastName(L"Rossi");
        m_birthDate.Year(2001); m_birthDate.Month(12); m_birthDate.Day(10);
        opr[i].BirthDate(m_birthDate);
        break;

      case 1:  opr[i].BadgeCode(L"441661CA-9A44-4B6A-AA4B-B99B13F4C214");
        opr[i].FirstName(L"Franco");
        opr[i].LastName(L"Verdi");
        m_birthDate.Year(1976); m_birthDate.Month(4); m_birthDate.Day(22);
        opr[i].BirthDate(m_birthDate);
        break;

      case 2:  opr[i].BadgeCode(L"1F10AFF3-4365-445B-B256-AFFA2CCC8BF7");
        opr[i].FirstName(L"Gianna");
        opr[i].LastName(L"Gialli");
        m_birthDate.Year(1985); m_birthDate.Month(5); m_birthDate.Day(31);
        opr[i].BirthDate(m_birthDate);
        break;

      case 3:  opr[i].BadgeCode(L"FE1F901F-6BBF-45F0-8885-DE049153FFD0");
        opr[i].FirstName(L"Maria");
        opr[i].LastName(L"Bianchi");
        m_birthDate.Year(1998); m_birthDate.Month(12); m_birthDate.Day(19);
        opr[i].BirthDate(m_birthDate);
        break;

      case 4:  opr[i].BadgeCode(L"C3D6F5F7-7981-433B-8A7E-61DD6AF8735E");
        opr[i].FirstName(L"Rosa");
        opr[i].LastName(L"Neri");
        m_birthDate.Year(1990); m_birthDate.Month(2); m_birthDate.Day(22);
        opr[i].BirthDate(m_birthDate);
        break;
      }

      m_operators.Append(opr[i]);

      ++i;
    }

    co_return m_operators;
  }
  hstring Operator::FirstName()
  {
    return m_firstName;
  }
  void Operator::FirstName(hstring const& value)
  {
    m_firstName = value;
  }
  hstring Operator::LastName()
  {
    return m_lastName;
  }
  void Operator::LastName(hstring const& value)
  {
    m_lastName = value;
  }
  TicketMachine::Date Operator::BirthDate()
  {
    return m_birthDate;
  }
  void Operator::BirthDate(TicketMachine::Date const& value)
  {
    m_birthDate = value;
  }
  void Operator::Add()
  {
  }
  void Operator::Edit()
  {
  }
  void Operator::Delete()
  {
  }
  void Operator::Save()
  {
  }
}
