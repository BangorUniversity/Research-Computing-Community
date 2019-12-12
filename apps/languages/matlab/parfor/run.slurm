#!/usr/bin/env bash

# Execute for-loop iterations in parallel on workers
# Usage: sbatch run.slurm

#SBATCH --job-name=parfor

#SBATCH --output=parfor.%J.out
#SBATCH --error=parfor.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=4

#SBATCH --account=scw1124
#SBATCH --time=00-00:05

module purge
module load matlab/R2019a

readonly job_storage="/scratch/${USER}/${SLURM_JOB_NAME}/${SLURM_JOB_ID}"
mkdir -p "${job_storage}"

matlab -nodisplay -r "job_storage='${job_storage}';main;exit;"
