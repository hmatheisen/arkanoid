#include "brick.h"

BrickState level_1[MAX_BRICKS_LINES][MAX_BRICKS_COLS]
    = { { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 3, 2, 2, 2, 2, 3, 0, 0, 0, 0, 0, 0, 1 },
        { 3, 3, 0, 0, 0, 0, 0, 3, 1, 1, 1, 1, 3, 0, 0, 0, 0, 0, 3, 3 },
        { 2, 2, 2, 0, 0, 0, 0, 3, 1, 1, 1, 1, 3, 0, 0, 0, 0, 2, 2, 2 },
        { 1, 1, 1, 1, 0, 0, 0, 3, 2, 2, 2, 2, 3, 0, 0, 0, 1, 1, 1, 1 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 } };

void
populate_bricks_field (Bricks bricks)
{
  int index, y, x;
  //  Add padding to center bricks field
  int padding = (COLS - MAX_BRICKS_COLS * BRICK_LENGTH_FACTOR) / 2;

  for (size_t i = 0; i < MAX_BRICKS_LINES; i++)
    {
      for (size_t j = 0; j < MAX_BRICKS_COLS; j++)
        {
          y = i * BRICK_HEIGHT_FACTOR;
          x = j * BRICK_LENGTH_FACTOR + padding;
          index = i * MAX_BRICKS_COLS + j; // Transform 2d to 1d index

          bricks[index] = init_brick (y, x, level_1[i][j]);
        }
    }
}

Brick
init_brick (int y, int x, BrickState state)
{
  Brick *brick = malloc (sizeof (Brick));

  brick->x = x;
  brick->y = y;
  brick->state = state;

  return *brick;
}

void
draw_brick (Brick brick)
{
  attron (COLOR_PAIR (brick.state));
  for (size_t i = 0; i < BRICK_HEIGHT_FACTOR; i++)
    {
      for (size_t j = 0; j < BRICK_LENGTH_FACTOR; j++)
        {
          if (brick.state != 0)
            {
              mvprintw (brick.y + i, brick.x + j, " ");
            }
        }
    }
  attroff (COLOR_PAIR (brick.state));
}

void
draw_field (Bricks bricks)
{
  for (size_t i = 0; i < MAX_BRICKS; i++)
    {
      draw_brick (bricks[i]);
    }
}

void
hit_brick (Brick *brick)
{
  if (brick->state == DEAD)
    {
      return;
    }

  brick->state--;
}
