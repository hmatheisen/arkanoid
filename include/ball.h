#pragma once

#include <ncurses.h>
#include <stdlib.h>
#include "vaus.h"
#include "brick.h"

typedef struct ball_t
{
  float x, y;     // position
  float v_x, v_y; // velocity
  char *format;   // looks
} Ball;

Ball *init_ball (void);
void draw_ball (Ball ball);
void move_ball (Ball *ball, Vaus vaus, Bricks bricks);
