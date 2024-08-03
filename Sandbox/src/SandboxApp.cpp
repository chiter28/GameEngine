#include <Hazel.h>


class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
	}

	void OnEvent(Hazel::Event& event) override
	{


		if (event.GetEventType() == Hazel::EventType::KeyPressed) {
			Hazel::KeyPressedEvent& e = static_cast<Hazel::KeyPressedEvent&>(event);

			if (e.GetKeyCode() == HZ_KEY_TAB) {
				HZ_TRACE("{0}", "TAB");
			} else 
				HZ_TRACE("{0}", static_cast<char>(e.GetKeyCode()));
		}

	}
};



class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushOverlay(new Hazel::ImGuiLayer());
	}

};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}
