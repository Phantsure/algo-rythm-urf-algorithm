// Linear Search in Golang
package main
import "fmt"
 
func linearSearch(target int, array []int) int {
 
    for i:=0; i<len(array);i++{
        if array[i] == target{
            return i
    }
    }
    return -1 
}

func main(){
    items := []int{1,2, 4, 8, 16, 32, 64}
    fmt.Println(linearSearch(64, items))
}