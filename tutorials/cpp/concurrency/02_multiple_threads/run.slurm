#!/usr/bin/env bash

# Usage:
#   module load compiler/gnu/9/2.0
#   g++ main.cpp -o multiple_threads -std=c++17 -pthread
#   sbatch run.slurm

#SBATCH --job-name=multiple_threads

#SBATCH --output=logs/multiple_threads.%J.out
#SBATCH --error=logs/multiple_threads.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

#SBATCH --account=scw1124
#SBATCH --time=00-00:01

module purge
module load compiler/gnu/9/2.0

./multiple_threads
