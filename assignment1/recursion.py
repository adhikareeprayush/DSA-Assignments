import time
n = int(input("Enter the nth term: "))
def fibonacci(n):
    if(n == 2 or n == 1):
        return 1
    return fibonacci(n-2) + fibonacci(n-1)
start_time = time.time()
print(fibonacci(n))
end_time = time.time()
print("Time taken to execute: ", end_time - start_time)
