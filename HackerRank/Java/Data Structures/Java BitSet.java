import java.io.*;
import java.util.*;

public class Solution {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        
        // Read length of bit sets and num of operations
        int length = scanner.nextInt();
        int numOfOperations = scanner.nextInt();
        
        // Create two bit sets and put links to the array
        BitSet bitSet1 = new BitSet(length);
        BitSet bitSet2 = new BitSet(length);
        BitSet[] bitSets = {bitSet1, bitSet2};
        
        // Create operational variables
        String operation = "";
        int firstArg = 0;
        int secondArg = 0;
        
        // For each operation
        for (int i = 0; i < numOfOperations; i++) {
            // Read type of operation and read args
            operation = scanner.next();
            firstArg = scanner.nextInt();
            secondArg = scanner.nextInt();
            
            // for each operation define case
            switch (operation){
                // Retreive relevant bit set from array
                // and call the operation on this set
                case "AND":
                    bitSets[firstArg-1].and(bitSets[secondArg-1]);
                    break;
                case "OR":
                    bitSets[firstArg-1].or(bitSets[secondArg-1]);
                    break;
                case "XOR":
                    bitSets[firstArg-1].xor(bitSets[secondArg-1]);
                    break;
                case "FLIP":
                    bitSets[firstArg-1].flip(secondArg);
                    break;
                case "SET":
                    bitSets[firstArg-1].set(secondArg);
                    break;
            }
            
            // After each operation output num of bits set to 1
            // using cardinality() from BitSet class
            System.out.printf("%d %d%n",
                bitSet1.cardinality(),
                bitSet2.cardinality()
            );
        }
    }
}