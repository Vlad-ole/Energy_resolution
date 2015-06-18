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
	interpolate* LYSO = new interpolate("D:\\git_repositories\\Geant_simulation\\data\\intrinsic_resolution\\yap_ce_keV_1.dat");


	ofstream file_out("D:\\git_repositories\\Energy_resolution\\out.dat");
	ER ER_object;

	ER_object.t_gate = 1;
	ER_object.nu_DC = 0;

	/*for (int i = 20; i < 150; i++)
	{
		file_out << i << "\t" << ER_object.GetER() << endl;
	}*/

	for (double i = 0; i < 1; i+= 0.01)
	{
		ER_object.Get_n_pe_DC(i);
		file_out << i << "\t" << ER_object.E_n_pe_DC << endl;
	}
	
	file_out.close();
	
	
	system("pause");
	
	return 0;
}