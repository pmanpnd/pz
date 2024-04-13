#pragma once

#include "PZ_Renderer.h"
#include "PZ_Tile.h"

#include <vector>

// OCD
class Level
{
	const int m_MapSize = 64, m_MapSizeMask = m_MapSize - 1;
	std::vector<int> m_Tiles;
	std::vector<Tile> m_DrawableTiles;
public:
	Level();
	~Level();

	// For testing purposes.
	void FillTiles(int num) { std::fill(m_Tiles.begin(), m_Tiles.end(), num); }

	void Update();
	void Render();
};