import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

class Result {

    /*
     * Complete the 'miniMaxSum' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void miniMaxSum(List<Integer> arr) {
    // Write your code here
        final List<Long> arrl = new ArrayList<>();
        for (Integer num : arr) {
            arrl.add(num.longValue());
        }
        long minSum = 0;
        long maxSum = 0;
        for (int i = 0; i < arrl.size(); i++) {
            for (int j = i+1; j < arrl.size(); j++) {
                if (arrl.get(i) > arrl.get(j)) {
                    long temp = arrl.get(i);
                    arrl.set(i, arrl.get(j));
                    arrl.set(j, temp);
                }
            }
        }
        for(int k = 0; k<4; k++){
            minSum += arrl.get(k);
            maxSum += arrl.get(arrl.size()-1-k);
        }
        System.out.print(minSum+" "+maxSum);
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        Result.miniMaxSum(arr);

        bufferedReader.close();
    }
}
