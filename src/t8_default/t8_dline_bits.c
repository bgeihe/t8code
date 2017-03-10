/*
  This file is part of t8code.
  t8code is a C library to manage a collection (a forest) of multiple
  connected adaptive space-trees of general element classes in parallel.

  Copyright (C) 2015 the developers

  t8code is free software; you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation; either version 2 of the License, or
  (at your option) any later version.

  t8code is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with t8code; if not, write to the Free Software Foundation, Inc.,
  51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
*/

#include "t8_default_common.h"
#include "t8_dline_bits.h"

int
t8_dline_get_level (const t8_dline_t * l)
{
  return l->level;
}

void
t8_dline_copy (const t8_dline_t * l, t8_dline_t * dest)
{
  memcpy (dest, l, sizeof (t8_dline_t));
}

void
t8_dline_parent (const t8_dline_t * l, t8_dline_t * parent)
{
  t8_dline_coord_t    h;

  T8_ASSERT (l->level > 0);

  /* Get the length of l */
  h = T8_DLINE_LEN (l->level);

  /* Set coordinates of parent */
  parent->x = l->x & ~h;
  /* Set the parent's level */
  parent->level = l->level - 1;
}
