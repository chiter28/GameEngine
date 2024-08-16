#pragma once

namespace Hazel
{

	enum class RendererAPI
	{
		None = 0, OpenGL
	};



	/////////////////////////////////
	// Renderer ////////////////////
	///////////////////////////////
	
	class Renderer
	{
	public:
		static void SetAPI(RendererAPI api);
		inline static RendererAPI GetAPI() { return s_RendererAPI; }

	private:
		static RendererAPI s_RendererAPI;
	};



}