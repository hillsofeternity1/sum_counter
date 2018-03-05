# Ultradesu 2017
# Because of GIL which doesn't allow to implement simultaneous computing 
# i had to use forks instead on threads for full utilization system resources.
# This version much slower rather C.

import multiprocessing
import time

# calculating summ between start and end. 
def sumumatoru_kun(start, end, number, return_dict):
    t = time.process_time()
    sum_ = 0
    ss = start
    ee = end
    while start <= end:
        for digit in str(start):
            sum_ += int(digit)
        start += 1
    return_dict[number] = sum_
    elapsed_time = time.process_time() - t
    print(" %s\t|%10d\t|%10d\t|%10d\t|\t%6.2f" % (number, ss, ee, sum_, elapsed_time))
    return sum_

def summ():
    start = 0
    end = 10000000
    thread_count = multiprocessing.cpu_count() * 2

    shift = int((end - start) / thread_count)
    result = 0
    print('Found %s CPUs. Going to spawn %s forks.' % (int(thread_count/2), thread_count))
    t = time.process_time()
    print("proc #\t|\tfrom\t|\ttill\t|\tsumm\t| elapsed time per child")
    print("-"*80)
    manager = multiprocessing.Manager()
    return_dict = manager.dict()
    jobs = []
    for i in range(thread_count):
        t_start = start + shift * i
        if i == (thread_count - 1):
            t_end = end
        else:
            t_end = t_start + shift - 1
        p = multiprocessing.Process(target=sumumatoru_kun, args=(t_start,t_end, i, return_dict))
        jobs.append(p)
        p.start()

    for proc in jobs:
        proc.join()
    for value in return_dict.values():
        result = result + value
    print("\n\tFinal result is %d" % result)

if __name__ == '__main__':
    summ()
