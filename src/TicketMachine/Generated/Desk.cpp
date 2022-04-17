#include "pch.h"
#include "Desk.h"
#include "Desk.g.cpp"

namespace winrt::TicketMachine::implementation
{
  Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<TicketMachine::Desk>> Desk::GetCollection()
  {
    winrt::TicketMachine::Desk dsk[4];
    m_desks = winrt::single_threaded_vector<winrt::TicketMachine::Desk>();

    int i = 0;
    while (i <= 4)
    {
      dsk[i] = winrt::make<winrt::TicketMachine::implementation::Desk>();

      switch (i)
      {

      case 0: dsk[i].DeskNumber(L"1");
        dsk[i].DeskCode(L"A");
        dsk[i].DeskName(L"A01");
        break;

      case 1: dsk[i].DeskNumber(L"2");
        dsk[i].DeskCode(L"B");
        dsk[i].DeskName(L"B02");
        break;

      case 2: dsk[i].DeskNumber(L"3");
        dsk[i].DeskCode(L"C");
        dsk[i].DeskName(L"C03");
        break;

      case 3: dsk[i].DeskNumber(L"4");
        dsk[i].DeskCode(L"D");
        dsk[i].DeskName(L"D04");
        break;

      case 4: dsk[i].DeskNumber(L"5");
        dsk[i].DeskCode(L"E");
        dsk[i].DeskName(L"E05");
        break;
      }

      m_desks.Append(dsk[i]);

      ++i;
    }

    co_return m_desks;
  }
  hstring Desk::DeskNumber()
  {
    return m_deskNumber;
  }
  void Desk::DeskNumber(hstring const& value)
  {
    m_deskNumber = value;
  }
  hstring Desk::DeskCode()
  {
    return m_deskCode;
  }
  void Desk::DeskCode(hstring const& value)
  {
    m_deskCode = value;
  }
  hstring Desk::DeskName()
  {
    return m_deskName;
  }
  void Desk::DeskName(hstring const& value)
  {
    m_deskName = value;
  }

  void Desk::Add()
  {
  }
  void Desk::Edit()
  {
  }
  void Desk::Delete()
  {
  }
  void Desk::Save()
  {
  }
}
