# Question 4.22 - Chapter 4 - Threads & Concurrency

## Statement
<p>Write a multithreaded program that calculates various statistical values
for a list of numbers. This program will be passed a series of numbers
on the command line and will then create three separate worker threads.
One thread will determine the average of the numbers, the second will
determine the maximum value, and the third will determine the minimum
value. For example, suppose your program is passed the integers<p>
<p align = "center">90 81 78 95 79 72 85<p>
The program will report<br>
<p>The average value is 82<br>
The minimum value is 72<br>
The maximum value is 95<br><p>
The variables representing the average, minimum, andmaximum values
will be stored globally. The worker threads will set these values, and
the parent thread will output the values once the workers have exited.
(We could obviously expand this program by creating additional threads
that determine other statistical values, such as median and standard
deviation.)
  
## Instructions
[Statistical_values.c](https://github.com/RoystonDsouza42/CS252/blob/main/Question%204.22/Statistical_values.c) - source code for statistical values program.
  
#### Instructions to follow while compiling this code
Enter the following on the command line<br>
1. ``` gcc Statistical_values.c -o stats -lm -lpthread ```
  
The data is then provided on the command line:<br> 
  
2. ``` ./stats {data... } ```

The result: maximum, minimum, average, median and standard deviation is display on the command line.
