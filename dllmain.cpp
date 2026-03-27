// dllmain.cpp : Defines the entry point for the DLL application.
#include "pch.h"
#include "MyModule/MyModule.h"

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    {
        // This is required to wait for Twinkie to start
        // Only use this when you are targeting your DLL for ModLoader release
        Sleep(100);

        ImGui::SetCurrentContext(GetImGuiContext());
        MyModule* NewModule = new MyModule(*GetTrackmaniaMgr(), *GetLogger(), GetUiRenderEnabled());
        AddModule(NewModule);
        break;
    }
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

// Only use this when you are targeting your DLL for ModLoader release
extern "C" __declspec(dllexport) void ThisFunctionDoesNothing()
{
    return;
}