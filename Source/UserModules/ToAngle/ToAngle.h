#ifndef ToAngle_
#define ToAngle_

#include "IKAROS.h"

class ToAngle: public Module
{

public:
	//Have not added parameters yet
	static Module * Create(Parameter * p) { return new ToAngle(p); }

	ToAngle(Parameter * p) : Module(p) {}
	virtual ~ToAngle();

	void Init();
	void Tick();
	int x0;
	int y0;
	float ** output_matrix;
	int input_matrix_size_x;
	int input_matrix_size_y;
	float ** internal_matrix;
	float ** input_matrix;
	float * origin;

	};

#endif
