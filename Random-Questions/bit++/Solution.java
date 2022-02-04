import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://codeforces.com/problemset/problem/282/A
public class Solution{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().trim());
        int x=0;
        
        for (int i = 0; i < n; i++) {
            if(br.readLine().trim().contains("++")){
                ++x;
            }else{
                --x;
            }
        }
        System.out.println(x);
        
    }
}