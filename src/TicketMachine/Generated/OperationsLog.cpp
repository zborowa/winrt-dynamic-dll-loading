#include "pch.h"
#include "OperationsLog.h"
#include "OperationsLog.g.cpp"

namespace winrt::TicketMachine::implementation
{
  Windows::Foundation::IAsyncOperation<Windows::Foundation::Collections::
    IVector<TicketMachine::OperationsLog>> OperationsLog::GetCollection()
  {
    return nullptr;
  }

  hstring OperationsLog::ServiceCode()
  {
    return m_serviceCode;
  }
  void OperationsLog::ServiceCode(hstring const& value)
  {
    m_serviceCode = value;
  }
  hstring OperationsLog::ServiceName()
  {
    return m_serviceName;
  }
  void OperationsLog::ServiceName(hstring const& value)
  {
    m_serviceName = value;
  }
  hstring OperationsLog::TicketNumber()
  {
    return m_ticketNumber;
  }
  void OperationsLog::TicketNumber(hstring const& value)
  {
    m_ticketNumber = value;
  }
  hstring OperationsLog::TicketBarcode()
  {
    return L"";
  }
  void OperationsLog::TicketBarcode(hstring const& /*value*/)
  {

  }
  int32_t OperationsLog::MaxQueueItems()
  {
    return m_maxQueueItems;
  }
  void OperationsLog::MaxQueueItems(int32_t value)
  {
    m_maxQueueItems = value;
  }
  TicketMachine::Date OperationsLog::CreationDate()
  {
    return m_CreationDate;
  }
  void OperationsLog::CreationDate(TicketMachine::Date const& value)
  {
    m_CreationDate = value;
  }
  Windows::Storage::StorageFile OperationsLog::TicketQRCode()
  {
    return nullptr;
  }
  void OperationsLog::TicketQRCode(Windows::Storage::StorageFile const& /*value*/)
  {

  }
  void OperationsLog::Add()
  {
  }
  void OperationsLog::Edit()
  {
  }
  void OperationsLog::Delete()
  {
  }
  void OperationsLog::Save()
  {
  }
}
