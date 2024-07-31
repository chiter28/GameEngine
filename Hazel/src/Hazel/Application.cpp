#include "hzpch.h"

#include "Application.h"
#include "Events/KeyEvent.h"

#include "glad/glad.h"

namespace Hazel
{
#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_WindowApp = std::unique_ptr<Window>(Window::Create());
		m_WindowApp->SetEventCallback(BIND_EVENT_FN(OnEvent));

		
	}

	Application::~Application()
	{
	}

	// Run
	void Application::Run()
	{
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			for (Layer* later : m_LayerStack) {
				later->OnUpdate(); // Not working yet
			}
			
			m_WindowApp->OnUpdate();
		
			
		}
	}

	// OnEvent
	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));
		dispatcher.Dispatch<KeyReleasedEvent>([this](KeyReleasedEvent& e) {
			if (e.GetCode() == 68) {
				m_LayerStack.PopLayer(*m_LayerStack.begin());
				return true;
			}
			});
		
		HZ_CORE_TRACE(e);
	
		for (auto it = m_LayerStack.end(); it != m_LayerStack.begin();) {
			(*--it)->OnEvent(e);
			if (e.Handled)
				break;
		}
	}



	// Push (Layer)
	void Application::PushLayer(Layer* layer)
	{
		m_LayerStack.PushLayer(layer);
		layer->OnAttach();

	}

	// Push (Overlay)
	void Application::PushOverlay(Layer* overlay)
	{
		m_LayerStack.PushOverlay(overlay);
		overlay->OnAttach();

	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}


}