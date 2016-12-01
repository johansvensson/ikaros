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


#include "PolarToCartesian.h"
#include <stdlib.h>
#include <cmath>

using namespace ikaros;
using namespace std;

void
PolarToCartesian::Init()
{
  //(phi, theta, r)
  input_matrix = GetInputMatrix("INPUT");

  output_matrix = GetOutputMatrix("OUTPUT");

  output_matrix_x = GetOutputMatrix("OUTPUT_X");
  output_matrix_y = GetOutputMatrix("OUTPUT_Y");
  output_matrix_z = GetOutputMatrix("OUTPUT_Z");

  output_matrix_xy = GetOutputMatrix("OUTPUT_XY");
  output_matrix_yz = GetOutputMatrix("OUTPUT_YZ");
}

void PolarToCartesian::Tick()
{
  float sin_phi = (float) sin(input_matrix[0][0] * (3.1415)/180.0);
  float sin_theta = (float) sin(input_matrix[0][1] * (3.1415)/180.0);
  float cos_phi = (float) cos(input_matrix[0][0] * (3.1415)/180.0);
  float cos_theta = (float) cos(input_matrix[0][1] * (3.1415)/180.0);
  float r = (float) input_matrix[0][2];

  float x = r*sin_theta*cos_phi;
  float y = r*sin_theta*sin_phi;
  float z = r*cos_phi;
  output_matrix[0][0] = x;
  output_matrix[0][1] = y;
  output_matrix[0][2] = z;

  output_matrix_x[0][0] = x;
  output_matrix_y[0][0] = y;
  output_matrix_z[0][0] = z;

  output_matrix_xy[0][0] = x;
  output_matrix_xy[0][1] = y;
  output_matrix_yz[0][0] = y;
  output_matrix_yz[0][1] = z;
}
static InitClass init("PolarToCartesian", &PolarToCartesian::Create, "Source/UserModules/PolarToCartesian/");
