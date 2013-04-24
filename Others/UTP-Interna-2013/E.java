import java.math.BigInteger;
import java.util.Scanner;


public class E {
	public static void main(String []args){
		Scanner sc = new Scanner(System.in);
		while(true){
			int c = sc.nextInt();
			if(c == 0) break;
			BigInteger ans = BigInteger.ZERO;
			for(int i=0;i<c;++i){
				String a = sc.next();
				String b = sc.next();
				BigInteger aa = new BigInteger(a);
				BigInteger uno = aa.pow(Integer.parseInt(b));
			    if(uno.compareTo(ans)>0){
			    	ans = uno;
			    }
			}
			System.out.println(ans);
		}
		
	}
}
