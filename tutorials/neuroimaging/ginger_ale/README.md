## GingerALE

GingerALE is the BrainMap application that is used to perform an ALE meta-analysis on coordinates in Talairach or MNI space. GingerALE can also be used to convert coordinates between MNI and Talairach spaces using the [icbm2tal](http://www.brainmap.org/icbm2tal/) transform.

See more at http://www.brainmap.org/ale/

---

### Single core example

---

- Login to the SCW cluster.

- Create a new directory called *ginger_ale*.

  ```bash
  mkdir ~/ginger_ale && cd $_
  ```

- Download the SCW single core GingerALE example.

  ```bash
  wget https://github.com/BangorUniversity/Research-Computing-Community/raw/master/tutorials/neuroimaging/ginger_ale/examples/GingerALE.zip
  ```

- Extract the archive.

  ```bash
  unzip GingerALE.zip
  cd GingerALE
  ```

- Change the account code to your SCW project code.

  ```
  nano run.slurm
  
  #SBATCH --account={{insert your project code}}
  ```

  - *To exit nano press 'ctrl + x' and press 'y' to save changes.*

- Submit the job request to the slurm scheduler.

  ```bash
  sbatch run.slurm
  ```

- Check the status of your jobs in the queue.

  ```bash
  watch squeue --user=$USER
  ```

  	- *Press 'ctrl + c' to exit the 'watch' program.*

- Once the job has finished, output results are available in the same directory as the job submission file.

  - To run multiple GingerALE jobs in parallel, see below.

    

---

### GingerALE and GNU Parallel

---

- TODO