#!/usr/bin/env bash

# Usage: sbatch run.slurm

#SBATCH --job-name=doParallel

#SBATCH --output=logs/doParallel.%J.out
#SBATCH --error=logs/doParallel.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks-per-node=4

#SBATCH --account=scw1124
#SBATCH --time=00-00:30

module purge
module load compiler/gnu/8/1.0
module load mpi/openmpi/1.10.7
module load R/3.6.1-shared

Rscript main.R
