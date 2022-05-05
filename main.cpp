#include "ConsoleEngine.h"

const int WIDTH = 50;
const int HEIGHT = 12;
const bool BORDER = true;

int main() {
  ConsoleEngine engine(WIDTH, HEIGHT, BORDER);
  int x = 5;
  int y = 5;
  int xSpeed = 2;
  int ySpeed = 1;
  while (true) 
  {
    if (x <= 1 || x >= WIDTH-1) {
      xSpeed *= -1;
    }
    if (y <= 0 || y >= HEIGHT-1) {
      ySpeed *= -1;
    }
    x+=xSpeed;
    y+=ySpeed;
    engine.background(' ');
    engine.setPoint(x, y, '^');
    engine.render();
    engine.clear(); 
    engine.delay(300);  
  }

  return 0;
}