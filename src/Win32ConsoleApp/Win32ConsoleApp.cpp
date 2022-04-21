#include <iostream>
#include <hstring.h>
#include <windows.h>
#include <winstring.h>
#include <activation.h>

#include "winrt/TicketMachine.h"

typedef HRESULT(WINAPI *dllAbstractionFactoryFp)(HSTRING activableClassId, IActivationFactory **factory);

int main()
{
    // By default multi threaded apartment
    winrt::init_apartment();

    // ########################################### Statically loaded ticket machine
    // Possible because of the direct reference to the TicketMachine.winmd file in the client References
    winrt::TicketMachine::Ticket staTicket;
    staTicket.Create();
    printf("%ls\n", staTicket.DeskName().c_str());

    // ########################################### Dynamically loaded ticket machine
    // Aiming at making this possible using the standard C++ DLL plugin system patterns, scan local directory (not
    // important for this example), load found DLLs (LoadLibrary), get the process address from memory (GetProcAddress)
    // etc...

    // #### 0. Prep
    HRESULT hRes;

    // #### 1. Load DLL into memory
    HMODULE hLibrary;
    hLibrary = LoadLibrary(L"TicketMachine.dll");
    //hLibrary = ::LoadLibraryEx(L"TicketMachine.dll", NULL, NULL);
    if (!hLibrary) return EXIT_FAILURE;

    // #### 2. Get the pointer to the DllGetActivationFactory of the loaded DLL
    dllAbstractionFactoryFp abstractionFactoryFp;
    abstractionFactoryFp = (dllAbstractionFactoryFp)GetProcAddress(hLibrary, "DllGetActivationFactory");
    if (!abstractionFactoryFp) return EXIT_FAILURE;

    // #### 3. Define the class name to activate
    HSTRING activableClassName;
    WindowsCreateString(L"TicketMachine.Ticket", 20, &activableClassName);
    if (!activableClassName) return EXIT_FAILURE;

    // #### 4. Set the activation factory
    IActivationFactory* activationFactoryP;
    hRes = (abstractionFactoryFp)(activableClassName, &activationFactoryP);
    if (!activationFactoryP || hRes != S_OK) return EXIT_FAILURE;

    // #### 5. Get the runtime class name to check if everything is going fine
    HSTRING className;
    activationFactoryP->GetRuntimeClassName(&className);
    if (!className) return EXIT_FAILURE;

    // #### 6. The identification GUID
    IID iid = winrt::guid_of<winrt::TicketMachine::ITicketFactory>();
    winrt::TicketMachine::ITicketFactory* iTicketFactory;
    hRes = activationFactoryP->QueryInterface(iid, (void**) & iTicketFactory); // iTicketFactory stays uninitialized
    if (!iTicketFactory || hRes != S_OK) return EXIT_FAILURE;

    // ### ?. ...
    
    // ### Throws access violation exception
    //winrt::Windows::Foundation::IInspectable baseInterface, innerInterface;
    //winrt::TicketMachine::Ticket ticket = iTicketFactory->CreateInstance(baseInterface, innerInterface);

    // ### Instantaties fine but only because of the static type linking
    //winrt::TicketMachine::Ticket ticket = winrt::impl::call_factory<winrt::TicketMachine::Ticket, winrt::TicketMachine::ITicketFactory>([&](winrt::TicketMachine::ITicketFactory const& f) { return f.CreateInstance(baseInterface, innerInterface); });
    //ticket.Create();

    // #### ?. Profit???
    ;

    std::cin.ignore();
}
