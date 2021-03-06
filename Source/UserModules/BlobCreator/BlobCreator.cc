//
//	BlobCreator.cc		This file is a part of the IKAROS project
//
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
//  This example is intended as a starting point for writing new Ikaros modules
//  The example includes most of the calls that you may want to use in a module.
//  If you prefer to start with a clean example, use he module medianimalModule instead.
//


#include "BlobCreator.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace ikaros;


void
BlobCreator::Init()
{
  input_matrix = GetInputMatrix("INPUT");
  input_matrix_size_x = GetInputSizeX("INPUT");
  input_matrix_size_y = GetInputSizeY("INPUT");

  output_matrix = GetOutputMatrix("OUTPUT");
  output_matrix_size_x = GetOutputSizeX("OUTPUT");
  output_matrix_size_y = GetOutputSizeY("OUTPUT");

  output_matrix_tracker = GetOutputMatrix("OUTPUT_TRACKER_POS");
  output_matrix_tracker_size_x = GetOutputSizeX("OUTPUT_TRACKER_POS");
  output_matrix_tracker_size_y = GetOutputSizeY("OUTPUT_TRACKER_POS");

  internal_matrix = create_matrix(input_matrix_size_x, input_matrix_size_y);
  internal_matrix_size_x = input_matrix_size_x;
  internal_matrix_size_y = input_matrix_size_y;

  output_matrix_distance = GetOutputMatrix("DISTANCE");
}

BlobCreator::~BlobCreator()
{
  destroy_matrix(internal_matrix);
}

void
BlobCreator::Tick()
{
  copy_matrix(internal_matrix, input_matrix, input_matrix_size_x, input_matrix_size_y);
  float temp = 10.0;
  bool flag = true;

  float min = 1.0;
  float filter = 0.0;

  for (int i = 0; i < internal_matrix_size_y; i++){
    for (int j = 0; j < internal_matrix_size_x; j++){
      if (internal_matrix[j][i] < min)
        min = internal_matrix[j][i];
    }
  }

  if(min <= 0.0 || min >= 1.0){
    min = 1.0;
  }

  filter = -45.0 * min + 50.0;

  output_matrix_distance[0][0] = min;



  // for (int i = 0; i < input_matrix_size_y; i++){
  //   if(input_matrix[i][1] == 0.0){
  //     input_matrix[i][0] = -1.0;
  //     input_matrix[i][1] = -1.0;
  //   }
  //   //output_matrix[k][2] = -1.0;
  // }

  //Sort y in ascending order
  while(flag){
    flag = false;
    for(int i = 0; i < input_matrix_size_y - 1; i++){
      if(internal_matrix[i][1] > internal_matrix[i+1][1] && internal_matrix[i+1][1] != -1.0){
        temp = internal_matrix[i][1];
        internal_matrix[i][1] = internal_matrix[i+1][1];
        internal_matrix[i+1][1] = temp;
        flag = true;
      }
    }
  }

  //Set all x doubles (or more) to -1
  for(int i = 0; i < internal_matrix_size_y; i++){
    temp = (float)internal_matrix[i][0];
    for(int j = i+1; j < internal_matrix_size_y; j++){
      //specication of selection
      if(filter > fabs(temp - internal_matrix[j][0]) || internal_matrix[j][1] == 0.0){
        internal_matrix[j][0] = -1.0;
        internal_matrix[j][1] = -1.0;
        internal_matrix[j][2] = -1.0;
      }
    }
  }
  //Fill output_matrix
  int k = 0;
  for (int j = 0; j < internal_matrix_size_y; j++){
    if(internal_matrix[j][0] != -1.0 && internal_matrix[j][1] != -1.0){
      output_matrix[k][0] = (float)internal_matrix[j][0]; //for visualization
      output_matrix[k][1] = (float)internal_matrix[j][1]; // this too
      output_matrix[k][2] = (float)internal_matrix[j][2];
      k++;
    }
  }

  for (int i = k; i < output_matrix_size_y; i++){
    output_matrix[i][0] = -1.0;
    output_matrix[i][1] = -1.0;
    output_matrix[i][2] = -1.0;
  }

  while(flag){
    flag = false;
    for(int i = 0; i < output_matrix_size_y - 1; i++){
      if(output_matrix[i][2] > output_matrix[i+1][2] && output_matrix[i+1][2] != -1.0){
        temp = output_matrix[i][2];
        output_matrix[i][2] = output_matrix[i+1][2];
        output_matrix[i+1][2] = temp;
        flag = true;
      }
    }
  }

  for (int i = 0; i < output_matrix_size_y; i++){
    output_matrix_tracker[i][0] = output_matrix[i][0] / 58.0;
    output_matrix_tracker[i][1] = output_matrix[i][1] / 45.0;
    output_matrix_tracker[i][2] = output_matrix[i][2] / 1.0;
  }

}
static InitClass init("BlobCreator", &BlobCreator::Create, "Source/UserModules/BlobCreator/");
