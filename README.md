# sum_counter
Homebrewed bad benchmark tool.


just sum every digit of every number. 
ex. 0 - 12 = 0 + 1 + 2 + 3 + 4 + 5 + 6 + 7 + 8 + 9 + *1 + 0 + 1 + 1 + 1 + 2* = 51

All versions use fork and tested on linux.

GO version (Author: Mikhalich)
```Processing sequence from 0 to 1000000000
Shard size: 250000000
remainder: 0
0 250000000
250000001 500000001
500000002 750000002
750000003 1000000000
Result: 40500000001

real	0m4.112s
user	0m15.037s
sys	0m0.014s
```

C version
```
This system has 4 processors configured. Going to spawn 8 forks.
Child 28454 was started. My job is 	0 	125000000
Child 28455 was started. My job is 	125000000 	250000000
Child 28456 was started. My job is 	250000000 	375000000
Child 28458 was started. My job is 	500000000 	625000000
Child 28457 was started. My job is 	375000000 	500000000
Child 28461 was started. My job is 	875000000 	1000000000
Child 28460 was started. My job is 	750000000 	875000000
Child 28459 was started. My job is 	625000000 	750000000
28453 - Sumumatoru kun handled 8 forks and got result 40500000001
```

Python version
```
Found 4 CPUs. Going to spawn 8 forks.
proc #	|	from	|	till	|	summ	| elapsed time per child
----------------------------------------------------------
 0	|         0	|    124999	|   2732500	|	  0.14
 1	|    125000	|    249999	|   2967500	|	  0.16
 2	|    250000	|    374999	|   3157500	|	  0.16
 3	|    375000	|    499999	|   3392500	|	  0.16
 4	|    500000	|    624999	|   3357500	|	  0.16
 5	|    625000	|    749999	|   3592500	|	  0.16
 7	|    875000	|   1000000	|   4017501	|	  0.16
 6	|    750000	|    874999	|   3782500	|	  0.16

	Final result is 27000001

real	0m0.471s
user	0m1.337s
sys	0m0.040s
```
