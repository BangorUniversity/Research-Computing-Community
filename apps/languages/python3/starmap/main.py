import os
import multiprocessing as mp


def worker_func(x, y, z):
    process_id = mp.current_process()
    print(f'worker_func is running on process {process_id}, '
          f'x={x}, y={y}, z={z}')


def main():
    # How many cores were assigned to the slurm job allocation?
    num_cores = int(os.getenv('SLURM_CPUS_PER_TASK'))
    print(f'Found {num_cores} cores')

    # Create a worker pool
    pool = mp.Pool(num_cores)

    # Generate a list of work data
    worker_data = [
        (1, 2, 3),
        (4, 5, 6),
        (7, 8, 9),
        (0, 5, 9),
    ]

    # Map worker_data to worker_func
    pool.starmap(worker_func, worker_data)


if __name__ == "__main__":
    main()