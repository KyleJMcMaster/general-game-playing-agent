
// Project: general_game_playing_agent
// File: src/games/twenty48.cpp
// Description: Implement 2048
// Author: Kyle McMaster
// Date: 2025-06-22

#include "include/general-game-playing-agent/games/twenty48.hpp"

#include <random>



Twenty48::Twenty48(int rows, int cols, float two_prob)
    : rows(rows), cols(cols), two_prob(two_prob) {
    // constructor body (not shown)
}

int Twenty48::get_empty_tiles(int* empty_tiles){
    // return the number of empty tiles. Modify empty_tiles to contain the indicies of the empty tiles

    int* board = game_state->get_board();
    int i = 0;
    for(int j = 0; j < rows*cols; j++){
        if(board[j] == 0){
            empty_tiles[i] = j;
            i++;
        }
    }
}

void Twenty48::place_random_tile() {

    int* empty_tiles[rows*cols];
    int num_empty_tiles = get_empty_tiles(*empty_tiles);

    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> unif(0, num_empty_tiles-1);
    std::bernoulli_distribution bern(two_prob);

    int* board = game_state->get_board();

    int tile_location = unif(gen);
    int tile_value = bern(gen) + 1; // 2^(0+1) = 2, 2^(1+1) = 4

    board[tile_location] = tile_value;
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
