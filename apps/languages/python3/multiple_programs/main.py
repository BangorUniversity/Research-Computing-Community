import os
import multiprocessing as mp


def run_python_script(script):
    process_id = mp.current_process()
    print(f'{script} will be launched on process {process_id}')
    os.system(f'python3 {script}')


def main():
    # How many cores were assigned to the slurm job allocation?
    num_cores = int(os.getenv('SLURM_CPUS_PER_TASK'))
    print(f'Found {num_cores} cores')

    # Create a worker pool
    pool = mp.Pool(num_cores)

    # Generate a list of python scripts to launch in parallel
    scripts = [
        'script_1.py',
        'script_2.py',
        'script_3.py',
        'script_4.py',
    ]

    # Map worker_data to worker_func
    pool.map(run_python_script, scripts)


if __name__ == "__main__":
    main()
