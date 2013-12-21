import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class outofcontext 
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
	
	static char[] izquierda;
	static char[][] producciones;
	static char[] entrada;
	static int[][][][] dp;
	
	static boolean dp(int cEntrada, int nProduccion, int indiceP, int numero)
	{
		if(numero < 0)
			return false;
		if(dp[cEntrada][nProduccion][indiceP][numero] >= 0)
			return dp[cEntrada][nProduccion][indiceP][numero] == 1;
		if(indiceP == producciones[nProduccion].length)
			return (dp[cEntrada][nProduccion][indiceP][numero] = numero == 0 ? 1 : 0) == 1;
		if(dp[cEntrada][nProduccion][indiceP][numero] != -1)
			return dp[cEntrada][nProduccion][indiceP][numero] == 1;
		dp[cEntrada][nProduccion][indiceP][numero] = 0;
		char actual = producciones[nProduccion][indiceP];
		if(actual >= 'a' && actual <= 'z')
		{
			if(numero == 0)
				return (dp[cEntrada][nProduccion][indiceP][numero] = 0) == 1;
			if(entrada[cEntrada] == actual)
				return (dp[cEntrada][nProduccion][indiceP][numero] = dp(cEntrada + 1, nProduccion, indiceP + 1, numero - 1) ? 1 : 0) == 1;
			else
				return (dp[cEntrada][nProduccion][indiceP][numero] = 0) == 1;
		}
		else
		{
			for(int i = 0; i < izquierda.length; i++)
			{
				if(izquierda[i] == actual)
				{
					for(int j = 0; j <= numero; j++)
						if(dp(cEntrada + j, nProduccion, indiceP + 1, numero - j) && dp(cEntrada, i, 0, j))
							return (dp[cEntrada][nProduccion][indiceP][numero] = 1) == 1;
				}
			}
			return (dp[cEntrada][nProduccion][indiceP][numero] = 0) == 1;
		}
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		Integer nI = sc.nextInteger();
		while(true)
		{
			int n = nI;
			izquierda = new char[n];
			producciones = new char[n][];
			for(int i = 0; i < n; i++)
			{
				String a = sc.nextLine();
				izquierda[i] = a.charAt(0);
				a = a.trim();
				a = a + " ";
				a = a.substring(5);
				producciones[i] = a.trim().toCharArray();
			}
			boolean empezo = false;
			while(true)
			{
				String l = sc.nextLine();
				if(l == null)
				{
					System.out.print("\n");
					System.out.flush();
					return;
				}
				if(empezo)
					System.out.println();
				else
					empezo = true;
				try
				{
					Integer.parseInt(l);
					nI = Integer.parseInt(l);
					break;
				}
				catch(Exception e)
				{
					int mejor = 0;
					String cual = "";
					entrada = l.toCharArray();
					dp = new int[entrada.length + 1][n][20][entrada.length + 1];
					for(int i = 0; i < entrada.length + 1; i++)
						for(int j = 0; j < n; j++)
							for(int k = 0; k < 20; k++)
								for(int m = 0; m < entrada.length + 1; m++)
									dp[i][j][k][m] = -1;
					for(int i = 0; i < entrada.length; i++)
						out:
						for(int j = i + 1; j <= entrada.length; j++)
							for(int k = 0; k < n; k++)
							{
								if(izquierda[k] == izquierda[0])
								{
									if(dp(i, k, 0, j - i))
									{
										if(j - i > mejor)
										{
											mejor = j - i;
											cual = l.substring(i, j);
										}
										continue out;
									}
								}
							}
					System.out.print(cual.isEmpty() ? "NONE" : cual.trim());
				}
			}
		}
	}

}
