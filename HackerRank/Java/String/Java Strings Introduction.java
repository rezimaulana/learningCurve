import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        
        final Scanner sc=new Scanner(System.in);
        final String A=sc.next();
        final String B=sc.next();
        /* Enter your code here. Print output to STDOUT. */
        
        final String capA = A.substring(0, 1).toUpperCase() + A.substring(1);
        final String capB = B.substring(0, 1).toUpperCase() + B.substring(1);
        
        System.out.println(A.length()+B.length());
        System.out.println(A.compareTo(B) > 0 ? "Yes" : "No");
        System.out.println(capA+" "+capB);
    }
}



