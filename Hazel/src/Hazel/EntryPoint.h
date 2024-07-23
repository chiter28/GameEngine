#pragma once

#ifdef HZ_PLATFORM_WINDOWS

//extern Hazel::Application* Hazel::CreateApplication();

int main(int argc, char** argv)
{
	Hazel::Log::Init();
	HZ_WARN("Initialized Log");

	int a = 4, b = 1;
	HZ_CORE_INFO("Hello Var={1}, {0}", a,  b);

	Hazel::Application* app = Hazel::CreateApplication();
	app->Run();


	delete app;



	
}

#endif