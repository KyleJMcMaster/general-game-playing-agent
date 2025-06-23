#ifndef TWENTY48_HPP
#define TWENTY48_HPP

// Project: general_game_playing_agent
// File: include/general_game_playing_agent/twenty48.hpp
// Description: describe the interface for 2048
// Author: Kyle McMaster
// Date: 2025-06-22


#include "general-game-playing-agent/games/single_player_game.hpp"

class Twenty48 : public SinglePlayerGame {

    std::shared_ptr<SinglePlayerGameState> game_state;
    float two_prob; // probability of a 2 being placed after each turn. Standard game is 0.9. four_prob = 1 - two_prob
    int rows;
    int cols;

    void place_random_tile();
    int get_empty_tiles(int *tiles);

public:

    Twenty48(int rows = 4, int cols = 4, float two_prob = 0.9);
    SinglePlayerGameState initialize_game() override;
    SinglePlayerGameState get_state() override;
    int* get_valid_moves() override;
    void apply_move(int move) override;

};

#endif