// Binary Search in Golang
package main
import "fmt"
 
func binarySearch(target int, array []int) int {
 
    low := 0
    high := len(array) - 1
 
    for low <= high{
        middle:= (high-low) / 2 + low
 
        if array[middle] == target{
            return middle
    }
        if array[middle] < target {
            low = middle + 1
        }else{
            high = middle - 1
        }
    }
    return -1 
}

func main(){
    items := []int{1,2, 4, 8, 16, 32, 64}
    fmt.Println(binarySearch(64, items))
}