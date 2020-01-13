#!/usr/bin/env bash

# Usage:
#   module load compiler/gnu/9/2.0
#   g++ main.cpp -o hardware_concurrency -std=c++17 -pthread
#   sbatch run.slurm

#SBATCH --job-name=hardware_concurrency

#SBATCH --output=logs/hardware_concurrency.%J.out
#SBATCH --error=logs/hardware_concurrency.%J.err

#SBATCH --partition=dev
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4

#SBATCH --account=scw1124
#SBATCH --time=00-00:01

module purge
module load compiler/gnu/9/2.0

./hardware_concurrency
