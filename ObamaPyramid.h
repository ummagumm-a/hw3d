#pragma once
#include "IndexedTriangleList.h"
#include <DirectXMath.h>
#include <initializer_list>

class ObamaPyramid
{
public:
	template<class V>
	static IndexedTriangleList<V> Make()
	{
		namespace dx = DirectX;

		constexpr float side = 1.0f / 2.0f;
		std::vector<V> vertices(5);
		vertices[0].pos = { 0.0f, 0.0f, 1.0f };
		vertices[1].pos = { side, side, -1.0f };
		vertices[2].pos = { side, -side, -1.0f };
		vertices[3].pos = { -side, -side, -1.0f };
		vertices[4].pos = { -side, side, -1.0f };

		return {
			std::move(vertices), {
				0, 2, 1,
				0, 3, 2,
				0, 4, 3,
				0, 1, 4,

				1, 2, 3,
				1, 3, 4
			}
		};
	}

	template<class V>
	static IndexedTriangleList<V> MakeSkinned()
	{
		namespace dx = DirectX;

		constexpr float side = 1.0f / 2.0f;

		std::vector<V> vertices(8);

		// center square
		vertices[0].pos = { side, side, 0.0f };
		vertices[0].tex = { 0.5f, 0.154f };
		vertices[1].pos = { side, -side, 0.0f };
		vertices[1].tex = { 0.814f, 0.3925f };
		vertices[2].pos = { -side, -side, 0.0f };
		vertices[2].tex = { 0.51f, 0.639f };
		vertices[3].pos = { -side, side, 0.0f };
		vertices[3].tex = { 0.2f, 0.4f };
		
		// tops
		vertices[4].pos = { 0.0f, 0.0f, 1.0f };
		vertices[4].tex = { 0.03f, 0.04f };
		vertices[5].pos = { 0.0f, 0.0f, 1.0f };
		vertices[5].tex = { 0.958f, 0.025f };
		vertices[6].pos = { 0.0f, 0.0f, 1.0f };
		vertices[6].tex = { 0.978f, 0.755f };
		vertices[7].pos = { 0.0f, 0.0f, 1.0f };
		vertices[7].tex = { 0.05f, 0.77f };

		return{
			std::move(vertices), {
				4, 0, 3,
				5, 1, 0,
				6, 2, 1,
				7, 3, 2,

				0, 1, 2,
				0, 2, 3
			}
		};
	}
};