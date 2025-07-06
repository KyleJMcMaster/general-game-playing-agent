### July 6th, 2025

Working on MDP estimation model to learn the transition matrix. First attempt is to try a GPT style model which is trained on games played by the model.

Will need to determine how to best tokenize game states for general MDP games. My first thought for 2048 is to make each row a token, but this might not generalize well for games with very large boards. For now, I plan to start with character-level tokens.

I will experiment in python first, and then rebuild the model in c++ when I'm happy with the structure.

### June 22nd, 2025

Started project organization.
Going to focus on single player games and interface to start.

Built 2048.