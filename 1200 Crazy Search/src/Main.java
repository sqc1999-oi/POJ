import java.util.*;
import java.io.*;

import static java.lang.System.out;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int n = sc.nextInt(), nc = sc.nextInt();
		sc.nextLine();
		String s = sc.nextLine();
		HashSet<String> hs = new HashSet<String>();
		for (int i = 0; i <= s.length() - n; i++)
		{
			hs.add(s.substring(i, i + n));
		}
		out.println(hs.size());
	}
}