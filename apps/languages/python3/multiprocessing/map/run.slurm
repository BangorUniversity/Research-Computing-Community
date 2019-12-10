#!/usr/bin/env bash

# Run main.py on 4 cores
# Usage: sbatch run.slurm

#SBATCH --job-name=map

#SBATCH --output=map.%J.out
#SBATCH --error=map.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4

#SBATCH --account=scw1124
#SBATCH --time=00-00:05

module purge
module load python/3.7.0

python3 main.py
