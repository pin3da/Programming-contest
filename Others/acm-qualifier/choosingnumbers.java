import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;


public class choosingnumbers
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
	
	static int gcd(int a, int b)
	{
		while(b != 0)
		{
			int temp = a % b;
			a = b;
			b = temp;
		}
		return a;
	}
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		final int[] nums = new int[1000];
		while(true)
		{
			Integer n = sc.nextInteger();
			if(n == null)
				return;
			for(int i = 0; i < n; i++)
				nums[i] = sc.nextInt();
			int res = 0;
			Arrays.sort(nums, 0, n);
			for(int i = n - 1; i >= 0; i--)
			{
				boolean bien = true;
				int numero = nums[i];
				for(int j = n - 1; j >= 0; j--)
					if(j != i && gcd(numero, nums[j]) != 1)
					{
						bien = false;
						break;
					}
				if(bien)
				{
					res = numero;
					break;
				}
			}
			System.out.println(res);
		}
	}
	
	
}
