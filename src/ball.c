#include "ball.h"

Ball *
init_ball (void)
{
  Ball *ball = malloc (sizeof (Ball));

  ball->x = COLS / 2;  // middle of screen
  ball->y = LINES - 2; // on top of Vaus

  ball->v_x = 1;
  ball->v_y = 1;

  ball->format = "O";

  return ball;
}

bool
ball_within_x (Ball *ball, int x1, int x2)
{
  return ball->x >= x1 && ball->x < x2;
}

bool
ball_within_y (Ball *ball, int y1, int y2)
{
  return ball->y >= y1 && ball->y < y2;
}

void
move_ball (Ball *ball, Vaus vaus, Bricks bricks)
{
  Brick *current_brick;

  // Bounce on left/right of screen
  if (ball->x > COLS || ball->x < 0)
    {
      ball->v_x *= -1;
    }

  // Bounce on top of screen
  if (ball->y < 0)
    {
      ball->v_y *= -1;
    }

  // Bounce on Vaus if it's here
  if (ball->y > LINES - 3)
    {
      if (ball_within_x (ball, vaus.pos, vaus.pos + vaus.size))
        {
          ball->v_y *= -1;
        }
    }

  // Bounce on brick
  for (size_t i = 0; i < MAX_BRICKS; i++)
    {
      current_brick = &bricks[i];
      if (current_brick->state == 0)
        continue;

      // Hitting on top or bottom
      if (ball_within_x (ball, current_brick->x - 1,
                         current_brick->x + BRICK_LENGTH_FACTOR + 1))
        {
          if (ball->y == current_brick->y - 1
              || ball->y == current_brick->y + BRICK_HEIGHT_FACTOR)
            {
              hit_brick (current_brick);
              ball->v_y *= -1;
            }
        }

      // Hiiting on the sides
      if (ball_within_y (ball, current_brick->y,
                         current_brick->y + BRICK_HEIGHT_FACTOR))
        {
          if (ball->x == current_brick->x - 1
              || ball->x == current_brick->x + BRICK_LENGTH_FACTOR)
            {
              hit_brick (current_brick);
              ball->v_x *= -1;
            }
        }
    }

  // Continue movement
  ball->x += ball->v_x;
  ball->y += ball->v_y;
}

void
draw_ball (Ball ball)
{
  mvprintw (ball.y, ball.x, ball.format);
}
