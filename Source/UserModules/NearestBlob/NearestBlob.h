//
//	MinimalModule.h		This file is a part of the IKAROS project
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


#ifndef NearestBlob_
#define NearestBlob_

#include "IKAROS.h"

class NearestBlob: public Module
{
public:
    static Module * Create(Parameter * p) { return new NearestBlob(p); }

    NearestBlob(Parameter * p) : Module(p) {}
    virtual ~NearestBlob();

    void 		Init();
    void 		Tick();

    float *     origin;

    float **    input_matrix;
    int         input_matrix_size_x;
    int         input_matrix_size_y;

    float **    output_matrix;
    int         output_matrix_size_x;
    int         output_matrix_size_y;

    float **    weight;

    float **    internal_matrix;

    float *     p1;

    float       maxdist;
};

#endif
