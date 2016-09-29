#include "ToAngle.h"
#include "Math.h"

void ToAnge::Init()
{
  origin = GetInputArray("ORIGIN");
  output_matrix = GetOutputMatrix("OUTPUT");
  input_matrix = GetInputMatrix("INPUT");
}

ToAngle::~ToAngle()
{

}

void ToAngle::Tick() {

}

static InitClass init("ToAngle", &ToAngle::Create, "Source/UserModules/ToAngle/");
