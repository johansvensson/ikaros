//
//    LowResBlobList.h		This file is a part of the IKAROS project
//
//    Copyright (C) 2014  Christian Balkenius
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

#ifndef LowResBlobList_
#define LowResBlobList_

#include "IKAROS.h"


class LowResBlobList: public Module
{
public:

    LowResBlobList(Parameter * p) : Module(p) {};
    virtual ~LowResBlobList() {};

    static Module * Create(Parameter * p) {return new LowResBlobList(p);};

    void Init();
    void Tick();

    float pan;
    float tilt;

    const float bg_threshold = 0.5;
    const float alpha = 0.001;

    int         size_x;
    int         size_y;

    int         grid_size_x;
    int         grid_size_y;

    float **	input;
    float **	position;

    float **	output;
    float **	grid;
    float **	background;
    float **	dilated_background;
    float **	detection;
    float **	smoothed;
    float **    maxima;
};


#endif
