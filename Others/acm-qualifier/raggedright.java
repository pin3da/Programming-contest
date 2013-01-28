import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

public class raggedright
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
		ArrayList <Integer> tams = new ArrayList <Integer> ();
		while(true)
		{
			String next = sc.nextLine();
			if(next == null)
				break;
			tams.add(next.length());
		}
		long max = Collections.max(tams);
		tams.remove(tams.size() - 1);
		if(tams.size() == 0)
		{
			System.out.println("0");
			return;
		}
		long count = 0;
		for(int i : tams)
			count += (max - i) * (max - i);
		System.out.println(count);
	}
}
