import java.util.*;
class test{
    static ArrayList<Integer> randInputArray(int n,int range){
        Random r=new Random();
        ArrayList<Integer> arr=new ArrayList<Integer>();
        for (int i=0;i<n;i++){
            arr.add(r.nextInt(range));
        }
        return arr;
    }
    static void print(List a){
        for (int i=0;i<a.size();i++)
            System.out.print(a.get(i)+" ");
        System.out.println("");
    }
    public static void main(String[]args){
     List<Integer> input=new ArrayList<Integer>();
        //List<Integer> unduplia=new ArrayList<Integer>();
        Random rand= new Random();
        int a=10000,temp;
         for(int i=0;i<a;i++){
            temp=rand.nextInt(1000000000);
            input.add(temp);
         }
         print(input);
         System.out.println(input.size());
     }

}