#pragma once

#include "Sound.h"

class Wave : public Sound {
public:
	Wave(
		double toneFrequency, 
		double waiverFrequency, 
		double longPeriod
	) : 
		toneFrequency(toneFrequency), 
		waiverFrequency(waiverFrequency), 
		longPeriod(longPeriod) 
	{ }

	double sample(double t) const {
		return 
			tone(t, toneFrequency)   * 
			freq(t, waiverFrequency) * 
			period(t, longPeriod);
	}

private:
	double toneFrequency;
	double waiverFrequency;
	double longPeriod;
};

