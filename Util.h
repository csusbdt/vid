#pragma once

class Util {
public: 
	static int randomInt(int a, int b);
	static double randomDouble(double a = 0, double b = 1);
	static bool randomBool(double p);
	static char doubleToChar(double x);
	static void HSVtoRGB(double * r, double * g, double * b, double h, double s, double v);
};

