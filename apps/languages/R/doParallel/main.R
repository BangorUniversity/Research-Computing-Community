library(doParallel)

# Register the parallel backend with the foreach package
registerDoParallel(cores=(Sys.getenv("SLURM_NTASKS_PER_NODE")))

# Get the name of the registered backend
getDoParName()

# Get the version of the registered backend
getDoParVersion()

# Check the doPar backend has been registered
getDoParRegistered()

# Get the number of workers foreach is going to use
getDoParWorkers()

# Run bootstrap iterations in parallel
x=iris[which(iris[,5] != "setosa"), c(1,5)]
trials=20000
stime=system.time({
	r <- foreach(icount(trials), .combine=cbind) %dopar% {
		ind <- sample(100, 100, replace=TRUE)
		result1 <- glm(x[ind,2]~x[ind,1], family=binomial(logit))
		coefficients(result1)
	}
})[3]
stime

