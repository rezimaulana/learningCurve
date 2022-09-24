import java.util.*;
import java.io.*;



class Solution{
    public static void main(String []argh)
    {



        Scanner sc = new Scanner(System.in);
        int t=sc.nextInt();

        for(int i=0;i<t;i++)
        {

            try
            {
                long x=sc.nextLong();
                System.out.println(x+" can be fitted in:");
                if(x>=-128 && x<=127)System.out.println("* byte");
                if(x>=-32_768 && x<=32_767)System.out.println("* short");
                if(x>=-2_147_483_648 &&
                x<=2_147_483_647)System.out.println("* int");
                long max = Long.MAX_VALUE;
                long min = Long.MIN_VALUE;
                if(x>= min && x<= max)System.out.println("* long");
                //Complete the code
            }
            catch(Exception e)
            {
                System.out.println(sc.next()+" can't be fitted anywhere.");
            }

        }
    }
}



