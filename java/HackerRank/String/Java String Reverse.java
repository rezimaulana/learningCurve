import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        Scanner sc=new Scanner(System.in);
        String A=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        final int strLen = A.length()/2;
        boolean status = true;
        for (int i = 0; i<strLen; i++) {
            if (A.charAt(i) == (A.charAt(A.length()-1-i))){
                continue;   
            } else {
                status = false;
                break;
            }
        }
        if(status == false){
            System.out.println("No");
        } else {
            System.out.println("Yes");
        }
    }
}



