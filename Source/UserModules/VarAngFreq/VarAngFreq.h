#ifndef VarAngFreq_
#define VarAngFreq_

#include "IKAROS.h"

class VarAngFreq: public Module
{

public:
	//Have not added parameters yet
	static Module * Create(Parameter * p) { return new VarAngFreq(p); }

	VarAngFreq(Parameter * p) : Module(p) {}

	void Init();
	void Tick();
	float ** from;
	float ** to;
	float ** speed;
	float norm;
	float max;
	int rest;

	};

#endif
