// Project: general_game_playing_agent
// File: src/games/twenty48.cpp
// Description: Implement 2048
// Author: Kyle McMaster
// Date: 2025-06-22

#include "general-game-playing-agent/games/twenty48.hpp"
#include "general-game-playing-agent/utils/game_display.hpp"

int main() {

    Twenty48 game = Twenty48();
    SPTextDisplay disp = SPTextDisplay();

    disp.display(game.get_state());

}