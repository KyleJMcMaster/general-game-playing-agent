// Project: general_game_playing_agent
// File: src/games/twenty48.cpp
// Description: Implement 2048
// Author: Kyle McMaster
// Date: 2025-06-22

#include "general-game-playing-agent/games/twenty48.hpp"
#include "general-game-playing-agent/utils/game_display.hpp"

#include <iostream>

int main() {

    Twenty48 game = Twenty48();
    SPTextDisplay disp = SPTextDisplay();

    disp.display(game.get_state());

    for (int i = 0; i < 10; i++){
        std::cout<<i%4<<"\n";
        game.apply_move(0);
        disp.display(game.get_state());
        game.apply_move(2);
        disp.display(game.get_state());
    }


}