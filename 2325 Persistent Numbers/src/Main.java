import java.util.*;
import java.math.*;

import static java.lang.System.out;

public class Main
{
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		BigInteger n;
		while (in.hasNext())
		{
			n = in.nextBigInteger();
			if (n.compareTo(BigInteger.valueOf(-1)) == 0) break;
			if (n.compareTo(BigInteger.TEN) < 0)
			{
				out.println(1 + n.toString());
				continue;
			}
			Stack<Integer> S = new Stack<Integer>();
			for (int i = 9; i > 1; i--)
			{
				while (n.mod(BigInteger.valueOf(i)).compareTo(BigInteger.ZERO) == 0)
				{
					S.push(i);
					n=n.divide(BigInteger.valueOf(i));
				}
			}
			if (n.compareTo(BigInteger.ONE) != 0)
			{
				out.println("There is no such number.");
				continue;
			}
			while (!S.empty()) out.print(S.pop());
			out.println();
		}
	}
}
