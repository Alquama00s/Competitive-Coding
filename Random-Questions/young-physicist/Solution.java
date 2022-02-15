import java.io.*;
import java.util.*;

//https://codeforces.com/problemset/problem/69/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int[] sum = new int[] { 0, 0, 0 }, in;
        while (n-- > 0) {
            in = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
            sum[0] += in[0];
            sum[1] += in[1];
            sum[2] += in[2];
        }
        if (sum[0] == 0 && sum[1] == 0 && sum[2] == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}