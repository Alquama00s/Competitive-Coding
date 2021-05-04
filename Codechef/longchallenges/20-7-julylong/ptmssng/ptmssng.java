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
    /*static Long Linput(BufferedReader reader) throws IOException{
        Long a=0L;
        String c = reader.readLine();
        a =Long.parseLong(c);
        return a;
    }*/
    /*----end---prototype:
     BufferedReader reader =  new BufferedReader(new InputStreamReader(System.in));
     int a=input(bf); */
    /*function takes BufferedReader as args and gives List<Integer> as output*/
    static List<Integer> intInput(BufferedReader reader) throws IOException{
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

    }
    /*static List<Long> intInput(BufferedReader reader) throws IOException{
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

    }*/
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
class Miss{
    static List<Point> data=new ArrayList<Point>();
    static boolean rectangle(Point a,Point b){
        if((a.x!=b.x) && (a.y!=b.y)) {
            Point p1, p2;
            p1 = new Point(a.x, b.y);
            p2 = new Point(b.x, a.y);
            int size = data.size(), counter = 0;
            for (int i = 0; i < size; i++) {
                if (p1.compare(data.get(i))) {
                    counter += 1;
                    break;
                }
            }
            for (int i = 0; i < size; i++) {
                if (p2.compare(data.get(i))) {
                    counter += 1;
                    break;
                }
            }
            if(counter==2)
                return true;
            return false;
        }else
            return false;
    }
    static void rem(Point a){
        int i=0;
        while(i<data.size()){
            if(a.compare(data.get(i))) {
                data.remove(i);
                break;
            }
            i++;
        }
    }
    static void result(){
        Point res;
        if((data.get(0).x!=data.get(1).x)&&(data.get(0).y!=data.get(1).y)){
            if(data.get(0).x==data.get(2).x) {
                res = new Point(data.get(1).x, data.get(0).y);
            }else{
                res = new Point(data.get(0).x, data.get(1).y);
            }
        }else if((data.get(0).x!=data.get(2).x)&&(data.get(0).y!=data.get(2).y)){
            if(data.get(0).x==data.get(1).x) {
                res = new Point(data.get(2).x, data.get(0).y);
            }else{
                res = new Point(data.get(0).x, data.get(2).y);
            }
        }else{
            if(data.get(1).x==data.get(0).x) {
                res = new Point(data.get(2).x, data.get(1).y);
            }else{
                res = new Point(data.get(1).x, data.get(2).y);
            }
        }
        res.print();

    }
    public static void main(String[]args)throws IOException{
        BufferedReader reader=new BufferedReader(new InputStreamReader(System.in));
        int t,i;
        int n;
        int size;
        List<Integer> temp=new ArrayList<Integer>();
        List<Point> copy=new ArrayList<Point>();
        Point p1,p2,tempPoint =new Point(0,0);
        t=IO.input(reader);
        while (t>0){
            n=IO.input(reader);
            data.clear();
            for (int j=0;j<(4*n-1);j++){
                temp=IO.intInput(reader);
                //temp.print();
                tempPoint=new Point(temp.get(0),temp.get(1));
                data.add(tempPoint);
                temp.clear();
            }
            /*for (int j=0;j<data.size();j++)
                data.get(j).print();
            System.out.println("out");*/
            //processdata
            i=0;
            while (data.size()>3){
                //size=data.size();
                //System.out.println("in");
                tempPoint=data.get(i);
                copy.clear();
                copy.addAll(data);
                copy.remove(tempPoint);
                size=copy.size();
                //System.out.println(copy.size());
                for(int j=0;j<size;j++){
                    //System.out.println("inn");
                    if(rectangle(tempPoint,copy.get(j))){
                        i=0;
                        //System.out.println("here;");
                        p1=new Point(tempPoint.x,copy.get(j).y);
                        p2=new Point(copy.get(j).x,tempPoint.y);
                        //copy.get(j).print();
                        rem(copy.get(j));
                        //tempPoint.print();
                        rem(tempPoint);
                        //p1.print();
                        rem(p1);
                        //p2.print();
                        rem(p2);
                        break;
                    }
                }
                //System.out.println("out1");
                if(i<data.size()-1) {
                    i++;
                    //System.out.println(i);
                }else
                    i=0;

            }
            //end process data
            /*for (int j = 0; j < data.size(); j++)
                data.get(j).print();*/
            if(data.size()==3) {
                result();
            }
            else
                System.out.println("error");
            t--;
        }
    }
}