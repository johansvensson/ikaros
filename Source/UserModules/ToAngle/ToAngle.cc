#include "ToAngle.h"
#include "Math.h"

void ToAnge::Init()
{
  output = GetOutputArray("OUTPUT");
  input_array = GetInputArray("INPUT");
}

void ToAngle::Tick() {
  output = atan2(input_array[1] - input_array[3], input_array[0] - input_array[2]);
  output = output*180/3.1415;
}

static InitClass init("ToAngle", &ToAngle::Create, "Source/UserModules/ToAngle/");
