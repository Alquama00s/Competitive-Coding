import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://codeforces.com/problemset/problem/158/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[];
        int data[];
        int n, k, ans = 0;
        input = br.readLine().trim().split(" ");
        n = Integer.parseInt(input[0]);
        k = Integer.parseInt(input[1]);
        input = br.readLine().trim().split(" ");
        data = new int[n];
        for (int i = 0; i < data.length; i++) {
            data[i] = Integer.parseInt(input[i]);
        }
        k--;
        while(k > 0 && data[k]<=0 ){
            k--;
        }

        if (data[k] > 0) {
            if (data[n - 1] == data[k]) {
                ans = n;
            } else {
                for (int i = k; i < data.length; i++) {
                    if (data[i] != data[k]) {
                        ans = i;
                        break;
                    }
                }
            }
        }
        System.out.println(ans);
    }
}