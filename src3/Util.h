#pragma once

typedef unsigned char byte;

class Util {
public: 
	static int randomInt(int a, int b);
	static double randomDouble(double a = 0, double b = 1);
	static bool randomBool(double p);
	static byte doubleToByte(double x);
	static void HSVtoRGB(double h, double s, double v, double * r, double * g, double * b);
};

