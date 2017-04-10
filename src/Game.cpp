#include "Game.hpp"
#include "Window.hpp"

Game::Game()
	:m_window("Chapter 2", sf::Vector2u(800, 600))
{
	m_smileTexture.loadFromFile("resources/img/smile.png");
	m_smile.setTexture(m_smileTexture);
	m_increment = sf::Vector2i(1, 1);
}
Game::~Game()
{
}

void Game::update()
{
	m_window.update();
	moveSmile();
}

void Game::moveSmile()
{
	sf::Vector2u l_windSize = m_window.getWindowSize();
	sf::Vector2u l_texSize = m_smileTexture.getSize();

	if ((m_smile.getPosition().x > l_windSize.x - l_texSize.x && m_increment.x > 0) || (m_smile.getPosition().x < 0 && m_increment.x < 0))
	{
		m_increment.x = -m_increment.x;
	}
	if ((m_smile.getPosition().y > l_windSize.x - l_texSize.x && m_increment.y > 0) || (m_smile.getPosition().y < 0 && m_increment.y < 0))
	{
		m_increment.y = -m_increment.y;
	}
	m_smile.setPosition(m_smile.getPosition().x + m_increment.x, m_smile.getPosition().y + m_increment.y);
}

void Game::render()
{
	m_window.beginDraw();
	m_window.Draw(m_smile);
	m_window.endDraw();
}