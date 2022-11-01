import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        final Scanner inputString = new Scanner(System.in);
        int index = 0;
        while(inputString.hasNext()==true){
            index += 1;
            final String file = inputString.nextLine();
            System.out.println(index+" "+file);
        }
        inputString.close();
    }
}