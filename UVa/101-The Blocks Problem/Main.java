
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Scanner;


/*
 * Accepted, runtime: 0.580
 * http://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=37
 */

/**
 *
 * @author Carlos (CaaL-15)
 */
public class Main {
    
    private static void moveOnto(ArrayList<LinkedList<Integer>> blocklists, int a, int b, int posa, int posb){
        int posl, x;
        LinkedList<Integer> jesus=blocklists.get(posa);
        posl=jesus.indexOf(a)+1;
        while(posl<jesus.size()){
            x=jesus.get(posl);
            jesus.removeFirstOccurrence(x);
            blocklists.get(x).add(x);
            }
        
        jesus.removeFirstOccurrence(a);
        LinkedList<Integer> jesus2=blocklists.get(posb);
        posl=jesus2.indexOf(b)+1;
        while(posl<jesus2.size()){
            x=jesus2.get(posl);
            jesus2.removeFirstOccurrence(x);
            blocklists.get(x).add(x);
            }
        jesus2.add(a);
    }
    
    private static void moveOver(ArrayList<LinkedList<Integer>> blocklists, int a, int b, int posa, int posb){
        int posl, x;
        LinkedList<Integer> jesus=blocklists.get(posa);
        posl=jesus.indexOf(a)+1;
        while(posl<jesus.size()){
            x=jesus.get(posl);
            jesus.removeFirstOccurrence(x);
            blocklists.get(x).add(x);
            }
        
        jesus.removeFirstOccurrence(a);
        blocklists.get(posb).add(a);
    }
    
    private static void pileOnto(ArrayList<LinkedList<Integer>> blocklists, int a, int b, int posa, int posb){
        int posl, x;  
        LinkedList<Integer> jesus=blocklists.get(posb);
        posl=jesus.indexOf(b)+1;
        while(posl<jesus.size()){
            x=jesus.get(posl);
            jesus.removeFirstOccurrence(x);
            blocklists.get(x).add(x);
            }                
        
        LinkedList<Integer> jesus2=blocklists.get(posa);
        posl=jesus2.indexOf(a);
        while(posl<jesus2.size()){
            x=jesus2.get(posl);
            jesus2.removeFirstOccurrence(x);
            jesus.add(x);
            }
    }
    
    private static void pileOver(ArrayList<LinkedList<Integer>> blocklists, int a, int b, int posa, int posb){
        int posl, x;  
        LinkedList<Integer> jesus=blocklists.get(posa);
        LinkedList<Integer> jesus2=blocklists.get(posb);
        posl=jesus.indexOf(a);
        while(posl<jesus.size()){
            x=jesus.get(posl);
            jesus.removeFirstOccurrence(x);
            jesus2.add(x);
            }
    }
    
       
       
    
    
    
    

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        int i=0, j=0, size, x=0, y=0, posa, posb;
        String str1=new String();
        String str2=new String();
        Scanner cin = new Scanner(System.in);
        PrintStream cout= System.out;
        size=cin.nextInt();
        ArrayList<LinkedList<Integer>> blocklists=new ArrayList<LinkedList<Integer>>(size);
        for(x=0;x<size;x++){
            blocklists.add(x, new LinkedList<Integer>());
            blocklists.get(x).add(x);
        }
        
        while((!(str1=cin.next()).equals("quit")) && cin.hasNext()){
            i=cin.nextInt();
            str2=cin.next();
            j=cin.nextInt();
            for(posa=0;posa<size;posa++){
                if(blocklists.get(posa).contains(i)){
                    break;                                        
                }
            }
            for(posb=0;posb<size;posb++){
                if(blocklists.get(posb).contains(j)){
                    break;                                        
                }
            }
            if(i!=j && j<size && i<size && posa!=posb){
                if(str1.equals("move") && str2.equals("onto")){
                    moveOnto(blocklists, i, j, posa, posb);
                }
                if(str1.equals("move") && str2.equals("over")){
                    moveOver(blocklists,i , j, posa, posb);
                }
                if(str1.equals("pile") && str2.equals("onto")){
                    pileOnto(blocklists,i,j,posa, posb);
                }
                if(str1.equals("pile") && str2.equals("over")){
                    pileOver(blocklists,i,j,posa, posb);
                }
            }
        }
        
        for(x=0;x<size;x++){
            cout.print(x + ":");
            LinkedList<Integer> god=blocklists.get(x);
            for(y=0;y<god.size();y++){
                cout.print(" " + god.get(y));                
            }
            cout.print("\n");                   
        }
    }
}
