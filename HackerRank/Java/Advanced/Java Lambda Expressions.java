import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int t = scan.nextInt();
        while (t-- > 0) {
            int type = scan.nextInt();
            int number = scan.nextInt();
            PerformOperation op;
            switch (type) {
                case 1:
                    op = isOdd();
                    break;
                case 2:
                    op = isPrime();
                    break;
                case 3:
                    op = isPalindrome();
                    break;
                default:
                    throw new IllegalArgumentException("Invalid type: " + type);
            }
            boolean result = op.check(number);
            String output = "";
            switch (type) {
                case 1:
                    output = result ? "ODD" : "EVEN";
                    break;
                case 2:
                    output = result ? "PRIME" : "COMPOSITE";
                    break;
                case 3:
                    output = result ? "PALINDROME" : "NOT PALINDROME";
                    break;
                default:
                    throw new IllegalArgumentException("Invalid type: " + type);
            }
            System.out.println(output);
        }
    }

    public static PerformOperation isOdd() {
        return n -> n % 2 != 0;
    }

    public static PerformOperation isPrime() {
        return n -> {
            if (n < 2) {
                return false;
            }
            for (int i = 2; i * i <= n; i++) {
                if (n % i == 0) {
                    return false;
                }
            }
            return true;
        };
    }

    public static PerformOperation isPalindrome() {
        return n -> {
            String str = Integer.toString(n);
            String reversed = new StringBuilder(str).reverse().toString();
            return str.equals(reversed);
        };
    }

    interface PerformOperation {
        boolean check(int n);
    }
}
