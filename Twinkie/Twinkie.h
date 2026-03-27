#pragma once

#include "IModule.h"
#include "TwinkTrackmania.h"

#pragma warning(disable : 4251)

__declspec(dllimport) void AddModule(IModule* Module);
__declspec(dllimport) TwinkTrackmania* const GetTrackmaniaMgr();
__declspec(dllimport) TwinkLogs* const GetLogger();
__declspec(dllimport) bool* const GetUiRenderEnabled();
__declspec(dllimport) ImGuiContext* const GetImGuiContext();