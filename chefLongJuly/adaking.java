import java.util.*;
import java.io.*;


class IO {
    /*function takes a BufferedReader as args and gives an int as output  */
    static int input(BufferedReader reader) throws IOException{
        int a=0;
        String c = reader.readLine();
        a =Integer.parseInt(c);
        return a;
    }
    /*----end---prototype:
     BufferedReader reader =  new BufferedReader(new InputStreamReader(System.in));
     int a=input(bf); */
    /*function takes BufferedReader as args and gives List<Integer> as output*/
}
class King{
    static void print(String s){
        System.out.print(s);
    }
    static void println(String s){
        System.out.println(s);
    }
    static void board(int k){
        int freeline=k/8;

        if(freeline==0){
            print("O");
            for (int i=0;i<k-1;i++)
                print(".");
            print("X");
            for (int i=0;i<7-k;i++)
                print(".");
            println("");
            for (int i=0;i<k+1;i++)
                print("X");
            for (int i=0;i<7-k;i++)
                print(".");
            println("");
            for (int i=0;i<6;i++){
                for(int j=0;j<8;j++){
                    print(".");
                }
                println("");
            }
        }else {
            int line=0;
            print("O");
            for (int i=0;i<7;i++)
                print(".");
            println("");
            line+=1;
            //System.out.println(line);
            for(int i=0;i<freeline-1;i++){
                for (int j=0;j<8;j++){
                    print(".");
                }
                println("");
                line+=1;
                //System.out.println(line);
            }
            int _final=k%8;
            //System.out.println(_final);
            if(_final>0) {
                if(line<8){
                for (int i = 0; i < _final; i++)
                    print(".");
                for (int i = 0; i < 8 - _final; i++)
                    print("X");
                println("");
                line+=1;
                    //System.out.println(line);
                    }
                if(line<8){
                for (int i = 0; i <= _final; i++)
                    print("X");
                for (int i = 0; i < 7 - _final; i++)
                    print(".");
                println("");
                line+=1;
                    //System.out.println(line);
                    }
            }else {
                if(line<8){
                for (int i=0;i<8;i++){
                    print("X");
                }
                println("");
                line+=1;
                    //System.out.println(line);
                    }
                if(line<8){
                for (int i=0;i<8;i++){
                    print(".");
                }
                println("");
                line+=1;
                    //System.out.println(line);
                    }

            }
            if(freeline>0) {
                for (int i = 0; i < 6 - freeline && line<8; i++) {
                    for (int j = 0; j < 8; j++) {
                        print(".");
                    }
                    println("");
                    line+=1;
                    //System.out.println(line);
                }
            }

        }
    }
    public static void main(String[]args)throws IOException{
        int t,k;
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        t=IO.input(reader);
        while (t>0){
            k=IO.input(reader);
            board(k);
            t--;
        }
    }
}