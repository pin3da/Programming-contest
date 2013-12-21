
import java.io.BufferedWriter;
import java.math.BigInteger;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Scanner;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author utp
 */
public class H {
    public static void main(String Args[]){
        Scanner sc = new Scanner(System.in);
            LinkedList<animal> padres = new LinkedList<animal>();
            LinkedList<animal> madres = new LinkedList<animal>();
            LinkedList<animal> hijos = new LinkedList<animal>();
            char[] clave = sc.nextLine().toCharArray();
           while (true){
                String linea = sc.nextLine();
                if (linea.charAt(0)=='*'){break;}
                String[] tmp = linea.split(" ");
                animal tmpa = new animal(tmp[0], tmp[1].charAt(0)=='M', tmp[2]);
                if (tmpa.hombre){
                    padres.add(tmpa);
                }
                else{
                    madres.add(tmpa);
                }
            }
            while (true){
                String linea = sc.nextLine();
                if (linea.charAt(0)=='*'){break;}
                String[] tmpl = linea.split(" ");
                hijos.add(new animal(tmpl[0], true,tmpl[1]));
            }
            
            LinkedList<String> padreshijos[] = new LinkedList[hijos.size()];
            for (int i=0;i<hijos.size();i++){
                padreshijos[i]= new LinkedList<String>();
            }
            for (animal M:madres){
                for (animal P:padres){
                    char[] keymadre = M.codigo;
                    char[] keypadre = P.codigo;
                    if(M.nombre.equals("Shadow")){
                        System.out.println(P.nombre);
                    }
                    ciclo1:
                    for (int hijo=0;hijo<hijos.size();hijo++){
                        animal ahijo = hijos.get(hijo);
                        for (int i=0;i<clave.length;i++){
                            if (clave[i]=='D'){
                                if (!OR(keymadre[i],keypadre[i],ahijo.codigo[i])){
                                    continue ciclo1;
                                }
                            }
                            else{
                                if (!AND(keymadre[i],keypadre[i],ahijo.codigo[i])){
                                    continue ciclo1;
                                }
                            }
                        }
                        padreshijos[hijo].add(M.nombre+"-"+P.nombre);
                    }
                    
                    
                }
            }
            int count=0;
            for (animal h : hijos){
                Collections.sort(padreshijos[count]);
                System.out.print(h.nombre+" by");
               boolean primero=true;
                for (String s:padreshijos[count]){
                    if (!primero){
                        System.out.print(" or");
                    }
                    System.out.print(" "+s);
                    primero=false;
                }
                System.out.println();
                    count++;
            }
            
        
    }
    
    public static boolean OR(char x, char y, char z){
        //si (x || y)==1 z debe ser 1
        //return ((x=='1' || y =='1') && z=='1');        
        if (x=='1' || y =='1')
            return z=='1';
        return z=='0';
    }
    
    public static boolean AND (char x, char y, char z){
        //si z == 1 entonces (x && y) deben ser 1
        //return (((x=='0' || y =='0') && z=='1') || (z=='0' && (x=='1' && y =='1')));
        if (x=='1' && y =='1') {
            return z=='1';
        }
        return z=='0';
    }
}

class animal{
    public String nombre;
    public boolean hombre;
    public char[] codigo;

    public animal(String nombre, boolean hombre, String codigo) {
        this.nombre = nombre;
        this.hombre = hombre;
        this.codigo = codigo.toCharArray();
    }
    
}
