[1mdiff --git a/Hazel.sln b/Hazel.sln[m
[1mindex 437ace8..bbb58c2 100644[m
[1m--- a/Hazel.sln[m
[1m+++ b/Hazel.sln[m
[36m@@ -1,6 +1,8 @@[m
 ﻿[m
 Microsoft Visual Studio Solution File, Format Version 12.00[m
 # Visual Studio Version 17[m
[32m+[m[32mProject("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "Sandbox", "Sandbox\Sandbox.vcxproj", "{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}"[m
[32m+[m[32mEndProject[m
 Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "GLFW", "Hazel\vendor\GLFW\GLFW.vcxproj", "{154B857C-0182-860D-AA6E-6C109684020F}"[m
 EndProject[m
 Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "Glad", "Hazel\vendor\Glad\Glad.vcxproj", "{BDD6857C-A90D-870D-52FA-6C103E10030F}"[m
[36m@@ -9,8 +11,6 @@[m [mProject("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "Hazel", "Hazel\Hazel.vcxpro[m
 EndProject[m
 Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "ImGui", "Hazel\vendor\imgui\ImGui.vcxproj", "{C0FF640D-2C14-8DBE-F595-301E616989EF}"[m
 EndProject[m
[31m-Project("{8BC9CEB8-8B4A-11D0-8D11-00A0C91BC942}") = "Sandbox", "Sandbox\Sandbox.vcxproj", "{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}"[m
[31m-EndProject[m
 Global[m
 	GlobalSection(SolutionConfigurationPlatforms) = preSolution[m
 		Debug|x64 = Debug|x64[m
[36m@@ -18,6 +18,12 @@[m [mGlobal[m
 		Release|x64 = Release|x64[m
 	EndGlobalSection[m
 	GlobalSection(ProjectConfigurationPlatforms) = postSolution[m
[32m+[m		[32m{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Debug|x64.ActiveCfg = Debug|x64[m
[32m+[m		[32m{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Debug|x64.Build.0 = Debug|x64[m
[32m+[m		[32m{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Dist|x64.ActiveCfg = Dist|x64[m
[32m+[m		[32m{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Dist|x64.Build.0 = Dist|x64[m
[32m+[m		[32m{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Release|x64.ActiveCfg = Release|x64[m
[32m+[m		[32m{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Release|x64.Build.0 = Release|x64[m
 		{154B857C-0182-860D-AA6E-6C109684020F}.Debug|x64.ActiveCfg = Debug|x64[m
 		{154B857C-0182-860D-AA6E-6C109684020F}.Debug|x64.Build.0 = Debug|x64[m
 		{154B857C-0182-860D-AA6E-6C109684020F}.Dist|x64.ActiveCfg = Dist|x64[m
[36m@@ -42,12 +48,6 @@[m [mGlobal[m
 		{C0FF640D-2C14-8DBE-F595-301E616989EF}.Dist|x64.Build.0 = Dist|x64[m
 		{C0FF640D-2C14-8DBE-F595-301E616989EF}.Release|x64.ActiveCfg = Release|x64[m
 		{C0FF640D-2C14-8DBE-F595-301E616989EF}.Release|x64.Build.0 = Release|x64[m
[31m-		{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Debug|x64.ActiveCfg = Debug|x64[m
[31m-		{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Debug|x64.Build.0 = Debug|x64[m
[31m-		{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Dist|x64.ActiveCfg = Dist|x64[m
[31m-		{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Dist|x64.Build.0 = Dist|x64[m
[31m-		{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Release|x64.ActiveCfg = Release|x64[m
[31m-		{F4C124E3-60A1-A37E-69B9-2E55D5170AE0}.Release|x64.Build.0 = Release|x64[m
 	EndGlobalSection[m
 	GlobalSection(SolutionProperties) = preSolution[m
 		HideSolutionNode = FALSE[m
[1mdiff --git a/Hazel/Hazel.vcxproj b/Hazel/Hazel.vcxproj[m
[1mindex 1e0aff6..fa6fb97 100644[m
[1m--- a/Hazel/Hazel.vcxproj[m
[1m+++ b/Hazel/Hazel.vcxproj[m
[36m@@ -79,12 +79,11 @@[m
       <PrecompiledHeader>Use</PrecompiledHeader>[m
       <PrecompiledHeaderFile>hzpch.h</PrecompiledHeaderFile>[m
       <WarningLevel>Level3</WarningLevel>[m
[31m-      <PreprocessorDefinitions>HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL;HZ_ANABLE_ASSERTS;GLFW_INCLUDE_NONE;HZ_DEBUG;%(PreprocessorDefinitions)</PreprocessorDefinitions>[m
[32m+[m[32m      <PreprocessorDefinitions>HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL;GLFW_INCLUDE_NONE;HZ_DEBUG;%(PreprocessorDefinitions)</PreprocessorDefinitions>[m
       <AdditionalIncludeDirectories>src;vendor\spdlog\include;vendor\GLFW\include;vendor\Glad\include;vendor\imgui;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>[m
       <DebugInformationFormat>EditAndContinue</DebugInformationFormat>[m
       <Optimization>Disabled</Optimization>[m
[31m-      <RuntimeLibrary>MultiThreadedDebug</RuntimeLibrary>[m
[31m-      <AdditionalOptions>/MDd %(AdditionalOptions)</AdditionalOptions>[m
[32m+[m[32m      <RuntimeLibrary>MultiThreadedDebugDLL</RuntimeLibrary>[m
       <LanguageStandard>stdcpp17</LanguageStandard>[m
       <ExternalWarningLevel>Level3</ExternalWarningLevel>[m
     </ClCompile>[m
[36m@@ -103,15 +102,14 @@[m
       <PrecompiledHeader>Use</PrecompiledHeader>[m
       <PrecompiledHeaderFile>hzpch.h</PrecompiledHeaderFile>[m
       <WarningLevel>Level3</WarningLevel>[m
[31m-      <PreprocessorDefinitions>HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL;HZ_ANABLE_ASSERTS;GLFW_INCLUDE_NONE;HZ_RELEASE;%(PreprocessorDefinitions)</PreprocessorDefinitions>[m
[32m+[m[32m      <PreprocessorDefinitions>HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL;GLFW_INCLUDE_NONE;HZ_RELEASE;%(PreprocessorDefinitions)</PreprocessorDefinitions>[m
       <AdditionalIncludeDirectories>src;vendor\spdlog\include;vendor\GLFW\include;vendor\Glad\include;vendor\imgui;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>[m
       <Optimization>Full</Optimization>[m
       <FunctionLevelLinking>true</FunctionLevelLinking>[m
       <IntrinsicFunctions>true</IntrinsicFunctions>[m
       <MinimalRebuild>false</MinimalRebuild>[m
       <StringPooling>true</StringPooling>[m
[31m-      <RuntimeLibrary>MultiThreaded</RuntimeLibrary>[m
[31m-      <AdditionalOptions>/MD %(AdditionalOptions)</AdditionalOptions>[m
[32m+[m[32m      <RuntimeLibrary>MultiThreadedDLL</RuntimeLibrary>[m
       <LanguageStandard>stdcpp17</LanguageStandard>[m
       <ExternalWarningLevel>Level3</ExternalWarningLevel>[m
     </ClCompile>[m
[36m@@ -131,15 +129,14 @@[m
       <PrecompiledHeader>Use</PrecompiledHeader>[m
       <PrecompiledHeaderFile>hzpch.h</PrecompiledHeaderFile>[m
       <WarningLevel>Level3</WarningLevel>[m
[31m-      <PreprocessorDefinitions>HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL;HZ_ANABLE_ASSERTS;GLFW_INCLUDE_NONE;HZ_DIST;%(PreprocessorDefinitions)</PreprocessorDefinitions>[m
[32m+[m[32m      <PreprocessorDefinitions>HZ_PLATFORM_WINDOWS;HZ_BUILD_DLL;GLFW_INCLUDE_NONE;HZ_DIST;%(PreprocessorDefinitions)</PreprocessorDefinitions>[m
       <AdditionalIncludeDirectories>src;vendor\spdlog\include;vendor\GLFW\include;vendor\Glad\include;vendor\imgui;%(AdditionalIncludeDirectories)</AdditionalIncludeDirectories>[m
       <Optimization>Full</Optimization>[m
       <FunctionLevelLinking>true</FunctionLevelLinking>[m
       <IntrinsicFunctions>true</IntrinsicFunctions>[m
       <MinimalRebuild>false</MinimalRebuild>[m
       <StringPooling>true</StringPooling>[m
[31m-      <RuntimeLibrary>MultiThreaded</RuntimeLibrary>[m
[31m-      <AdditionalOptions>/MD %(AdditionalOptions)</AdditionalOptions>[m
[32m+[m[32m      <RuntimeLibrary>MultiThreadedDLL</RuntimeLibrary>[m
       <LanguageStandard>stdcpp17</LanguageStandard>[m
       <ExternalWarningLevel>Level3</ExternalWarningLevel>[m
     </ClCompile>[m
[1mdiff --git a/Hazel/src/Hazel/Application.cpp b/Hazel/src/Hazel/Application.cpp[m
[1mindex 2a6780c..f9f4d5b 100644[m
[1m--- a/Hazel/src/Hazel/Application.cpp[m
[1m+++ b/Hazel/src/Hazel/Application.cpp[m
[36m@@ -7,7 +7,6 @@[m
 [m
 namespace Hazel[m
 {[m
[31m-#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)[m
 [m
 	Application* Application::s_Instance = nullptr;[m
 [m
[36m@@ -17,7 +16,7 @@[m [mnamespace Hazel[m
 		s_Instance = this;[m
 [m
 		m_WindowApp = std::unique_ptr<Window>(Window::Create());[m
[31m-		m_WindowApp->SetEventCallback(BIND_EVENT_FN(OnEvent));[m
[32m+[m		[32mm_WindowApp->SetEventCallback(HZ_BIND_EVENT_FN(Application::OnEvent));[m
 [m
 		[m
 	}[m
[36m@@ -37,7 +36,7 @@[m [mnamespace Hazel[m
 			}[m
 			[m
 			m_WindowApp->OnUpdate();[m
[31m-		[m
[32m+[m[41m		 [m
 			[m
 		}[m
 	}[m
[36m@@ -46,11 +45,14 @@[m [mnamespace Hazel[m
 	void Application::OnEvent(Event& e)[m
 	{[m
 		EventDispatcher dispatcher(e);[m
[31m-		dispatcher.Dispatch<WindowCloseEvent>(BIND_EVENT_FN(OnWindowClose));[m
[32m+[m		[32mdispatcher.Dispatch<WindowCloseEvent>(HZ_BIND_EVENT_FN(Application::OnWindowClose));[m
 		dispatcher.Dispatch<KeyReleasedEvent>([this](KeyReleasedEvent& e) {[m
[31m-			if (e.GetCode() == 68) {[m
[31m-				m_LayerStack.PopLayer(*m_LayerStack.begin());[m
[32m+[m			[32mif (e.GetCode() == 256 && m_LayerStack.begin() != m_LayerStack.end()) {[m
[32m+[m				[32mauto a = m_LayerStack.begin();[m
[32m+[m				[32mm_LayerStack.PopLayer(*a);[m
 				return true;[m
[32m+[m			[32m} else if (e.GetCode() == 256) {[m
[32m+[m				[32mHZ_CORE_ASSERT(false, "Can't delete any layer - LayerStack empty!");[m
 			}[m
 			});[m
 		[m
[1mdiff --git a/Hazel/src/Hazel/Core.h b/Hazel/src/Hazel/Core.h[m
[1mindex eb91f53..9d48617 100644[m
[1m--- a/Hazel/src/Hazel/Core.h[m
[1m+++ b/Hazel/src/Hazel/Core.h[m
[36m@@ -10,6 +10,9 @@[m
 	#error Hazel support only Windows[m
 #endif // HZ_PLATFORM_WINDOWS[m
 [m
[32m+[m[32m#ifdef HZ_DEBUG[m
[32m+[m	[32m#define HZ_ANABLE_ASSERTS[m
[32m+[m[32m#endif[m
 [m
 // ASSERT[m
 #ifdef HZ_ANABLE_ASSERTS[m
[36m@@ -17,10 +20,11 @@[m
 	#define HZ_CORE_ASSERT(x, ...) if(!(x)) { HZ_CORE_ERROR("ASSERT: {0}", __VA_ARGS__); __debugbreak(); }[m
 #else[m
 	#define HZ_ASSERT(x, ...)[m
[31m-	#define HZ_CORE_ASSERT(x, ...)[m
[32m+[m	[32m#define HZ_CORE_ASSERT(x, ..[m
 #endif // HZ_ANABLE_ASSERTS[m
 [m
 [m
[31m-[m
 // BIT for EventCategory[m
[31m-#define BIT(x) 1 << x[m
\ No newline at end of file[m
[32m+[m[32m#define BIT(x) 1 << x[m
[32m+[m
[32m+[m[32m#define HZ_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)[m
\ No newline at end of file[m
[1mdiff --git a/Hazel/src/Hazel/Events/Event.h b/Hazel/src/Hazel/Events/Event.h[m
[1mindex 6581975..003ce2e 100644[m
[1m--- a/Hazel/src/Hazel/Events/Event.h[m
[1m+++ b/Hazel/src/Hazel/Events/Event.h[m
[36m@@ -9,7 +9,7 @@[m [mnamespace Hazel[m
 		None = 0,[m
 		WindowClose, WindowResize, WindowFocus, WindowLostFocus, WindowMoved,[m
 		AppTick, AppUpdate, AppRender,[m
[31m-		KeyPressed, KeyReleased,[m
[32m+[m		[32mKeyPressed, KeyReleased, KeyTyped,[m
 		MouseButtonPressed, MouseButtonReleased, MouseMoved, MouseScrolled[m
 	};[m
 [m
[1mdiff --git a/Hazel/src/Hazel/Events/KeyEvent.h b/Hazel/src/Hazel/Events/KeyEvent.h[m
[1mindex 56fca25..8ef6740 100644[m
[1m--- a/Hazel/src/Hazel/Events/KeyEvent.h[m
[1m+++ b/Hazel/src/Hazel/Events/KeyEvent.h[m
[36m@@ -57,4 +57,25 @@[m [mnamespace Hazel[m
 		EVENT_CLASS_TYPE(KeyReleased)[m
 	};[m
 [m
[32m+[m
[32m+[m	[32mclass HAZEL_API KeyTypedEvent : public KeyEvent[m
[32m+[m	[32m{[m
[32m+[m	[32mpublic:[m
[32m+[m		[32mKeyTypedEvent(int keycode)[m
[32m+[m			[32m: KeyEvent(keycode) {}[m
[32m+[m
[32m+[m		[32mstd::string ToString() const override[m
[32m+[m		[32m{[m
[32m+[m			[32mstd::stringstream ss;[m
[32m+[m			[32mss << "KeyTypedEvent: " << m_KeyCode;[m
[32m+[m			[32mreturn ss.str();[m
[32m+[m		[32m}[m
[32m+[m
[32m+[m		[32mconst int& GetCode() { return m_KeyCode; }[m
[32m+[m
[32m+[m		[32mEVENT_CLASS_TYPE(KeyTyped);[m
[32m+[m	[32m};[m
[32m+[m
 }[m
[41m+[m
[41m+[m
[1mdiff --git a/Hazel/src/Hazel/ImGui/ImGuiLayer.cpp b/Hazel/src/Hazel/ImGui/ImGuiLayer.cpp[m
[1mindex 2b7d8a7..45b32bf 100644[m
[1m--- a/Hazel/src/Hazel/ImGui/ImGuiLayer.cpp[m
[1m+++ b/Hazel/src/Hazel/ImGui/ImGuiLayer.cpp[m
[36m@@ -3,6 +3,7 @@[m
 [m
 #include "Platform/OpenGL/ImGuiOpenGLRenderer.h"[m
 #include "GLFW/glfw3.h"[m
[32m+[m[32m#include "glad/glad.h"[m
 [m
 #include "Hazel/Application.h"[m
 [m
[36m@@ -61,7 +62,99 @@[m [mnamespace Hazel[m
 [m
 	void ImGuiLayer::OnEvent(Hazel::Event& event)[m
 	{[m
[31m-		HZ_TRACE("ImGui: {0}", event);[m
[32m+[m		[32mEventDispatcher dispatcher(event);[m
[32m+[m		[32mdispatcher.Dispatch<MouseButtonPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonPressedEvent));[m
[32m+[m		[32mdispatcher.Dispatch<MouseButtonReleasedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseButtonReleasedEvent));[m
[32m+[m		[32mdispatcher.Dispatch<MouseMovedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseMovedEvent));[m
[32m+[m		[32mdispatcher.Dispatch<MouseScrolledEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnMouseScrolledEvent));[m
[32m+[m		[32mdispatcher.Dispatch<KeyPressedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyPressedEvent));[m
[32m+[m		[32mdispatcher.Dispatch<KeyReleasedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyReleasedEvent));[m
[32m+[m		[32mdispatcher.Dispatch<WindowResizeEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnWindowResizeEvent));[m
[32m+[m		[32mdispatcher.Dispatch<KeyTypedEvent>(HZ_BIND_EVENT_FN(ImGuiLayer::OnKeyTypedEvent));[m
[32m+[m
[32m+[m	[32m}[m
[32m+[m
[32m+[m
[32m+[m
[32m+[m	[32mbool ImGuiLayer::OnMouseButtonPressedEvent(MouseButtonPressedEvent& e)[m
[32m+[m	[32m{[m
[32m+[m		[32mImGuiIO& io = ImGui::GetIO();[m
[32m+[m		[32m//io.MouseDown[e.GetMouseButton()] = true;[m
[32m+[m		[32mio.AddMouseButtonEvent(e.GetMouseButton(), true);[m
[32m+[m
[32m+[m		[32mreturn false;[m
[32m+[m	[32m}[m
[32m+[m
[32m+[m	[32mbool ImGuiLayer::OnMouseButtonReleasedEvent(MouseButtonReleasedEvent& e)[m
[32m+[m	[32m{[m
[32m+[m		[32mImGuiIO& io = ImGui::GetIO();[m
[32m+[m		[32m//io.MouseDown[e.GetMouseButton()] = false;[m
[32m+[m		[32mio.AddMouseButtonEvent(e.GetMouseButton(), false);[m
[32m+[m
[32m+[m		[32mreturn false;[m
[32m+[m	[32m}[m
[32m+[m
[32m+[m	[32mbool ImGuiLayer::OnMouseMovedEvent(MouseMovedEvent& e)[m
[32m+[m	[32m{[m
[32m+[m		[32mImGuiIO& io = ImGui::GetIO();[m
[32m+[m		[32m//io.MousePos = ImVec2(e.GetX(), e.GetY());[m
[32m+[m		[32mio.AddMousePosEvent(e.GetX(), e.GetY());[m
[32m+[m		[32mreturn false;[m
[32m+[m	[32m}[m
[32m+[m
[32m+[m	[32mbool ImGuiLayer::OnMouseScrolledEvent(MouseScrolledEvent& e)[m
[32m+[m	[32m{[m
[32m+[m		[32mImGuiIO& io = ImGui::GetIO();[m
[32m+[m		[32m//io.MouseWheelH += e.GetXOffset();[m
[32m+[m		[32m//io.MouseWheel += e.GetYOffset();[m
[32m+[m		[32mio.AddMouseWheelEvent(e.GetXOffset(), e.GetYOffset());[m
[32m+[m
[32m+[m
[32m+[m		[32mreturn false;[m
[32m+[m	[32m}[m
[32m+[m
[32m+[m	[32mbool ImGuiLayer::OnKeyPressedEvent(KeyPressedEvent& e)[m
[32m+[m	[32m{[m
[32m+[m		[32mImGuiIO& io = ImGui::GetIO();[m
[32m+[m		[32mio.KeysDown[e.GetKeyCode()] = true;[m
[32m+[m		[32m//io.AddKeyEvent((ImGuiKey)e.GetKeyCode(), true);[m
[32m+[m
[32m+[m		[32mio.KeyCtrl = io.KeysDown[GLFW_KEY_LEFT_CONTROL] || io.KeysDown[GLFW_KEY_RIGHT_CONTROL];[m
[32m+[m		[32mio.KeyShift = io.KeysDown[GLFW_KEY_LEFT_SHIFT] || io.KeysDown[GLFW_KEY_RIGHT_SHIFT];[m
[32m+[m		[32mio.KeyAlt = io.KeysDown[GLFW_KEY_LEFT_ALT] || io.KeysDown[GLFW_KEY_RIGHT_ALT];[m
[32m+[m		[32mio.KeySuper = io.KeysDown[GLFW_KEY_LEFT_SUPER] || io.KeysDown[GLFW_KEY_RIGHT_SUPER];[m
[32m+[m		[32mreturn false;[m
[32m+[m	[32m}[m
[32m+[m
[32m+[m	[32mbool ImGuiLayer::OnKeyReleasedEvent(KeyReleasedEvent& e)[m
[32m+[m	[32m{[m
[32m+[m		[32mImGuiIO& io = ImGui::GetIO();[m
[32m+[m		[32mio.KeysDown[e.GetKeyCode()] = false;[m
[32m+[m		[32m//io.AddKeyEvent((ImGuiKey)e.GetKeyCode(), false);[m
[32m+[m
[32m+[m		[32mreturn true;[m
 	}[m
 [m
[32m+[m	[32mbool ImGuiLayer::OnWindowResizeEvent(WindowResizeEvent& e)[m
[32m+[m	[32m{[m
[32m+[m		[32mImGuiIO& io = ImGui::GetIO();[m
[32m+[m		[32mio.DisplaySize = ImVec2(e.GetWidth(), e.GetHeight());[m
[32m+[m		[32mio.DisplayFramebufferScale = ImVec2(1.0f, 1.0f);[m
[32m+[m		[32mglViewport(0, 0, e.GetWidth(), e.GetHeight());[m
[32m+[m
[32m+[m		[32mreturn false;[m
[32m+[m	[32m}[m
[32m+[m[41m	[m
[32m+[m[41m	[m
[32m+[m[41m	[m
[32m+[m	[32mbool ImGuiLayer::OnKeyTypedEvent(KeyTypedEvent & e)[m
[32m+[m	[32m{[m
[32m+[m		[32mImGuiIO& io = ImGui::GetIO();[m
[32m+[m		[32mio.AddInputCharacter(e.GetCode());[m
[32m+[m[41m		[m
[32m+[m		[32mreturn false;[m
[32m+[m	[32m}[m
[32m+[m
[32m+[m
[32m+[m
 }[m
[1mdiff --git a/Hazel/src/Hazel/ImGui/ImGuiLayer.h b/Hazel/src/Hazel/ImGui/ImGuiLayer.h[m
[1mindex cb80f49..a87774a 100644[m
[