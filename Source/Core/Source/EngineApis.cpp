//
// Created by Bentoo on 2016-09-26.
//

#include "Engine.h"

namespace Core
{
	void Engine::initializeReferences(Engine* engine)
	{
	//	engine->Logger->Default->info("Initializing YAGE for '{}'...", engine->Name);

	#ifdef YAGE_VULKAN
			//		engine->RegisterApi<Gfx::VulkanDevice>();
	#endif

	#ifdef YAGE_OPENGL
			//		engine->RegisterApi<Gfx::OpenGlContext>();
	#endif
	}
}

