#ifndef Movement_
#define Movement_

#include "IKAROS.h"

class Movement: public Module
{

public:
	static Module * Create(Parameter * p) { return new Movement(p); }

	Movement(Parameter * p) : Module(p) {}
	virtual ~BlobChooser();


	void Init();
	void Tick();

	float **    input_matrix;
	int         input_matrix_size_x;
	int         input_matrix_size_y;

	float **    output_matrix;
	int         output_matrix_size_x;
	int         output_matrix_size_y;

	float **    internal_matrix;

	float *     p1;
	
	};

#endif
