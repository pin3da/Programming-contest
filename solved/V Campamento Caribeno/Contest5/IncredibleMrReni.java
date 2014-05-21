
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;


public class Main {


  static long h_exp(long p, long n) {
    long ans = 0;
    long t = p;
    BigInteger pp  =new BigInteger(p + "");
    BigInteger tt = new BigInteger(t + "");
    BigInteger nn = new BigInteger(n + "");
    while (tt.compareTo(nn) <= 0) {
      ans +=nn.divide(tt).longValue();
      tt = tt.multiply(pp);
    }
    return ans;
  }



  public static void main(String []args) throws IOException {
    long a, b, p;
    BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    while(true) {
      String current = rd.readLine();
      if (current == null)
        break;
      StringTokenizer tk = new StringTokenizer(current);
      a = Long.valueOf(tk.nextToken());
      b = Long.valueOf(tk.nextToken());
      p = Long.valueOf(tk.nextToken());
      if (a == 1)
        bw.write(Long.toOctalString(h_exp(p,b)) + "\n");
      else {
        String cad = Long.toOctalString((h_exp(p,b) - h_exp(p, a -1)));
        bw.write(cad + "\n");
      }
    }
    bw.flush();
  }

}
