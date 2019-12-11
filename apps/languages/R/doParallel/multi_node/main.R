library(doParallel)

num_nodes=strtoi(Sys.getenv('SLURM_JOB_NUM_NODES'))
cat('SLURM_JOB_NUM_NODES:', num_nodes, '\n')

num_tasks_per_node=strtoi(Sys.getenv('SLURM_NTASKS_PER_NODE'))
cat('SLURM_NTASKS_PER_NODE:', num_tasks_per_node, '\n')

num_cores=num_nodes*num_tasks_per_node
cat('Num cores:', num_cores, '\n')

cl=makeCluster(num_cores, type="MPI")
registerDoParallel(cl)

num_workers=getDoParWorkers()
cat('Num workers:', num_workers, '\n')

stime=system.time(
	foreach(i=1:5000, .combine='c') %dopar% {
		sqrt(i)
	}
)[3]
stime

stopCluster(cl)
