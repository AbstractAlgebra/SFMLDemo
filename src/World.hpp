#ifndef world
#define world
#include <SFML/Graphics.hpp>
#include "Snake.hpp"
class World {
public: 
	World(sf::Vector2u l_windSize);
	~World();
	
	int getBlockSize();
	void respawnApple();
	void update(Snake& l_player);
	void render(sf::RenderWindow& l_window);
	int World::GetBlockSize();
private:
	sf::Vector2u m_windowSize;
	sf::Vector2i m_item;
	int m_blockSize;
	sf::CircleShape m_appleShape;
	sf::RectangleShape m_bounds[4];
};


#endif