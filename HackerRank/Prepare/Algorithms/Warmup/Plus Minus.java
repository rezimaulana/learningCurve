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
     * Complete the 'plusMinus' function below.
     *
     * The function accepts INTEGER_ARRAY arr as parameter.
     */

    public static void plusMinus(List<Integer> arr) {
    // Write your code here
        int size = arr.size();
        int positive = 0;
        int negative = 0;
        int zero = 0;
        for(Integer el : arr){
            if(el > 0){
                positive += 1;
            }
            if(el < 0){
                negative += 1;
            }
            if(el == 0){
                zero += 1;
            }
        }
        DecimalFormat decimalFormat = new DecimalFormat("0.000000");
        System.out.println(decimalFormat.format((double) positive / size));
        System.out.println(decimalFormat.format((double) negative / size));
        System.out.println(decimalFormat.format((double) zero / size));
    }

}

public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bufferedReader.readLine().trim());

        List<Integer> arr = Stream.of(bufferedReader.readLine().replaceAll("\\s+$", "").split(" "))
            .map(Integer::parseInt)
            .collect(toList());

        Result.plusMinus(arr);

        bufferedReader.close();
    }
}
