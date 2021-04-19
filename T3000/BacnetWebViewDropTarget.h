#pragma once
#include <wil/wrl.h>
#include <wil/com.h>
#include <WebView2.h>
#include <ShObjIdl_core.h>

class IDropTargetHelper;
class ViewComponent;

class DropTarget : public Microsoft::WRL::RuntimeClass<
    Microsoft::WRL::RuntimeClassFlags<Microsoft::WRL::ClassicCom>,
    IDropTarget>
{

public:
    DropTarget();
    virtual ~DropTarget();

    // Initialize the drop target by associating it with the given HWND.
    void Init(
        HWND window, ViewComponent* viewComponent,
        ICoreWebView2CompositionController* webViewExperimentalCompositionController3);

    // IDropTarget implementation:
    HRESULT __stdcall DragEnter(IDataObject* dataObject,
        DWORD keyState,
        POINTL cursorPosition,
        DWORD* effect) override;
    HRESULT __stdcall DragOver(DWORD keyState,
        POINTL cursor_position,
        DWORD* effect) override;
    HRESULT __stdcall DragLeave() override;
    HRESULT __stdcall Drop(IDataObject* dataObject,
        DWORD keyState,
        POINTL cursorPosition,
        DWORD* effect) override;

private:
    ViewComponent* m_viewComponent = nullptr;

    // Returns the hosting HWND.
    HWND GetHWND() { return m_window; }

    wil::com_ptr<IDropTargetHelper> DropHelper();
    wil::com_ptr<IDropTargetHelper> m_dropTargetHelper;

    // The HWND of the source. This HWND is used to determine coordinates for
    // mouse events that are sent to the renderer notifying various drag states.
    HWND m_window;

    wil::com_ptr<ICoreWebView2CompositionController> m_webViewCompositionController;
};
