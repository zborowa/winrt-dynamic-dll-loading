#pragma once
#include "CloseOperationEventArgs.g.h"

namespace winrt::TicketMachine::implementation
{
    struct CloseOperationEventArgs : CloseOperationEventArgsT<CloseOperationEventArgs>
    {
        CloseOperationEventArgs() = default;

        bool OperationClosed();

        CloseOperationEventArgs(bool isClosed);

    private:
      bool m_closed = false;
    };
}
