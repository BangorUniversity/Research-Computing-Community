# Quick Guide to the Hawk Supercomputer for Bangor Researchers

## What is the Hawk supercomputer service?

Fundamentally, the Hawk supercomputer is a large collection of the same technology that sits in most PCs. There are over 200 individual nodes (computers) that are tied together with a specialist network called Infiniband that provides high-performance capabilities. Each node has significant amounts of processors and memory, but some nodes present even more memory for particularly large tasks. Additionally, Hawk offers a couple of different storage subsystems that offer high performance to suit different types of tasks and a subsection of GPU accelerators. This provides a wide range of capabilities that are managed and shared through a Linux command-line environment

However, using the supercomputer is typically much easier than it sounds, and can be done in a number of ways and/or for a number of different reasons. In short, don't be scared of the word 'supercomputer' and the unfamiliar environment it may represent.

## How can Hawk be used?

Hawk can be looked at as a general purpose research computing resource. It can run large, parallel, computationally-heavy simulations in very established disciplines such as Computational Chemistry and Computational Fluid Dynamics, but it can also be used to run smaller (PC sized) jobs – potentially in multiples of hundreds or thousands – in newer and growing areas such as Life Sciences or Data Processing that typically use scripting languages such as Python or R. Hawk also provides access to a large array of scientific software that is installed, and can be used interactively for development work.

In short, Hawk may enable you to do _bigger_ tasks, _longer_ tasks or _more_ tasks.

## How is Hawk accessed and used?

Hawk is physically based in Cardiff, but Bangor benefits from a good network to access the system, which offers sufficient capacity to transfer large datasets.

By registering to use Hawk via the MySCW Registration web site, Bangor researchers will be issued with a userid and able to set their own password, the combination of which enables access.

Hawk is fronted by a pair of __login nodes__ that are used for both data transfer to/from Hawk and for interactive use at the Linux command-line. The __compute nodes__ that do the actual work are not directly accessed by users and access thereto is managed by the __scheduler__. Users submit their __jobs__ into a number of __queues__, and the __scheduler__ then runs those jobs when compute resources are available, taking all the inputs and producing the outputs just as if the operations they comprise were run manually by the user.

## Getting Access

The Supercomputing Wales User Portal at [http://portal.supercomputing.wales](http://portal.supercomputing.wales/) provides the necessary links and guidance on registering to use Hawk. Once registered, Bangor staff will provide all the support you need to make the most of the system in supporting and enabling your research.  The Bangor eResearch team can be reached via <research-computing@bangor.ac.uk>.
