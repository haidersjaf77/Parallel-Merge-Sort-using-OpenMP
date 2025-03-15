# Parallel Merge Sort using OpenMP  

## Overview  
This project implements **Parallel Merge Sort** using **OpenMP** to enhance computational efficiency on shared-memory systems. The program generates a **random integer array**, applies **parallel sorting**, and measures execution time to analyze performance improvements over increasing array sizes.  

## Features  
- **Parallel Merge Sort Implementation** using OpenMP.  
- **Random Array Generation** for flexible input sizes.  
- **Execution Time Measurement** to evaluate sorting performance.  
- **Thread Optimization** by adjusting OpenMP settings.  
- **Performance Analysis** with different array sizes.  

## Technologies Used  
- **C++**  
- **OpenMP** (for parallelization)  
- **Chrono Library** (for execution time measurement)  

## How to Run  
1. **Ensure OpenMP is installed** (included in most modern C++ compilers).  
2. **Compile the program**:  
   ```sh
   g++ -fopenmp parallel_merge_sort.cpp -o parallel_sort
