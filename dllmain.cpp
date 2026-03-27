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

