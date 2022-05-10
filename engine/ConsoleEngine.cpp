#include "ConsoleEngine.h"

ConsoleEngine::ConsoleEngine(int width, int height, bool border) {
  this->width = width;
  this->height = height;
  this->border = border;
  points.resize(height, std::vector<char>(width, '.'));
}

void ConsoleEngine::render() {
  printf("\033[H\033[J");
  printf("\033[%d;%dH", 0, 0);

  if (border) {
    for (int i = 0; i < width; i++) {
      std::cout << '-';
    }
    std::cout << "\n";
  }
  for (int y = 0; y < height; y++) {
      for (int x = 0; x < width; x++) {
          std::cout << points[y][x];
      }   
      std::cout << "\n";
  }
  if (border) {
    for (int i = 0; i < width; i++) {
      std::cout << '-';
    }
    std::cout << "\n";
  }
}

void ConsoleEngine::fill(char col) {
  this->color = col;
}

void ConsoleEngine::point(int x, int y) {
  this->points[y][x] = this->color;
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

void ConsoleEngine::rect(int x, int y, int width, int height) {
  for (int j = y; j < y + height; j++) {
    for (int i = x; i < x + width; i++) {
      this->points[j][i] = this->color;
    }
  }
}
