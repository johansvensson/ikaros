//    Copyright (C) 2012 <Johan Svensson>
//
//    This program is free software; you can redistribute it and/or modify
//    it under the terms of the GNU General Public License as published by
//    the Free Software Foundation; either version 2 of the License, or
//    (at your option) any later version.
//
//    This program is distributed in the hope that it will be useful,
//    but WITHOUT ANY WARRANTY; without even the implied warranty of
//    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//    GNU General Public License for more details.
//
//    You should have received a copy of the GNU General Public License
//    along with this program; if not, write to the Free Software
//    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
//
//    See http://www.ikaros-project.org/ for more information.
//


#include "WatchRandom.h"
#include <stdlib.h>

using namespace ikaros;

void
WatchRandom::Init()
{
  input_matrix = GetInputMatrix("INPUT");
  input_matrix_size_x = GetInputSizeX("INPUT");
  input_matrix_size_y = GetInputSizeY("INPUT");

  output_matrix = GetOutputMatrix("OUTPUT");
  output_matrix_size_x = GetOutputSizeX("OUTPUT");
  output_matrix_size_y = GetOutputSizeY("OUTPUT");


  internal_matrix = create_matrix(input_matrix_size_x, input_matrix_size_y);
}

WatchRandom::~WatchRandom()
{
    destroy_matrix(internal_matrix);
}

void
WatchRandom()
{
    copy_matrix(internal_matrix, input_matrix, input_matrix_size_x, input_matrix_size_y);
    for (int j=0; j<output_matrix_size_y; j++)
        for (int i=0; i<output_matrix_size_x; i++)
              output_matrix[j][i] = -1;

/* count the amount of valid points in matrix */
    int amount = 0;
    while(internal_matrix[0][amount] != 0){
      amount++;
    }

    /* random int between 0 and amount  */
    int random = rand() % amount;

/* Inserting the the random point from internal_matrix to output_matrix */
    output_matrix[0][0] = internal_matrix[random][0];
    output_matrix[0][1] = internal_matrix[random][1];

}

static InitClass init("WatchRandom", &WatchRandom::Create, "Source/UserModules/WatchRandom/");
