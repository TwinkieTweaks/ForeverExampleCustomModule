#pragma once

#include "../Twinkie/Twinkie.h"

class MyModule : public IModule
{
public:
	MyModule() = delete;
	MyModule(MyModule&) = delete;
	MyModule(TwinkTrackmania& Twinkie, TwinkLogs& Logger, const bool* UiRenderEnabled)
	{
		this->UiRenderEnabled = UiRenderEnabled;
		this->Twinkie = &Twinkie;
		this->Logger = &Logger;

		this->Name = "MyModule";
		this->FancyName = "My module";
	}

	virtual ~MyModule() = default;

	virtual void RenderAnyways() override;
	virtual void RenderMenuItem() override;
	virtual void RenderSettings() override;
};