#include "engine/ConsoleEngine.h"

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
    if (x <= 1 || x+2 >= WIDTH-1) {
      xSpeed *= -1;
    }
    if (y <= 0 || y+1 >= HEIGHT-1) {
      ySpeed *= -1;
    }
    x+=xSpeed;
    y+=ySpeed;
    engine.background(' ');
    engine.rect(x, y, 2, 2, 'X');
    engine.render();
    engine.clear(); 
    engine.delay(300);  
  }

  return 0;
}