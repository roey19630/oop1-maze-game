#pragma once

#include <algorithm>
#include <fstream>
#include <iosfwd>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>


#include "Cheese.h"
//#include "Cat.h"
#include "Door.h"
#include "Wall.h"
#include "StupidCat.h"
#include "SmartCat.h"
#include "GiftExtraLife.h"
#include "GiftExtraTime.h"
#include "GiftCatFreeze.h"
#include "GiftCatDisappear.h"
#include "Key.h"
#include "Mouse.h"
#include "SoundHandler.h"
#include "GameStats.h"

const int GIFT_PTS = 5;
const int KEY_PTS = 7;
const int CHEESE_PTS = 2;
const int TIME_BONUS = 10;
const int FREEZE_TIME = 8;
const int SUPER_TIME = 10;
const int TOP_OFFSET = 50;
const double OBJ_PERCENT = 0.7;
const float MOUSE_SPEED = 150.f;
const float CAT_SPEED = 100.f;


class Board 
{
public:
	Board();

	void renderObjects(sf::RenderWindow* window);

	void updateObjects();

	int getCheeseCount() const; 

	int getCurrentLevel() const;

	int getMouseLive() const;

	int remainningTime() const;

	void resetLevelScore();

	void resetKeyCount();

	bool loadNextLevel(int levelNum);

	void resetTimers();

private:
	std::ifstream m_boardFile;

	std::vector<std::unique_ptr<MovingObject>> m_MovingObjects;
	std::vector<std::unique_ptr<StaticObject>> m_staticObjects;

	int m_rows = 0, m_cols = 0;		
	int m_timeLimit = 0;
	int m_cheeseCount = 0;
	int m_currentLevel = 0, m_keyCount = 0,
		m_lives = 0, m_score = 0, m_InitScore = 0;
	bool m_isFrozen = false;
	sf::Clock m_clock, m_movementClock;
	sf::Time m_SuperTimeStart, m_superCurrTime;
	sf::Time m_freezeTimeStart, m_freezeCurrTime;
	GameStats m_gameStats;

	void resetVals(int levelNum);
};
