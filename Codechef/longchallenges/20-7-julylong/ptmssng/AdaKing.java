import java.io.*;
import java.util.*;

public class AdaKing {

    public static void main(String args[]) throws IOException {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while (t-- > 0) {
            int K = sc.nextInt();
            int i = 0, j = 0;
            for (i = 0; i < 8; i++) {
                for (j = 0; j < 8; j++) {
                    if (i == 0 && j == 0) {
                        System.out.print("O");
                    } else if (K - 1 > 0) {
                        System.out.print(".");
                        K = K - 1;
                    } else {
                        System.out.print("X");
                    }

                }
                System.out.println("");
            }
        }

    }

}