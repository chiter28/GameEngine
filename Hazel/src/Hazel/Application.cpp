#include "hzpch.h"

#include "Application.h"
#include "Events/KeyEvent.h"

#include "glad/glad.h"

namespace Hazel
{

	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_WindowApp = std::unique_ptr<Window>(Window::Create());
		m_WindowApp->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));

		
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
		dispatcher.Dispatch<WindowCloseEvent>(HZ_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<KeyReleasedEvent>([this](KeyReleasedEvent& e) {
			if (e.GetCode() == 256 && m_LayerStack.begin() != m_LayerStack.end()) {
				auto a = m_LayerStack.begin();
				m_LayerStack.PopLayer(*a);
				return true;
			} else if (e.GetCode() == 256) {
				HZ_CORE_ASSERT(false, "Can't delete any layer - LayerStack empty!");
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