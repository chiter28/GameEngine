#include <Hazel.h>

class ExampleLayer : public Hazel::Layer
{
public:
	ExampleLayer()
		: Layer("Example") {}

	void OnUpdate() override
	{
		HZ_INFO("ExampleLayer::Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("Example: {0}", event);
	}
};

class AO : public Hazel::Layer
{
public:
	AO()
		: Layer("AO")
	{}

	void OnUpdate() override
	{
		HZ_INFO("AO::Update");
	}

	void OnEvent(Hazel::Event& event) override
	{
		HZ_TRACE("AO: {0}", event);
	}
};

class Sandbox : public Hazel::Application
{
public:
	Sandbox()
	{
		PushLayer(new ExampleLayer());
		PushLayer(new AO());
		PushOverlay(new AO());
	}

};

Hazel::Application* Hazel::CreateApplication()
{
	return new Sandbox();
}
