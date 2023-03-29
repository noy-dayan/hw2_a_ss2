#include "game.hpp"
#include <iostream>

namespace ariel {
    // Game object
    Game::Game(Player& p1, Player& p2): 
        p1(p1), p2(p2){
            if(p1.getIsPlaying() == true || p2.getIsPlaying() == true)
                throw std::invalid_argument("Player(s) already in game and playing");
            if (p1.getName() == p2.getName())
                throw std::invalid_argument("Duplicate player detected");

            p1.setIsPlaying(true);
            p2.setIsPlaying(true);
        }

    // play 1 turn
    void Game::playTurn() {
        std::cout << "play 1 turn"<< std::endl;
    }

    // play all turns until game is over
    void Game::playAll() {
        std::cout << "play all turns" << std::endl;
    }

    // print the last turn's log
    void Game::printLastTurn() const {
        std::cout << "last turn log" << std::endl;
    }

    // print the winner up to this point
    void Game::printWiner() const {
        std::cout << "winner" << std::endl;  
    }

    // print the game's log up to this point
    void Game::printLog() const {
        std::cout << "all logs" << std::endl;  
    }

    // print game stats up to this point
    void Game::printStats() const {
        std::cout << "stats" << std::endl;  
    }

}
