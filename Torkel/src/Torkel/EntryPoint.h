#pragma once

#ifdef TORKEL_PLATFORM_WINDOWS

extern Torkel::Application* Torkel::CreateApplication();

int main(int argc, char** argv) 
{
	auto app = Torkel::CreateApplication();
	app->Run();
	delete app;
}

#endif
