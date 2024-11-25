import time
n = int(input("Enter the nth term: "))
def fibonacci(n):
    if(n == 2 or n == 1):
        return 1
    a = 1
    b = 1
    for i in range(3, n+1):
        c = a + b
        a = b
        b = c
    return b
start_time = time.time()
print(fibonacci(n))
end_time = time.time()
print("Time taken to execute: ", end_time - start_time)
