#!/usr/bin/env bash

# Usage:
#   module load compiler/gnu/9/2.0
#   g++ main.cpp -o hello_world -pthread
#   sbatch run.slurm

#SBATCH --job-name=hello_world

#SBATCH --output=logs/hello_world.%J.out
#SBATCH --error=logs/hello_world.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

#SBATCH --account=scw1124
#SBATCH --time=00-00:01

module purge
module load compiler/gnu/9/2.0

./hello_world
