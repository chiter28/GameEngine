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

		if (Hazel::Input::IsKeyPressed(HZ_KEY_TAB)) {
			HZ_INFO("Tab Key pressed");
		}

		if (event.GetEventType() == Hazel::EventType::KeyPressed) {
			Hazel::KeyPressedEvent& e = static_cast<Hazel::KeyPressedEvent&>(event);
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
