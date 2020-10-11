#include <Torkel.h>

class Sandbox : public Torkel::Application 
{
public:
	Sandbox() 
	{

	}

	~Sandbox() 
	{

	}
};

Torkel::Application* Torkel::CreateApplication() {
	return new Sandbox();
}