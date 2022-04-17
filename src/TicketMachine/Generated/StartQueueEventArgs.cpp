#include "pch.h"
#include "StartQueueEventArgs.h"
#include "StartQueueEventArgs.g.cpp"

namespace winrt::TicketMachine::implementation
{
  bool StartQueueEventArgs::ItemAdded()
  {
    return m_added;
  }

  StartQueueEventArgs::StartQueueEventArgs(bool isAdded) :m_added(isAdded)
  {
    m_added = isAdded;
  }
}
