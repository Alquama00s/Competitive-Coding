import java.io.*;
import java.util.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t, n, temp;
        int[] data;
        boolean toggle;
        t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            toggle = true;
            n = Integer.parseInt(br.readLine().trim());
            data = Arrays.stream(br.readLine().trim().split(" ")).mapToInt(I -> Integer.parseInt(I)).toArray();
            for (int j = data.length; j >1 && toggle; j--) {
                for (int i = 1; i < j; i++) {
                    if (data[i] < data[i - 1]) {
                        if ((data[i] + data[i - 1]) % 2 != 0) {
                            temp = data[i];
                            data[i] = data[i - 1];
                            data[i - 1] = temp;
                        } else {
                           
                            toggle = false;
                            break;
                        }
                    }
                }
            }
            if (toggle) {
                System.out.println("Yes");
            } else {
                System.out.println("No");
            }
        }
    }
}