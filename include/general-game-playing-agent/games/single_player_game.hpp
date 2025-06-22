#ifndef SINGLE_PLAYER_GAME_HPP
#define SINGLE_PLAYER_GAME_HPP

// Project: general_game_playing_agent
// File: include/general_game_playing_agent/single_player_game.hpp
// Description: describe the interface for single player games
// Author: Kyle McMaster
// Date: 2025-06-22

#include <unordered_map>
#include <string>
#include <memory>

class SinglePlayerGameState {

    std::unique_ptr<int[]> board;
    size_t rows;
    std::unique_ptr<std::unordered_map<std::string, float>> state_values;

public:

    SinglePlayerGameState(std::unique_ptr<int[]>& board, size_t rows, std::unique_ptr<std::unordered_map<std::string, float>> state_values)
        : board(std::move(board)), rows(rows), state_values(std::move(state_values)) {}

    int* get_board(){return board.get();}
    size_t get_rows(){return rows;}
    std::unordered_map<std::string, float>* get_state_values(){return state_values.get();}

};

class SinglePlayerGame {
public:

    virtual SinglePlayerGameState initialize_game();
    virtual SinglePlayerGameState get_state();
    virtual int* get_valid_moves();
    virtual void apply_move(int move);
};


#endif