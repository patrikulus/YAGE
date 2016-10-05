//
// Created by mrjaqbq on 07.03.16.
//

#ifndef VOLKHVY_RECTANGLE_H
#define VOLKHVY_RECTANGLE_H

#include "glm/vec2.hpp"

namespace Gfx
{
	template <typename N>
	class Rectangle
	{
		glm::tvec2<N, glm::precision::defaultp> _min;
		glm::tvec2<N, glm::precision::defaultp> _max;

	public:
		auto getWidth() -> N { return _max.x - _min.x; }
		auto getHeight() -> N { return _max.y - _min.y; }

		auto getTop() -> N { return _max.y; }
		auto getBottom() -> N { return _min.y; }
		auto getLeft() -> N { return _min.x; }
		auto getRight() -> N { return _max.x; }

		auto getMin() -> glm::tvec2<N, glm::precision::defaultp> { return _min; }
		auto getMax() -> glm::tvec2<N, glm::precision::defaultp>{ return _max; }

		auto getCenter() -> glm::tvec2<N, glm::precision::defaultp>
		{
			return glm::tvec2<N, glm::precision::defaultp> (
				_min.x + getWidth() * 0.5, _min.y + getHeight() * 0.5
			);
		}
	};
}

#endif //VOLKHVY_RECTANGLE_H