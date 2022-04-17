#pragma once
#include "Ticket.g.h"

namespace winrt::TicketMachine::implementation
{
    struct Ticket : TicketT<Ticket>
    {
        Ticket() = default;

        void Create();
        hstring TicketToString();
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
        winrt::Windows::Storage::StorageFile ImageFile();
        void ImageFile(winrt::Windows::Storage::StorageFile const& value);
        void Add();
        void Edit();
        void Delete();
        void Save();
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
        hstring FirstName();
        void FirstName(hstring const& value);
        hstring LastName();
        void LastName(hstring const& value);
        winrt::TicketMachine::Date BirthDate();
        void BirthDate(winrt::TicketMachine::Date const& value);

    private:

      hstring m_ticketNumber{ L"" };
      hstring m_ticketBarcode{ L"" };
      int32_t m_maxQueueElements{ 100 };
      winrt::TicketMachine::Date m_creationDate;

      winrt::TicketMachine::Service m_service;
      winrt::TicketMachine::Desk m_desk;
      winrt::TicketMachine::Operator m_operator;

      int m_index = 0;

      hstring m_ticketString = L"";

      //Services
      hstring m_serviceCode{ L"" };
      hstring m_serviceName{ L"" };

      //Desks
      hstring m_deskNumber{ L"" };
      hstring m_deskCode{ L"" };
      hstring m_deskName{ L"" };

      //Operators
      hstring m_badgeCode{ L"" };
      hstring m_firstName{ L"" };
      hstring m_lastName{ L"" };
      TicketMachine::Date m_birthDate;

      TicketMachine::Date GetDate();
    };
}
namespace winrt::TicketMachine::factory_implementation
{
    struct Ticket : TicketT<Ticket, implementation::Ticket>
    {
    };
}
