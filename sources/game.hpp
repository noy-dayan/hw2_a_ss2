#ifndef GAME_HPP
#define GAME_HPP

#include "player.hpp"

namespace ariel {
    class Game {
        // Game object header
        private:
            Player &p1, &p2;
        public:
            Game(Player& p1, Player& p2);

            // plays
            void playTurn();    // play 1 turn
            void playAll();    // play all turns until game is over

            // prints
            void printLastTurn() const;    // print the last turn's log
            void printWiner() const;    // print the winner up to this point
            void printLog() const;    // print the game's log up to this point
            void printStats() const;    // print game stats up to this point
    };
}

#endif