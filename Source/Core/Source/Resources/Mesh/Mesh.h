//
// Created by MrJaqbq on 2016-02-10.
//

#ifndef VOLKHVY_MESH_H
#define VOLKHVY_MESH_H

#include <vector>
#include <string>
#include <map>

#include <glm/vec3.hpp>
#include <Utils/Index.h>
#include <Utils/List.h>
#include <Utils/String.h>
#include <Utils/BorrowedPtr.h>
#include <Utils/DefaultTrait.h>
#include <Utils/SafeDelete.h>

#include "../Resource.h"

namespace Core
{
	class MeshApi
	{
		// Handles to api objects
	};

	class MeshData
	{
		// Raw arrays of data
	};

	class MeshFile
	{
	public:
	//	inline explicit MeshFile(const Utils::String& path)
	//		: filePath(path) { }

	//	Utils::String filePath;
	};

	class Submesh
	{
		MeshApi* 	Api;
		MeshData* 	Data;
		// MaterialHandle

	public:
		Submesh() : Api(nullptr), Data(nullptr) { }
	};

	DECL_RESOURCE(Mesh)
	{
		MeshFile*	File;

		Memory::MemoryBlockBase& memory;

	public:
		inline explicit Mesh(Memory::MemoryBlockBase& memory);
		inline ~Mesh() { }

		Utils::List<Submesh> Submeshes;
	};

	// data may be interleaved or separated
	// how do I provide one api to maintain this?
	// thus, there can be one or more buffers
	// when only one, VAO will be present
	// anyway, indexing may be used
	/*class Submesh
	{
	//	Gfx::BufferScheme scheme;

	public:
//		void uploadApiData(Gfx::MeshApi *pApi);
//		auto getApiHandle() -> Gfx::MeshApi::ApiMeshHandle;
//		auto setApiHandle(Gfx::MeshApi::ApiMeshHandle handle) -> void;

		template <typename T>
		auto addProperty(std::string name, uint32_t count) noexcept -> void
		{
			// api will iterate through them, calc stride, offset
			// and pick internal type of data
	//		scheme.createComponent<T>(count, name);
		}
	};

	DECL_RESOURCE(MeshResource)
	{
	public:
		 MeshResource() : Resource() { }
		 //MeshResource(const MeshResource& other);
		~MeshResource() { }

		//auto operator=(const MeshResource& other) -> MeshResource&;

		// we do not care about memory over here. yet.
		// todo: this has to be done as handles as well, real submeshes in their container (renderer?)
		std::vector<Submesh> Submeshes;

		void swap(MeshResource& other) noexcept override { }
		void cleanUp() noexcept override { }

		Submesh& createSubmesh()
		{
			Submeshes.emplace_back();
			return Submeshes.back();
		}
	};

	class MeshTrait : public Utils::DefaultTrait<MeshResource> {};*/
}

#endif