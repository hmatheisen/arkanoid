#pragma once

#include <stdlib.h>
#include <ncurses.h>
#include "vaus.h"
#include "brick.h"
#include "ball.h"

typedef struct game_t
{
  bool running;

  Vaus *vaus;
  Ball *ball;
  Bricks bricks;
} Game;

Game *init_game (void);
void handle_event (Game *game);
void update (Game *game);
void render (Game *game);
void cleanup (Game *game);
