workspace "Torkel"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Torkel"
	location "Torkel"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "torkelpch.h"
	pchsource "Torkel/src/torkelpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TORKEL_PLATFORM_WINDOWS", 
			"TORKEL_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox)")
		}

	filter "configurations:Debug"
		defines "TORKEL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TORKEL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TORKEL_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Torkel/vendor/spdlog/include",
		"Torkel/src"
	}

	links 
	{
		"Torkel"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
			"TORKEL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "TORKEL_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "TORKEL_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "TORKEL_DIST"
		optimize "On"