import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t, n, firstDifference, orignalNumber;
        int[] data;
        String ans;
        t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            ans="";
            n = Integer.parseInt(br.readLine().trim());
            firstDifference = orignalNumber = n;
            data = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(I -> Integer.parseInt(I)).toArray();
            for (int i = 0; i < data.length; i++) {
                if (data[i] != i + 1) {
                    firstDifference = i;
                    break;
                }
                ans+= data[i] + " ";
            }
            if (firstDifference != n) {
                for (int i = firstDifference; i < data.length; i++) {
                    if (data[i] == firstDifference + 1) {
                        orignalNumber = i;
                        break;
                    }
                }

                for (int i = orignalNumber; i >= firstDifference; i--) {
                    ans+= data[i] + " ";
                }
                for (int i = orignalNumber + 1; i < data.length; i++) {
                    ans+= data[i] + " ";
                }
            }
            System.out.println(ans);
        }
    }
}