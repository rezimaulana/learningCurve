import java.util.*;

public class Solution {

    public static void main(String[] args) {
        /* Enter your code here. Read input from STDIN. Print output to STDOUT. Your class should be named Solution. */
        Solution solution = new Solution();
        solution.app();
    }
    
    private void app() {
        final Scanner scanner = new Scanner(System.in);
        final int b = scanner.nextInt();
        final int h = scanner.nextInt();
        if (b <= 0 || h <= 0){
            System.out.println("java.lang.Exception: Breadth and height must be positive");
        } else {
            System.out.println(b*h);
        }
        scanner.close();
    }
}