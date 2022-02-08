import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://codeforces.com/problemset/problem/281/A
public class Solution{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String in = br.readLine().strip();
        System.out.println(in.substring(0, 1).toUpperCase().concat(in.substring(1)));
    }
}