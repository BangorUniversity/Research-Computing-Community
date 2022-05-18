#!/usr/bin/env bash

#SBATCH --job-name=single-cpu

#SBATCH --output=logs/single-cpu.%J.out
#SBATCH --error=logs/single-cpu.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

#SBATCH --time=00-00:10

module purge
module load python/3.9.2

python3 single-cpu.py
