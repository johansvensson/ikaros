//
//	MyModule.cc		This file is a part of the IKAROS project
//
//    Copyright (C) 2012 <Shan Langlais>
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


#include "BlobSearch.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace ikaros;


void
BlobSearch::Init()
{

  //The input-matrix from Kinect, containing raw depth-data
  input_matrix = GetInputMatrix("INPUT");
  input_matrix_size_x = GetInputSizeX("INPUT");
  input_matrix_size_y = GetInputSizeY("INPUT");

  //Output matrix to be sent out. A compressed version of the input matrix.
  output_matrix = GetOutputMatrix("OUTPUT");
  output_matrix_size_x = GetOutputSizeX("OUTPUT");
  output_matrix_size_y = GetOutputSizeY("OUTPUT");

  kernel_size = 7;
}

void
BlobSearch::Tick()
{
  bool flag = false;
  for (int i = 0; i < output_matrix_size_x; i++){
    for (int j = 0; j < output_matrix_size_y; j++){
      output_matrix[j][i] = -1.0;
    }
  }
  int output_ind = 0;
  for(int i = (kernel_size)/2 + 1; i < input_matrix_size_y - (kernel_size)/2 - 1; i++){
    for(int j = (kernel_size)/2 + 1; j < input_matrix_size_x - (kernel_size)/2 - 1; j++){
      int foreground_pixels = 0;
      for(int k = i - kernel_size/2 - 1; k < i + kernel_size/2 + 1; k++){
        for(int l = j - kernel_size/2 - 1; l < j + kernel_size/2 + 1; l++){
          if(input_matrix[k][l] > 0.05){
            foreground_pixels++;
          }
        }
      }
      if(foreground_pixels > kernel_size*kernel_size/2 + 1 && input_matrix[i][j] > 0.05){
        output_matrix[output_ind][0] = (float)j;
        output_matrix[output_ind][1] = (float)i;
        output_matrix[output_ind][2] = (float)input_matrix[i][j];
        if(output_ind < 998){
          output_ind++;
        } else {
          output_ind = 0;
          flag = true;
        }
      }
    }
  }
  if(!flag){
      for (int i = output_ind; i < output_matrix_size_y; i++){
        for (int j = 0; j < output_matrix_size_x; j++){
          output_matrix[i][j] = -1.0;
        }
      }
  }

}


static InitClass init("BlobSearch", &BlobSearch::Create, "Source/UserModules/BlobSearch/");
