#pragma once

#include <ncurses.h>
#include <stdlib.h>

#define MAX_BRICKS_LINES 10
#define MAX_BRICKS_COLS 20
#define MAX_BRICKS MAX_BRICKS_COLS*MAX_BRICKS_LINES

static const int BRICK_LENGTH_FACTOR = 9;
static const int BRICK_HEIGHT_FACTOR = 2;

typedef enum State
{
  DEAD,
  GREEN,
  YELLOW,
  RED
} BrickState;

typedef struct brick_t
{
  int x, y; // position
  BrickState state;
} Brick;

typedef Brick Bricks[MAX_BRICKS];

Brick init_brick (int y, int x, BrickState state);
void draw_field (Bricks bricks);
void populate_bricks_field (Bricks bricks);
void hit_brick (Brick *brick);
