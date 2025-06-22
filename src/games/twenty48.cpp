
// Project: general_game_playing_agent
// File: src/games/twenty48.cpp
// Description: Implement 2048
// Author: Kyle McMaster
// Date: 2025-06-22

#include "include/general-game-playing-agent/games/twenty48.hpp"




Twenty48::Twenty48(int rows, int cols, float two_prob)
    : rows(rows), cols(cols), two_prob(two_prob) {
    // constructor body (not shown)
}

void Twenty48::place_random_tile() {
    int* board = game_state->get_board();

    
}

// Virtual function overrides
SinglePlayerGameState Twenty48::initialize_game() {
    size_t size = rows * cols;
    int board[size] = {0};


}

SinglePlayerGameState Twenty48::get_state() {
    // implementation here
}

int* Twenty48::get_valid_moves() {
    // implementation here
}

void Twenty48::apply_move(int move) {
    // implementation here
}
