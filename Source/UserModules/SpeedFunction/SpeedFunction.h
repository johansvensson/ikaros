#ifndef SpeedFunction_
#define SpeedFunction_

#include "IKAROS.h"

class SpeedFunction: public Module
{

public:
	//Have not added parameters yet
	static Module * Create(Parameter * p) { return new SpeedFunction(p); }

	SpeedFunction(Parameter * p) : Module(p) {}

	void Init();
	void Tick();
	float ** from;
	float ** to;
	float ** speed;
	float norm;
	float max;
	int rest;
	float x;
	float past;

	};

#endif
