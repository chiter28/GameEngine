#include "hzpch.h"
#include "Renderer.h"

namespace Hazel
{
	RendererAPI Renderer::s_RendererAPI = RendererAPI::None;


	void Renderer::SetAPI(RendererAPI api) { Renderer::s_RendererAPI = api;	}

}