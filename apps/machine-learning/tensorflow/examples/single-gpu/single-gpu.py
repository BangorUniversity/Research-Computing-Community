import tensorflow as tf

physical_devices = tf.config.list_physical_devices('GPU')

print("Num GPUs:", len(physical_devices))

for devices in physical_devices:
    print(devices)
