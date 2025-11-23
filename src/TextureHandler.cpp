
#include "TextureHandler.h"


// loads the textures into an array of textures
TextureHandler::TextureHandler() 
{
    for (int i = 0; i < NUMBER_OF_OBJECTS; i++)
    {
        m_textures[i].loadFromFile(m_imgNames[i]);
    }

    m_font.loadFromFile("Caramel.ttf");
}

TextureHandler& TextureHandler::getInstance() 
{
    static TextureHandler instance;
    return instance;
}


//returns the appropriate texture according to the nmber received
sf::Texture* TextureHandler::getObjTexture(int objNum) 
{
    return &m_textures[objNum];
}

sf::Font TextureHandler::getFont() const { return m_font; }


TextureHandler::~TextureHandler() {}