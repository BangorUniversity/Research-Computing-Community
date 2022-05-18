#!/usr/bin/env bash

#SBATCH --job-name=single-cpu

#SBATCH --output=logs/single-cpu.%J.out
#SBATCH --error=logs/single-cpu.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

#SBATCH --time=00-00:10

export OMP_NUM_THREADS="${SLURM_CPUS_PER_TASK}"

module purge
module load cuDNN python/3.9.2
module list

python3 single-cpu.py
