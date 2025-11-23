#include "Board.h"


Board::Board() 
    : m_currentLevel(0), m_gameStats(3, 1), m_lives(3), m_score(0),m_keyCount(0)
{
}

//renders\draws all the objects on  the window
void Board::renderObjects(sf::RenderWindow* window)
{
    m_gameStats.setClock(m_clock.getElapsedTime().asSeconds());
    
    if (m_timeLimit != -1)
    {
        m_gameStats.setTimer(m_timeLimit - m_clock.getElapsedTime().asSeconds());
    }
    
    m_gameStats.drawStatusBar(window);

    for (size_t i = 0; i < m_staticObjects.size(); i++)
    {
        (*m_staticObjects[i]).render(window);
    }

    for (size_t j = 0; j < m_MovingObjects.size(); j++) 
    {
        (*m_MovingObjects[j]).render(window);
    }
}




//-----------------------------------------------------------------
//updates the objects.
//for example it asks all the moving objects to move and also it checks for
//collisions
//-----------------------------------------------------------------
void Board::updateObjects() 
{
    Object_ID movePoints;  
    

    
    if (m_isFrozen) 
    {
        m_freezeCurrTime = m_clock.getElapsedTime();
        if (m_freezeCurrTime.asSeconds() - m_freezeTimeStart.asSeconds() >= FREEZE_TIME) 
        {
            m_isFrozen = false;

            SoundHandler::getInstance().playSound(Sound_ID::FREEZE_END);
            m_MovingObjects[0]->inactiveFreeze(); //////??????????????????????????
        } 
    }
    

    // move the moving objects
   const auto deltaTime = m_movementClock.restart();
    for (size_t i = 0; i < m_MovingObjects.size(); i++) 
    {
        (*m_MovingObjects[i]).move(deltaTime);
        
        // for each object check collision with other objects in the vector
        for (size_t j = 0; j < m_MovingObjects.size(); j++) 
        {
            if (m_MovingObjects[i]->getObjBound() .intersects(m_MovingObjects[j]->getObjBound()))
            {
                movePoints = m_MovingObjects[i]->handleCollision(*m_MovingObjects[j]);

                if (movePoints == Object_ID::CAT) 
                {
                    SoundHandler::getInstance().playSound(Sound_ID::MOUSE_EATEN);
                    --m_lives;
                    m_gameStats.setLives(m_lives);
                    for (size_t o = 0; o < m_MovingObjects.size(); o++)
                    {
                        m_MovingObjects[o]->resetToStartPos();
                    }
                }
            }
        }

        // check collision with the static objects
        for (size_t k = 0; k < m_staticObjects.size(); k++) 
        {
            if ((*m_MovingObjects[i]).getObjBound().intersects(m_staticObjects[k]->getObjBound())) 
            {
                movePoints = m_MovingObjects[i]->handleCollision(*m_staticObjects[k]);
                movePoints = m_staticObjects[k]->handleCollision(*m_MovingObjects[i]); 

                bool thereIsDoor = false;

                switch (movePoints) {
                case CLOCK:
                    SoundHandler::getInstance().playSound(Sound_ID::COLLECT_GIFT); 
                    m_gameStats.setScore(m_score += GIFT_PTS);

                    if (m_timeLimit != -1) 
                    {
                        m_timeLimit += TIME_BONUS;
                    }
                    break;
                case CHEESE:
                    SoundHandler::getInstance().playSound(Sound_ID::CHEESE_EATING);
                    --m_cheeseCount;
                    m_gameStats.setScore(m_score += CHEESE_PTS);
                    break;
                case FREEZE:
                    SoundHandler::getInstance().playSound(Sound_ID::FREEZE_START);
					m_gameStats.setScore(m_score += GIFT_PTS);

                    m_isFrozen = true;
                    m_freezeTimeStart = m_clock.getElapsedTime();
                    m_freezeCurrTime = m_freezeTimeStart;
                    break;
                case HEART:
                    SoundHandler::getInstance().playSound(Sound_ID::COLLECT_GIFT);
					m_gameStats.setScore(m_score += GIFT_PTS);

					m_gameStats.setLives(++m_lives);
                    break;
                case KEY:
                    /*
                    for (size_t j = 0; j < m_staticObjects.size(); j++) 
                    {
                        const type_info& objType = typeid(*m_staticObjects[j]);

                        if (objType == typeid(Door)) 
                        {
                            m_staticObjects[j]->gotEaten();
                            SoundHandler::getInstance().playSound(Sound_ID::DOOR_BREAK);
                            thereIsDoor = true;
                            break;
                        }
                    }
                    if (!thereIsDoor)
                    {
                        SoundHandler::getInstance().playSound(Sound_ID::COLLECT_GIFT);
                    }
                    */
                    SoundHandler::getInstance().playSound(Sound_ID::COLLECT_GIFT);///todelete????
					m_gameStats.setScore(m_score += KEY_PTS);
                    m_keyCount++;
                    m_gameStats.setKey(m_keyCount);
                    break;
                case KILL:
                    SoundHandler::getInstance().playSound(Sound_ID::COLLECT_GIFT);
                    for (size_t l = 0; l < m_MovingObjects.size(); l++)
                    {
                        if ((*m_MovingObjects[l]).getMyType() == SMART_CAT ||
                            (*m_MovingObjects[l]).getMyType() == STUPID_CAT)
                        {
                            m_MovingObjects.erase(m_MovingObjects.begin() + l);
                            break;
                        }
                    }

                    break;
                    /////???????????? delete all case below ?????????
                case DOOR:
                    for (size_t j = 0; j < m_MovingObjects.size(); j++)
                    {
                        if (auto mousePtr = dynamic_cast<Mouse*>(m_MovingObjects[j].get())) {
                            if (mousePtr->getKeys() > 0)
                            {
                                mousePtr->setKeys(-1);
                                m_staticObjects[k]->gotEaten();
                                SoundHandler::getInstance().playSound(Sound_ID::DOOR_BREAK);
                                m_keyCount--;
                                m_gameStats.setKey(m_keyCount);
                                break;
                            }
                        }
                    }
                    break;
                    //////////????????????????????????????????^^^^
                default:
                    break;
                }
            }
        }
        /////////??????????????????????????? need to change while ??????????????????
        auto index = m_staticObjects.begin();
        while (index != m_staticObjects.end())
        {
            // If element is even number then delete it
            if ((*index)->isEaten())
            {
                // Due to deletion in loop, iterator became
                // invalidated. So reset the iterator to next item.
                index = m_staticObjects.erase(index);
            }
            else 
            {
                index++;
            }
        }
    }
}



int Board::getCheeseCount() const
{
    return m_cheeseCount;
}

int Board::getCurrentLevel() const 
{ 
    return m_currentLevel;
}


int Board::getMouseLive() const 
{  
    return m_lives; 
}



//-----------------------------------------------------------------
// resets the score to what it was before the time ended
void Board::resetLevelScore()
{
    m_score = m_InitScore;
}

void Board::resetKeyCount()
{
    m_keyCount = 0;
    for (size_t j = 0; j < m_MovingObjects.size(); j++)
    {
        if (auto mousePtr = dynamic_cast<Mouse*>(m_MovingObjects[j].get()))
        {
            mousePtr->setKeys(-(mousePtr->getKeys()));
        }
    }
}

//-----------------------------------------------------------------
 //reset variables that we need at the start of the level
 //like timers and mouse lives, cheese count, the status bar info.
//-----------------------------------------------------------------
void Board::resetVals(int levelNum) 
{
    m_isFrozen = false;
    m_MovingObjects.clear();
    m_staticObjects.clear();
    m_currentLevel = levelNum;
    m_cheeseCount = 0;
    m_lives = 3;
    m_gameStats.setLives(m_lives);
    m_gameStats.seteLevel(m_currentLevel);
}



//-----------------------------------------------------------------
//receives a number and tries to load the level matching that number.
//if it was able to open a file with that level number it load all the objects
//and returns true. if the file was not found it returns false
//-----------------------------------------------------------------
bool Board::loadNextLevel(int levelNum)
{
    m_boardFile.open("Level_" + std::to_string(levelNum) + ".txt");

    if (!m_boardFile)
    {
        return false;
    }

    m_InitScore = m_score;
    m_gameStats.setScore(m_score);
    m_gameStats.setKey(m_keyCount);
    m_boardFile >> m_rows >> m_cols  >> m_timeLimit;



    // calcualte the tile size according to the row and column number
    int tileSize = 900 / std::max(m_rows, m_cols);

    
    resetVals(levelNum);
    

    int randNum;
    char c;
    // loop over the files and push objects to the vectors according to the
    // characters in the file
    for (int i = 0; i < m_rows; i++)
    {
        c = char(m_boardFile.get());  // swallow \n
        for (int j = 0; j < m_cols; j++) 
        {
            c = char(m_boardFile.get());
            if (c != ' ') 
            {
                switch (c) 
                {
                case '%':   //mouse
                    m_MovingObjects.push_back(std::make_unique<Mouse>
                        (float(j * tileSize), float(i * tileSize + TOP_OFFSET),
                        float(tileSize * OBJ_PERCENT), float(tileSize * OBJ_PERCENT),
                        MOUSE_SPEED, m_lives)); 
                    break; 
                case '^':   //cats
                   
                    randNum = rand() % 2;       //smart or stupid cat
                    if (randNum == 0) {
                        m_MovingObjects.push_back(std::make_unique<SmartCat>
                            (float(j * tileSize), float(i * tileSize + TOP_OFFSET),
                            float(tileSize * OBJ_PERCENT), float(tileSize * OBJ_PERCENT)
                            ,CAT_SPEED));
                    }
                    
                    else
                    {
                        m_MovingObjects.push_back(std::make_unique<StupidCat>
                            (float(j * tileSize), float(i * tileSize+ TOP_OFFSET),
                            float(tileSize * OBJ_PERCENT), float(tileSize * OBJ_PERCENT),
							CAT_SPEED));
                    }

                    break;

                case '#':  // Wall
                    m_staticObjects.push_back(std::make_unique<Wall>(
                        float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                        tileSize));
                    break;
                case 'D':  // Door
                    m_staticObjects.push_back(std::make_unique<Door>(
                        float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                        tileSize));
                    break;
                case 'F':  // key
                    m_staticObjects.push_back(std::make_unique<Key>(
                        float(j * tileSize), float(i * tileSize+ TOP_OFFSET), tileSize,
                        tileSize));
                    break;
                case '*':  // cheese
                    m_staticObjects.push_back(std::make_unique<Cheese>(
                        float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                        tileSize));
                    ++m_cheeseCount;
                    break;

                case '+':  //extra time gift
                    m_staticObjects.push_back(std::make_unique<GiftExtraTime>(
                        float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                        tileSize));
                    break;
                case 'S':  // Freeze gift
                    m_staticObjects.push_back(std::make_unique<GiftCatFreeze>(
                        float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                        tileSize));
                    break;
                case '3':  // Life gift
                    m_staticObjects.push_back(std::make_unique<GiftExtraLife>(
                        float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
                        tileSize));
                    break;

				case 'X':  // cat dissapear gift
					m_staticObjects.push_back(std::make_unique<GiftCatDisappear>(
						float(j * tileSize), float(i * tileSize + TOP_OFFSET), tileSize,
						tileSize));
					break;
                
                default:
                    break;
                }

            }
        }
    }

    resetTimers();

    m_boardFile.close();
    return true;
}


//-----------------------------------------------------------------
// send 1 if there's no time limit, otherwise it returns the remaining time
//-----------------------------------------------------------------
int Board::remainningTime() const
{
    return m_timeLimit == -1 ? 1
        : m_timeLimit - m_clock.getElapsedTime().asSeconds();
}


//-----------------------------------------------------------------
// reset the timers for the game and the ability timers
//-----------------------------------------------------------------
void Board::resetTimers()
{
    m_clock.restart();
    m_movementClock.restart();
    m_freezeTimeStart = m_clock.getElapsedTime();  
    m_freezeCurrTime = m_freezeTimeStart; 
}