#pragma once
#include "Service.g.h"

namespace winrt::TicketMachine::implementation
{
    struct Service : ServiceT<Service>
    {
        Service() = default;

        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::TicketMachine::Service>> GetCollection();
        hstring ServiceCode();
        void ServiceCode(hstring const& value);
        hstring ServiceName();
        void ServiceName(hstring const& value);
        void Add();
        void Edit();
        void Delete();
        void Save();

    private:
      hstring m_serviceCode{ L"" };
      hstring m_serviceName{ L"" };
      Windows::Foundation::Collections::IVector<TicketMachine::Service> m_services;
    };
}
namespace winrt::TicketMachine::factory_implementation
{
    struct Service : ServiceT<Service, implementation::Service>
    {
    };
}
