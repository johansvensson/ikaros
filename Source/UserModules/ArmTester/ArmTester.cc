//
//	MinimalModule.cc		This file is a part of the IKAROS project
//
//    Copyright (C) 2012 <Author Name>
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


#include "ArmTester.h"

using namespace ikaros;

void
ArmTester::Init()
{
  goal_matrix = GetInputMatrix("GOAL_POSITION");
  present_matrix = GetInputMatrix("PRESENT_POSITION");
  output_pos = GetOutputArray("GOAL_POSITION_OUTPUT");
  output_speed = GetOutputArray("GOAL_SPEED_OUTPUT");
}

void
ArmTester::Tick()
{
  output_pos[0] = 360.0 - (goal_matrix[0][0] + 90.0);
  output_pos[1] = 135.0 - (goal_matrix[0][1]/2);
  output_pos[2] = 135.0 - (goal_matrix[0][1]/2);

  output_speed[0] = 0.5;
  output_speed[1] = 0.5;
  output_speed[2] = 0.5;
}

static InitClass init("ArmTester", &ArmTester::Create, "Source/UserModules/ArmTester/");
