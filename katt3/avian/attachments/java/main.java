import java.util.*;

public class main {

	public static void main(String... args) {
		Scanner sc = new Scanner(System.in);
		int C, K, N;
		String X;
		C = sc.nextInt();
		K = sc.nextInt();
		N = sc.nextInt();
		X = sc.next();
		String[] Y = avian.encode(C, K, N, X);


		if (Y.length != K) {
			System.out.println("Encoder gave " + Y.length + " strings, expected " + K);
			return;
		}
		for (String s : Y) {
			if (s.length() != N) {
				System.out.println("Encoder gave string of length " + s.length() + " strings, expected " + N);
				return;
			}
			for (char c : s.toCharArray()) {
				if (c != '0' && c != '1') {
					System.out.println("Encoder gave string with characted " + c + " strings, expected 0 or 1");
					return;
				}
			}
		}
		int[] I = new int[C];
		for (int i = 0; i < C; i++) {
			I[i] = sc.nextInt();
		}
		String[] subset = new String[C];
		for (int i = 0; i < C; i++) {
			subset[i] = Y[I[i]];
		}
		String dec = avian.decode(C, K, N, subset, I);
		System.out.println(dec);
	}
}
