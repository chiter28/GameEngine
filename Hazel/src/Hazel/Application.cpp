#include "hzpch.h"

#include "Application.h"
#include "Events/KeyEvent.h"
#include "Platform/Windows/WindowsInput.h"

#include "glad/glad.h"

#include "glm/glm.hpp"


namespace Hazel
{
	
	Application* Application::s_Instance = nullptr;

	Application::Application()
	{
		HZ_CORE_ASSERT(!s_Instance, "Application already exists!");
		s_Instance = this;

		m_WindowApp = std::unique_ptr<Window>(Window::Create());
		m_WindowApp->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));

		m_ImGuiLayer = new ImGuiLayer();
		PushOverlay(m_ImGuiLayer);
		//////////////////////////////////
		glGenVertexArrays(1, &m_VertexArray);
		glBindVertexArray(m_VertexArray);

		glGenBuffers(1, &m_VertexBuffer);
		glBindBuffer(GL_ARRAY_BUFFER, m_VertexBuffer);

		float vertices[3 * 4]
		{
			-0.5f,  0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
		};

		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		glGenBuffers(1, &m_IndexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_IndexBuffer);
		
		unsigned int indeces[6]	{ 0, 1, 2, 1, 2, 3 };
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indeces), indeces, GL_STATIC_DRAW);
	
	}

	Application::~Application()
	{
	}

	// Run
	void Application::Run()
	{
		while (m_Running) {
			glClearColor(0.5, 0.5, 0.9, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);

			for (Layer* later : m_LayerStack) {
				later->OnUpdate(); // Not working yet
			}

			m_ImGuiLayer->Begin();

			for (Layer* layer : m_LayerStack) {
				layer->OnImGuiRender();
			}

			m_ImGuiLayer->End();

			
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
			return true;
			});
		
		//HZ_CORE_TRACE(e);
	
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