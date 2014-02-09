
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.LinkedList;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author Carlos
 */
public class Main1 {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws FileNotFoundException, IOException {
        // TODO code application logic here
        
        LinkedList<String> encwords= new LinkedList<String>();
        LinkedList<String> oriwords= new LinkedList<String>();
        int i=0, j=0, k=0, x=0;
        boolean pin;
        String str=new String();
        //InputStream input = new FileInputStream("c:/Documentos/Netbeans/Decoded/src/in.txt");
        Scanner cin = new Scanner(System.in);
        PrintStream cout= System.out;
        while(!(str=cin.next()).equals("$")){
            encwords.add(str);                        
        }
        while(!(str=cin.next()).equals("$")){
            oriwords.add(str);                        
        }
        int[] oriseq=new int[oriwords.size()];
        int[] encseq=new int[oriwords.size()];
        cout.print(oriwords);
        for(i=0;i<oriseq.length;i++){
            oriseq[i]=i;
            for(j=0;j<i;j++){
                if(oriwords.get(j).equals(oriwords.get(i)) && i!=j){
                    oriseq[i]=oriseq[j];
                    
                }
                
            }
            cout.print(oriseq[i]);
        }
        cout.print("\n");
        for(k=0;(k+oriseq.length)<encwords.size();k++){
            cout.print(encwords);
            pin=true;
            for(i=0;i<oriseq.length;i++){
                encseq[i]=i;
                for(j=0;j<i;j++){
                    if(encwords.get(j+k).equals(encwords.get(i+k)) && (i+k)!=j ){
                        encseq[i]=encseq[j];
                    }
                }
                cout.print(encseq[i]);
            }
            cout.print("\n");
            for(x=0;x<oriseq.length;x++){
                if(oriseq[x]!=encseq[x]){
                    pin= false;
                }
            }
            if(pin==true){
                cout.print(k+1);
                break;
            }
        }
        
        
    }
    
}
