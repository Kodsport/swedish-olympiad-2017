using System;

public class main {

	public static int Main(string[] args) {
		int C, K, N;
		string X;
		string[] parts = Console.ReadLine().Split();
		C = Int32.Parse(parts[0]);
		K = Int32.Parse(parts[1]);
		N = Int32.Parse(parts[2]);
		X = Console.ReadLine();

		string[] Y = avian.Encode(C, K, N, X);
		if (Y.Length != K) {
			Console.WriteLine("Encoder gave " + Y.Length + " strings, expected " + K);
			return 0;
		}
		foreach (string s in Y) {
			if (s.Length != N) {
				Console.WriteLine("Encoder gave string of length " + s.Length + " strings, expected " + N);
				return 0;
			}
			foreach (char c in s.ToCharArray()) {
				if (c != '0' && c != '1') {
					Console.WriteLine("Encoder gave string with characted " + c + " strings, expected 0 or 1");
					return 0;
				}
			}
		}
		parts = Console.ReadLine().Split();
		int[] I = new int[C];
		for (int i = 0; i < C; i++) {
			I[i] = Int32.Parse(parts[i]);
		}
		string[] subset = new string[C];
		for (int i = 0; i < C; i++) {
			subset[i] = Y[I[i]];
		}
		string dec = avian.Decode(C, K, N, subset, I);
		Console.WriteLine(dec);
		return 0;
	}
	
}
