#include <SFML/Graphics.hpp>

void main(int argc, char** argv[])
{
	sf::RenderWindow window(sf::VideoMode(640, 480), "Bouncing Smiley");

	sf::Texture smileTexture;

	if (!smileTexture.loadFromFile("resources/img/smile.png"))
	{
		window.close();
	}
	sf::Sprite smile(smileTexture);
	sf::Vector2u size = smileTexture.getSize();
	smile.setOrigin(size.x / 2, size.y / 2);
	sf::Vector2f increment(0.03f, 0.03f);
	smile.setColor(sf::Color(255, 0, 0, 200));
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		if ((smile.getPosition().x + (size.x / 2) > window.getSize().x && increment.x > 0) || (smile.getPosition().x - (size.x / 2) < 0 && increment.x < 0))
		{
			increment.x = -increment.x;
		}

		if ((smile.getPosition().y + (size.y / 2) > window.getSize().y && increment.y > 0) || (smile.getPosition().y - (size.y / 2) < 0 && increment.y < 0))
		{
			increment.y = -increment.y;
		}
		smile.setPosition(smile.getPosition() + increment);
		window.clear(sf::Color(16,16,16,255));
		window.draw(smile);
		window.display();


	}
}