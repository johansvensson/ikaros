//
//	Compressor.h		This file is a part of the IKAROS project
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


#ifndef Compressor_
#define Compressor_

#include "IKAROS.h"

class Compressor: public Module
{
public:
    static Module * Create(Parameter * p) { return new Compressor(p); }

    Compressor(Parameter * p) : Module(p) {}
    virtual ~Compressor();

    void 		Init();
    void 		Tick();

    float **    input_matrix;
    int         input_matrix_size_x;
    int         input_matrix_size_y;
    int         habituate;

    float **    output_matrix;
    float **    background_matrix;
    float **    internal_matrix;

};

#endif
