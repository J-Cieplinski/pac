#include <SFML\Graphics.hpp>
#include "Game.h"
#include "Entity.h"

class TestObject : 
	public Entity {
private:
	sf::RectangleShape m_Shape;
public:
	TestObject() {
		m_Shape.setSize(sf::Vector2f(50.f, 50.f));
		m_Shape.setFillColor(sf::Color(255, 0, 0, 255));
		m_Shape.setPosition(0, 0);
		//std::cout << "Test Object Position: " << "X: " << m_Shape.getPosition().x << " Y: " << m_Shape.getPosition().y << std::endl;
	};
	void draw(sf::RenderTarget& target, sf::RenderStates states) const {
		states.transform *= m_Shape.getTransform();
		target.draw(m_Shape, states);
	}
	void update() override {};
};

int main()
{
	std::shared_ptr<Player> player = std::make_shared<Player>(Player());
	std::shared_ptr<TestObject> test = std::make_shared<TestObject>(TestObject());
	std::shared_ptr<LevelMap> levelMap = std::make_shared<LevelMap>(LevelMap());

	if (!levelMap->load("map.txt", 16, 8))
		return 0;

	Game game;

	game.addDrawObject(player, PLAYER);
	game.addDrawObject(test, "test");
	game.addDrawObject(levelMap, "levelMap");

	game.run();
	

	
}