#include "pch.h"
#include "MyModule.h"

void MyModule::RenderAnyways()
{
	ImGui::Begin(ICON_FK_BOOK " Hello from MyModule!");

	ImGui::Text("This example is from ");
	ImGui::SameLine();
	ImGui::TextLinkOpenURL("https://github.com/TwinkieTweaks/ExampleCustomModule");

	if (ImGui::Button("Cool"))
	{
		this->Logger->Print("Hello world!");
	}

	ImGui::End();
}

void MyModule::RenderMenuItem()
{
	ImGui::Separator();

	if (ImGui::MenuItem(ICON_FK_BOOK " Example module", "", this->Enabled))
	{
		this->Enabled = !this->Enabled;
	}
}

void MyModule::RenderSettings()
{
	static ImVec4 ExampleColor = ImVec4(1, 0, 1, 1);
	static bool ExampleCheckbox = true;

	ImGui::ColorEdit4("Color", &ExampleColor.x);
	ImGui::Checkbox("Checkbox", &ExampleCheckbox);
	
	ImGui::Separator();

	ImGui::Text("This example is from ");
	ImGui::SameLine();
	ImGui::TextLinkOpenURL("https://github.com/TwinkieTweaks/ExampleCustomModule");
}