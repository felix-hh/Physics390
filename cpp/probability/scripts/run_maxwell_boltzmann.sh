a=1 && ./bin/test_maxwell_boltzmann_rejection $RANDOM $a > data/maxwell_boltzmann_rejection_a${a}.dat
a=2 && ./bin/test_maxwell_boltzmann_rejection $RANDOM $a > data/maxwell_boltzmann_rejection_a${a}.dat
a=5 && ./bin/test_maxwell_boltzmann_rejection $RANDOM $a > data/maxwell_boltzmann_rejection_a${a}.dat

a=1 && ./bin/test_maxwell_boltzmann_metropolis $RANDOM $a > data/maxwell_boltzmann_metropolis_a${a}.dat
a=2 && ./bin/test_maxwell_boltzmann_metropolis $RANDOM $a > data/maxwell_boltzmann_metropolis_a${a}.dat
a=5 && ./bin/test_maxwell_boltzmann_metropolis $RANDOM $a > data/maxwell_boltzmann_metropolis_a${a}.dat