#pragma once

#include <ncurses.h>
#include <stdlib.h>

#define VAUS_COLOR 4

typedef struct vaus_t
{
  int pos;
  uint8_t size;
} Vaus;

Vaus *init_vaus (void);
void draw_vaus (Vaus vaus);
void move_right (Vaus *vaus);
void move_left (Vaus *vaus);
