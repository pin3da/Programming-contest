import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class unicycles
{
	static class Scanner
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer("");
		
		String nextLine()
		{
			try
			{
				return br.readLine();
			}
			catch(Exception e)
			{
				throw(new RuntimeException(e));
			}
		}
		
		String next()
		{
			while(!st.hasMoreTokens())
			{
				String linea = nextLine();
				if(linea == null)
					return linea;
				st = new StringTokenizer(linea);
			}
			return st.nextToken();
		}
		
		Integer nextInteger()
		{
			String line = next();
			if(line == null)
				return null;
			return Integer.parseInt(line);
		}
		
		int nextInt()
		{
			return Integer.parseInt(next());
		}
	}
	private static boolean valido(int i, int gap) 
	{
		int tmp = i;
		while(tmp >= 0)
		{
			if(!existe[tmp])
				return false;
			tmp -= gap;
		}
		tmp = i;
		while(tmp < tam)
		{
			if(!existe[tmp])
				return false;
			tmp += gap;
		}
		return true;
	}
	
	static int[] posiciones;
	static int tam;
	static boolean[] existe;
	static Integer[] dp;
	
	static int dp(int mascara)
	{
		if(dp[mascara] != null)
			return dp[mascara];
		int cuenta = Integer.bitCount(mascara);
		if(cuenta == 0)
			return dp[mascara] = 0;
		if(cuenta == 1)
			return dp[mascara] = 1;
		int pos = Integer.numberOfTrailingZeros(Integer.lowestOneBit(mascara));
		int mejor = Integer.MAX_VALUE;
		for(int i = pos + 1; i < posiciones.length; i++)
		{
			if((mascara & (1 << i)) == 0)
				continue;
			int gap = posiciones[i] - posiciones[pos];
			if(!valido(posiciones[i], gap))
				continue;
			int mascara2 = marcar(mascara, posiciones[i], gap);
			mejor = Math.min(mejor, 1 + dp(mascara2));
		}
		mejor = Math.min(Integer.bitCount(mascara), mejor);
		return dp[mascara] = mejor;
	}

	private static int marcar(int mascara, int inicio, int gap)
	{
		for(int i = 0; i < posiciones.length; i++)
		{
			int diff = Math.abs(posiciones[i] - inicio);
			if((diff % gap == 0) && ((mascara & (1 << i)) != 0))
					mascara ^= (1 << i);
		}
		return mascara;
	}

	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		while(true)
		{
			Integer t = sc.nextInteger();
			if(t == null)
				return;
			tam = t;
			int n = sc.nextInt();
			posiciones = new int[n];
			existe = new boolean[tam];
			for(int i = 0; i < n; i++)
			{
				posiciones[i] = sc.nextInt();
				existe[posiciones[i]] = true;
			}
			dp = new Integer[(1 << n)];
			System.out.println(dp((1 << n) - 1));
		}
	}
}