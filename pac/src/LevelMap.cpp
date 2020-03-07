#include "LevelMap.h"
#include <fstream>

bool LevelMap::loadTilesFromFile(const std::string& tiles) //load tiles from txt file repesented by numbers. 0 means empty, anything above is a tile
{
	std::ifstream tilesStream;
	int temp{};
	int tilesCounter{};
	tilesStream.open(tiles);
	if (!tilesStream.is_open())
	{
		std::cout << "File " << tiles << " not found\n";
		return false;
	}

	while (!tilesStream.eof())
	{
		tilesStream >> temp;
		if (temp > 0)
			tilesCounter++; //count how many tiles are >0

		m_TileMap.push_back(temp);
		//std::cout << temp << "\n";
		
		
	}

	//reserve appropiate size for map tiles
	m_Tiles.resize(tilesCounter); 

	tilesStream.close();
	return true;

}

void LevelMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	for (auto& singleTile : m_Tiles)
	{
		states.transform *= singleTile.getTransform();
		target.draw(singleTile, states);
	}
}

bool LevelMap::load(const std::string& tiles, unsigned int width, unsigned int height)
{
	if (!loadTilesFromFile(tiles))
		return false;

	int tilesCounter{ 0 };

	for (unsigned int i = 0; i < width; i++)
	{
		for (unsigned int j = 0; j < height; j++)
		{
			//get current tile number
			int tileNumber = i * height + j;
			
						
			if (m_TileMap[tileNumber] > 0)
			{
				if(tileNumber == 48)
					std::cout << "DEBUG";
				
				m_Tiles[tilesCounter].setFillColor(sf::Color::Yellow);
				m_Tiles[tilesCounter].setPosition(i * m_TileSize.x, j * m_TileSize.y); //set tiles position
				std::cout << "Tile " << tilesCounter << std::endl;
				std::cout << "X: " << i * m_TileSize.x << std::endl << "Y: " << j * m_TileSize.y << std::endl;
				m_Tiles[tilesCounter].setSize(m_TileSize);
				tilesCounter++;
			}
			
		}
	}
	return true;
}

void LevelMap::update()
{
}
