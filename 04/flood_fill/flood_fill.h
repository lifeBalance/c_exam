#ifndef FLOOD_FILL_H
#define FLOOD_FILL_H

#include "t_point.h"

void	flood_fill(char **tab, t_point size, t_point begin);
void	fill_row(char **tab, t_point begin);
void	fill_col(char **tab, t_point begin);

#endif