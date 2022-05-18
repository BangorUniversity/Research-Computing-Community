#!/usr/bin/env bash

#SBATCH --job-name=multi-gpu

#SBATCH --output=logs/multi-gpu.%J.out
#SBATCH --error=logs/multi-gpu.%J.err

#SBATCH --partition=gpu
#SBATCH --gres=gpu:2
#SBATCH --cpus-per-task=40

#SBATCH --time=00-00:10

export OMP_NUM_THREADS="${SLURM_CPUS_PER_TASK}"

module purge
module load cuDNN python/3.9.2
module list

python3 multi-gpu.py
