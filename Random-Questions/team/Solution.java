import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://codeforces.com/problemset/problem/231/A
public class Solution{
    public static void main(String[] args) throws IOException{
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[];
        int n= Integer.parseInt(br.readLine().trim());
        int t1,t2,t3,ans=0;
        while(n-->0){
            input = br.readLine().trim().split(" ");
            t1= Integer.parseInt(input[0]);
            t2= Integer.parseInt(input[1]);
            t3= Integer.parseInt(input[2]);
            if(t1+t2+t3>1){
                ans++;
            }
        }
        System.out.println(ans);
    }
}