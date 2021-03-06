//
//	MyModule.cc		This file is a part of the IKAROS project
//
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
//  This example is intended as a starting point for writing new Ikaros modules
//  The example includes most of the calls that you may want to use in a module.
//  If you prefer to start with a clean example, use he module MinimalModule instead.
//


#include "Compressor.h"
#include <iostream>

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

  counter_matrix = create_matrix(58, 45);



}

Compressor::~Compressor()
{
  destroy_matrix(internal_matrix);
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



  while (i < 480) {
    while (j < 640){
      // std::cout << "i: ";
      // std::cout << i;
      // std::cout << "  ";
      // std::cout << "j: ";
      // std::cout << j;

      //std::cout << "\n";
      // Submatrix-work inside here
      float min = 999.0;
      float depth_sum = 0.0;
      int counter = 0;
      for(int k=i; k < i + 11 && k < 480; k++){
        for(int l=j; l < j+11 && l < 640; l++){
          // std::cout << "k: ";
          // std::cout << k;
          // std::cout << "  ";
          // std::cout << "l: ";
          // std::cout << l;
          //    std::cout << "\n";
          counter += 1;
          depth_sum += internal_matrix[k][l];
          if (internal_matrix[k][l] < min){
            min = internal_matrix[k][l];
          }
        }
      }
      float depth_elem = depth_sum / counter;
      //Submatrix end here
      if(out_x < 58 && out_y < 45)
      //Save max to output_matrix
      if (habituate > 0){
        background_matrix[out_y][out_x] += depth_elem; //min
      } else if(habituate == 0) {
        background_matrix[out_y][out_x] = background_matrix[out_y][out_x] / 24.0;
      } else {
        //output_matrix[out_y][out_x] = min;
        if(abs(depth_elem - background_matrix[out_y][out_x]) < 0.04){//min

          output_matrix[out_y][out_x] = depth_elem - background_matrix[out_y][out_x];//min


        } else {
          output_matrix[out_y][out_x] = min;
        }
        if(output_matrix[out_y][out_x] >= 1.0){
          output_matrix[out_y][out_x] = 0.0;
        }


        if(depth_elem != 0.0){
          counter_matrix[out_y][out_x] += 1.0;
        } else {
          counter_matrix[out_y][out_x] = 0.0;
        }
        if(counter_matrix[out_y][out_x] > 50.0){
          output_matrix[out_y][out_x] = min;//min
        } else {
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
  if(habituate == 0){
    habituate = -1;
  } else {
      habituate--;
  }


}


static InitClass init("Compressor", &Compressor::Create, "Source/UserModules/Compressor/");
