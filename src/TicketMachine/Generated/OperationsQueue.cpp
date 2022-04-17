#include "pch.h"
#include "OperationsQueue.h"
#include "OperationsQueue.g.cpp"

#include "StartQueueEventArgs.h"
#include "CloseOperationEventArgs.h"
#include "Helpers.h"

namespace winrt::TicketMachine::implementation
{
  Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::
    IVector<TicketMachine::OperationsQueue>> OperationsQueue::GetCollection()
  {
    return nullptr;
  }

  //Events
  void OperationsQueue::OperationItemAdded(bool isAdded)
  {
    m_startQueue = isAdded;
    auto args = winrt::make_self<winrt::TicketMachine::implementation::
      StartQueueEventArgs>(m_startQueue);
    m_OnStartQueueEvent(*this, *args);
  }

  void OperationsQueue::OperationCompleted(bool isCompleted)
  {
    m_completed = isCompleted;
    auto args = winrt::make_self<winrt::TicketMachine::implementation::
      CloseOperationEventArgs>(m_completed);
    m_OnCompletedEvent(*this, *args);
  }

  winrt::event_token OperationsQueue::OnQueueItemAdded(Windows::Foundation::
    EventHandler<TicketMachine::StartQueueEventArgs> const& handler)
  {
    return  m_OnStartQueueEvent.add(handler);
  }
  void OperationsQueue::OnQueueItemAdded(winrt::event_token const& token) noexcept
  {
    m_OnStartQueueEvent.remove(token);
  }

  winrt::event_token OperationsQueue::OnOperationCompleted
  (Windows::Foundation::EventHandler<TicketMachine::CloseOperationEventArgs> const& handler)
  {
    return m_OnCompletedEvent.add(handler);
  }
  void OperationsQueue::OnOperationCompleted(winrt::event_token const& token) noexcept
  {
    m_OnCompletedEvent.remove(token);
  }

  //Service
  hstring OperationsQueue::ServiceCode()
  {
    return m_serviceCode;
  }
  void OperationsQueue::ServiceCode(hstring const& value)
  {
    m_serviceCode = value;
  }
  hstring OperationsQueue::ServiceName()
  {
    return m_serviceName;
  }
  void OperationsQueue::ServiceName(hstring const& value)
  {
    m_serviceName = value;
  }

  //Desk
  hstring OperationsQueue::DeskNumber()
  {
    return m_deskNumber;
  }
  void OperationsQueue::DeskNumber(hstring const& value)
  {
    m_deskNumber = value;
  }
  hstring OperationsQueue::DeskCode()
  {
    return m_deskCode;
  }
  void OperationsQueue::DeskCode(hstring const& value)
  {
    m_deskCode = value;
  }
  hstring OperationsQueue::DeskName()
  {
    return m_deskName;
  }
  void OperationsQueue::DeskName(hstring const& value)
  {
    m_deskName = value;
  }

  //Ticket
  hstring OperationsQueue::TicketNumber()
  {
    return m_ticketNumber;
  }
  void OperationsQueue::TicketNumber(hstring const& value)
  {
    m_ticketNumber = value;
  }
  hstring OperationsQueue::TicketBarcode()
  {
    return L"";
  }
  void OperationsQueue::TicketBarcode(hstring const& /*value*/)
  {

  }
  int32_t OperationsQueue::MaxQueueItems()
  {
    return m_maxQueueItems;
  }
  void OperationsQueue::MaxQueueItems(int32_t value)
  {
    m_maxQueueItems = value;
  }
  TicketMachine::Date OperationsQueue::CreationDate()
  {
    return m_CreationDate;
  }
  void OperationsQueue::CreationDate(TicketMachine::Date const& value)
  {
    m_CreationDate = value;
  }
  Windows::Storage::StorageFile OperationsQueue::TicketQRCode()
  {
    return nullptr;
  }
  void OperationsQueue::TicketQRCode(Windows::Storage::StorageFile const& /*value*/)
  {

  }

  //Common
  void OperationsQueue::Add()
  {
  }
  void OperationsQueue::Edit()
  {
  }
  void OperationsQueue::Delete()
  {
  }
  void OperationsQueue::Save()
  {
  }
}
