# LCPT dipole

This code provides a library that can be used to evaluate dipole amplitude computed using light cone perturbation theory, as a function of dipole size r (unit: GeV^(-1)), impact parameter b (unit: GeV^(-1)), and the angle between r and b. 

Note that the calculation is only valid in the perturbative small-r and small-b region. Consequently results at non-perturbatively large r and b are not included in the grids.

## Reference 

H. Mäntysaari, R. Paatelainen, A. Dumitru, 2021 arXiv:2103.11682,  Phys.Lett.B 820 (2021) 136560 
 
 Questions and comments to heikki.mantysaari@jyu.fi

## Build

The code can be built using `cmake` (needs GSL)

    mkdir build
    cd build
    cmake ..
    make

This generates a static library `build/dipole/liblcptdipole.a` which can be linked to an another C++ project. The necessary datafiles can be found from the `data` directory. The filename shows the corresponding Bjorken-`x`, strong coupling constant `as` and infrared regulator `m` (in GeV). 

## How to use

See `src/example.cpp` as an example on how to use the library. The attached `dipole_amplitude.ipynb` Jupyter notebook can also be used to study the dipole amplitudes.

## License

The code in the `cmake` directory is licensed under the Boost Software License, Version 1.0.

Everything else is licensed under the Attribution 4.0 International (CC BY 4.0) license.
