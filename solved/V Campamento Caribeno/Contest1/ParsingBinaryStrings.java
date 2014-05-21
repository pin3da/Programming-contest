import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {


  static boolean isbinary(char c){
    if (c == '0' || c == '1')
      return true;
    return false;
  }

  public static void main(String args[]) throws IOException{
    BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
    char[] t = rd.readLine().toCharArray();
    StringBuilder sb = new StringBuilder();
    long acum = 0;
    boolean bin = false;
    for(int i = 0; i < t.length; i++){
      if (!isbinary(t[i]) && bin){
        bin = false;
        sb.append(acum+"");
        acum = 0;
        sb.append(t[i]);
        continue;
      }
      if (!isbinary(t[i])){
        sb.append(t[i]);
        continue;
      }
      // es binario
      acum = acum << 1;
      acum = acum % 1000000007;
      acum += t[i] - '0';
      acum = acum % 1000000007;
      bin = true;
    }
    if (bin)
      sb.append(acum+"");
    System.out.println(sb.toString());
  }

}
