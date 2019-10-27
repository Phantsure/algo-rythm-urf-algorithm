import java.util.Scanner;

public class linearSearch{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of entries : ");
        int n = sc.nextInt();
        int []a = new int[n];
        for(int i = 0; i < n; i++){
            a[i] = sc.nextInt();
        }
        System.out.println("Enter the element to be searched : ");
        int element = sc.nextInt();
        boolean flag = false;
        for(int i = 0; i < n; i++){
            if(a[i] == element){
                System.out.println("Element found at index : " + (i + 1));
                flag = true;
            }
        }
        if(!flag)
            System.out.println("Element not found");
    }
}