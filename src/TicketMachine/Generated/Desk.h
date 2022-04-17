#pragma once
#include "Desk.g.h"

namespace winrt::TicketMachine::implementation
{
    struct Desk : DeskT<Desk>
    {
        Desk() = default;

        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::TicketMachine::Desk>> GetCollection();
        hstring DeskNumber();
        void DeskNumber(hstring const& value);
        hstring DeskCode();
        void DeskCode(hstring const& value);
        hstring DeskName();
        void DeskName(hstring const& value);
        void Add();
        void Edit();
        void Delete();
        void Save();

    private:
      hstring m_deskNumber{ L"" };
      hstring m_deskCode{ L"" };
      hstring m_deskName{ L"" };
      Windows::Foundation::Collections::IVector<TicketMachine::Desk> m_desks;
    };
}
namespace winrt::TicketMachine::factory_implementation
{
    struct Desk : DeskT<Desk, implementation::Desk>
    {
    };
}
