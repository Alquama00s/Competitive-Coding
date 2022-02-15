import java.io.*;
import java.util.*;

public class two {
    public static void main(String[] args) throws IOException {
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        int[] count, data;
        int n;
        String ans;
        while (t-- > 0) {
            ans = "YES";
            n = Integer.parseInt(br.readLine().trim());
            data = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
            count = new int[n + 1];
            Arrays.fill(count, 0);
            for (int j = 0; j < 2 * n; j++) {
                count[data[j]]++;
            }
            for (int j = 0; j < count.length; j++) {
                
                if (count[j] == 0)
                    break;
                if (count[j] == 1) {
                    ans = "NO";
                }
            }
            System.out.println(ans);
        }  
    }
}
