#pragma once
#include "Common.g.h"

namespace winrt::TicketMachine::implementation
{
  struct Common : CommonT<Common>
  {
    Common() = default;

    void Add();
    void Edit();
    void Delete();
    void Save();
  };
}
namespace winrt::TicketMachine::factory_implementation
{
  struct Common : CommonT<Common, implementation::Common>
  {
  };
}
