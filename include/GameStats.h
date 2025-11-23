#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include "TextureHandler.h"

class GameStats {
public:
	GameStats(int lives, int level);

	void drawStatusBar(sf::RenderWindow* window);

	void setScore(int score);

	void setKey(int key);

	void setLives(int lives);

	void setClock(int seconds);

	void setTimer(int seconds);

	void seteLevel(int level);

	void resetTimer();

private:
	sf::Font m_font;

	sf::RectangleShape m_heartShape, m_clockShape, m_timerShape,m_keyShape;
	sf::Text m_heartTxt;


	std::string m_tmpMin, m_tmpSec;
	int m_minutes, m_seconds;

	sf::Text m_clockTxt, m_timerTxt;

	sf::Text m_levelTxt;

	sf::Text m_scoreTxt;

	sf::Text m_keyTxt;

	void secondToNormalTime(int seconds);
};