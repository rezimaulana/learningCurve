//Java Output Formatting
import java.util.Scanner;

public class Solution {

    public static void main(String[] args) {
            Scanner sc=new Scanner(System.in);
            System.out.println("================================");
            for(int i=0;i<3;i++)
            {
                String s1=sc.next();
                int x=sc.nextInt();
                //Complete this line
                
                System.out.print(s1);
                for(int j = s1.length(); j< 15; j++){
                    System.out.print(" ");
                }
                if(x>=100){
                    System.out.print(x);
                }else if (x<100 && x >=10){
                    System.out.print("0"+x);
                }else if(x<10){
                    System.out.print("00"+x);
                }
                System.out.println();
                
            }
            System.out.println("================================");

    }
}



