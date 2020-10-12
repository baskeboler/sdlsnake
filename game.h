#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <vector>

#include <SDL.h>
#include <entt/entt.hpp>

#include "sys/playercontrolsystem.h"
#include "sys/rendersystem.h"

class Game : public std::enable_shared_from_this<Game> {

  SDL_Window *_window;
  SDL_Renderer *_renderer;
  bool _is_running;
  std::string _title;
  Uint32 _tick_count;

  entt::registry _registry;

  int _windowWidth;
  int _windowHeight;

  std::vector<Uint8> kbState;

  std::unique_ptr<RenderSystem> renderSys;
  std::unique_ptr<PlayerControlSystem> playerControlSys;

  entt::entity playerEntity;

public:
  void processInput();
  /**
   * @brief Game
   * @param w the sdl window
   * @param renderer the sdl renderer
   * @param r true iif gamer is running
   * @param t window title
   * @param ww window width
   * @param wh window height
   */
  Game(SDL_Window *w = nullptr, SDL_Renderer *renderer = nullptr,
       bool r = false, const std::string &t = "", int ww = 1024, int wh = 768);
  ~Game();
  bool initialize();

  void runLoop();
  void updateGame();
  void generateOutput();
  void shutdown();

  SDL_Renderer *renderer() const;
  SDL_Window *window() const;
  entt::registry &registry();
  std::vector<Uint8> getKbState() const;
  entt::entity getPlayerEntity() const;
};

#endif // GAME_H
