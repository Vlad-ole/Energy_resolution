#pragma once
#include "Math\Interpolator.h"
using namespace std;


class interpolate
{

public:

	interpolate();
	interpolate(const char F[], char type[] = "default", char linear_or_spline[] = "spline");
	interpolate(interpolate* spec_i, const double norm_const);
	interpolate(interpolate* spec_i);
	interpolate(interpolate* spec_i, interpolate* mu_filter, const double rho_l);

	interpolate(vector<double> const& temp_x, vector<double> const& temp_y, char type[], char linear_or_spline[]);

	interpolate(interpolate* spec_i, double(*func)(const double value, const double energy)); // convolution constructor

	void print(string file_output_name);

	double Eval_Data(double value, char type[] = "default");

	double GetXVectorMin();
	double GetXVectorMax();


private:

	ROOT::Math::Interpolator* interpolator;
	vector<double> xv;
	vector<double> yv;

};
