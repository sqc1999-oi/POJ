import java.util.*;
import java.io.*;

import static java.lang.System.out;

public class Main
{
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(new BufferedInputStream(System.in));
		int[][] a = new int[4][4001];
		int n = sc.nextInt();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				a[j][i] = sc.nextInt();
			}
		}
		HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x = a[0][i] + a[1][j];
				if (hm.containsKey(x)) { hm.put(x, hm.get(x) + 1); }
				else { hm.put(x, 1); }
			}
		}
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				int x = -a[2][i] - a[3][j];
				if (hm.containsKey(x)) cnt += hm.get(-a[2][i] - a[3][j]);
			}
		}
		out.println(cnt);
	}
}