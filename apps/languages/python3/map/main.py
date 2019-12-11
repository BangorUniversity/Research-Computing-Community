import os
import multiprocessing as mp


def worker_func(data):
    process_id = mp.current_process()
    print(f'worker_func is running on process {process_id}, data={data}')


def main():
    # How many cores were assigned to the slurm job allocation?
    num_cores = int(os.getenv('SLURM_CPUS_PER_TASK'))
    print(f'Found {num_cores} cores')

    # Create a worker pool
    pool = mp.Pool(num_cores)

    # Generate a list of work data
    worker_data = range(10)

    # Map worker_data to worker_func
    pool.map(worker_func, worker_data)


if __name__ == "__main__":
    main()
