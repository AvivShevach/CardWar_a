namespace ariel{};
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "card.hpp"
using namespace std;
struct Player {
  string name;
//   Card hand[52];
//   int stack;
  int stacksize();
  int cardesTaken();
  Player();
  Player(string n);
};