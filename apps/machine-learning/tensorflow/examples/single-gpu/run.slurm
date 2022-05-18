#!/usr/bin/env bash

#SBATCH --job-name=single-gpu

#SBATCH --output=logs/single-gpu.%J.out
#SBATCH --error=logs/single-gpu.%J.err

#SBATCH --partition=gpu
#SBATCH --gres=gpu:1
#SBATCH --cpus-per-task=20

#SBATCH --time=00-00:10

export OMP_NUM_THREADS="${SLURM_CPUS_PER_TASK}"

module purge
module load cuDNN python/3.9.2
module list

python3 single-gpu.py
