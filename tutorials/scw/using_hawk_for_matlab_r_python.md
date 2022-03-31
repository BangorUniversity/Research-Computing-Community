# Using the Hawk Supercomputer to run Matlab, R and/or Python scripts

The Supercomputing Wales Hawk supercomputer is well-suited to both large highly-parallel computational tasks and smaller serial or slightly-parallel tasks alike. Those that typically sit in the latter category can benefit from being able to run many at one time, or being able to run larger tasks than on a typical desktop computer, or being able to run for long periods in a controlled environment.

A large amount of modern research computing tasks use scripted languages such as Matlab, R or Python. All three languages are well used in Bangor and all have areas where they individually excel. All three languages can also be deployed to a range of parallel degrees, but have historically been more typically associated with smaller parallel tasks.

## Shifting to Hawk

To move a scripted job to the Hawk supercomputer is usually very easy, and both computational runs and interactive development are then easily supported in a relatively transparent fashion, meaning those who use Rstudio, Matlab's Graphical User Interface or other tools such as Visual Studio Code can use the system in a familiar fashion with only a small amount of Linux knowledge necessary.

Data and scripts/code must be uploaded, and then the command-line is used to run tasks, but awkward file editing via the command-line is not necessary, and existing tools can be used. Please see the associated document on the use of SSH-FS to see how to map Hawk's storage as if it were a locally mounted drive in a Windows, Mac OS X or Linux desktop. As the data location may be different on Hawk, the use of relative paths in all scripts is advised, otherwise, paths may need an update.

## Running on Hawk

As discussed in other support documentation on this site, the Hawk supercomputer is separated into login and compute nodes. The login nodes are shared by all logged-in users, whereas the compute node resources are allocated exclusively to individual user jobs. Computationally heavy and/or lengthy work (i.e. the primary function of the system) must occur, therefore, on the compute nodes and this is managed by the _scheduler_, to which users send jobs for execution. They are then executed at the earliest opportunity.

However, the login nodes can be used for interactive development and small program execution as part thereof. To do this, they are used just like any Linux command line. We access application software through a system known as the _modular environment_, which enables us to provide and use many different software applications and versions thereof. Once we are logged into the login nodes, the command _module avail_ displays available software and the required software is then made available by loading the module for which software we wish to use via _module load xyz_, like this:

```sh
[user@cl1 ~]$ module avail

--------------------- /apps/local/modules/languages -----------------------

matlab/R2019a spss/25

----------------------- /apps/modules/compilers ---------------------------

compiler/gnu/4/8.5 compiler/gnu/7/3.0 compiler/intel/2017/4 compiler/intel/2018/3 compiler/pgi/18/4

compiler/gnu/5/5.0 compiler/gnu/8/1.0 compiler/intel/2017/7 compiler/intel/2018/4 compiler/pgi/19/4

compiler/gnu/6/4.0 compiler/intel/2016/4 compiler/intel/2018/2 compiler/intel/2019/3

----------------------- /apps/modules/languages ---------------------------

anaconda/3 octave/4.4.1 python-mayavi/4.6.0 R/3.5.1(default)

java/1.8 python/3.6.3-intel2018u3 python-numpy/1.14.5 R/3.5.3

mpi4py/20181128 python/3.7.0 python-pyside/1.2.4 R/3.6.0

mpi4py/20190521 python-h5py/2.8.0 python-scipy/1.1.0 ruby/2.6.0

ncl/6.5.0 python-matplotlib/2.2.2 python-vtk/8.1.0 stata/15
```

__R__
```sh
[user@cl1 ~]$ module load R/3.6.0

[user@cl1 ~]$ R

WARNING: ignoring environment value of R_HOME

R version 3.6.0 (2019-04-26) -- 'Planting of a Tree'

Copyright (C) 2019 The R Foundation for Statistical Computing

Platform: x86_64-pc-linux-gnu (64-bit)

R is free software and comes with ABSOLUTELY NO WARRANTY.

You are welcome to redistribute it under certain conditions.

Type 'license()' or 'licence()' for distribution details.

Natural language support but running in an English locale

R is a collaborative project with many contributors.

Type 'contributors()' for more information and

'citation()' on how to cite R or R packages in publications.

Type 'demo()' for some demos, 'help()' for on-line help, or

'help.start()' for an HTML browser interface to help.

Type 'q()' to quit R.

>
```
__Python__
```sh

[user@cl1 ~]$ module load python/3.7.0

[user@cl1 ~]$ python3

Python 3.7.0 (default, Jul 13 2018, 10:08:05)

[GCC Intel(R) C++ gcc 4.8.5 mode] on linux

Type 'help', 'copyright', 'credits' or 'license' for more information.

>>>
```
__Matlab__
```sh

[user@cl1 ~]$ module load matlab/R2019a

[user@cl1 ~]$ matlab

MATLAB is selecting SOFTWARE OPENGL rendering.

M A T L A B (R)

Copyright 1984-2019 The MathWorks, Inc.

R2019a (9.6.0.1072779) 64-bit (glnxa64)

March 8, 2019

To get started, type doc.

For product information, visit www.mathworks.com.

>>
```

So, these loaded interactive development environments can be used as part of our development process on the login nodes, with small tasks running on the login nodes interactively. When we then come to scale up our efforts, there are two scales, both now using the scheduler to access the compute nodes.

Larger development jobs using more resource than just a login node can be deployed interactively on compute resources as follows.

First, we create an allocation – which means we have some compute resource dedicated to us – in this case 8 processors:

```sh
[user@cl1 ~]$ salloc -n 8 --ntasks-per-node=8

salloc: Granted job allocation 134
```

_Note that this command will wait until resource is available before returning._

Then, to use the allocation, we can access a command-line shell on the allocated resource like this:

```sh
[user@cl1 ~]$ srun --pty bash

[user@ccs0135 ~]$ hostname

ccs0135
```

At this point, we now can load the software we require via the module commands just as we did on the login node before. We can then use the larger available compute within it. We must logout of the compute node and end the allocation when we are finished with it by running _exit_ twice, i.e.

```sh
[user@ccs0135 ~]$ exit

exit

[user@cl1 ~]$ exit

exit

salloc: Relinquishing job allocation 7582681

[user@cl1 ~]$
```

When we become ready to run larger computational jobs, we do not typically do this interactively - instead we write a _batch script_, which lists the command-line instructions necessary to carry out a task, and then submit it to the scheduler to run as and when resource is available without any user interaction required. Once a job is submitted to the scheduler, we do not need to stay logged in – indeed, it is unlikely the job will run immediately, so it's best to come back later. The scheduler can be requested to send notification emails when a job completes its run.

The batch script has a basic repeatable format:

```sh
#!/bin/bash --login

#SBATCH -n 40 #number of processors

#SBATCH --tasks-per-node=40 #number of processors per node

#SBATCH -J jobname #a handy job name for our purposes

#SBATCH -o outfile.%J #file for command-line output

_execution commands_
```

So, in our typical scripted languages, we would have something like:
__R__
```sh
#!/bin/bash --login

#SBATCH -n 40 #number of processors

#SBATCH --tasks-per-node=40 #number of processors per node

#SBATCH -J jobname #a handy job name for our purposes

#SBATCH -o outfile.%J #file for command-line output

module purge #ensure no unexpected software loaded

module load R/3.6.0 #this is what we want to use

R CMD BATCH myscript.R #run our script
```
__Python__
```sh
#!/bin/bash --login

#SBATCH -n 40 #number of processors

#SBATCH --tasks-per-node=40 #number of processors per node

#SBATCH -J jobname #a handy job name for our purposes

#SBATCH -o outfile.%J #file for command-line output

module purge #ensure no unexpected software loaded

module load python/3.7.0 #this is what we want to use

python3 myscript.py #run our script
```
__Matlab__
```sh
#!/bin/bash --login

#SBATCH -n 40 #number of processors

#SBATCH --tasks-per-node=40 #number of processors per node

#SBATCH -J jobname #a handy job name for our purposes

#SBATCH -o outfile.%J #file for command-line output

module purge #ensure no unexpected software loaded

module load matlab/2019a #this is what we want to use

matlab myscript.ml #run our script
```

The commands specified are literally the same commands we would type at the command-line and so can become quite complex with the shell's available syntax.

We put the batch script in its own file, and then submit it to the scheduler using _sbatch_:

```sh
[user@cl1 ~]$ sbatch run_script.q

Submitted batch job 7582690
```

We can then use _squeue_ to monitor the job status:

```sh
[user@cl1 ~]$ squeue -u $USER

JOBID PARTITION NAME USER ST TIME NODES NODELIST(REASON)

7581739 compute scriptjob user PD 0:00 1 (Resources)
```

In this case, the job is pending (state PD) and will move to state running (R) when the scheduler has launched the job on some compute nodes.

Once the job completes, the output of the batch script commands will be in the _outfile_ and the output from the actual R/Python/Matlab script will be either in a dedicated file or embedded, depending on how we called the language in question.

## Growing for Hawk

Hawk provides capabilities to use GPUs, Array jobs running many instances of similar tasks and parallel support through Rparallel, pyMPI, Matlab parallel.  If you are interested in any of them, please get in touch.

## In Summary

This all-in-one plan shows how to use the supercomputer resources available to researchers in a very popular and typical usage scenario. Whilst there are considerable other technical support documents available on the SCW User Portal <http://portal.supercomputing.wales>, we hope the nature of this guide will provide an accessible and easy way for new users to harness the resources quickly and effectively. Research Computing staff, of course, remain available and keen to support you in any way possible, so please don't hesitate to get in touch.  The Bangor eResearch team can be reached via <research-computing@bangor.ac.uk>.