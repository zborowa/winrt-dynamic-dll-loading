#include "pch.h"
#include "Service.h"
#include "Service.g.cpp"

namespace winrt::TicketMachine::implementation
{
  Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::IVector<TicketMachine::Service>> Service::GetCollection()
  {
    winrt::TicketMachine::Service srv[4];

    m_services = winrt::single_threaded_vector<winrt::TicketMachine::Service>();

    int i = 0;
    while (i <= 4)
    {
      srv[i] = winrt::make<winrt::TicketMachine::implementation::Service>();

      switch (i)
      {
      case 0: srv[i].ServiceCode(L"01");
        srv[i].ServiceName(L"Currency Exchanges");
        break;
      case 1: srv[i].ServiceCode(L"02");
        srv[i].ServiceName(L"Front Desk Customer Service");
        break;
      case 2: srv[i].ServiceCode(L"03");
        srv[i].ServiceName(L"Computer&Smartphone Assistance");
        break;
      case 3: srv[i].ServiceCode(L"04");
        srv[i].ServiceName(L"Lost&Found");
        break;
      case 4: srv[i].ServiceCode(L"05");
        srv[i].ServiceName(L"Parking");
        break;
      }

      m_services.Append(srv[i]);

      ++i;
    }

    co_return m_services;
  }

  hstring Service::ServiceCode()
  {
    return m_serviceCode;
  }
  void Service::ServiceCode(hstring const& value)
  {
    m_serviceCode = value;
  }
  hstring Service::ServiceName()
  {
    return m_serviceName;
  }
  void Service::ServiceName(hstring const& value)
  {
    m_serviceName = value;
  }
  void Service::Add()
  {
  }
  void Service::Edit()
  {
  }
  void Service::Delete()
  {
  }
  void Service::Save()
  {
  }
}
