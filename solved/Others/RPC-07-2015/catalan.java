import java.util.*;
import java.io.*;
import java.math.*;

public class catalan {

  public static void main(String args[]) {
    Scanner in = new Scanner(System.in);
    BigInteger[] cat = new BigInteger[5005];

    cat[0] = new BigInteger("1");
    for (int i = 0; i < 5004; i++) {
      cat[i + 1] = cat[i];
      cat[i + 1] = cat[i + 1].multiply(new BigInteger("" + ((2 * i + 1) * (2 * i + 2))));
      cat[i + 1] = cat[i + 1].divide(new BigInteger("" + ((i + 2) * (i + 1))));
    }


    int n = in.nextInt();
    BigInteger ans = new BigInteger("0");
    for (int i = 0; i <= n; ++i)
      ans = ans.add(cat[i].multiply(cat[n - i]));

    System.out.println(ans);


  }
}

