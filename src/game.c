#include "game.h"

Game *
init_game (void)
{
  Game *game = malloc (sizeof (Game));

  game->running = true;
  game->vaus = init_vaus ();
  game->ball = init_ball ();

  populate_bricks_field (game->bricks);

  return game;
}

void
handle_event (Game *game)
{
  int c = getch ();
  switch (c)
    {
    case KEY_LEFT:
      move_left (game->vaus);
      break;
    case KEY_RIGHT:
      move_right (game->vaus);
      break;
    case 'q':
      game->running = false;
      break;
    default:
      break;
    }
}

void
update (Game *game)
{
  move_ball (game->ball, *game->vaus, game->bricks);
}

void
render (Game *game)
{
  // Start by erasing what was drawn
  erase ();

  draw_vaus (*game->vaus);
  draw_ball (*game->ball);
  draw_field (game->bricks);

  // Refresh to show updates
  refresh ();
}

void
cleanup (Game *game)
{
  free (game->vaus);
  free (game->ball);
}
