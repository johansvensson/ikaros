#include "VarAngFreq.h"

void VarAngFreq::Init()
{
  from = GetInputMatrix("FROM");
  to = GetInputMatrix("TO");
  inc = GetOutputMatrix("OUTPUT");

}

void VarAngFreq::Tick() {
    if(from[0][0] < to[0][0]){
      inc[0][0] = from[0][0] + 1.0;
    }
    if(from[0][0] > to[0][0]){
      inc[0][0] = from[0][0] - 1;
    }
    if(from[0][0] == to[0][0]){
      inc[0][0] = from[0][0];
    }
}

static InitClass init("VarAngFreq", &VarAngFreq::Create, "Source/UserModules/VarAngFreq/");
