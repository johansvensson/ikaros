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

  internal_matrix = create_matrix(input_matrix_size_x, input_matrix_size_y);
  temp = 0;
  flag = true;
}

BlobCreator::~BlobCreator()
{
  destroy_matrix(internal_matrix);
}

void
BlobCreator::Tick()
{
  copy_matrix(internal_matrix, input_matrix, input_matrix_size_x, input_matrix_size_y);
//Sort y in ascending order
  while(flag){
    flag = false;
    for(int i = 0; i < input_matrix_size_y - 1; i++){
      if(internal_matrix[1][i] > internal_matrix[1][i+1]){
        temp = internal_matrix[1][i];
        internal_matrix[1][i] = internal_matrix[1][i+1];
        internal_matrix[1][i+1] = temp;
        flag = true;
      }
    }
  }

  //Set all x doubles (or more) to -1
  for(int i = 0; i < internal_matrix_size_y; i++){
    temp = internal_matrix[0][i];
    for(int j = i+1; j < internal_matrix_size_y; j++){
      //specication of selection
      if(internal_matrix[0][j] == temp){
        internal_matrix[0][j] = -1;
      }
    }
  }
  //Fill output_matrix (möjligt problem: skapar tomma rader i output tror jag)
  for (int i = 0; i < output_matrix_size_x; i++){
    for (int j = 0; j < output_matrix_size_y; j++){
      if(internal_matrix[0][j] != -1){
      output_matrix[i][j] = internal_matrix[i][j];
      }
    }
  }

}
static InitClass init("BlobCreator", &BlobCreator::Create, "Source/UserModules/BlobCreator/");
