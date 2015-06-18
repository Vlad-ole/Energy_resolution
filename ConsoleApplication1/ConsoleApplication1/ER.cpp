#include "ER.h"
#include <iostream>
using namespace std;

ER::ER() : Delta(2.355)
{
}


ER::~ER()
{
}

double ER::GetER() const
{
	const double E_N_DC = t_gate * nu_DC;
	
	const double E_N_born = energy * light_yield;
	const double Var_N_born = E_N_born; //simple case

	//double p = 0; //x-talk parameter
	
	//double E_n_pe_DC = ;
	//double Var_n_pe_DC = ;

	const double Conv = 0.5;
	const double E_n_abs = Conv;
	const double Var_n_abs = Conv * (1 - Conv);

	const double Var_N_abs = Var_N_born *pow(E_n_abs, 2) + Var_n_abs * E_N_born;
	const double E_N_abs = E_n_abs * E_N_born;

	const double Var_Npe = (Var_N_abs * pow(E_n_pe_DC, 2) + Var_n_pe_DC * E_N_abs)* pow(epsilon, 2) + (pow(E_n_pe_DC, 2) + Var_n_pe_DC) * E_N_DC;
	const double E_Npe = E_n_pe_DC * (epsilon * E_N_abs + E_N_DC);

	//double Var_G_tot;
	//double E_G_tot;
	
	return Var_Npe / pow(E_Npe, 2) + Var_G_tot / pow(E_G_tot, 2) * 1 / (E_Npe);
}

void ER::Get_n_pe_DC(double p)
{
	const double q = 1 - p;
	
	const double P1 = pow(q, 4);
	const double P2 = 4 * p * pow(q, 6);
	const double P3 = 18 * pow(p, 2) * pow(q, 8);
	const double P4 = 4 * pow(p, 3) * pow(q, 8) * ( 1 + 3*q + 18*pow(q, 2) );
	const double P5 = 5 * pow(p, 4) * pow(q, 10) * ( 8 + 24 * q + 55 * pow(q, 2) );

	const double P1234 = P1 + P2 + P3 + P4;
	
	E_n_pe_DC = P1 * 1 + P2 * 2 + P3 * 3 + P4 * 4 + P5 * 5;
	double E2_n_pe_DC = P1 * 1 + P2 * 4 + P3 * 9 + P4 * 16 + P5 * 25;

	if (p != 0)
	{
		for (int i = 6; i < 100000; i++)
		{
			E_n_pe_DC += P5 * pow(1 - P5 / (1 - P1234), i - 5) * i;
			E2_n_pe_DC += P5 * pow(1 - P5 / (1 - P1234), i - 5) * pow(i, 2);
		}
	}

	Var_n_pe_DC = E2_n_pe_DC - pow(E_n_pe_DC, 2);

}