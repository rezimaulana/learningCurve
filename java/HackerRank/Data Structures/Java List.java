import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
         Scanner scan = new Scanner(System.in);
    int listSize= scan.nextInt();
    List<Integer> list=new ArrayList<Integer>();
    for(int i=0; i<listSize;i++){
        list.add(scan.nextInt());
    }
    //System.out.println(list);
    int queries= scan.nextInt();

    for(int i=0;i<queries;i++){
        String query= scan.next();
        //System.out.println(query+"i:"+i);
        if(query.equals("Insert")){
            list.add(scan.nextInt(), scan.nextInt());
        }else if(query.equals("Delete")){
             list.remove(scan.nextInt());

        }

    }

    for(Integer i: list){
        System.out.printf("%d ",i);
    }

    }
}