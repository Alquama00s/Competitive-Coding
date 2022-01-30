import java.io.*;

public class C {
    static void output(int b, int a) {
        System.out.println(a + " " + b);
    }

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String input[];
        int t, n, k;

        t = Integer.parseInt(br.readLine().trim());
        while (t-- > 0) {
            input = br.readLine().trim().split(" ");
            n = Integer.parseInt(input[0]);
            k = Integer.parseInt(input[1]);
            if (k == 0) {
                for (int i = 0; i < n / 2; i++) {
                    output(i ^ (n - 1), i);
                } 
            } else if (k == n - 1) {
                if (n == 4)
                    System.out.println(-1);
                else {
                    output(n - 1, n - 2);
                    output(n - 3, 1);
                    output(2, 0);
                    for (int i = 3; i < n / 2 ; i++) {
                        output(i ^ (n - 1), i);
                    }
                }
            } else {
                output(k ^ (n - 1), 0);
                output(n - 1, k);
                for (int i = 1; i < n / 2 ; i++) {
                    if (i != k && i!= (k ^ (n - 1))) {
                        output(i ^ (n - 1), i);
                    }
                }
            }

        }

    }
}
