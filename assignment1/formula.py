# ref : https://medium.com/@adarshtyagi/fibonacci-in-constant-time-945546c9e64c
import time
n = int(input("Enter the nth term: "))

def fibonacci(n):
    a = (1 + (5 ** 0.5)) / 2
    b = (1 - (5 ** 0.5)) / 2
    return int((a ** n - b ** n) / (5 ** 0.5))
start_time = time.time()
print(fibonacci(n))
end_time = time.time()
print("Time taken to execute: ", end_time - start_time)
