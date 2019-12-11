library(Rmpi)
library(snow)

num_cores = mpi.universe.size() - 1
cluster = makeMPIcluster(num_cores)

# Call each process to print nodename and machine
print_node_info = function() {
    info = Sys.info()[c("nodename", "machine")]
    paste("Hello from", info[1], "with CPU type", info[2])
}
names = clusterCall(cluster, print_node_info)
print(unlist(names))

# Compute row sums in parallel using all processes
parallel_sum = function(m, n) {
    A = matrix(rnorm(m * n), nrow = m, ncol = n)
    row.sums = parApply(cluster, A, 1, sum)
    print(sum(row.sums))
}
stime = system.time(parallel_sum(50000, 50000))[3]
stime

stopCluster(cluster)
mpi.exit()
