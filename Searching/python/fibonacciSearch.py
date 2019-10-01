#List should be in Sorted ascending order 

from bisect import bisect_left 
def fibonacciSearch(arr, x, n): 
      
    # Initialize fibonacci numbers  
    m2 = 0 # (m-2)'th Fibonacci No. 
    m1 = 1 # (m-1)'th Fibonacci No. 
    m = m2 + m1 # m'th Fibonacci 
  
    # m is going to store the smallest  
    # Fibonacci Number greater than or equal to n  
    while (m < n): 
        m2 = m1 
        m1 = m 
        m = m2 + m1 
   
    offset = -1; 

    while (m > 1): 
        i = min(offset+m2, n-1)   
        if (arr[i] < x): 
            m = m1 
            m1 = m2 
            m2 = m - m1 
            offset = i 
        elif (arr[i] > x): 
            m = m2 
            m1 = m1 - m2 
            m2 = m - m1 
        else : 
            return i 
  
    if(m1 and arr[offset+1] == x): 
        return offset+1; 
    return -1

print("Enter the elements of the array in a single line: ")
arr = list(map(int,input().split()))
num = int(input("Enter the number you want to search\n"))

ind = fibonacciSearch(arr, num, len(arr))
if(ind>=0):
    print("Found at index: ",ind)
else:
    print("Searched Element not found") 
      