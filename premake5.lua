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

   files { "**.h", "**.cpp" }

filter "system:windows"
		defines {"WINDOWS"}

filter "configurations:Debug"
		defines { "DEBUG" }
		symbols "On"

filter "configurations:Release"
		defines { "NDEBUG" }
		optimize "On"