
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;


/*
 * Accepted, Runtime 0.22
 */

/**
 *
 * @author Carlos (CaaL-15)
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException{
        // TODO code application logic here
        String str=new String();
        BufferedReader cin2=new BufferedReader(new InputStreamReader(System.in));
        PrintStream cout= System.out;
        int i=0;
        int c=0;
        int len=0;
        cin2.readLine();
        while(true){
            str=cin2.readLine();
            len=str.length();
            
            if(str.contains("_")){
                break;
            }
            for(i=0, c=0;i<len;i++){
                if(str.charAt(i)=='o'){
                    c=(c*2)+1;
                    
                    }
                if(str.charAt(i)==' '){
                    c=c*2;
                    
                }
            }
            cout.print((char)c);
        }       
    }
    
}
