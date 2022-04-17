#pragma once
#include "StartQueueEventArgs.g.h"

namespace winrt::TicketMachine::implementation
{
    struct StartQueueEventArgs : StartQueueEventArgsT<StartQueueEventArgs>
    {
        StartQueueEventArgs() = default;

        bool ItemAdded();

        StartQueueEventArgs(bool isAdded);

    private:
      bool m_added = false;
    };
}
