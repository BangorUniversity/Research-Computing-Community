#!/usr/bin/env bash

# Usage:
#   module load compiler/gnu/9/2.0
#   g++ main.cpp -o vectors -std=c++17
#   sbatch run.slurm

#SBATCH --job-name=vectors

#SBATCH --output=logs/vectors.%J.out
#SBATCH --error=logs/vectors.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

#SBATCH --account=scw1124
#SBATCH --time=00-00:01

module purge
module load compiler/gnu/9/2.0

./vectors
