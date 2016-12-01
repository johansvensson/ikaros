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


#include "FastMovement.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace ikaros;

void
FastMovement::Init()
{
  //Input
  input_matrix = GetInputMatrix("INPUT");
  input_matrix_size_x = GetInputSizeX("INPUT");
  input_matrix_size_y = GetInputSizeY("INPUT");
  //Matrix from ChangeDetector
  change_matrix = GetInputMatrix("INPUT");
  change_matrix_size_x = GetInputSizeX("INPUT");
  change_matrix_size_y = GetInputSizeY("INPUT");
  //Output
  output_matrix = GetOutputMatrix("OUTPUT");

  //Weight
  weight_output = GetOutputMatrix("WEIGHT");
}

void FastMovement::Tick()
{
  int change = 0;
  for (int j=0; j<change_matrix_size_y; j++){
    for (int i=0; i<change_matrix_size_x; i++){
      if(change_matrix[j][i] > temp){
        change = input_matrix[j][i];
        output_matrix[0][0] = input_matrix[j][0];
        output_matrix[0][1] = input_matrix[j][1];
        output_matrix[0][2] = input_matrix[j][2];
      }
    }
  }

  weight_output[0][0] = change;
}

static InitClass init("FastMovement", &FastMovement::Create, "Source/UserModules/FastMovement/");
