#include "engine/ConsoleEngine.h"

const int WIDTH = 51;
const int HEIGHT = 12;
const bool BORDER = true;

int main() {
  ConsoleEngine engine(WIDTH, HEIGHT, BORDER);

  while (true) 
  {
    engine.background(' ');

    engine.fill('o');
    engine.point(4, 4);
    
    engine.render();
    engine.delay(300);
  }

  return 0;
}
