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

    void display(std::shared_ptr<SinglePlayerGameState> game_state) override;
};

#endif