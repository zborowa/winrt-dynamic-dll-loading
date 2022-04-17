#pragma once
#include "Date.g.h"

namespace winrt::TicketMachine::implementation
{
    struct Date : DateT<Date>
    {
        Date() = default;

        hstring DateToString();
        hstring TimeToString();
        int32_t Year();
        void Year(int32_t value);
        int32_t Month();
        void Month(int32_t value);
        int32_t Day();
        void Day(int32_t value);
        int32_t Hh();
        void Hh(int32_t value);
        int32_t Mm();
        void Mm(int32_t value);
        int32_t Ss();
        void Ss(int32_t value);

    private:
      int32_t m_year{ 0 };
      int32_t m_month{ 0 };
      int32_t m_day{ 0 };
      int32_t m_hh{ 0 };
      int32_t m_mm{ 0 };
      int32_t m_ss{ 0 };

      hstring Format(int32_t t);
    };
}
namespace winrt::TicketMachine::factory_implementation
{
    struct Date : DateT<Date, implementation::Date>
    {
    };
}
