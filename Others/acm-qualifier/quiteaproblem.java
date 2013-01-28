import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;


public class quiteaproblem 
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
	}

	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner();
		while(true)
		{
			String next = sc.nextLine();
			if(next == null)
				return;
			System.out.println(next.toUpperCase().contains("PROBLEM") ? "yes" : "no");
		}
	}
}
