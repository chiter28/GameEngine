
#include "hzpch.h"
#include "Application.h"

#include "Events/KeyEvent.h"
#include "Log.h"

namespace Hazel
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}


	void Application::Run()
	{
		KeyPressedEvent key(12, 0); 
		HZ_INFO(key);

		while (true);
	}

}