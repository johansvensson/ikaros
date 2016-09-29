#include "ToAngle.h"
#include <math.h>

void ToAngle::Init()
{
  output = GetOutputArray("OUTPUT");
  input_array = GetInputArray("INPUT");
}

void ToAngle::Tick() {
  output[0] = atan2(input_array[1] - input_array[3], input_array[0] - input_array[2]);
  output[0] = output[0] * (float)180.0/(float)3.1415;
}

static InitClass init("ToAngle", &ToAngle::Create, "Source/UserModules/ToAngle/");
