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
#include <iostream>

using namespace ikaros;
using namespace std;

void
WatchRandom::Init()
{
  input_matrix = GetInputMatrix("INPUT");
  input_matrix_size_x = GetInputSizeX("INPUT");
  input_matrix_size_y = GetInputSizeY("INPUT");

  output_matrix = GetOutputMatrix("OUTPUT");
  output_matrix_size_x = GetOutputSizeX("OUTPUT");
  output_matrix_size_y = GetOutputSizeY("OUTPUT");

  weight_output = GetOutputMatrix("WEIGHT");

  tick_counter = 0;
  random = 0;
  randx = 0;
  randy = 0;


  internal_matrix = create_matrix(input_matrix_size_x, input_matrix_size_y);
}

WatchRandom::~WatchRandom()
{
    destroy_matrix(internal_matrix);
}

void WatchRandom::Tick()
{
    copy_matrix(internal_matrix, input_matrix, input_matrix_size_x, input_matrix_size_y);
    //Set all in output_matrix to -1
    for (int j=0; j<output_matrix_size_y; j++)
        for (int i=0; i<output_matrix_size_x; i++)
              output_matrix[j][i] = -1.0;
    tick_counter++;
    int amount = 0;
    if(tick_counter > (rand()%(60-30+1) + 30)){
          tick_counter = 0;
          /* count the amount of valid points in matrix */
          for (int j=0; j<input_matrix_size_y;j++){
            if(internal_matrix[j][0] != -1.0){
              amount++;
            }
          }
          /* random int between 0 and amount  */
          random = (int)rand()%(amount+1);

    }

    //Calculate weight
    float weight = 0.0;
    weight = 1.0 - 1.0/amount;
    weight_output[0][0] = weight;
    /* Inserting the the random point from internal_matrix to output_matrix */
    if(amount > 0){
      output_matrix[0][0] = internal_matrix[random][0];
      output_matrix[0][1] = internal_matrix[random][1];
      //output_matrix[0][2] = weight;
    }


}

static InitClass init("WatchRandom", &WatchRandom::Create, "Source/UserModules/WatchRandom/");
