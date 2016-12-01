//
//	NerestPixel.cc		This file is a part of the IKAROS project
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


#include "NerestPixel.h"
#include <iostream>

using namespace ikaros;


void
NerestPixel::Init()
{

  input_matrix = GetInputMatrix("INPUT");

  output_matrix = GetOutputMatrix("OUTPUT");

  weight_output = GetOutputMatrix("WEIGHT");

}

void
NerestPixel::Tick()
{

  /* X-cordinate*/
  output_matrix[0][0]=input_matrix[0][0];
  /*Y-corndinate*/
  output_matrix[0][1]=input_matrix[0][1];

  output_matrix[0][2]=input_matrix[0][2];

  /*Weight is for the current output
  The weight is the same value as the depth-data*/
  weight_output[0][0]=input_matrix[0][2];


}

static InitClass init("NerestPixel", &NerestPixel::Create, "Source/UserModules/NerestPixel/");
