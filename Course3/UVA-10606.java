import java.math.BigInteger;
import java.util.Scanner;

public class Main {
	public static BigInteger bigIntSqRootFloor(BigInteger x) throws IllegalArgumentException {
		if (x == BigInteger.ZERO || x == BigInteger.ONE)
			return x;
		BigInteger y, two = BigInteger.valueOf(2L);
		for (y = x.divide(two) ; y.compareTo(x.divide(y)) > 0 ; y = ((x.divide(y)).add(y)).divide(two));
		return y;
	}

	public static void main(String args[]) {
		Scanner scan = new Scanner(System.in);
		String n;
		while ((n = scan.next()).equals("0") == false) {
			BigInteger ret = n.equals("1") ? new BigInteger(n) : bigIntSqRootFloor(new BigInteger(n));
			System.out.println(ret.multiply(ret));
		}
	}
}
