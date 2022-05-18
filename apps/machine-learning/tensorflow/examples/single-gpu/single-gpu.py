import tensorflow as tf

print('*' * 80)
num_threads = tf.config.threading.get_inter_op_parallelism_threads()
print(f'Num threads: {num_threads}')

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
