//    Copyright (C) 2012 <Daniel Myhrman>
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


#include "RandomBlob.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace ikaros;
using namespace std;

void
RandomBlob::Init()
{
  //Input
  input_matrix = GetInputMatrix("INPUT");
  input_matrix_size_x = GetInputSizeX("INPUT");
  input_matrix_size_y = GetInputSizeY("INPUT");

  //Output
  output_matrix = GetOutputMatrix("OUTPUT");

  //Weight
  weight_output = GetOutputMatrix("WEIGHT");

  std::srand(std::time(0));

  //Internal matrix
  internal_matrix = create_matrix(input_matrix_size_x, input_matrix_size_y);

  randomIndex = 0;
  //Tick counter

  tick_counter = 0;
}

RandomBlob::~RandomBlob()
{
  destroy_matrix(internal_matrix);
}

void RandomBlob::Tick()
{
  copy_matrix(internal_matrix, input_matrix, input_matrix_size_x, input_matrix_size_y);
  int amount = 0;
  //Blob amount and random index calculation
  if(tick_counter > (rand()%(60-30+1) + 30)){
    tick_counter = 0;
    amount = 0;
    for (int j=0; j<input_matrix_size_y; j++){
      if(internal_matrix[j][0] != -1.0){
        amount++;
      }
      else{
        break;
      }
    }
    randomIndex = (std::rand()%amount);
  }

  //Output and weight
  output_matrix[0][0] = internal_matrix[randomIndex][0];
  output_matrix[0][1] = internal_matrix[randomIndex][1];
  output_matrix[0][2] = internal_matrix[randomIndex][2];
  if(amount != 0){
    weight_output[0][0] = 1.0 - 1.0/(float)amount;
  }
  else{
    weight_output[0][0] = 0.0;
  }
}

static InitClass init("RandomBlob", &RandomBlob::Create, "Source/UserModules/RandomBlob/");
