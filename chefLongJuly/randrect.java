import java.util.*;
import java.io.*;
class IOR {
    /*function takes a BufferedReader as args and gives an int as output  */
    static int input(BufferedReader reader) throws IOException{
        int a=0;
        String c = reader.readLine();
        a =Integer.parseInt(c);
        return a;
    }
    static Long Linput(BufferedReader reader) throws IOException{
        Long a=0L;
        String c = reader.readLine();
        a =Long.parseLong(c);
        return a;
    }
    /*----end---prototype:
     BufferedReader reader =  new BufferedReader(new InputStreamReader(System.in));
     int a=input(bf); */
    /*function takes BufferedReader as args and gives List<Integer> as output*/
    /*static List<Integer> intInput(BufferedReader reader) throws IOException{
        String input = reader.readLine();
        List<Integer> integer = new ArrayList<Integer>();
        String tempstring="";
        for (int i =0;i<input.length();i++){
            if(input.charAt(i) ==' '){
                integer.add(Integer.parseInt(tempstring));
                tempstring="";
            }
            else{
                tempstring=tempstring+(input.substring(i,i+1));
            }
        }
        integer.add(Integer.parseInt(tempstring));
        return integer;

    }*/
    static List<Long> intInput(BufferedReader reader) throws IOException{
        String input = reader.readLine();
        List<Long> integer = new ArrayList<Long>();
        String tempstring="";
        for (int i =0;i<input.length();i++){
            if(input.charAt(i) ==' '){
                integer.add(Long.parseLong(tempstring));
                tempstring="";
            }
            else{
                tempstring=tempstring+(input.substring(i,i+1));
            }
        }
        integer.add(Long.parseLong(tempstring));
        return integer;

    }
    /*---end---prototype:
    BufferedReader reader =  new BufferedReader(new InputStreamReader(System.in));
     List<Integer> no = new ArrayList<Integer>();no=intInput(bf) */

}
class Point{
    int x,y;
    Point(int x,int y){
        this.x=x;
        this.y=y;
    }
    boolean compare(Point a){
        if((this.x==a.x)&&(this.y==a.y))
            return true;
        return false;
    }
    void print(){
        System.out.println(this.x+" "+this.y);
    }
}
class rectangle{
    public static void main(String[]args)throws IOException{
        BufferedReader reader =new BufferedReader(new InputStreamReader(System.in));
        Random rand=new Random();
        int x,y,l,b;
        int t,stat=0,range;
        Point a,be,c,d,temp;
        List<Point> data =new ArrayList<Point>();
        t=IOR.input(reader);
        range=IOR.input(reader);
        while(t>0) {
            x = rand.nextInt(range) + 0;
            y = rand.nextInt(range) + 0;
            l = rand.nextInt(range) + 1;
            b = rand.nextInt(range) + 1;
            a=new Point(x,y);
            be=new Point(x+l,y);
            c=new Point(x+l,y+b);
            d=new Point(x,y+b);
            stat=0;
            for (int i=0;i<data.size();i++){
                temp=data.get(i);
                if(a.compare(temp)||be.compare(temp)||c.compare(temp)||d.compare(temp)) {
                    stat = 1;
                    break;
                }
            }
            if(stat==0){
                data.add(a);
                data.add(be);
                data.add(c);
                data.add(d);
            }
            t--;
        }
        for (int i=0;i<data.size();i++)
            data.get(i).print();

    }
}