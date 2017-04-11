
#ifndef snake
#define snake
#include <SFML\Graphics.hpp>

struct SnakeSegment
{
	SnakeSegment(int x, int y) : position(x, y) {}
	sf::Vector2i position;
};
using SnakeContainer = std::vector<SnakeSegment>;
enum class Direction { None, Up, Down, Left, Right };

class Snake
{
public:
	Snake(int l_blockSize);
	~Snake();

	//Helper methods
	void setDirection(Direction l_dir);
	Direction getDirection();
	int getSpeed();
	sf::Vector2i getPosition();
	int getLives();
	int getScore();
	void increaseScore();
	bool hasLost();

	void lose();
	void toggleLost();

	void extend(); //Grow the snake
	void reset(); //Reset to starting position

	void move();
	void tick();
	void cut(int l_segments);
	void render(sf::RenderWindow& l_window);

	void checkCollision();

	SnakeContainer m_snakeBody;
	int m_size;
	Direction m_dir;
	int m_speed;
	int m_lives;
	int m_score;
	bool m_lost;
	sf::RectangleShape m_bodyRect;

};
#endif