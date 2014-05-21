
import java.util.Scanner;


public class Main {


  static int[] primes = {2,3,5,7,11,13,17,19,23};
  static int N;
  static int[] array;
  static Integer[][] dp;


  static boolean test(int num, int mask){
    for(int i = 0; i < primes.length; i++){
      int aux = mask >> i;
      aux = aux & 1;
      if (aux == 1){
        int prime = primes[i];
        if (num % prime == 0)
          return false;
      }
    }
    return true;
  }

  static int nmask(int num, int mask){
    int ret = mask;
    for(int i = 0; i < primes.length; i++){
      if (num % primes[i] == 0)
        ret = ret | (1<<i);
    }
    return ret;
  }



  static int dp(int idx, int mask){
    if (dp[idx][mask] != null)
      return dp[idx][mask];
    if (!test(array[idx], mask))
      return dp[idx][mask]=0;
    int ret = 1;
    int nm = nmask(array[idx], mask);
    for(int i = idx + 1 ; i < array.length; i++)
      ret = Math.max(ret, 1 + dp(i, nm));
    dp[idx][mask] = ret;
    return ret;
  }

  public static void main(String args[]){
    Scanner sc = new Scanner(System.in);
    N = sc.nextInt();
    array = new int[N];
    for(int i = 0; i < N; i++)
      array[i] = sc.nextInt();
    dp = new Integer[N][1 << 15];
    int ans = 0;
    for(int i = 0; i < N; i++){
      ans = Math.max(ans, dp(i, 0));
      //System.out.println(dp(i,0));
    }
    System.out.println(ans);
  }

}
