
// Project: general_game_playing_agent
// File: src/games/twenty48.cpp
// Description: Implement 2048
// Author: Kyle McMaster
// Date: 2025-06-22

#include "general-game-playing-agent/games/twenty48.hpp"

#include <random>
#include <iostream>



Twenty48::Twenty48(int rows, int cols, float two_prob)
    : rows(rows), cols(cols), two_prob(two_prob) {
    initialize_game();
}

int Twenty48::get_empty_tiles(int *empty_tiles){
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

    int empty_tiles[rows*cols];
    int num_empty_tiles = get_empty_tiles(empty_tiles);

    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> unif(0, num_empty_tiles-1);
    std::bernoulli_distribution bern(1-two_prob);

    int* board = game_state->get_board();

    int tile_location = unif(gen);
    int tile_value = bern(gen) + 1; // 2^(0+1) = 2, 2^(1+1) = 4

    board[tile_location] = tile_value;

}

// Virtual function overrides
void Twenty48::initialize_game() {

    size_t size = rows * cols;
    std::unique_ptr<int[]> board = std::make_unique<int[]>(size);
    auto state_values = std::make_unique<std::unordered_map<std::string, float>>(
    std::unordered_map<std::string, float>{{"Score", 0.0f}});

    game_state = std::shared_ptr<SinglePlayerGameState>(
    new SinglePlayerGameState(std::move(board), rows, cols, std::move(state_values)));

    place_random_tile();
    place_random_tile();

    int* game_board = game_state->get_board();
}

std::shared_ptr<SinglePlayerGameState> Twenty48::get_state() {
    return game_state;
}

int* Twenty48::get_valid_moves() {
    // implementation here
}

void Twenty48::apply_move(int move) {
    // implementation here
}
