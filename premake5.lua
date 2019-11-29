-- premake5.lua
workspace "HelloOpenGl"
	configurations { "Debug", "Release" }

project "Application"
	location "Application"		
	kind "ConsoleApp"
	language "C++"
	architecture "x86_64"
	systemversion "latest"
   
	targetdir "bin/%{cfg.buildcfg}-%{cfg.architecture}"

	files { "Application/src/**.h", "Application/src/**.cpp" }
	
	includedirs {"ThirdParty/GLEW/include", "ThirdParty/GLFW/include", "ThirdParty/GLM"}
	libdirs { "ThirdParty/GLEW/lib"}
	
	if _ACTION == "vs2019" then
		libdirs { "ThirdParty/GLFW/lib-vc2019"}
	elseif _ACTION == "vs2017" then
		libdirs { "ThirdParty/GLFW/lib-vc2017"}
	end
	
	filter "system:windows"
		links { "glfw3", "glew32s", "opengl32"}
		defines {"WINDOWS", "GLEW_STATIC"}

	filter "system:linux"
		links { "GL", "glfw", "GLEW", "glut" }
		defines {"LINUX"}

	filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"
