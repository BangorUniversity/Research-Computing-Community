#!/usr/bin/env bash

#SBATCH --job-name=step_1

#SBATCH --output=logs/step_1.%J.out
#SBATCH --error=logs/step_1.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=1

#SBATCH --account=scw1124
#SBATCH --time=00-00:01

date
hostname
echo "Step 1"
