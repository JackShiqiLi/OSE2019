CF=-O3 -g -ffast-math -fopenmp 
CPP=mpicxx
INCL=


#### Executable ####
VFI: main.o param.o econ.o solver.o
	$(CPP) $(CF) -o VFI main.o param.o econ.o solver.o 

main.o: main.cpp param.hpp econ.hpp
	$(CPP) $(CF) -c main.cpp 

param.o: param.cpp econ.hpp
	$(CPP) $(CF) -c param.cpp

econ.o: econ.cpp param.hpp
	$(CPP) $(CF) -c econ.cpp

solver.o: solver.cpp param.hpp econ.hpp
	$(CPP) $(CF) -c solver.cpp 

#### Clean ####

clean:
	rm VFI main.o param.o econ.o solver.o 
