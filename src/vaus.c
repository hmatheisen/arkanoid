#include "vaus.h"

const int MOVE_SIZE = 4;

Vaus *
init_vaus (void)
{
  Vaus *vaus = malloc (sizeof (Vaus));
  vaus->size = 25;
  vaus->pos = (COLS / 2) - (vaus->size / 2); // Put Vaus at the center

  return vaus;
}

void
draw_vaus (Vaus vaus)
{
  attron (COLOR_PAIR (4));
  for (size_t i = 0; i < vaus.size; i++)
    {
      mvprintw (LINES - 1, vaus.pos + i, " ");
    }
  attroff (COLOR_PAIR (4));
}

void
move_left (Vaus *vaus)
{
  if (vaus->pos - MOVE_SIZE < 0)
    {
      vaus->pos = 0;
      return;
    }

  vaus->pos -= MOVE_SIZE;
}

void
move_right (Vaus *vaus)
{
  if (vaus->pos + vaus->size + MOVE_SIZE > COLS)
    {
      vaus->pos = COLS - vaus->size - 1;
      return;
    }

  vaus->pos += MOVE_SIZE;
}
