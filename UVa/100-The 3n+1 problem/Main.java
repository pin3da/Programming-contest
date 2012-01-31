import java.io.IOException;
import java.io.PrintStream;
import java.util.Scanner;


/*
 * Accepted, runtime 1.237
 */

/**
 *
 * @author Carlos
 */
public class Main {
    private static int function(int k){
        int ans=1;
        for(;k!=1;++ans){
            if((k%2)!=0){
                k=(3*k)+1;
            }
            else{
                k=k/2;
            }
        }
        return ans;
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        int i=0, j=0, k=0, ans=0, tmp=0;
        Scanner cin = new Scanner(System.in);
        PrintStream cout= System.out;
        while(cin.hasNextInt()){
            i=cin.nextInt();
            j=cin.nextInt();
            for(ans=0, k=Math.min(i, j);k<=Math.max(i, j);k++){
                if(ans<(tmp=function(k))){
                    ans=tmp;                    
                }
                    
            }
            cout.println(i + " " + j + " " + ans);
        }
    }
    
}
