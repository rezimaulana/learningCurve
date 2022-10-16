import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        int count = 0;
        Scanner sc = new Scanner(System.in);
        String str =  sc.nextLine();
        str = str.trim();
        String[] arr =  str.split("[!,?._'@ ]+");
        int size = (str.isEmpty()) ? 0 : arr.length;
        System.out.println(size);
        for(String i : arr){
            System.out.println(i);
        }
        sc.close();
    }
}

