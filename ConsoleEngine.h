#include <iostream>
#include <vector>
#include <chrono>
#include <thread>
#include <array>

class ConsoleEngine {
private:
int width, height;
bool border;
public:
char **points;
ConsoleEngine(int width, int height, bool border);
void render();
void setPoint(int x, int y, char c);
void clear();
void background(char c);
void delay(int ms);
};