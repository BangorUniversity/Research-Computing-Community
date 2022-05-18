import os

import tensorflow as tf

num_threads = int(os.getenv('OMP_NUM_THREADS'))

tf.config.threading.set_inter_op_parallelism_threads(num_threads)
tf.config.threading.set_intra_op_parallelism_threads(num_threads)
tf.config.set_soft_device_placement(True)

print('*' * 80)
parallel_threads = tf.config.threading.get_inter_op_parallelism_threads()
print(f'Num threads: {parallel_threads}')

print('*' * 80)
logical_devices = tf.config.list_logical_devices('GPU')
print(f'Logical Num GPUs: {len(logical_devices)}')
for devices in logical_devices:
    print(devices)

print('*' * 80)
physical_devices = tf.config.list_physical_devices('GPU')
print(f'Physical Num GPUs: {len(logical_devices)}')
for devices in physical_devices:
    print(devices)
