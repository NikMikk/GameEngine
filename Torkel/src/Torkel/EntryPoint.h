#pragma once

#ifdef TORKEL_PLATFORM_WINDOWS

extern Torkel::Application* Torkel::CreateApplication();

int main(int argc, char** argv) 
{
	Torkel::Log::Init();

	TORKEL_CORE_WARN("Initialized Log!");

	auto app = Torkel::CreateApplication();
	app->Run();
	delete app;
}

#endif
