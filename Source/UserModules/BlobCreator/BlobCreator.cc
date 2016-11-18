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
}

BlobCreator::~BlobCreator()
{
  destroy_matrix(internal_matrix);
}

void
BlobCreator::Tick()
{
  copy_matrix(internal_matrix, input_matrix, input_matrix_size_x, input_matrix_size_y);
  for(int i = 0; i < input_matrix_size_y; i++){
    if(internal_matrix[3][i] >= internal_matrix[3][i+1]){
    }
  }
}


static InitClass init("BlobCreator", &BlobCreator::Create, "Source/UserModules/BlobCreator/");
