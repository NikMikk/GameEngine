#include "torkelpch.h"
#include "Application.h"

#include "Torkel/Events/ApplicationEvent.h"
#include "Torkel/Log.h"

namespace Torkel {

	Application::Application() 
	{

	}

	Application::~Application() 
	{

	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		if (e.IsInCategory(EventCategoryApplication))
		{
			TORKEL_INFO(e.ToString() + " is inside Application category!");
		}
		TORKEL_TRACE(e);

		while (true);
	}
}