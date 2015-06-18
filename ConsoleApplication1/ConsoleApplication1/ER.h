#pragma once
class ER
{
public:
	ER();
	~ER();

	double GetER() const;


	void Get_n_pe_DC(double p);
		

	const double Delta;

	double p; //x-talk parameter

	double E_n_pe_DC;
	double Var_n_pe_DC;

	double Var_G_tot;
	double E_G_tot;

	double epsilon;
	double t_gate;
	double nu_DC;
	double energy;
	double light_yield;
};

