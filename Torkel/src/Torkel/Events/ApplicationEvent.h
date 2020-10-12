#pragma once

#include "Event.h"

namespace Torkel {

	class TORKEL_API WindowResizeEvent : public Event
	{
	public:
		WindowResizeEvent(unsigned int width, unsigned int heigth) : m_Width(width), m_Heigth(heigth) {}

		inline float GetWidth() const { return m_Width; }
		inline float GetHeight() const { return m_Heigth; }

		std::string ToString() const override
		{
			std::stringstream ss;
			ss << "WindowResizeEvent: " << GetWidth() << ", " << GetHeight();
			return ss.str();
		}

		EVENT_CLASS_TYPE(WindowResize)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	private:
		int m_Width, m_Heigth;
	};

	class TORKEL_API AppTickEvent : public Event
	{
	public:
		AppTickEvent() {}


		EVENT_CLASS_TYPE(AppTick)
			EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class TORKEL_API AppUpdateEvent : public Event
	{
	public:
		AppUpdateEvent() {}


		EVENT_CLASS_TYPE(AppUpdate)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};

	class TORKEL_API AppRenderEvent : public Event
	{
	public:
		AppRenderEvent() {}


		EVENT_CLASS_TYPE(AppRender)
		EVENT_CLASS_CATEGORY(EventCategoryApplication)
	};
}