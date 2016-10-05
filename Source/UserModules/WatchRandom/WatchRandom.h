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


#ifndef WatchRandom_
#define WatchRandom_

#include "IKAROS.h"

class WatchRandom: public Module
{
public:
    static Module * Create(Parameter * p) { return new WatchRandom(p); }

    WatchRandom(Parameter * p) : Module(p) {}
    virtual ~WatchRandom();

    void 		Init();
    void 		Tick();

    float **    input_matrix;
    int         input_matrix_size_x;
    int         input_matrix_size_y;

    float **    output_matrix;
    int         output_matrix_size_x;
    int         output_matrix_size_y;

    float **    internal_matrix;

    int         amount;
    int         random;


};

#endif
