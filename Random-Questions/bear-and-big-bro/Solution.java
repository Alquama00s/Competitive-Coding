import java.io.*;
import java.util.*;

//https://codeforces.com/problemset/problem/791/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] data = Arrays.stream(br.readLine().strip().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        System.out.println((int) ((Math.log((float) data[0] / data[1]) / Math.log(2.0 / 3.0)) + 1.0000001));
    }
}