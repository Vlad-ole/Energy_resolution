#include <iostream>
#include <fstream>
#include <string>
#include "ER.h"

#include "Math/Interpolator.h"
#include "Math/GSLMinimizer.h"
#include "Math/Functor.h"

#include "Math/Minimizer.h"
#include "Math/Factory.h"
#include "Math/Functor.h"
#include "TRandom2.h"
#include "TError.h"

#include "interpolate.h"

using namespace std;

int main()
{
	interpolate* YAP_ER = new interpolate("D:\\git_repositories\\Geant_simulation\\data\\intrinsic_resolution\\yap_ce_keV_1.dat");
	interpolate* YAP_nonprop = new interpolate("D:\\git_repositories\\Geant_simulation\\data\\nonprop\\yap_ce_keV_1.dat");

	
	ofstream file_out("D:\\git_repositories\\Energy_resolution\\out.dat");
	ER ER_object;

	ER_object.light_yield = 40.7; // ph/keV at 662 keV

	ER_object.t_gate = 1;
	ER_object.nu_DC = 0;
	ER_object.p = 0;
	ER_object.epsilon = 0.28;

	ER_object.E_G_tot = 1E6;
	ER_object.Var_G_tot = pow(ER_object.E_G_tot * 0.1, 2);


	//סגועמסבמנ
	ER_object.E_n_abs = 0.5;
	ER_object.Var_n_abs = pow(0.1 * ER_object.E_n_abs, 2);


	
	for (int i = 25; i < 150; i++)
	{
		ER_object.E_N_born = ER_object.light_yield * i * YAP_nonprop->Eval_Data(i);
		ER_object.Var_N_born = pow( (YAP_ER->Eval_Data(i) / ER_object.Delta) * ER_object.E_N_born, 2);
		
		ER_object.Get_n_pe_DC(ER_object.p);

		//file_out << i << "\t" << sqrt(ER_object.Var_N_born) / ER_object.E_N_born * ER_object.Delta << endl;
		//file_out << i << "\t" << sqrt(ER_object.Var_n_abs) / ER_object.E_n_abs * ER_object.Delta * 1 / ER_object.E_N_born << endl;
		//file_out << i << "\t" << sqrt( (1 - ER_object.epsilon) / ER_object.epsilon * 1 / (ER_object.E_N_born * ER_object.E_n_abs) ) * ER_object.Delta << endl;
		//file_out << i << "\t" << sqrt(ER_object.Var_G_tot) / ER_object.E_G_tot * ER_object.Delta * 1 / (ER_object.E_N_born * ER_object.E_n_abs * ER_object.epsilon) << endl;

		/*file_out << i << "\t" << sqrt(pow(sqrt(ER_object.Var_N_born) / ER_object.E_N_born * ER_object.Delta, 2) +
			pow(sqrt(ER_object.Var_n_abs) / ER_object.E_n_abs * ER_object.Delta * 1 / ER_object.E_N_born, 2) + 
			pow(sqrt((1 - ER_object.epsilon) / ER_object.epsilon * 1 / (ER_object.E_N_born * ER_object.E_n_abs)) * ER_object.Delta, 2) +
			pow(sqrt(ER_object.Var_G_tot) / ER_object.E_G_tot * ER_object.Delta * 1 / (ER_object.E_N_born * ER_object.E_n_abs * ER_object.epsilon), 2)) 
			<< endl;*/

		file_out << i << "\t" << ER_object.GetER() << endl;
	}


	file_out.close();
	
	system("pause");
	
	return 0;
}