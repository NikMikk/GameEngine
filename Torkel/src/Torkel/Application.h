#pragma once

#include "Core.h"

namespace Torkel {

	class TORKEL_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
