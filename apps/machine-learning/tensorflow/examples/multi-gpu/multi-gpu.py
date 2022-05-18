import tensorflow as tf

print('*' * 80)
logical_devices = tf.config.list_logical_devices('GPU')
print("Logical Num GPUs:", len(logical_devices))
for devices in logical_devices:
    print(devices)

print('*' * 80)
physical_devices = tf.config.list_physical_devices('GPU')
print("Physical Num GPUs:", len(physical_devices))
for devices in physical_devices:
    print(devices)
