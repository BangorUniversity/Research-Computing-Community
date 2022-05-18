#!/usr/bin/env bash

#SBATCH --job-name=multi-cpu

#SBATCH --output=logs/multi-cpu.%J.out
#SBATCH --error=logs/multi-cpu.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=10

#SBATCH --time=00-00:10

module purge
module load python/3.9.2

python3 multi-cpu.py
