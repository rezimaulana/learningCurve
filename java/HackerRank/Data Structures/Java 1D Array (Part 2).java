import java.util.*;

public class Solution {

    public static boolean canWin(int leap, int[] game) {
        // Return true if you can win the game; otherwise, return false.
            boolean winnable = false;

    Stack<Integer> visitedZeros = new Stack<Integer>();

    List<Integer> visited = new ArrayList<Integer>();

    visitedZeros.push(0);
    while(!visitedZeros.isEmpty())  {
        int i = visitedZeros.pop();
        while(i<game.length) {

            if (i == game.length - 1 || i+leap > game.length - 1){
                winnable = true;
                break;
            } else if( !visited.contains(i+1) && game[i+1] == 0 ) {
                //leapedZeros.put(i, Boolean.FALSE);
                i++;
                visited.add(i);  
                visitedZeros.push(i);              
            } else if (!visited.contains(i+leap)&& game[i+leap] == 0) {

                //leapedZeros.put(i, Boolean.TRUE);
                i+=leap;             
                visited.add(i);
                visitedZeros.push(i);
            } 
            else if (i>0 && !visited.contains(i-1) && game[i-1] == 0) {
                i--;
                visited.add(i);
                visitedZeros.push(i);
            }
            else {
                break;
            }
        }
    }

    return winnable;
    }

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int q = scan.nextInt();
        while (q-- > 0) {
            int n = scan.nextInt();
            int leap = scan.nextInt();
            
            int[] game = new int[n];
            for (int i = 0; i < n; i++) {
                game[i] = scan.nextInt();
            }

            System.out.println( (canWin(leap, game)) ? "YES" : "NO" );
        }
        scan.close();
    }
}