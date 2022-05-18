# TensorFlow

## About

[TensorFlow](https://www.tensorflow.org/) is an end-to-end open source platform for machine learning. It has a comprehensive, flexible ecosystem of tools, libraries and community resources that lets researchers push the state-of-the-art in ML and developers easily build and deploy ML powered applications.

## Examples

- Login in to the SCW cluster.

    ```sh
    ssh username@hawklogin.cf.ac.uk
    ```

- Download and run the setup script.

    ```sh
    mkdir tensorflow
    cd tensorflow
    wget https://github.com/BangorUniversity/Research-Computing-Community/raw/master/apps/machine-learning/tensorflow/examples.zip
    unzip examples.zip
    ./setup
    ```

- Submit the jobs to the scheduler.

    ```sh
    ./submit
    ```

- Monitor the status of the jobs.

    ```sh
    watch squeue --user=$USER
    ```

    > To exit out of the watch command, just hit the Ctrl+C key combination.

