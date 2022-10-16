import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc = new Scanner(System.in); 
        int n = sc.nextInt();
        int[] arr = new int[n]; 
        int Neg = 0; 

        for(int j = 0; j < n; j++){
            arr[j] = sc.nextInt();

            int Sum = 0; 
            for(int i = j; 0 <= i; i--){
                Sum += arr[i]; 
                if(Sum < 0) Neg++; 
            }
        }
        sc.close();
        System.out.print(Neg);
    }
}