#!/usr/bin/env bash

# Usage: sbatch run.slurm

#SBATCH --job-name=meshroom

#SBATCH --output=meshroom.%J.out
#SBATCH --error=meshroom.%J.err

#SBATCH --partition=gpu
#SBATCH --gres=gpu:1
#SBATCH --nodes=1
#SBATCH --ntasks=1
#SBATCH --cpus-per-task=20

#SBATCH --account=scw1124
#SBATCH --time=00-01:00

module purge
module load meshroom/2019.1.0

readonly input_dir="dataset_monstree/full"
readonly output_dir="output"

mkdir "${output_dir}"

time meshroom_photogrammetry --input "${input_dir}" --output "${output_dir}"
