#!/usr/bin/env bash

# Usage: sbatch run.slurm

#SBATCH --job-name=gnu_parallel

#SBATCH --output=logs/gnu_parallel.%J.out
#SBATCH --error=logs/gnu_parallel.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=4
#SBATCH --cpus-per-task=1

#SBATCH --account=scw1124
#SBATCH --time=00-00:05

module purge
module load R/3.6.1-shared
module load parallel

pwd
hostname
date

time parallel --joblog "logs/gnu_parallel_tasks.${SLURM_JOB_ID}.out" <commands.txt
