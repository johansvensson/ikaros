#ifndef ToAngle_
#define ToAngle_

#include "IKAROS.h"

class ToAngle: public Module
{

public:
	//Have not added parameters yet
	static Module * Create(Parameter * p) { return new ToAngle(p); }

	ToAngle(Parameter * p) : Module(p) {}

	void Init();
	void Tick();
	float ** output;
	float ** input;

	};

#endif
