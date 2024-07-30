#pragma once
#include "Core.h"

#include "Window.h"
#include "Events/ApplicationEvent.h"

#include "LayerStack.h"

namespace Hazel
{

	 class HAZEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* overlay);

	private:

		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_WindowApp;
		bool m_Running = true;
		LayerStack m_LayerStack;

	};

	 // To be defined in CLIENT
	 Application* CreateApplication();
}
