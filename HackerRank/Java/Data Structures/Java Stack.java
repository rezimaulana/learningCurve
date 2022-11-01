import java.util.*;
class Solution{
	
	public static void main(String []argh)
	{
		Scanner sc = new Scanner(System.in);
		
		while (sc.hasNext()) {
			String input=sc.next();
            int n=-1;
            while (input.length()!=n){
                n=input.length();
                input=input.replace("{}","");
                input=input.replace("()","");
                input=input.replace("[]","");    
            }
            if (input.length()==0)
                System.out.println("true");
            else
                System.out.println("false");
        }
        sc.close();
	}
}



