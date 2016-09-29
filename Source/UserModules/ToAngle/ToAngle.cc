#include "ToAngle.h"
#include <math.h>

void ToAngle::Init()
{
  output = GetOutputMatrix("OUTPUT");
  input = GetInputMatrix("INPUT");
}

void ToAngle::Tick() {
  output[0][0] = atan2(input[0][1] - input[0][3], input[0][0] - input[0][2]);
  output[0][0] = output[0][0] * (float)180.0/(float)3.1415;
}

static InitClass init("ToAngle", &ToAngle::Create, "Source/UserModules/ToAngle/");
