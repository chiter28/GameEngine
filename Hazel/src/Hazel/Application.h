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

		inline Window& GetWindow() { return *m_WindowApp; }
		inline static Application& Get() { return *s_Instance; }

	private:
		bool OnWindowClose(WindowCloseEvent& e);

		std::unique_ptr<Window> m_WindowApp;
		bool m_Running = true;
		LayerStack m_LayerStack;
	
	private:
		static Application* s_Instance;
	};

	 // To be defined in CLIENT
	 Application* CreateApplication();
}
