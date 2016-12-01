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


#include "WatchSky.h"
#include <stdlib.h>
#include <iostream>
#include <ctime>

using namespace ikaros;
using namespace std;

void
WatchSky::Init()
{
  output_matrix = GetOutputMatrix("OUTPUT");
  weight_output = GetOutputMatrix("WEIGHT");
  tick_counter = 1;


  std::srand(std::time(0));

}

void WatchSky::Tick()
{
          if(tick_counter == 0){
          /* Generate two random cordinates and scales them to a valid scope */


          randx = (float)(rand()%(58) + 1.0);
          randy = (float)(rand()%(45) + 1.0);
          randr = (float)(rand()%(100-20+1) + 20);
          randr = (float)randr/100.0;

          tick_counter = (rand()%(60-30+1) + 30);
        }else {
          tick_counter--;
        }


          /* Insert the radom cordinates in the output_matrix
          witch is to be sent to the robot */
          output_matrix[0][0] = randx;
          output_matrix[0][1] = randy;
          output_matrix[0][2] = randr;
          weight_output[0][0] = 0.1;


}

static InitClass init("WatchSky", &WatchSky::Create, "Source/UserModules/WatchSky/");
