#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int NUMBER_OF_OBJECTS = 18;   

enum Object_ID {
    CLOCK,
    CHEESE,
    DOOR,
    WALL,
    KEY,
    SMART_CAT,
    STUPID_CAT,
    FROZEN_CAT,
    FROZEN_STUPID_CAT,
    FREEZE,
    HEART,
    MOUSE,
    LEVEL_UP,
    TIME_UP,
    GAME_OVER,
    FINAL_WIN,
    KILL,
    TIMER,
    CAT,
    EMPTY_PLACE
};

class TextureHandler 
{
public:
    TextureHandler();

    static TextureHandler& getInstance();

    sf::Texture* getObjTexture(int objNum);

    sf::Font getFont() const;

    ~TextureHandler();

private:
    
    std::string m_imgNames[NUMBER_OF_OBJECTS] = {
        "clock.png",         "cheese.png",       "door.png", 
		"wall.png",          "key.png",          "smart_cat.png",
		"stupid_cat.png",    "frozen_cat.png",   "frozen_stupid_cat.png",   
        "freeze.png",        "heart.png",        "mouse.png",        
        "level_up.png",      "time_up.png",      "game_over.png",   
        "final_win.png",     "kill.png",         "timer.png" };

    sf::Texture m_textures[NUMBER_OF_OBJECTS];
    sf::Font m_font;
};