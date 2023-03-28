//#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
using namespace std;
#include "sources/player.hpp"
#include "sources/game.hpp"
#include "sources/card.hpp"
using namespace ariel;
#include "doctest.h"

Player p1("Aviv");
Player p2("Bob");

TEST_CASE("names")
{
   CHECK(p1.name == "Aviv");
   CHECK(p2.name == "Bob");
  
}
TEST_CASE("size")
{
   CHECK(p1.stacksize() == 26 );
   CHECK(p2.stacksize() == 26 );
   Game game(p1,p2); 
   for (int i=0;i<5;i++) 
   {
    game.playTurn();
   }
   CHECK(p1.stacksize() <= 26 );
   CHECK(p2.stacksize() <= 26 );
   CHECK(p1.stacksize() >= 0 );
   CHECK(p2.stacksize() >= 0 );
   CHECK(p1.stacksize() == p2.stacksize());

   CHECK(p1.cardesTaken() <= 52 );
   CHECK(p2.cardesTaken() <= 52 );
   CHECK(p1.cardesTaken() + p2.cardesTaken() <= 52 );
   CHECK(p1.cardesTaken() >= 0 );
   CHECK(p2.cardesTaken() >= 0 );
}
TEST_CASE("exceptions")
{
   Game game(p1,p2);
   CHECK_THROWS(game.printWiner());
   CHECK_THROWS(game.printLastTurn());
   CHECK_THROWS(game.printLog());
   CHECK_THROWS(game.printStats()); 
   CHECK_NOTHROW(game.playTurn());

   game.playAll();
   CHECK_NOTHROW(game.printWiner());
   CHECK_THROWS(game.playTurn());
}


