import os

import tensorflow as tf

num_threads = int(os.getenv('OMP_NUM_THREADS'))

tf.config.threading.set_inter_op_parallelism_threads(num_threads)
tf.config.threading.set_intra_op_parallelism_threads(num_threads)
tf.config.set_soft_device_placement(True)

parallel_threads = tf.config.threading.get_inter_op_parallelism_threads()
print(
    f'Number of threads used for parallelism between independent operations.: {parallel_threads}'
)

parallel_threads = tf.config.threading.get_intra_op_parallelism_threads()
print(
    f'Get number of threads used within an individual op for parallelism.: {parallel_threads}'
)

logical_devices = tf.config.list_logical_devices('CPU')
print(f'Logical Num CPUs: {len(logical_devices)}')
for device in logical_devices:
    print(f'\t {device}')

physical_devices = tf.config.list_physical_devices('CPU')
print(f'Physical Num CPUs: {len(logical_devices)}')
for device in physical_devices:
    print(f'\t {device}')
