
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;


public class Main {

  static int gauss(int n){
    int tmp = n * (n + 1);
    tmp /= 2;
    return tmp;
  }

  public static void main(String args[]) throws IOException{
    BufferedReader rd = new BufferedReader(new InputStreamReader(System.in));
    BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    while(true){
      String cad = rd.readLine();
      if (cad == null)
        break;
      int N = Integer.valueOf(cad);
      if (N == 0)
        break;
      int count = 0;
      for(int i = 1; gauss(i) <= N; i++){
        int offset = N - gauss(i);
        if (offset != 0 && (offset % i == 0))
          count++;
      }
      bw.write(count+"\n");
    }
    bw.flush();
  }

}
