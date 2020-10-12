#include "game.h"
#include <iostream>
using namespace std;

int main() {
  cout << "Hello World!" << endl;

  std::shared_ptr<Game> game{new Game};
  game->initialize();

  game->runLoop();

  game->shutdown();

  return 0;
}
