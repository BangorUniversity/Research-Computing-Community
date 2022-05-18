import tensorflow as tf

physical_devices = tf.config.list_physical_devices('CPU')

print("Num CPUs:", len(physical_devices))

for devices in physical_devices:
    print(devices)
