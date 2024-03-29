#pragma once

class Input
{
protected:
	bool stateA;
	bool stateB;
	bool stateC;
	bool stateD;
	bool stateStart;
	double dx;
	double dy;
	double ax;
	double ay;
public:
	Input(void);
	virtual ~Input(void);

	bool GetA(void){ return stateA; }
	bool GetB(void){ return stateB; }
	bool GetC(void){ return stateC; }
	bool GetD(void){ return stateD; }
	bool GetStart(void){ return stateStart; }

	double GetX(void){ return dx; }
	double GetY(void){ return dy; }
	double AimX(void){ return ax; }
	double AimY(void){ return ay; }

	virtual void update(){};
	virtual void rumble(){};
};
