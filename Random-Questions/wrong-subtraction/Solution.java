import java.io.*;
import java.util.*;
//https://codeforces.com/problemset/problem/977/A
public class Solution{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] data = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(i->Integer.parseInt(i)).toArray();
        for (int j = 0; j < data[1]; j++) {
            if(data[0]%10==0){
                data[0]/=10;
            }else{
                data[0]--;
            }
        }
        System.out.println(data[0]);
    }
}