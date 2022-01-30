import java.io.*;

public class B {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        int n, contag, op, val;
        String input[];
        int a[];
        while (t-- > 0) {
            op = 0;
            n = Integer.parseInt(br.readLine().trim());
            a = new int[n];
            input = br.readLine().trim().split(" ");
            for (int i = 0; i < n; i++) {
                a[i] = Integer.parseInt(input[i]);
            }
            val = a[n - 1];
            contag = 1;
            for (int i = n - 2; i >= 0; i--) {
                
                if (a[i] != val) {
                    op++;
                    i -= contag;
                    i += 1;
                    contag *= 2;
                }else{
                    contag++;
                }
                
            }

            System.out.println(op );
        
        }
    }
}