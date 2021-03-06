//
// Created by bentoo on 24.11.16.
//

#ifndef GAME_ENTITY_H_H
#define GAME_ENTITY_H_H

#include <bitset>
#include <Utils/DefaultTrait.h>

#include "World.h"

namespace Logic
{
	class World;

	class Scene;

	class Entity
	{
		friend class World;

		// TODO: expose component count to compile time setting
		World*			_world;
		Scene*			_scene;
		std::bitset<32>	componentBits;
		std::bitset<32>	cachedComponentBits;

		struct Status
		{
			bool dirty : 1;
			bool removed : 1;
		} _status;

		static_assert(sizeof(Status) <= sizeof(char),
					  "Status struct cannot take more than 1 byte!");

	public:
		using handle_t	= Utils::Handle<Entity>;
		using trait_t	= Utils::DefaultTrait<Entity>;

		handle_t Handle;

		explicit Entity(World* world, Scene* scene)
			: _world(world), _scene(scene), Handle()
		{ _status.dirty = false; }

		virtual ~Entity()
		{ }

		Entity(Entity&& other)
			: _status(other._status), _world(other._world), _scene(other._scene),
			  componentBits(std::move(other.componentBits)),
			  cachedComponentBits(std::move(other.cachedComponentBits)),
			  Handle()
		{
			other._world = nullptr;
			other._scene = nullptr;
			other.componentBits.reset();
		}

		Entity(const Entity&) = delete;
		Entity& operator=(Entity&&) = delete;
		Entity& operator=(const Entity&) = delete;

		inline Scene& getScene() const
		{
			YAGE_ASSERT(_scene != nullptr, "Entity '%zu' : Scene cannot be nullptr!", Handle.key);
			return *_scene;
		}

		inline World& getWorld() const
		{
			YAGE_ASSERT(_world != nullptr, "Entity '%zu' : World cannot be nullptr!", Handle.key);
			return *_world;
		}

		template <typename T>
		bool hasComponent() const
		{
			static_assert(std::is_base_of<IComponent, T>::value, "T must derive from IComponent!");
			return componentBits.test(IComponent::GetComponentId<T>());
		}

		template <typename T, typename ... Args>
		T& addComponent(Args&& ... args)
		{
			return getWorld().addComponent<T, Args...>(*this, std::forward<Args>(args)...);
		}

		template <typename T>
		void removeComponent()
		{
			return getWorld().removeComponent<T>(*this);
		}

		template <typename T>
		T& getComponent()
		{
			return getWorld().getComponent<T>(*this);
		}

		template <typename T>
		T* tryGetComponent()
		{
			return getWorld().tryGetComponent<T>(*this);
		}
	};
}

#endif //GAME_ENTITY_H_H
