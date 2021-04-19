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

Results

* sable-intel ([Summary sheet](https://docs.google.com/spreadsheets/d/1h9GHvkmiJ0Vbp6Le4HQdXxawH5fOy-eXT7ov7EwsLIE/edit#gid=1003938004))
    - HorsePower
        + Path: `exp/tpch/fastgen`
        + Log: `log/run4`
    - MonetDB
        + Path: `exp/monetdb`
        + Log: `log/run5`
* sable-tigger ([Summary sheet](https://docs.google.com/spreadsheets/d/1h9GHvkmiJ0Vbp6Le4HQdXxawH5fOy-eXT7ov7EwsLIE/edit#gid=2098237371))
    - HorsePower
        + Path: `exp/tpch/fastgen`
        + Log: `log/run5`
    - MonetDB
        + Path: `exp/monetdb`
        + Log: `log/run6`
* analysis ([Summary sheet](https://docs.google.com/spreadsheets/d/1h9GHvkmiJ0Vbp6Le4HQdXxawH5fOy-eXT7ov7EwsLIE/edit#gid=1434279808))
    - HorsePower
        + Path: `exp/tpch/new-analysis`
        + Log: `log/run2`


## 2. Experiments: Array Programs

Benchmarks

- Black-Scholes
- Morgan

Results ([Summary sheet](https://docs.google.com/spreadsheets/d/1h9GHvkmiJ0Vbp6Le4HQdXxawH5fOy-eXT7ov7EwsLIE/edit#gid=0))

* Black-Scholes
  - HorsePower
      + Path: `exp/morgan/hir/gencode`
      + Log: `log/run1`
  - MATLAB
      + Path: `exp/morgan/matlab`
      + Log: `log/run1`
* Morgan
  - HorsePower
      + Path: `exp/bs/hir/gencode`
      + Log: `log/run1`
  - MATLAB
      + Path: `exp/morgan/matlab`
      + Log: `log/run4`


## 3. Experiments: Queries and UDFs

Benchmarks

- udf-froid
- udf-bs

Results ([Summary sheet](https://docs.google.com/spreadsheets/d/1-V5bIV2EtWUS8g26YMDidXljymy_3pA0GJMh6v70wOY/edit#gid=1173154133))

* udf-froid: queries derived from TPC-H queries on the Froid paper
  - HorsePower
      + Path: `exp/udf/froid/hir`
      + Log: `log/sf8`
  - MonetDB
      + Path: `exp/udf/froid/monetdb`
      + Log: `log/sf8`
* udf-bs: queries derived from the Black-Scholes code
  - HorsePower
      + Path: `exp/udf/bs/hir`
      + Log: `log`
  - MonetDB
      + Path: `exp/udf/bs/monetdb`
      + Log: `log/log-t*`


## 4. Experiments: GPU Benchmarks

Benchmarks

- Black-Scholes
- Morgan

Results ([Summary sheet](https://docs.google.com/spreadsheets/d/1h9GHvkmiJ0Vbp6Le4HQdXxawH5fOy-eXT7ov7EwsLIE/edit#gid=1240442184))

* Black-Scholes
  - HorsePower
      + Path: `exp/morgan/gpu`
      + Log: `log/run1`
* Morgan
  - HorsePower
      + Path: `exp/bs/gpu`
      + Log: `log/run2`

