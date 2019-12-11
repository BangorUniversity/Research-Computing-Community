#!/usr/bin/env bash

# Run main.R on multiple nodes
# Usage: sbatch run.slurm

#SBATCH --job-name=doparallel

#SBATCH --output=doparallel.%J.out
#SBATCH --error=doparallel.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2

#SBATCH --account=scw1124
#SBATCH --time=00-00:30

module purge
module load compiler/gnu/8/1.0
module load mpi/openmpi/1.10.7
module load R/3.6.1-shared

mpirun -np 1 -quiet R --slave -f main.R
