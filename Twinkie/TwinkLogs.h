#pragma once

#include <filesystem>
#include <string>
#include "../imgui-dx9/imgui.h"

class __declspec(dllimport) TwinkLogs
{
public:
	bool EnableLog = false;
	std::string LogStr = "";

    TwinkLogs();

    void PrintInternal(const char* Str);

    void PrintWarn(const char* Str);

    void PrintError(const char* Str);

    void Print(const char* Str);

    void PrintCustom(const char* Str);

    void RenderLog();
};