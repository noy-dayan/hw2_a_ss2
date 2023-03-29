#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>
#include "card.hpp"

namespace ariel {
    // Player object header
    class Player {
        private:
            std::string name;    // Player name
            int cardsTaken;     // amount of cards taken
            bool isPlaying;     // current playing state

        public:
            Player(std::string name);
            int stacksize() const;    // get the current amount of cards in the stack
            int cardesTaken() const;    // get amount of total amount of cards taken
            void takeCards(int card_amount);    // take acertain amount of cards
            void setIsPlaying(bool isPlaying);  // set the playing state (true/false)
            bool getIsPlaying();    // get the playing state (true/false)
            std::string getName() const;    // get the player's name

    };
}

#endif
