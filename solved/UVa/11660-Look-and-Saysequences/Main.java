import java.io.BufferedReader;
import java.io.InputStreamReader;
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
	
	/**
	 * Look and say sequences
	 * http://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=2707
	 * */
	public static void main(String []args){
		int a,b,c;
		Scanner cin = new Scanner();
		while(true){
			a = cin.nextInt();
			b = cin.nextInt();
			c = cin.nextInt();
			
			if(a+b+c == 0) break;
			char [] num = String.valueOf(a).toCharArray();
			for (int i = 0; i < b-1; i++){
				StringBuilder sb = new StringBuilder();
				int veces = 1;
				char ant = '$';
				for(int k = 0; k< Math.min(num.length, 1000); ++k){
					char d = num[k];
					if(d == ant) veces++;
					else if (ant != '$'){
						sb.append(veces);
						sb.append(ant);
						veces = 1;
					}
					ant = d;
				}
				if(veces > 0){
					sb.append(veces);
					sb.append(num[num.length-1]);
				}
				num = sb.toString().toCharArray();
				
			}
			System.out.println(num[c-1]);
			
		}
		
	}
}
