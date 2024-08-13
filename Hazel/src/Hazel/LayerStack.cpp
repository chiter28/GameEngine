#include "hzpch.h"
#include "LayerStack.h"

// Constructor
Hazel::LayerStack::LayerStack()
{
}

// Destructor
Hazel::LayerStack::~LayerStack()
{
	for (Layer* layer : m_Layers) {
		delete layer;
	}
}

// Push (Layer)
void Hazel::LayerStack::PushLayer(Layer* layer)
{
	m_Layers.emplace(begin() + m_LayerInsertIndex, layer);
	m_LayerInsertIndex++;
}

// Pop (Layer)
void Hazel::LayerStack::PopLayer(Layer* layer)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
	if (it != m_Layers.end()) {
		m_Layers.erase(it);
		m_LayerInsertIndex--;
	} 
}

// Push (Overlay)
void Hazel::LayerStack::PushOverlay(Layer* overlay)
{
	m_Layers.emplace_back(overlay);
}

// Pop (Overlay)
void Hazel::LayerStack::PopOverlay(Layer* overlay)
{
	auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
	if (it != m_Layers.end()) {
		m_Layers.erase(it);
	}
}