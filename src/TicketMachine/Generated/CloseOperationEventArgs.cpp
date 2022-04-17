#include "pch.h"
#include "CloseOperationEventArgs.h"
#include "CloseOperationEventArgs.g.cpp"

namespace winrt::TicketMachine::implementation
{
  bool CloseOperationEventArgs::OperationClosed()
  {
    return m_closed;
  }

  implementation::CloseOperationEventArgs::CloseOperationEventArgs(bool isClosed)
  {
    m_closed = isClosed;
  }
}
