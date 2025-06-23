// Project: general_game_playing_agent
// File: src/utils/sp_text_display.cpp
// Description: text display for single player games
// Author: Kyle McMaster
// Date: 2025-06-22

#include "general-game-playing-agent/utils/game_display.hpp"


#include <iostream>



void SPTextDisplay::display(std::shared_ptr<SinglePlayerGameState> game_state)  {
    int rows = game_state->get_rows();
    int cols = game_state->get_cols();
    int* board = game_state->get_board();

    for(int i = 0; i < rows; i++){
        for(int j = 0; j < cols; j++){
            int val = 1 << board[i * cols + j];
            std::cout<< ((val == 1) ? 0 : val) << "  " << ((j == cols-1) ? "\n":"");
        }
    }
    std::cout<<"\n";
}
