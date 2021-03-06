/*********************************************************************
Matt Marchant 2013 - 2016

Zlib License:

This software is provided 'as-is', without any express or
implied warranty. In no event will the authors be held
liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose,
including commercial applications, and to alter it and redistribute
it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented;
   you must not claim that you wrote the original software.
   If you use this software in a product, an acknowledgment
   in the product documentation would be appreciated but
   is not required.

2. Altered source versions must be plainly marked as such,
   and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any
   source distribution.
*********************************************************************/

#ifndef HELPERS_H_
#define HELPERS_H_


#include <SFML/Graphics/Rect.hpp>
#include <SFML/System/Vector2.hpp>

#include <cmath>
#include <cassert>

/*!
\brief Helper functions
*/
namespace Helpers
{
	namespace Vectors
	{
		/*!
        \brief Calculates dot product of 2 vectors
        */
		static inline float dot(sf::Vector2f lv, sf::Vector2f rv)
		{
			return lv.x * rv.x + lv.y * rv.y;
		}	

        /*!
        \brief Returns length squared of a given vector
        */
        static inline float getLengthSquared(const sf::Vector2f& source)
		{
			return dot(source, source);
		}

		/*!
        \brief Returns length of a given vector
        */
        static inline float getLength(const sf::Vector2f& source)
		{
			return std::sqrt(getLengthSquared(source));
		}

        static inline float cross(const sf::Vector2f& lv, const sf::Vector2f& rv)
		{
			return lv.x * rv.y - lv.y * rv.x;
		}
        static inline float cross(const sf::Vector2f& a, const sf::Vector2f& b, const sf::Vector2f& c)
		{
			sf::Vector2f BA = a - b;
			sf::Vector2f BC = c - b;
			return (BA.x * BC.y - BA.y * BC.x);
		}

		/*!
        \brief Returns a given vector with its length normalized to 1
        */
        static inline sf::Vector2f normalize(sf::Vector2f& source)
		{
            float length = getLength(source);
			if (length != 0) source /= length;

			return source;
		}

		/*!
        \brief Returns angle in degrees of a given vector where 0 is horizontal
        */
        static inline float getAngle(const sf::Vector2f& source)
		{
			return std::atan2(source.y , source.x) * 180.f / 3.14159265f;
		}
	};
	
	namespace Math
	{
        /*!
        \brief Returns value x clamped in the range a - b
        */
        static inline float clamp(float x, float a, float b)
		{
            assert(a < b);
            return x < a ? a : (x > b ? b : x);
		}

        /*!
        \brief Rounds the given value to the nearest whole number
        */
        static inline float round(float val)
		{
			return std::floor(val + 0.5f);
		}
	};
};

#endif //HELPERS_H_
