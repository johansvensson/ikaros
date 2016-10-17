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
  output_matrix_size_x = GetOutputSizeX("OUTPUT");
  output_matrix_size_y = GetOutputSizeY("OUTPUT");

// Do we need an internal_matrix?
  internal_matrix = create_matrix(input_matrix_size_x, input_matrix_size_y);
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
  for(int i = 0; i < input_matrix_size_x; i++){
    for(int j = 0; j < input_matrix_size_y; j++){

      //Calculate a mid-value for all the pixels in the small part of the matrix



    }
  }

}


static InitClass init("Compressor", &Compressor::Create, "Source/UserModules/Compressor/");
