#include "Movement.h"

void Movement::Init()
{
  input_matrix = GetInputMatrix("INPUT");
  input_matrix_size_x = GetInputSizeX("INPUT");
  input_matrix_size_y = GetInputSizeY("INPUT");

  output_matrix = GetOutputArray("OUTPUT");
  output_matrix_size_x = GetOutputSizeX("OUTPUT");
  output_matrix_size_y = GetOutputSizeY("OUTPUT");

  internal_matrix = create_matrix(input_matrix_size_x, input_matrix_size_y);

  p = create_array(2);
}

BlobChooser::~BlobChooser()
{
    destroy_matrix(internal_matrix);
}

void Movement::Tick() {
  copy_matrix(internal_matrix, input_matrix, input_matrix_size_x, input_matrix_size_y);
}

static InitClass init("Movement", &Movement::Create, "Source/UserModules/Movement/");
