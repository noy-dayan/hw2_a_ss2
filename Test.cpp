#include "doctest.h"
#include "sources/card.hpp"
#include "sources/player.hpp"
#include "sources/game.hpp"

#include <stdexcept>
#include <string>
using namespace std;

TEST_CASE("player init"){
    CHECK_NOTHROW(ariel::Player test("test"));
}

TEST_CASE("game init"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    CHECK_NOTHROW(ariel::Game test(p1, p2));
}

TEST_CASE("get stack size"){
    ariel::Player p("Noy");
    CHECK_NOTHROW(p.stacksize());
}

TEST_CASE("get cards taken"){
    ariel::Player p("Noy");
    CHECK_NOTHROW(p.cardesTaken());
}

TEST_CASE("get player name"){
    ariel::Player p("Noy");
    CHECK_NOTHROW(p.getName());
}

TEST_CASE("stack size init"){
    ariel::Player p("Noy");
    CHECK(p.stacksize() == 0);
}

TEST_CASE("cardesTaken init"){
    ariel::Player p("Noy");
    CHECK(p.cardesTaken() == 0);
}

TEST_CASE("getName init"){
    ariel::Player p("Noy");
    CHECK(p.getName() == "Noy");
}

TEST_CASE("get isPlaying"){
    ariel::Player p("Noy");
    CHECK_NOTHROW(p.getIsPlaying());
}

TEST_CASE("isPlaying init"){
    ariel::Player p("Noy");
    CHECK(p.getIsPlaying() == false);
}

TEST_CASE("set isPlaying"){
    ariel::Player p("Noy");
    CHECK(p.getIsPlaying() == false);
    CHECK_NOTHROW(p.setIsPlaying(true));
    CHECK(p.getIsPlaying() == true);
}

TEST_CASE("play turn"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    ariel::Game test(p1, p2);
    CHECK_NOTHROW(test.playTurn());
}

TEST_CASE("play all turns"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    ariel::Game test(p1, p2);
    CHECK_NOTHROW(test.playAll());
}

TEST_CASE("print winner"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    ariel::Game test(p1, p2);
    test.playAll();
    CHECK_NOTHROW(test.printWiner());
}

TEST_CASE("print last turn"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    ariel::Game test(p1, p2);
    test.playAll();
    CHECK_NOTHROW(test.printLastTurn());
}

TEST_CASE("print game logs"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    ariel::Game test(p1, p2);
    test.playAll();
    CHECK_NOTHROW(test.printLog());
}

TEST_CASE("print game stats"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    ariel::Game test(p1, p2);
    test.playAll();
    CHECK_NOTHROW(test.printStats());
}

TEST_CASE("game end"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    ariel::Game test(p1, p2);
    test.playAll();
    //CHECK(p1.cardesTaken() == 0 + p2..cardesTaken() >= 52);
    if (p1.stacksize() != 0){
        CHECK(p2.stacksize() == 0);
        return;
    }
    if (p2.stacksize() != 0){
        CHECK(p1.stacksize() == 0);
        return;
    }
    CHECK(p1.stacksize() == 0);
    CHECK(p2.stacksize() == 0);
}

TEST_CASE("isPlaying update"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    CHECK(p1.getIsPlaying() == false);
    CHECK(p2.getIsPlaying() == false);
    ariel::Game test(p1, p2);
    CHECK(p1.getIsPlaying() == true);
    CHECK(p2.getIsPlaying() == true);

}

TEST_CASE("take cards"){
    ariel::Player p1("Noy1");
    int cards_to_take = 26;
    CHECK(p1.cardesTaken() == 0);
    CHECK_NOTHROW(p1.takeCards(cards_to_take));
    CHECK(p1.cardesTaken() == 26);
}

TEST_CASE("player not already playing validation"){
    ariel::Player p1("Noy1");
    ariel::Player p2("Noy2");
    ariel::Player p3("Noy2");
    ariel::Game test1(p1, p2);
    CHECK_THROWS_AS(ariel::Game(p1, p3), invalid_argument);

}

TEST_CASE("not duplicate player validation"){
    ariel::Player p1("Noy1");
    CHECK_THROWS_AS(ariel::Game(p1, p1), invalid_argument);

}
