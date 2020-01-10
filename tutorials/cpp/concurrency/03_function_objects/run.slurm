#!/usr/bin/env bash

# Usage:
#   module load compiler/gnu/9/2.0
#   g++ main.cpp -o function_objects -std=c++17 -pthread
#   sbatch run.slurm

#SBATCH --job-name=function_objects

#SBATCH --output=logs/function_objects.%J.out
#SBATCH --error=logs/function_objects.%J.err

#SBATCH --partition=dev
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

#SBATCH --account=scw1124
#SBATCH --time=00-00:01

module purge
module load compiler/gnu/9/2.0

./function_objects
