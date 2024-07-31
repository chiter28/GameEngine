#pragma once

#ifdef HZ_PLATFORM_WINDOWS

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_WARN("Initialized Log");



	Hazel::Application* app = Hazel::CreateApplication();
	app->Run();


	delete app;

}

#endif