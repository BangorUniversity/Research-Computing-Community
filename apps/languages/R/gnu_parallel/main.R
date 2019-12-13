args <- commandArgs(trailingOnly = TRUE)

species <- tolower(args[1])
species

paste(Sys.info()[['nodename']], Sys.getpid(), sep='-')
