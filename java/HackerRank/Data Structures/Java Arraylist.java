import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Scanner sc=new Scanner(System.in);

        ArrayList<ArrayList<Integer>> a=new ArrayList<>();

        int n1=sc.nextInt();
        while((n1--)>0){
            int n=sc.nextInt();
            ArrayList<Integer> t=new ArrayList<>();
            for(int i=0;i<n;i++)
                t.add(sc.nextInt());
            a.add(t);
        }

        int n2=sc.nextInt();

        for(int i=0;i<n2;i++){
        int l=sc.nextInt();
        int p=sc.nextInt();
        if(a.get(l-1).size()==0 || a.get(l-1).size()<p)
                System.out.println("ERROR!");
            else
                System.out.println(a.get(l-1).get(p-1));
        }
        sc.close();
    }
}