#!/usr/bin/env bash

# Usage: sbatch run.slurm

#SBATCH --job-name=rmpi_snow

#SBATCH --output=logs/rmpi_snow.%J.out
#SBATCH --error=logs/rmpi_snow.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=4

#SBATCH --account=scw1124
#SBATCH --time=00-00:30

module purge
module load compiler/gnu/8/1.0
module load mpi/openmpi/1.10.7
module load R/3.5.1

mpirun -np 1 Rscript main.R
