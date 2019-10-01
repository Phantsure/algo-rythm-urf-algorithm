#List should be in Sorted ascending order 

def interpolationSearch(arr, n, x): 
    # Settting indexes of two corners 
    lo = 0
    hi = n 
   
    while (lo <= hi and x >= arr[lo] and x <= arr[hi]): 
        if lo == hi: 
            if arr[lo] == x:  
                return lo; 
            return -1; 

        pos  = lo + int(((float(hi - lo) / 
            ( arr[hi] - arr[lo])) * ( x - arr[lo]))) 
  

        if arr[pos] == x: 
            return pos 
   
        if arr[pos] < x: 
            lo = pos + 1; 
   
        else: 
            hi = pos - 1; 
      
    return -1

print("Enter the elements of the array in a single line: ")
arr = list(map(int,input().split()))
num = int(input("Enter the number you want to search\n"))

index = interpolationSearch(arr, len(arr)-1, num) 

if (index != -1): 
    print ("Element found at index ",index )
else: 
    print ("Element not found")