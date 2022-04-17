#pragma once
#include "Operator.g.h"

namespace winrt::TicketMachine::implementation
{
    struct Operator : OperatorT<Operator>
    {
        Operator() = default;

        hstring BadgeCode();
        void BadgeCode(hstring const& value);
        winrt::Windows::Foundation::IAsyncOperation<winrt::Windows::Foundation::Collections::IVector<winrt::TicketMachine::Operator>> GetCollection();
        hstring FirstName();
        void FirstName(hstring const& value);
        hstring LastName();
        void LastName(hstring const& value);
        winrt::TicketMachine::Date BirthDate();
        void BirthDate(winrt::TicketMachine::Date const& value);
        void Add();
        void Edit();
        void Delete();
        void Save();

    private:
      hstring m_badgeCode{ L"" };
      hstring m_firstName{ L"" };
      hstring m_lastName{ L"" };
      TicketMachine::Date m_birthDate;
      Windows::Foundation::Collections::IVector<TicketMachine::Operator> m_operators;
    };
}
namespace winrt::TicketMachine::factory_implementation
{
    struct Operator : OperatorT<Operator, implementation::Operator>
    {
    };
}
