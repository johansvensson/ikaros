#include "VarAngFreq.h"
#include <cmath>
#include <iostream>
using namespace std;

void VarAngFreq::Init()
{
  from = GetInputMatrix("FROM");
  to = GetInputMatrix("TO");
  speed = GetOutputMatrix("OUTPUT");
  Bind(norm, "norm");
  Bind(max, "max");
  rest = 0;
}

void VarAngFreq::Tick() {

    float v1 = from[0][0];
    float v2 = to[0][0];
    if(fabs(v1 - v2) < 10.0){
      speed[0][0] = 0;
      if(rest < 5){
        rest++;
      }
    }
    cout << rest;
    if(rest > 0  && fabs(v1 - v2) > 10.0){
      speed[0][0] = speed[0][0] + speed[0][0]/5.0;
      rest--;
    } else {
      float temp = fabs(v1 - v2)/norm;
      if (temp > max){
        speed[0][0] = max;
      } else {
        speed[0][0] = temp;
      }
    }



}

static InitClass init("VarAngFreq", &VarAngFreq::Create, "Source/UserModules/VarAngFreq/");
