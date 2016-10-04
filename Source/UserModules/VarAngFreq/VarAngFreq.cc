#include "VarAngFreq.h"

void VarAngFreq::Init()
{
  from = GetInputMatrix("FROM");
  to = GetInputMatrix("TO");
  inc = GetOutputMatrix("OUTPUT");
  i = 0.0;

}

void VarAngFreq::Tick() {
    inc[0][0] = from[0][0] + 3.0;
}

static InitClass init("VarAngFreq", &VarAngFreq::Create, "Source/UserModules/VarAngFreq/");
