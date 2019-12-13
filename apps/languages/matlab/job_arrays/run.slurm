#!/usr/bin/env bash

# Usage: sbatch run.slurm

#SBATCH --job-name=job_arrays

#SBATCH --output=logs/job_arrays.%A_%a.out
#SBATCH --error=logs/job_arrays.%A_%a.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --array=1-4

#SBATCH --account=scw1124
#SBATCH --time=00-00:01

module purge
module load matlab/R2019a

matlab -nodisplay -r "func(${SLURM_ARRAY_TASK_ID});exit"
