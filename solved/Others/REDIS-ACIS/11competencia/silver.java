
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author utp
 */
public class silver {

    public static void main(String Args[]) throws IOException{
        BufferedReader br = new BufferedReader(new FileReader("silver.in"));
        int n;
        while ((n=Integer.valueOf(br.readLine()))!=0){
            System.out.println((int)(Math.log(n)/Math.log(2)));
        }
    }
    
}
