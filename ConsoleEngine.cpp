#include "ConsoleEngine.h"

ConsoleEngine::ConsoleEngine(int width, int height, bool border) {
  this->width = width;
  this->height = height;
  this->border = border;
  this->points = new char*[this->height];
  for(int i = 0; i < this->height; ++i)
    this->points[i] = new char[this->width];
  for (int y = 0; y < this->height; y++) {
    for (int x = 0; x < this->width; x++) {
      this->points[y][x] = '.';
    }
  }
}

void ConsoleEngine::render() {
  printf("\033[H\033[J");
  printf("\033[%d;%dH", 0, 0);

  if (border) {
    for (int i = 0; i < this->width; i++) {
      std::cout << '-';
    }
    std::cout << "\n";
  }
  for (int y = 0; y < this->height; y++) {
      for (int x = 0; x < this->width; x++) {
          std::cout << this->points[y][x];
      }   
      std::cout << "\n";
  }
  if (border) {
    for (int i = 0; i < this->width; i++) {
      std::cout << '-';
    }
    std::cout << "\n";
  }
}

void ConsoleEngine::setPoint(int x, int y, char c) {
  this->points[y][x] = c;
}

void ConsoleEngine::clear() {
  for (int y = 0; y < this->height; y++) {
    for (int x = 0; x < this->width; x++) {
      this->points[y][x] = '.';
    }
  }
}

void ConsoleEngine::background(char c) {
  for (int y = 0; y < this->height; y++) {
    for (int x = 0; x < this->width; x++) {
      this->points[y][x] = c;
    }
  }
}


void ConsoleEngine::delay(int ms) {     
  std::this_thread::sleep_for(std::chrono::milliseconds(ms));
}