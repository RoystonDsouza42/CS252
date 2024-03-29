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
  
## Results
  The statistical values obtained are displayed below
  
  #### 1. For odd number of data elements 
  ![result_stat1](https://user-images.githubusercontent.com/93470434/142973112-e2c2c0e0-6ccd-457c-83a2-5939e0f6d916.png)
  
  #### 2. For even number of data elements
  ![result_stat2](https://user-images.githubusercontent.com/93470434/142973728-d2c0b030-4315-4e9f-bec5-47d65709b55f.png)

The following thread fuctions and declarations were used:
  1. ``` pthread_t {thread name }```
      * Used to declare a thread.
      * store the thread ID of the new thread.
      * example : `pthread_t t1;`
  
  2. ``` int pthread_create(pthread_t *thread, pthread_attr_t *attr, void *(*start_routine) (void *arg), void *arg); ```
      * thread: location where the thread ID is stored
      * attr:  structure that specifies the attributes of the new thread.
      * start_routine: routine where the thread begins.
      * arg : arguments to pass to start_routine.
      * example : `pthread_create(&t1,NULL,&avg,NULL);`
  
  3. ```  void pthread_exit(void *status); ```
      * Used to terminate a thread.
      * example : `pthread_exit(NULL);`
  
  4. ``` int pthread_join(pthread_t thread, void **status); ```
      * Used to wait for the termination of a thread
      * example : `pthread_join(t1,NULL);`

 ## References
  * [https://www.homeworklib.com/qaa/1707080/write-in-c-program-write-a-multi-threaded-program](https://www.homeworklib.com/qaa/1707080/write-in-c-program-write-a-multi-threaded-program)
  * [https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-pthread-create-create-thread](https://www.ibm.com/docs/en/zos/2.2.0?topic=functions-pthread-create-create-thread)

Note: Code based on [www.homeworklib.com](https://www.homeworklib.com/qaa/1707080/write-in-c-program-write-a-multi-threaded-program). A array was created using dynamic memory allocation to store inputs obtained from command line, code to calculate median and standard deviation was added. Apart from this several other small modifications were made.

## License
No license was found on their website. The author does not intend any copyright infringement.
