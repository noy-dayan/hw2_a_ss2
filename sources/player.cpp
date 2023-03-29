#include "player.hpp"
#include <iostream>
#include <string>

namespace ariel {
    // Player object 
    Player::Player(std::string name){
        this->name = name;
        this->isPlaying = false;
        this->cardsTaken = 0;
    }

    // get the current amount of cards in the stack
    int Player::stacksize() const {
        return 0;
    }
    
    // get amount of total amount of cards taken
    int Player::cardesTaken() const {
        return cardsTaken;
    }

    // take acertain amount of cards
    void Player::takeCards(int card_amount){
        this->cardsTaken += card_amount;
    }

    // set the playing state (true/false)
    void Player::setIsPlaying(bool isPlaying){
        this->isPlaying = isPlaying;
    }

    // get the playing state (true/false)
    bool Player::getIsPlaying(){
        return this->isPlaying;
    }

    // get the player's name
    std::string Player::getName() const{
        return this->name;
    }
}
