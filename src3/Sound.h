#pragma once

#include <cassert>
#include <string>
#include <cstdio>
#include "Object.h"
#include "globals.h"

using namespace std;

class Sound : public Object {
public:
	static double scale(
		double octaveTones, 
		double baseFrequency, 
		double halfNotesAwayFromBase);

	static double tone(
		double t, 
		double f, 
		double normalizedPhase = 0);

	static double freq(
		double t, 
		double frequency, 
		double normalizedPhase = 0, 
		double min = 0, 
		double max = 1);

	static double period(
		double t, 
		double period, 
		double normalizedPhase = 0, 
		double min = 0, 
		double max = 1);

	static double wave(
		double t, 
		double f, 
		double waver, 
		double p, 
		double h);

	Sound(	double startTime   =  0    , 
		double duration    = 12    , 
		double attack      =  0.01 , 
		double decay       =  0.02 ,
		double release     =  0.50 ,
		double attackDelta =  1.00 ,
		double decayDelta  =  0.10
	) :
		startTime   (startTime)    ,
		duration    (duration)     ,
		attack      (attack)       , 
		decay       (decay)        , 
		release     (release)      ,
		attackDelta (attackDelta)  ,
		decayDelta  (decayDelta)  
	{
		assert(duration > attack + decay + release); 
	}

	double startTime   ;
	double duration    ;
	double attack      ;
	double decay       ;
	double release     ;
	double attackDelta ; // normalized
	double decayDelta  ; // normalized

	virtual void activate   ()           {}
	virtual void deactivate ()           {}
	virtual void update     (double dt)  {}
	virtual void draw       (double t)   {}

	void mix(double t);

protected:
	virtual double sample(double seconds) const = 0;

	double envelope(double clockTime, double sample) const;
};

