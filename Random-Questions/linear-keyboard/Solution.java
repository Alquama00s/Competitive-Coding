import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

//https://codeforces.com/problemset/problem/1607/A
public class Solution{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().strip());
        String alfa,word;
        int ans,prev_char,curr_char;
        while(n-->0){
            ans=0;
            alfa=br.readLine().strip();
            word=br.readLine().strip();
            prev_char=alfa.indexOf(word.charAt(0));
            for (int i = 1; i < word.length(); i++) {
                curr_char=alfa.indexOf(word.charAt(i));
                ans+=Math.abs(curr_char-prev_char);
                prev_char=curr_char;
            }
            System.out.println(ans);
        }
    }
}