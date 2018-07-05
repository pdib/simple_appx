#include <winrt/Windows.ApplicationModel.Core.h>
#include <winrt/Windows.ApplicationModel.Activation.h>
#include <winrt/Windows.UI.Core.h>

namespace MyPackage {
    class Application : public winrt::implements<
        Application,
        winrt::Windows::ApplicationModel::Core::IFrameworkViewSource,
        winrt::Windows::ApplicationModel::Core::IFrameworkView>
        {
        public:
            void OnActivated(
                winrt::Windows::ApplicationModel::Core::CoreApplicationView const& /* applicationView */,
                winrt::Windows::ApplicationModel::Activation::IActivatedEventArgs const& /* args */);

            // IFrameworkView
            void Run();
            void Initialize(winrt::Windows::ApplicationModel::Core::CoreApplicationView const& appView);
            void Uninitialize();
            void Load(winrt::hstring const& entryPoint);
            void SetWindow(winrt::Windows::UI::Core::CoreWindow const& window);

            // IFrameworkViewSource
            winrt::Windows::ApplicationModel::Core::IFrameworkView CreateView();

        private:
            winrt::Windows::UI::Core::CoreWindow m_window {nullptr};
        };
}
