#pragma once
#include "OperationsLog.g.h"

namespace winrt::TicketMachine::implementation
{
    struct OperationsLog : OperationsLogT<OperationsLog>
    {
        OperationsLog() = default;

        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::TicketMachine::OperationsLog>> GetCollection();
        hstring ServiceCode();
        void ServiceCode(hstring const& value);
        hstring ServiceName();
        void ServiceName(hstring const& value);
        hstring TicketNumber();
        void TicketNumber(hstring const& value);
        hstring TicketBarcode();
        void TicketBarcode(hstring const& value);
        int32_t MaxQueueItems();
        void MaxQueueItems(int32_t value);
        winrt::TicketMachine::Date CreationDate();
        void CreationDate(winrt::TicketMachine::Date const& value);
        winrt::Windows::Storage::StorageFile TicketQRCode();
        void TicketQRCode(winrt::Windows::Storage::StorageFile const& value);
        void Add();
        void Edit();
        void Delete();
        void Save();

    private:
      hstring m_serviceCode{ L"" },
        m_serviceName{ L"" },
        m_deskCode{ L"" },
        m_deskName{ L"" },
        m_deskNumber{ L"" },
        m_ticketNumber{ L"" };

      int32_t m_maxQueueItems{ 0 };
      TicketMachine::Date m_CreationDate;
    };
}
namespace winrt::TicketMachine::factory_implementation
{
    struct OperationsLog : OperationsLogT<OperationsLog, implementation::OperationsLog>
    {
    };
}
