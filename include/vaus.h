#pragma once

#include <ncurses.h>
#include <stdlib.h>

typedef struct vaus_t
{
  int pos;
  int size;
} Vaus;

Vaus *init_vaus (void);
void draw_vaus (Vaus vaus);
void move_right (Vaus *vaus);
void move_left (Vaus *vaus);
