#ifndef GAME_DISPLAY_HPP
#define GAME_DISPLAY_HPP

// Project: general_game_playing_agent
// File: include/general_game_playing_agent/utils/game_display.hpp
// Description: prints the game based on SinglePlayerGameState
// Author: Kyle McMaster
// Date: 2025-06-22

#include "general-game-playing-agent/games/single_player_game.hpp"

#include <iostream>
#include <memory>

class SinglePlayerGameDisplay {

public:

    virtual void display(std::shared_ptr<SinglePlayerGameState> game_state) = 0;

    virtual ~SinglePlayerGameDisplay() = default;
};

class SPTextDisplay : public SinglePlayerGameDisplay{

public:

    void display(std::shared_ptr<SinglePlayerGameState> game_state) override {
        int rows = game_state->get_rows();
        int cols = game_state->get_cols();
        int* board = game_state->get_board();

        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                int val = 1 << board[i * cols + j];
                std::cout<< ((val == 1) ? 0 : val) << "  " << ((j == cols-1) ? "\n":"");
            }
        }
    }
};

#endif