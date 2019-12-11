library(doParallel)

num_nodes=strtoi(Sys.getenv('SLURM_JOB_NUM_NODES'))
cat('SLURM_JOB_NUM_NODES:', num_nodes, '\n')

num_tasks_per_node=strtoi(Sys.getenv('SLURM_NTASKS_PER_NODE'))
cat('SLURM_NTASKS_PER_NODE:', num_tasks_per_node, '\n')

num_cores=num_nodes*num_tasks_per_node
cat('Num cores:', num_cores, '\n')

cl=makeCluster(num_cores-1, type="MPI")
registerDoParallel(cl)

getDoParRegistered()
getDoParWorkers()

x=iris[which(iris[,5] != "setosa"), c(1,5)]
trials=5000

stime=system.time({
	r <- foreach(icount(trials), .combine=cbind) %dopar% {
		ind <- sample(100, 100, replace=TRUE)
		result1 <- glm(x[ind,2]~x[ind,1], family=binomial(logit))
		coefficients(result1)
	}
})[3]
stime

cat('Finished')

stopCluster(cl)

