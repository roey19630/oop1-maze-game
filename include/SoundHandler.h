#pragma once

#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

const int SOUND_NUM = 13;

enum Sound_ID {
  SELECTED,
  MOUSE_EATEN,
  GAME_OVER_SOUND,
  FREEZE_START,
  DOOR_BREAK,
  CHEESE_EATING,
  FREEZE_END,
  COLLECT_GIFT,
  VICTORY,
  CLAPPING,
  TIME_UP_SOUND,
  LEVEL_UP_SOUND,
  GAME_START
};

class SoundHandler {
 public:
  ~SoundHandler();
  static SoundHandler& getInstance();

  void playSound(Sound_ID id);

 private:
  SoundHandler();

  const std::string m_soundNames [SOUND_NUM] = {
      "selected.wav",    "mouse_eaten.wav",   "game_over.wav",  "freeze_start.wav", 
      "door_break.wav",  "cheese_eating.wav", "freeze_end.wav", "collect_gift.wav",
      "victory.wav",     "clapping.wav",      "time_up.wav",    "level_up.wav", 
      "game_start.wav"};

  sf::SoundBuffer m_buffers[SOUND_NUM];
  sf::Sound m_sound;
  sf::Sound m_sounds[SOUND_NUM];
};
