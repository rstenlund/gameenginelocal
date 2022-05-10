#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <array>

class ConsoleEngine {
private:
int width, height;
bool border;
char color = '#';
public:
std::vector<std::vector<char>> points;
ConsoleEngine(int width, int height, bool border);
void render();
void point(int x, int y);
void clear();
void background(char c);
void delay(int ms);
void fill(char col);
void rect(int x, int y, int width, int height);
};
