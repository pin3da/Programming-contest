/**
 * solved with Diego_A_E
 * */

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class Main {

	static class Scanner{
		BufferedReader br=null;
		StringTokenizer tk=null;
		public Scanner(){
			br=new BufferedReader(new InputStreamReader(System.in));
		}
		public String next() throws IOException{
			while(tk==null || !tk.hasMoreTokens())
				tk=new StringTokenizer(br.readLine());
			return tk.nextToken();
		}
		public int nextInt() throws NumberFormatException, IOException{
			return Integer.valueOf(next());
		}
		public double nextDouble() throws NumberFormatException, IOException{
			return Double.valueOf(next());
		}
	}



	static int[][] m;
	static int[][] integral;
	static int[][] dp;
	static int N,K;


	static int sum(int x, int y){
		if (x < 0 || y < 0)
			return 0;
		return integral[x][y];
	}

	static int getarea(int a, int b){
		int ret = sum(b, b) - sum(a - 1, b) - sum(b , a - 1) + sum(a - 1, a - 1);
		return ret;
	}

	static void solve(int k, int a, int b, int L, int R){
		if (b < a)
			return;
		int mid = (a + b)/2;
		int best = Integer.MAX_VALUE;
		int bestidx = -1;
		for(int i = Math.max(mid, L); i <= R; i++){
			if (dp[i + 1][k - 1] == Integer.MAX_VALUE)
				continue;
			int value = dp[i + 1][k - 1] + getarea(mid, i)/2;
			if (value < best){
				best = value;
				bestidx = i;
			}
		}
		dp[mid][k] = best;
		solve(k, a, mid - 1, L, bestidx);
		solve(k, mid + 1, b, bestidx, R);
	}

	public static void main(String args[]) throws NumberFormatException, IOException{
		Scanner sc = new Scanner();
		N = sc.nextInt();
		K = sc.nextInt();
		m = new int[N][N];
		integral = new int[N][N];
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				m[i][j] = sc.nextInt();
		for(int i = 0; i < N; i++)
			for(int j = 0; j < N; j++)
				integral[i][j] = sum(i, j - 1) + sum(i - 1, j) - sum(i - 1, j - 1) + m[i][j];
		dp = new int[N + 1][K + 1];
		for(int i = 0;  i < N ; i++)
			dp[i][0] = Integer.MAX_VALUE;
		for(int i = 0; i <= K; i++)
			dp[N][i] = 0;
		for(int k = 1; k <= K; k++)
			solve(k, 0, N - 1, 0, N - 1);

		System.out.println(dp[0][K]);
	}

}
