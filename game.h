#ifndef GAME_H
#define GAME_H

#include <memory>
#include <string>
#include <vector>

//#include <GL/glew.h>
//#include <SDL.h>
//#include <SDL_opengl.h>
#include <entt/entt.hpp>

#include "sys/playercontrolsystem.h"
#include "sys/rendersystem.h"

class EventSystem;
class Game : public std::enable_shared_from_this<Game> {

  //  SDL_Window *_window;
  //  SDL_Renderer *_renderer;
  //  SDL_GLContext _context;
  bool isRunning;
  std::string _title;
  uint32_t _tick_count;

  entt::registry _registry;

  int _windowWidth;
  int _windowHeight;

  std::unique_ptr<System> renderSys;
  std::unique_ptr<System> playerControlSys;
  std::unique_ptr<EventSystem> eventSystem;
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
  Game(
      //          SDL_Window *w = nullptr, SDL_Renderer *renderer = nullptr,
      bool r = false, const std::string &t = "", int ww = 1024, int wh = 768);
  ~Game();
  bool initialize();

  void runLoop();
  void updateGame();
  void generateOutput();
  void shutdown();

  //  SDL_Renderer *renderer() const;
  //  SDL_Window *window() const;
  entt::registry &registry();

  entt::entity getPlayerEntity() const;
  bool getIsRunning() const;
  void setIsRunning(bool value);

  int getWindowWidth() const;

  int getWindowHeight() const;

  void signalClose();

private:
  entt::entity createRandomEnemy();
  entt::entity createPlayer();

  void on_exit_signal() { isRunning = false; }
  void on_mousewheel_signal(int i);
  entt::sigh<void()> exit_signal;
  entt::sink<void()> exit_signal_sink;

  friend class RaylibRenderSystem;
};

#include "sys/eventsystem.h"

#endif // GAME_H
