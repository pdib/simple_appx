#include "application.h"

using namespace winrt;
using namespace Windows::ApplicationModel;
using namespace Windows::ApplicationModel::Activation;
using namespace Windows::ApplicationModel::Core;
using namespace Windows::UI::Core;

using namespace MyPackage;

// Application
IFrameworkView Application::CreateView()
{
    return *this;
}

void Application::Run()
{
    CoreDispatcher dispatcher { m_window.Dispatcher() };
    dispatcher.ProcessEvents(CoreProcessEventsOption::ProcessUntilQuit);
}

void Application::Initialize(winrt::Windows::ApplicationModel::Core::CoreApplicationView const& appView)
{
    appView.Activated({ this, &Application::OnActivated });
}

void Application::Uninitialize()
{

}

void Application::Load(winrt::hstring const& entryPoint)
{

}

void Application::SetWindow(winrt::Windows::UI::Core::CoreWindow const& window)
{
    m_window = window;
}

void Application::OnActivated(
    CoreApplicationView const& /* applicationView */,
    IActivatedEventArgs const& /* args */)
{
    m_window.Activate();
}

int __stdcall wWinMain(HINSTANCE, HINSTANCE, PWSTR, int)
{
    init_apartment();
    MyPackage::Application application;
    CoreApplication::Run(application);
}
