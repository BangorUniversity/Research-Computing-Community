% Setup cluster
pc = parcluster;
pc.JobStorageLocation = job_storage;
num_cores = feature('numcores');
parpool(pc, num_cores);

tic
ticBytes(gcp);

n = 200;
A = 500;
a = zeros(n);

parfor i = 1:n
    a(i) = max(abs(eig(rand(A))));
end

tocBytes(gcp)
toc

delete(gcp('nocreate'));
