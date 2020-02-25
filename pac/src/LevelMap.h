#pragma once
#include "Headers.h"
class LevelMap:
	public Entity
{
private:
	std::vector<sf::RectangleShape> m_Tiles;
	std::vector<int> m_TileMap{};
	sf::Vector2f m_TileSize{50,50};
	bool loadTilesFromFile(const std::string& tiles);
public:
	void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	bool load(const std::string& tiles, unsigned int width, unsigned int height);
	LevelMap() {};
	void update() override;
};