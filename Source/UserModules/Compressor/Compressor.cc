//
//	MyModule.cc		This file is a part of the IKAROS project
//
//    Copyright (C) 2012 <Johan Svensson, Shan Langlais>
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


#include "Compressor.h"
#include <iostream>
#include <algorithm>
#include <vector>

using namespace ikaros;


void
Compressor::Init()
{

  //The input-matrix from Kinect, containing raw depth-data
  input_matrix = GetInputMatrix("INPUT");
  input_matrix_size_x = GetInputSizeX("INPUT");
  input_matrix_size_y = GetInputSizeY("INPUT");

  //Output matrix to be sent out. A compressed version of the input matrix.
  output_matrix = GetOutputMatrix("OUTPUT");

  // Do we need an internal_matrix?
  internal_matrix = create_matrix(input_matrix_size_x, input_matrix_size_y);


  // Background stuff
  background_matrix = create_matrix(58, 45);
  habituate = 25;



}

Compressor::~Compressor()
{
  destroy_matrix(internal_matrix);
  destroy_matrix(background_matrix);
}

void
Compressor::Tick()
{
  // DISCLAIMER!
  // I have harcoded the input-depth-matix as 640x480 px, and
  // viewing angles   45 deg vertical & 58 deg horizontal.
  // If the input from the kincet-module is something else, this code needs to be modified.

  copy_matrix(internal_matrix, input_matrix, input_matrix_size_x, input_matrix_size_y);

  //Step the pixel-amount in the input_matrix
  int i = 0;
  int j = 0;
  int out_x = 0;
  int out_y = 0;
  float real_jump_x = 640.0/58.0;
  float real_jump_y = 480.0/45.0;
  float real_jump_x_cumul = real_jump_x;
  float real_jump_y_cumul = real_jump_y;
  int actual_jump_x = (int)real_jump_x;
  int actual_jump_y = (int)real_jump_y;

  while (i < 480) {
    while (j < 640){
      // Submatrix-work inside here
      float* values = new float[121];
      float median = 0;
      int ind = 0;
      int even = 0;

      for(int k=i; k < i + actual_jump_y && k < 480; k++){
        for(int l=j; l < j + actual_jump_x && l < 640; l++){
          values[ind] = internal_matrix[k][l];
          if (even % 2 == 0){
            ind += 1;
          }
          even += 1;
          real_jump_x_cumul += real_jump_x;
          if((int)real_jump_x_cumul % 11 == 1){
            actual_jump_x = 12;
            real_jump_x_cumul -= 1.0;
          } else {
            actual_jump_x = 11;
          }
        }
        real_jump_y_cumul += real_jump_y;
        if((int)real_jump_y_cumul % 11 == 1){
          actual_jump_y = 12;
          real_jump_y_cumul -= 1.0;
        } else {
          actual_jump_y = 11;
        }
      }
      median = sort(values, 60)[30];
      //Submatrix end here
      //DELETE THE MEMORY LEAK
      delete [] values;
      if(out_x < 58 && out_y < 45)
      //Save max to output_matrix
      if (habituate > 0){
        background_matrix[out_y][out_x] = median;
        if(background_matrix[out_y][out_x] >= 1.0){
          background_matrix[out_y][out_x] = 0.0;
        }
        if(background_matrix[out_y][out_x] <= 0.0){
          background_matrix[out_y][out_x] = 0.0;
        }
      } else {
        output_matrix[out_y][out_x] = median;
        if(abs(output_matrix[out_y][out_x] - background_matrix[out_y][out_x]) < 0.01){
          output_matrix[out_y][out_x] = output_matrix[out_y][out_x] - background_matrix[out_y][out_x];
        } else {
          output_matrix[out_y][out_x] = median;
        }
        if(output_matrix[out_y][out_x] >= 1.0){
          output_matrix[out_y][out_x] = 0.0;
        }
        if(output_matrix[out_y][out_x] <= 0.0){
          output_matrix[out_y][out_x] = 0.0;
        }
      }
      j=j+11;
      out_x++;
    }
    out_x = 0;
    out_y++;

    j = 0;
    i=i+11;
  }
  habituate--;
}


static InitClass init("Compressor", &Compressor::Create, "Source/UserModules/Compressor/");
