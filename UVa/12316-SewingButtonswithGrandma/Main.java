import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.Arrays;
import java.util.StringTokenizer;



public class Main {

	static class Scanner
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");

		public String nextLine()
		{
			try
			{
				return br.readLine();
			}
			catch(Exception e)
			{
				throw(new RuntimeException());
			}
		}

		public String next()
		{
			while(!st.hasMoreTokens())
			{
				String l = nextLine();
				if(l == null)
					return null;
				st = new StringTokenizer(l);
			}
			return st.nextToken();
		}

		public int nextInt()
		{
			return Integer.parseInt(next());
		}

		public long nextLong()
		{
			return Long.parseLong(next());
		}

		public double nextDouble()
		{
			return Double.parseDouble(next());
		}

		public int[] nextIntArray(int n)
		{
			int[] res = new int[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextInt();
			return res;
		}

		public long[] nextLongArray(int n)
		{
			long[] res = new long[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextLong();
			return res;
		}

		public double[] nextDoubleArray(int n)
		{
			double[] res = new double[n];
			for(int i = 0; i < res.length; i++)
				res[i] = nextLong();
			return res;
		}
		public void sortIntArray(int[] array)
		{
			Integer[] vals = new Integer[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}

		public void sortLongArray(long[] array)
		{
			Long[] vals = new Long[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}

		public void sortDoubleArray(double[] array)
		{
			Double[] vals = new Double[array.length];
			for(int i = 0; i < array.length; i++)
				vals[i] = array[i];
			Arrays.sort(vals);
			for(int i = 0; i < array.length; i++)
				array[i] = vals[i];
		}
	}

	static BigInteger [][]binomial;
	static BigInteger [][]dp;
	static int m,k;
	static int buttons [];
	static int MAXN = 55;


	public static void main(String []args){
		binomial =  new BigInteger[MAXN][MAXN];
		binomial[0][0] = BigInteger.ONE;
		for (int i = 0; i < MAXN; ++i) {
			for (int j = 0; j < MAXN; ++j) {
				if (i != 0 || j != 0) binomial[i][j] = BigInteger.ZERO;
				if (i > 0) binomial[i][j] = binomial[i][j].add(binomial[i-1][j]);
				if (i > 0 && j > 0) binomial[i][j] = binomial[i][j].add(binomial[i-1][j-1]);
			}
		}
		Scanner cin = new Scanner();
		while(true){
			m = cin.nextInt();
			k = cin.nextInt();
			if(m+k==0) break;

			dp = new BigInteger[k+1][m+1];
			buttons = cin.nextIntArray(k);

			for (int b = 1; b <= m; ++b) {
				dp[k][b] = BigInteger.ZERO;
			}
			dp[k][0] = BigInteger.ONE;

			for (int i = k - 1; i >= 0; --i) {
				for (int b = 0; b <= m; ++b) {
					dp[i][b] = dp[i+1][b];
					int mmax = Math.min(buttons[i],b);
					for (int n = 1; n <= mmax; n++) {
						for (int s = 1; s <= n; ++s) {
							dp[i][b] = dp[i][b].add(dp[i+1][b-n].multiply(binomial[b-n+1][s]).multiply(binomial[n-1][s-1]));
						}
					}
				}
			}
			System.out.println(dp[0][m]);
		}
	}
}
