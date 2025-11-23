
#include "GameStats.h"

// constructor for the status bar
GameStats::GameStats(int lives, int level) 
{
	m_font.loadFromFile("Caramel.ttf");
	// lives icon
	m_heartShape.setTexture(TextureHandler::getInstance().getObjTexture(HEART));
	m_heartTxt = sf::Text(": " + std::to_string(lives), m_font);
	m_heartTxt.setFillColor(sf::Color::White);
	m_heartShape.setPosition(0.f, 0.f);
	m_heartShape.setSize(sf::Vector2f(50.f, 50.f));
	m_heartTxt.setPosition(sf::Vector2f(60.f, 0.f));

	// clock icon
	m_clockShape.setTexture(TextureHandler::getInstance().getObjTexture(CLOCK));
	m_clockTxt = sf::Text(": 00:00", m_font);
	m_clockTxt.setFillColor(sf::Color::White);
	m_clockShape.setPosition(150.f, 0.f);
	m_clockShape.setSize(sf::Vector2f(50.f, 50.f));
	m_clockTxt.setPosition(sf::Vector2f(210.f, 0.f));

	// key icon
	m_keyShape.setTexture(TextureHandler::getInstance().getObjTexture(KEY));
	m_keyTxt = sf::Text(": " + std::to_string(0), m_font);
	m_keyTxt.setFillColor(sf::Color::White);
	m_keyShape.setPosition(300.f, 0.f);
	m_keyShape.setSize(sf::Vector2f(50.f, 50.f));
	m_keyTxt.setPosition(sf::Vector2f(360.f, 0.f));

	// timer icon
	m_timerShape.setTexture(TextureHandler::getInstance().getObjTexture(TIMER));
	resetTimer();
	m_timerShape.setPosition(450.f, 0.f);
	m_timerShape.setSize(sf::Vector2f(50.f, 50.f));

	// lvl number icon
	m_levelTxt = sf::Text("lvl :" + std::to_string(level), m_font);
	m_levelTxt.setFillColor(sf::Color::White);
	m_levelTxt.setPosition(sf::Vector2f(600.f, 0.f));

	// score icon
	m_scoreTxt = sf::Text("Score :" + std::to_string(0), m_font);
	m_scoreTxt.setFillColor(sf::Color::White);
	m_scoreTxt.setPosition(sf::Vector2f(750.f, 0.f));
	
}


/*
* draws the status bar on the window
*/
void GameStats::drawStatusBar(sf::RenderWindow* window) 
{
	window->draw(m_heartShape);
	window->draw(m_heartTxt);
	window->draw(m_clockShape);
	window->draw(m_timerShape);
	window->draw(m_keyShape);

	window->draw(m_clockTxt);
	window->draw(m_keyTxt);
	window->draw(m_timerTxt);
	window->draw(m_levelTxt);
	window->draw(m_scoreTxt);
}

void GameStats::setScore(int score) 
{
	m_scoreTxt.setString("Score :" + std::to_string(score));
}

void GameStats::setKey(int key)
{
	m_keyTxt.setString(": " + std::to_string(key));
}

void GameStats::setLives(int lives)
{
	m_heartTxt.setString(": " + std::to_string(lives));
}


// receives the number of seconds passed and shows it on the timer on the status bar
void GameStats::setClock(int seconds) 
{
	secondToNormalTime(seconds);
	m_clockTxt.setString(": " + m_tmpMin + ":" + m_tmpSec);
}

void GameStats::setTimer(int seconds)
{
	secondToNormalTime(seconds);
	m_timerTxt.setString(": " + m_tmpMin + ":" + m_tmpSec);
}

void GameStats::seteLevel(int level) 
{
	m_levelTxt.setString("lvl :" + std::to_string(level));
}


// converts the seconds to normal xx:xx representation
void GameStats::secondToNormalTime(int seconds)
{
	m_seconds = seconds;
	m_minutes = m_seconds / 60;
	m_seconds = m_seconds % 60;

	m_tmpMin = std::to_string(m_minutes);
	if (m_minutes < 10)
	{
		m_tmpMin = "0" + std::to_string(m_minutes);
	}
	else if(m_minutes<60)
	{
		m_tmpMin = std::to_string(m_minutes);
	}

	m_tmpSec = std::to_string(m_seconds);
	if (m_seconds < 10)
	{
		m_tmpSec = "0" + std::to_string(m_seconds);
	}
	else
	{
		m_tmpSec = std::to_string(m_seconds);
	}
}

// resets the timer. we also use this to disable it when there's
// no time limit
void GameStats::resetTimer()
{ 
	m_timerTxt = sf::Text(": --:--", m_font);
	m_timerTxt.setPosition(sf::Vector2f(510.f, 0.f));
}
