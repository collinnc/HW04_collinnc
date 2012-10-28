#pragma once
#include "Starbucks.h"

class CollinncStarbucks : public Starbucks {

	virtual void build(Entry* c, int n);
	virtual Entry* getNearest(double x, double y) = 0;

};