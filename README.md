# Repository for Hanfeng's Thesis

This repository is created for showing details of experiments in the thesis,
including source code, data, and intermediate results.
They are placed under the folder `exp`.
We also provide [a google sheet](https://docs.google.com/spreadsheets/d/1h9GHvkmiJ0Vbp6Le4HQdXxawH5fOy-eXT7ov7EwsLIE/edit?usp=sharing)
containg the summary of our intermeidate results.


## Setup

Machines

| Item            | sable-intel             | sable-tigger            |
| :-------------: | :---------------------: | :---------------------: | 
| CPU             | E7-4850 @ 2.00 GHz      | i7-8700K @ 3.70 GHz     |
| L1 Cache        | 32 KB                   | 32 KB                   |
| L2 Cache        | 256 KB                  | 256 KB                  |
| L3 Cache        | 24 MB                   | 12 MB                   |
| Threads per Core| 2                       | 2                       |
| Cores per Socket| 10                      | 6                       |
| Sockets         | 4                       | 1                       |
| Total Threads   | 80                      | 12                      |
| Thread Scales   | T1/2/4/8/16/32/64       | T1/2//4/8/16            |
| RAM Size        | 128 GB                  | 32 GB                   |
| GPU             | (No GPU)                | GeForce GTX 1080 Ti     |
| Operation System| Ubuntu 18.04.04 LTS     | Ubuntu 18.04.04 LTS     |


Software

- MonetDB v11.35.9 (Nov2019-SP1)
- MATLAB version R2019a
- GCC v8.1.0 (-O3, -march=native)
- NVIDIA PGI compiler 19.10-0 (-O4)


Methodology

- In terms of execution time, we only consider the time once data resides in
  main memory.
- We consider performance variance by running each test 15 times, measuring the
  average execution time over the last 10 runs.


## 1. Experiments: Database Queries

Benchmarks

- 22 TPC-H benchmarks

Folder

- `exp/tpch/new-analysis/`

Results ([Summary sheet](https://docs.google.com/spreadsheets/d/1h9GHvkmiJ0Vbp6Le4HQdXxawH5fOy-eXT7ov7EwsLIE/edit#gid=1434279808))

- `exp/tpch/new-analysis/log/run2`


## 2. Experiments: Array Programs


## 3. Experiments: Queries and UDFs

## 4. Experiments: GPU Benchmarks



