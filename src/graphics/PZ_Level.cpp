#include "PZ_Level.h"

Level::Level()
{
	m_Tiles.resize(m_MapSize * m_MapSize);
	m_DrawableTiles.resize(m_MapSize * m_MapSize);
}

Level::~Level()
{
}

void Level::Update()
{
	for (Tile& t : m_DrawableTiles)
		t.Update();
}

void Level::Render()
{
	for (int y = 0; y < 720; y++)
		for (int x = 0; x < 1280; x++)
		{
			for (Tile& t : m_DrawableTiles)
			{
				switch (m_Tiles[((x >> 4) & m_MapSizeMask) + ((y >> 4) & m_MapSizeMask) * m_MapSize])
				{
					case 0:
						t.Create(TileTypes::Sunflower);
						break;
				}
				t.Render(glm::vec3(glm::vec2((float)x, (float)y), 0.0f));
			}
		}
}