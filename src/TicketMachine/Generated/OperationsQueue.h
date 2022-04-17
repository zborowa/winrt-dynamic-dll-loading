#pragma once
#include "OperationsQueue.g.h"

namespace winrt::TicketMachine::implementation
{
    struct OperationsQueue : OperationsQueueT<OperationsQueue>
    {
        OperationsQueue() = default;

        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::TicketMachine::OperationsQueue>> GetCollection();
        void OperationItemAdded(bool isAdded);
        void OperationCompleted(bool isCompleted);
        winrt::event_token OnQueueItemAdded(winrt::Windows::Foundation::EventHandler<winrt::TicketMachine::StartQueueEventArgs> const& handler);
        void OnQueueItemAdded(winrt::event_token const& token) noexcept;
        winrt::event_token OnOperationCompleted(winrt::Windows::Foundation::EventHandler<winrt::TicketMachine::CloseOperationEventArgs> const& handler);
        void OnOperationCompleted(winrt::event_token const& token) noexcept;
        hstring ServiceCode();
        void ServiceCode(hstring const& value);
        hstring ServiceName();
        void ServiceName(hstring const& value);
        hstring DeskNumber();
        void DeskNumber(hstring const& value);
        hstring DeskCode();
        void DeskCode(hstring const& value);
        hstring DeskName();
        void DeskName(hstring const& value);
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

      winrt::event<Windows::Foundation::EventHandler<StartQueueEventArgs>> m_OnStartQueueEvent;
      bool m_startQueue = false;

      winrt::event<Windows::Foundation::EventHandler<CloseOperationEventArgs>> m_OnCompletedEvent;
      bool m_completed = false;
    };
}
namespace winrt::TicketMachine::factory_implementation
{
    struct OperationsQueue : OperationsQueueT<OperationsQueue, implementation::OperationsQueue>
    {
    };
}
