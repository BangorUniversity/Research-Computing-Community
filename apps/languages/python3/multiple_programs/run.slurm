#!/usr/bin/env bash

# Launch multiple python programs in parallel
# Usage: sbatch run.slurm

#SBATCH --job-name=multiple-programs

#SBATCH --output=multiple-programs.%J.out
#SBATCH --error=multiple-programs.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4

#SBATCH --account=scw1124
#SBATCH --time=00-00:05

module purge
module load python/3.7.0

python3 main.py
