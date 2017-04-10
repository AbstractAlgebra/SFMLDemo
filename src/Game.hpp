#ifndef game_hpp
#define game_hpp
#include "Window.hpp"

class Game
{
public:
	Game();
	~Game();

	void handleInput();
	void update();
	void render();
	Window* getWindow();

private:

	void moveSmile();
	Window m_window;
	sf::Texture m_smileTexture;
	sf::Sprite m_smile;
	sf::Vector2i m_increment;

};

#endif