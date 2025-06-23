
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
    return i;
    
}

void Twenty48::place_random_tile() {

    int empty_tiles[rows*cols];
    int num_empty_tiles = get_empty_tiles(empty_tiles);

    std::random_device rd; // Obtain a random number from hardware
    std::mt19937 gen(rd()); // mersenne_twister_engine seeded with rd()
    std::uniform_int_distribution<> unif(0, num_empty_tiles-1);
    std::bernoulli_distribution bern(1-two_prob);

    int* board = game_state->get_board();

    int tile_location = empty_tiles[unif(gen)];
    int tile_value = bern(gen) + 1; // 2^(0+1) = 2, 2^(1+1) = 4

    board[tile_location] = tile_value;

}

bool Twenty48::move_tiles(int t1, int t2){
    //try to move and combine tiles. If destination tile is non-zero, return true
    int* board = game_state->get_board();
    std::unordered_map<std::string, float>& state_values = game_state->get_state_values();

        if(board[t2] != 0){
            if (board[t1] == 0){//destination is 0, move t2 to t1
                board[t1] = board[t2];
                board[t2] = 0;
                return false;
            }
            else if(board[t1] == board[t2]){//match, combine tiles and increment score
                board[t1]++;
                board[t2] = 0;
                state_values["Score"] += float(1 << board[t1]);
                return true;
            }
            else {return true;}
        }
        return false;
    }

bool Twenty48::check_tiles(int t1, int t2){
    //try to move and combine tiles. If valid move would have occured, return true. Does not actually perform move.
    int* board = game_state->get_board();
    std::unordered_map<std::string, float>& state_values = game_state->get_state_values();

        if(board[t2] != 0){
            if (board[t1] == 0){//destination is 0, move t2 to t1
                return true;
            }
            else if(board[t1] == board[t2]){//match, combine tiles and increment score
                return true;
            }
        }
        return false;
}

bool Twenty48::check_move(int move){
    // 0: RIGHT, 1: LEFT, 2:UP, 3:DOWN
    switch(move){
        case 0: //RIGHT
            for(int row = 0; row < rows; row++){
                for(int t1 = (row+1)*cols-1; t1 > row*cols; t1 -= 1) { // stop in second to last col
                    for(int t2 = t1 - 1; t2 > row*cols-1; t2 -=1){
                        if(check_tiles(t1, t2)){
                            return true;
                        }
                    }
                }
            }
            break;
        case 1: //LEFT
            for(int row = 0; row < rows; row++){
                for(int t1 = row*cols; t1 < (row+1)*cols; t1 += 1) { // stop in second to last col
                    for(int t2 = t1 + 1; t2 < (row+1)*cols+1; t2 +=1){
                        if(check_tiles(t1, t2)){
                            return true;
                        }
                    }
                }
            }
            break;
        case 2: //UP
            for(int col = 0; col < cols; col++){
                for(int t1 = col; t1 < ((rows-2)*cols + col + 1); t1 += cols) { // stop in second to last row
                    for(int t2 = t1 + cols; t2 < ((rows-1)*cols + col + 1); t2 += cols){
                        if(check_tiles(t1, t2)){
                            return true;
                        }
                    }
                }
            }
            break;
        case 3: //DOWN
            for(int col = 0; col < cols; col++){
                for(int t1 = (rows-1)*cols + col; t1 > cols+col-1; t1 -= cols) { // stop in second to last row
                    for(int t2 = t1 - cols; t2 >= col; t2 -= cols){
                        if(check_tiles(t1, t2)){
                            return true;
                        }
                    }
                }
            }
            break;
    }
    return false;
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

std::vector<int> Twenty48::get_valid_moves() {
    // 0: RIGHT, 1: LEFT, 2:UP, 3:DOWN
    std::vector<int> moves;
    for(int i = 0; i < 4; i++){
        if (check_move(i)){
            moves.push_back(i);
        }
    }
    return moves;
    
}

void Twenty48::apply_move(int move) {
    // 0: RIGHT, 1: LEFT, 2:UP, 3:DOWN
    switch(move){
        case 0: //RIGHT
            for(int row = 0; row < rows; row++){
                for(int t1 = (row+1)*cols-1; t1 > row*cols; t1 -= 1) { // stop in second to last col
                    for(int t2 = t1 - 1; t2 > row*cols-1; t2 -=1){
                        if(move_tiles(t1, t2)){
                            break;
                        }
                    }
                }
            }
            break;
        case 1: //LEFT
            for(int row = 0; row < rows; row++){
                for(int t1 = row*cols; t1 < (row+1)*cols; t1 += 1) { // stop in second to last col
                    for(int t2 = t1 + 1; t2 < (row+1)*cols+1; t2 +=1){
                        if(move_tiles(t1, t2)){
                            break;
                        }
                    }
                }
            }
            break;
        case 2: //UP
            for(int col = 0; col < cols; col++){
                for(int t1 = col; t1 < ((rows-2)*cols + col + 1); t1 += cols) { // stop in second to last row
                    for(int t2 = t1 + cols; t2 < ((rows-1)*cols + col + 1); t2 += cols){
                        if(move_tiles(t1, t2)){
                            break;
                        }
                    }
                }
            }
            break;
        case 3: //DOWN
            for(int col = 0; col < cols; col++){
                for(int t1 = (rows-1)*cols + col; t1 > cols+col-1; t1 -= cols) { // stop in second to last row
                    for(int t2 = t1 - cols; t2 >= col; t2 -= cols){
                        if(move_tiles(t1, t2)){
                            break;
                        }
                    }
                }
            }
            break;
    }
    place_random_tile();
    
}
