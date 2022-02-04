import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://codeforces.com/problemset/problem/71/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        String str;
        while (t-- > 0) {
            str = br.readLine().trim();
            if (str.length() > 10)
                System.out.println(str.substring(0, 1) + String.valueOf(str.length() - 2)
                        + str.substring(str.length() - 1, str.length()));
            else
                System.out.println(str);
        }
    }
}