import java.io.BufferedReader;
import java.io.*;
import java.util.*;

public class A {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        int n;
        int[] data;
        boolean toggle;
        while (t-- > 0) {
            toggle = true;
            n = Integer.parseInt(br.readLine().trim());
            data = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
            for (int j = 1; j < data.length; j++) {
                if (data[j - 1] > data[j]) {
                    toggle = false;
                    break;
                }
            }
            if (toggle)
                System.out.println("NO");
            else
                System.out.println("YES");
        }

    }
}
