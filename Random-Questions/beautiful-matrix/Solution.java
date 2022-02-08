import java.io.*;

//https://codeforces.com/problemset/problem/263/A
public class Solution {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[];
        boolean done =false;
        for (int i = 0; i <5 && !done; i++) {
            input = br.readLine().trim().split(" ");
            
            for (int j = 0; j < 5; j++) {
                if(Integer.parseInt(input[j])==1){
                    System.out.println(Math.abs(i-2)+Math.abs(j-2));
                    done=true;
                    break;
                }
            }
        }
    }

}
