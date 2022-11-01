import java.util.*;

class Solution{
    public static void main(String []argh){
        Scanner in = new Scanner(System.in);
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            int a = in.nextInt();
            int b = in.nextInt();
            int n = in.nextInt();
            int s=a;
            for (int j=0; j<n; j++){
                int sum=0;
                sum+= (Math.pow(2,j))*b;
                s=s+sum;
                System.out.print((s)+" ");
            }
            System.out.println("");
        }
        in.close();
    }
}