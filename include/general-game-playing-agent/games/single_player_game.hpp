#ifndef SINGLE_PLAYER_GAME_HPP
#define SINGLE_PLAYER_GAME_HPP

// Project: general_game_playing_agent
// File: include/general_game_playing_agent/single_player_game.hpp
// Description: describe the interface for single player games
// Author: Kyle McMaster
// Date: 2025-06-22

#include <unordered_map>
#include <string>
class SinglePlayerGameState {

    int* board;
    std::unordered_map<std::string, float> state_values;
};

class SinglePlayerGame {
public:
    virtual SinglePlayerGameState get_state();
};


#endif