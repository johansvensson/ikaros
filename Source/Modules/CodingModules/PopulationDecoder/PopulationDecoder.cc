//
//	PopulationDecoder.cc	This file is a part of the IKAROS project
//
//
//    Copyright (C) 2016  Christian Balkenius
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


#include "PopulationDecoder.h"

using namespace ikaros;


void
PopulationDecoder::SetSizes()
{
//    size_x  =   GetInputSizeX("INPUT");
    size_y  =   GetInputSizeY("INPUT");

    if (size_y != unknown_size)
    {
        SetOutputSize("OUTPUT", size_y);
        SetOutputSize("AMPLITUDE", size_y);
    }
}


void
PopulationDecoder::Init()
{
    size_x          =   GetInputSizeX("INPUT");
    size_y          =   GetInputSizeY("INPUT");
    min             =   GetFloatValue("min");
    max             =   GetFloatValue("max");
    
    input = GetInputMatrix("INPUT");
    output = GetOutputArray("OUTPUT");
    amplitude = GetOutputArray("AMPLITUDE");
}



static float
decode_population_code(float * x, int size, float min, float max)
{
    float s = 0;
    float w = 0;
    for(int i=0; i<size; i++)
    {
        s += x[i] * (min + (max-min)*(float(i)/(size-1)));
        w += x[i];
    }
    
    if(w > 0)
    {
        float c = s/w;
        return c;
    }
    else
    {
        return (max-min)/2;
    }
}


void
PopulationDecoder::Tick()
{
    for(int j=0; j<size_y; j++)
    {
        output[j] = decode_population_code(input[j], size_x, min, max);
        amplitude[j] = norm1(input[j], size_x);
    }
}

static InitClass init("PopulationDecoder", &PopulationDecoder::Create, "Source/Modules/CodingModules/PopulationDecoder/");


