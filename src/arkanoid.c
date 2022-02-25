#include <ncurses.h>
#include <time.h>
#include <unistd.h>

#include "game.h"

const int FPS = 60;
const double DELAY_TIME = 1000.0 / FPS;

void
init_curses (void)
{
  // Init ncurses
  initscr ();
  cbreak ();
  noecho ();
  // Make getch non blocking
  nodelay (stdscr, true);
  // Enable key pad
  keypad (stdscr, true);
  // Don't show cursor
  curs_set (false);

  // init colors
  start_color ();
  // Brick Colors
  init_pair (1, COLOR_BLACK, COLOR_GREEN);
  init_pair (2, COLOR_BLACK, COLOR_YELLOW);
  init_pair (3, COLOR_BLACK, COLOR_RED);
  // Vaus Color
  init_pair (4, COLOR_BLACK, COLOR_WHITE);
  // Clear screen
  clear ();
}

double
clocks_to_ms (clock_t clocks)
{
  return (clocks / (double)CLOCKS_PER_SEC) * 1000.0;
}

int
main (void)
{
  clock_t frame_start, frame_time;
  int frame_time_ms;

  srand (time (0));

  init_curses ();
  Game *game = init_game ();

  while (game->running)
    {
      frame_start = clock ();

      handle_event (game);
      update (game);
      render (game);

      frame_time = clock () - frame_start;
      frame_time_ms = clocks_to_ms (frame_time);

      if (frame_time_ms < DELAY_TIME)
        {
          usleep ((DELAY_TIME - frame_time_ms) * 1000);
        }
    }

  cleanup (game);
  endwin ();

  return 0;
}
