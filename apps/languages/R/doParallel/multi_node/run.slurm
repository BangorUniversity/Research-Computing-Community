#!/usr/bin/env bash

# Run main.R on multiple nodes
# Usage: sbatch run.slurm

#SBATCH --job-name=doparallel_mutli_node

#SBATCH --output=doparallel_mutli_node.%J.out
#SBATCH --error=doparallel_mutli_node.%J.err

#SBATCH --partition=htc
#SBATCH --nodes=2
#SBATCH --ntasks-per-node=2

#SBATCH --account=scw1124
#SBATCH --time=00-00:30

module purge
module load compiler/gnu/8/1.0
module load mpi/openmpi/1.10.7
module load R/3.5.1

export OMPI_MCA_mpi_warn_on_fork=0 # Disable mpi_warn_on_fork message

Rscript main.R
