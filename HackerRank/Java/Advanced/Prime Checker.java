import java.io.*;
import java.util.*;

import java.util.Scanner;

class Prime {
    public void checkPrime(int... numbers) {
        for (int num : numbers) {
            boolean isPrime = true;
            if (num < 2) {
                isPrime = false;
            }
            for (int i = 2; i <= Math.sqrt(num); i++) {
                if (num % i == 0) {
                    isPrime = false;
                    break;
                }
            }
            if (isPrime) {
                System.out.print(num + " ");
            }
        }
        System.out.println();
    }
}

public class Solution {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int p = scan.nextInt();
        int q = scan.nextInt();
        int r = scan.nextInt();
        int s = scan.nextInt();
        int t = scan.nextInt();
        Prime obj = new Prime();
        obj.checkPrime(p);
        obj.checkPrime(p, q);
        obj.checkPrime(p, q, r);
        obj.checkPrime(p, q, r, s, t);
    }
}
