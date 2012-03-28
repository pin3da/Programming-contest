//accepted
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.Scanner;
import java.util.StringTokenizer;
public class F2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        DecimalFormatSymbols aux = new DecimalFormatSymbols();
        aux.setDecimalSeparator('.');
        DecimalFormat df = new DecimalFormat("0.0000",aux);         
        //int n = sc.nextInt();     
        //sc.nextLine();
        while(true){
            StringTokenizer st = new StringTokenizer(sc.nextLine());
            int m = Integer.parseInt(st.nextToken());
		 	if(m==0)break;
            Pair[][] matriz = new Pair[m][m];
            for (int j = 0; j < m; j++)                 
                matriz[j][0] = new Pair(Double.parseDouble(st.nextToken()),1);                            
            //ordenar esto que acabamos de leer;
            int k=1;
            while (k<m){
                for (int j = 0; j < m-k; j++) 
                    if(k==1)
                        matriz[j][k] = new Pair(matriz[j][k-1],matriz[j+1][k-1]);                  
                    else
                        matriz[j][k] = new Pair(matriz[j][k-1],matriz[j+1][k-1],matriz[j+1][k-2]);                  
                k++;
            }            
            double x = Math.round(matriz[0][m-1].x*10000)/10000.0;
            double y = Math.round(matriz[0][m-1].y*10000)/10000.0;        
            System.out.println(df.format(x)+" "+df.format(y));            
            
        }        
    }    

    public static class Pair {
        double x,y;
        public Pair(double x, double y){
            this.x=x;
            this.y=y;
        }
        
        public Pair(Pair uno, Pair dos){
            x=(uno.x+dos.x)/2;
            y= Math.sqrt(4-Math.pow((dos.x-uno.x)/2,2))+1;
        }
        
        public Pair(Pair uno, Pair dos, Pair tres){
            x=dos.x-(tres.x-uno.x);
            y=dos.y-(tres.y-uno.y);                          
        }
    }
    
}
