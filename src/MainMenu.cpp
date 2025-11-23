#include "MainMenu.h"


// main menu constructor
MainMenu::MainMenu() 
{
    
    // set the background
    m_mainBackGround.setPosition(0.f, 0.f); 
    m_mainBackGround.setSize(sf::Vector2f(900.f, 950.f)); 
    m_mainTexture.loadFromFile("main_background.png"); 
    m_mainBackGround.setTexture(&m_mainTexture);
    
    // set the newGame button
    m_newGameButton.setPosition(50.f, 450.f);
    m_newGameButton.setSize(sf::Vector2f(350.f, 250.f));
    m_newGameButtonTexture.loadFromFile("new_game_btn.png");
    m_newGameButton.setTexture(&m_newGameButtonTexture);

    // sets the help button
	m_helpButton.setPosition(50.f, 550.f);
	m_helpButton.setSize(sf::Vector2f(350.f, 250.f));
	m_helpButtonTexture.loadFromFile("helpButton.png");
	m_helpButton.setTexture(&m_helpButtonTexture);

    // set the exit button
	m_exitButton.setPosition(50.f, 650.f);
	m_exitButton.setSize(sf::Vector2f(350.f, 250.f));
	m_exitButtonTexture.loadFromFile("exitButton.png");
	m_exitButton.setTexture(&m_exitButtonTexture);

    // set the insturctions 
	m_helpPageTexture.loadFromFile("instructions.png");
	m_helpTexture.setPosition(0.f, 0.f);
	m_helpTexture.setSize(sf::Vector2f(900.f, 950.f));
	m_helpTexture.setTexture(&m_helpPageTexture);
    
}


// draws the background and buttons on the main menu
void MainMenu::drawMainMenu(sf::RenderWindow* window) 
{
    window->draw(m_mainBackGround);
    window->draw(m_newGameButton);
    window->draw(m_helpButton);
    window->draw(m_exitButton);
}

// draws the help page when called
void MainMenu::drawHelpPage(sf::RenderWindow* window) 
{
    window->draw(m_helpTexture);
}


// returns which button was pressed
int MainMenu::buttonPressed(sf::RenderWindow* window,
    const sf::Event::MouseButtonEvent& event) 
{
    if (m_newGameButton.getGlobalBounds().contains(
        window->mapPixelToCoords({ event.x, event.y })))
    {
        return NEW_GAME;
    }
    else if (m_helpButton.getGlobalBounds().contains(
        window->mapPixelToCoords({ event.x, event.y })))
    {
        return HELP;
    }
    else if (m_exitButton.getGlobalBounds().contains(
        window->mapPixelToCoords({ event.x, event.y }))) 
    {
        return EXIT;
    }
    return MAIN_MENU;
}
