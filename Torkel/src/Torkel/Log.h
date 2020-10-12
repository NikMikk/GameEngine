#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Torkel 
{
	class TORKEL_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define TORKEL_CORE_TRACE(...)	::Torkel::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define TORKEL_CORE_INFO(...)	::Torkel::Log::GetCoreLogger()->info(__VA_ARGS__);
#define TORKEL_CORE_WARN(...)	::Torkel::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define TORKEL_CORE_ERROR(...)	::Torkel::Log::GetCoreLogger()->error(__VA_ARGS__);
#define TORKEL_CORE_CRITICAL(...)	::Torkel::Log::GetCoreLogger()->critical(__VA_ARGS__);

// Client log macros
#define TORKEL_TRACE(...)		::Torkel::Log::GetClientLogger()->trace(__VA_ARGS__);
#define TORKEL_INFO(...)		::Torkel::Log::GetClientLogger()->info(__VA_ARGS__);
#define TORKEL_WARN(...)		::Torkel::Log::GetClientLogger()->warn(__VA_ARGS__);
#define TORKEL_ERROR(...)		::Torkel::Log::GetClientLogger()->error(__VA_ARGS__);
#define TORKEL_CRITICAL(...)		::Torkel::Log::GetClientLogger()->critical(__VA_ARGS__);