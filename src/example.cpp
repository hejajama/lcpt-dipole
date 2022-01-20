/*
 * Example code: how to use the LCPT dipole
 *
 * H. Mäntysaari, R. Paatelainen, A. Dumitru, 2021
 * arXiv:2103.11682 [hep-ph],  Phys.Lett.B 820 (2021) 136560 
 */

#include <iostream>
#include <string>
#include <cmath>

#include "gitsha1.h"

#include "dipoleamplitude.hpp"
using namespace std;


int main(int argc, char* argv[])
{

    LCPT_Dipole dipole("./data/nlo_dipole_x_0.01_as_0.2_m_0.2",
        "./data/nlo_v2_x_0.01_as_0.2_m_0.2" );
    
    // Code returns 0 outside the grid
    dipole.Set_out_of_range_warnings(false);
    
   
    
    // Without angular dependence: dipole at r= 1 GeV^(-1), b=2 GeV^(_1)
    cout << "N(r=1,b=2)=" << dipole.Evaluate(1,2) << endl;
    cout << "N(r=1.1,b=2)=" << dipole.Evaluate(1.1,2) << endl;
    
    // v2 coefficient
    cout << "v_2(r=1,b=2)=" << 100*dipole.v2(1,2) << "\%" << endl;
    
    // Angle dependent dipole
    cout << "N(r=1,b=2, phi_(rb)=pi/2)=" << dipole.Evaluate(1,2, M_PI/2.0) << endl;
}

