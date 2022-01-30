import java.io.*;

public class A{
    public static void main(String[] args)throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().trim());
        int n,maxA,maxB,temp;
        String input[];
        int a[],b[];
        while(t-->0){
            maxA=maxB=0;
            n= Integer.parseInt(br.readLine().trim());
            a= new int[n];
            b= new int[n];
            input=br.readLine().trim().split(" ");
            for(int i=0;i<n;i++){
                a[i]=Integer.parseInt(input[i]);
            }
            input=br.readLine().trim().split(" ");
            for(int i=0;i<n;i++){
                b[i]=Integer.parseInt(input[i]);
            }
            for(int i=0;i<n;i++){
                if(a[i]<b[i]){
                    temp=a[i];
                    a[i]=b[i];
                    b[i]=temp;
                }
                maxA=Math.max(maxA,a[i]);
                maxB=Math.max(maxB,b[i]);
            }
            System.out.println(maxA*maxB);
        }
    }
}