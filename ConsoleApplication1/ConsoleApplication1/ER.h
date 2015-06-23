#pragma once
class ER
{
public:
	ER();
	~ER();

	double GetER();


	void Get_n_pe_DC(double p);
		
	double E2_n_pe_DC;

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

	double E_N_born;
	double Var_N_born;

	double E_n_abs;
	double Var_n_abs;
};

