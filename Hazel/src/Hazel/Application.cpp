#include "hzpch.h"

#include "Application.h"
#include "Events/KeyEvent.h"
#include "Platform/Windows/WindowsInput.h"

#include "glad/glad.h"

#include "glm/glm.hpp"

#include "Platform/OpenGL/OpenGLBuffer.h"

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

		

		float vertices[3 * 4]
		{
			-0.5f,  0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
			 0.5f,  0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f
		};

		m_VertexBuffer = std::unique_ptr<VertexBuffer>(VertexBuffer::Create(vertices, sizeof(vertices)));


		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);

		
		uint32_t indices[6]	{ 0, 1, 2, 1, 2, 3 };
		m_IndexBuffer = std::unique_ptr<IndexBuffer>(IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));


		std::string vertexSrc = R"(
			
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			
			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = vec4(a_Position, 1.0);
			}		
		)";


		std::string fragmentSrc = R"(
			
			#version 330 core

			layout(location = 0) out vec4 color;
			
			in vec3 v_Position;

			void main()
			{
				color = vec4(v_Position + 0.5, 1.0);
			}		
		)";


		m_Shader.reset(new Shader(vertexSrc, fragmentSrc));
	}

	Application::~Application()
	{
	}

	// Run
	void Application::Run()
	{
		while (m_Running) {
			glClearColor(0.1, 0.1, 0.1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			
			m_Shader->Bind();
			glBindVertexArray(m_VertexArray);
			glDrawElements(GL_TRIANGLES, m_IndexBuffer->GetCount(), GL_UNSIGNED_INT, nullptr);

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