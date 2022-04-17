#include "pch.h"
#include "Ticket.h"
#include "Ticket.g.cpp"

#include "Helpers.h"
#include <ctime>

using namespace winrt::Windows::Foundation;
using namespace winrt::Windows::Foundation::Collections;

namespace winrt::TicketMachine::implementation
{
  void Ticket::Create()
  {
    // Get Services
    winrt::TicketMachine::Service srv;
    Collection<winrt::TicketMachine::Service> _srv;

    auto _services = _srv.GetItems(srv, true);
    //===========================

    // Get Desks
    winrt::TicketMachine::Desk dsk;
    Collection<winrt::TicketMachine::Desk> _dsk;

    auto _desks = _dsk.GetItems(dsk, true);
    //===========================

    // Get Operators
    winrt::TicketMachine::Operator opr;
    Collection<winrt::TicketMachine::Operator> _opr;

    auto _operators = _opr.GetItems(opr, true);
    //===========================

    //Check ticket number        
    if (m_index > m_maxQueueElements)
      m_index = 1;
    else
      m_index += 1;

    //Set current ticket index
    TicketNumber(winrt::to_hstring(m_index));

    //Ticket combinations
    int rnd = rand() % 5;

    hstring tmpTicket = _services[rnd].ServiceCode() + L", " +
      _services[rnd].ServiceName() + L", " +
      _desks[rnd].DeskNumber() + L", " +
      _desks[rnd].DeskCode() + L", " +
      _desks[rnd].DeskName() + L", " +
      _operators[rnd].BadgeCode() + L", " +
      _operators[rnd].FirstName() + L", " +
      _operators[rnd].LastName() + L", " +
      _operators[rnd].BirthDate().DateToString() + L", ";

    m_creationDate = GetDate();

    //Service 
    m_serviceCode = _services[rnd].ServiceCode();
    m_serviceName = _services[rnd].ServiceName();

    //Desk
    m_deskNumber = _desks[rnd].DeskNumber();
    m_deskCode = _desks[rnd].DeskCode();
    m_deskName = _desks[rnd].DeskName();

    //Operator
    m_badgeCode = _operators[rnd].BadgeCode();
    m_firstName = _operators[rnd].FirstName();
    m_lastName = _operators[rnd].LastName();
    m_birthDate = _operators[rnd].BirthDate();

    //Set current ticket code
    m_ticketString = tmpTicket;
  }

  TicketMachine::Date implementation::Ticket::GetDate()
  {
    std::time_t t = std::time(0);
    struct tm date;
    _localtime64_s(&date, &t);

    int year = date.tm_year + 1900;
    int month = date.tm_mon + 1;
    int day = date.tm_mday;

    int hour = date.tm_hour;
    int minutes = date.tm_min;
    int seconds = date.tm_sec;

    TicketMachine::Date dt;

    dt.Year(year);
    dt.Month(month);
    dt.Day(day);

    dt.Hh(hour);
    dt.Mm(minutes);
    dt.Ss(seconds);

    return dt;
  }

  hstring Ticket::TicketToString()
  {
    return m_ticketString;
  }

  hstring Ticket::TicketNumber()
  {
    return m_ticketNumber;
  }
  void Ticket::TicketNumber(hstring const& value)
  {
    m_ticketNumber = value;
  }
  hstring Ticket::TicketBarcode()
  {
    return m_ticketBarcode;
  }
  void Ticket::TicketBarcode(hstring const& value)
  {
    m_ticketBarcode = value;
  }
  int32_t Ticket::MaxQueueItems()
  {
    return m_maxQueueElements;
  }
  void Ticket::MaxQueueItems(int32_t value)
  {
    m_maxQueueElements = value;
  }
  TicketMachine::Date Ticket::CreationDate()
  {
    return m_creationDate;
  }
  void Ticket::CreationDate(TicketMachine::Date const& value)
  {
    m_creationDate = value;
  }
  Windows::Storage::StorageFile Ticket::TicketQRCode()
  {
    //throw hresult_not_implemented();
    return nullptr;
  }
  void Ticket::TicketQRCode(Windows::Storage::StorageFile const& /*value*/)
  {
    //throw hresult_not_implemented();
  }
  Windows::Storage::StorageFile Ticket::ImageFile()
  {
    //throw hresult_not_implemented();
    return nullptr;
  }
  void Ticket::ImageFile(Windows::Storage::StorageFile const& /*value*/)
  {
    //throw hresult_not_implemented();
  }

  //Common
  void Ticket::Add()
  {
    //throw hresult_not_implemented();
  }
  void Ticket::Edit()
  {
    //throw hresult_not_implemented();
  }
  void Ticket::Delete()
  {
    //throw hresult_not_implemented();
  }
  void Ticket::Save()
  {
    //throw hresult_not_implemented();
  }

  //Services
  hstring Ticket::ServiceCode()
  {
    return m_serviceCode;
  }
  void Ticket::ServiceCode(hstring const& value)
  {
    m_serviceCode = value;
  }
  hstring Ticket::ServiceName()
  {
    return m_serviceName;
  }
  void Ticket::ServiceName(hstring const& value)
  {
    m_serviceName = value;
  }

  //Desks
  hstring Ticket::DeskNumber()
  {
    return m_deskNumber;
  }
  void Ticket::DeskNumber(hstring const& value)
  {
    m_deskNumber = value;
  }
  hstring Ticket::DeskCode()
  {
    return m_deskCode;
  }
  void Ticket::DeskCode(hstring const& value)
  {
    m_deskCode = value;
  }
  hstring Ticket::DeskName()
  {
    return m_deskName;
  }
  void Ticket::DeskName(hstring const& value)
  {
    m_deskName = value;
  }

  //Operators
  hstring Ticket::FirstName()
  {
    return m_firstName;
  }
  void Ticket::FirstName(hstring const& value)
  {
    m_firstName = value;
  }
  hstring Ticket::LastName()
  {
    return m_lastName;
  }
  void Ticket::LastName(hstring const& value)
  {
    m_lastName = value;
  }
  TicketMachine::Date Ticket::BirthDate()
  {
    return m_birthDate;
  }
  void Ticket::BirthDate(TicketMachine::Date const& value)
  {
    m_birthDate = value;
  }
}
