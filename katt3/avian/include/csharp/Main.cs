using System;
using System.Diagnostics;
using System.Reflection;

public class main {

	public static int Main(string[] args) {
		if (args.Length == 0) {
			string path = System.Reflection.Assembly.GetExecutingAssembly().CodeBase;
			Process enc = new Process();
			enc.StartInfo.FileName = "/usr/bin/mono";
			enc.StartInfo.Arguments = "\"" + path + "\" encoder";
			enc.StartInfo.UseShellExecute = false;
			enc.StartInfo.RedirectStandardOutput = true;
			enc.Start();

			Process dec = new Process();
			dec.StartInfo.FileName = "/usr/bin/mono";
			dec.StartInfo.Arguments = "\"" + path + "\" decoder";
			dec.StartInfo.UseShellExecute = false;
			dec.StartInfo.RedirectStandardInput = true;
			dec.Start();

			try {
				string buf = enc.StandardOutput.ReadToEnd();
				dec.StandardInput.Write(buf, 0, buf.Length);
				dec.StandardInput.Close();
			} catch (Exception e) {
			}
			enc.WaitForExit();
			int encWF = enc.ExitCode;
			if (encWF != 0) {
				return encWF;
			}
			dec.WaitForExit();
			int decWF = dec.ExitCode;
			if (decWF != 0) {
				return encWF;
			}
		} else if (args[0].Equals("encoder")) {
			int C, K, N;
			string X;
			string[] parts = Console.ReadLine().Split();
			C = Int32.Parse(parts[0]);
			K = Int32.Parse(parts[1]);
			N = Int32.Parse(parts[2]);
			X = Console.ReadLine();

			Console.WriteLine(C);
			Console.WriteLine(K);
			Console.WriteLine(N);
			string[] Y = avian.Encode(C, K, N, X);
			if (Y.Length != K) return 0;
			foreach (string s in Y) {
				if (s.Length != N) return 0;
				foreach (char c in s.ToCharArray()) {
					if (c != '0' && c != '1') return 0;
				}
			}
			parts = Console.ReadLine().Split();
			for (int i = 0; i < C; i++) {
				int I = Int32.Parse(parts[i]);
				Console.WriteLine(I);
				Console.WriteLine(Y[I]);
			}
		} else if (args[0].Equals("decoder")) {
			int C, K, N;
			C = Int32.Parse(Console.ReadLine());
			K = Int32.Parse(Console.ReadLine());
			N = Int32.Parse(Console.ReadLine());
			string[] Y = new string[C];
			int[] I = new int[C];
			for (int i = 0; i < C; i++) {
				I[i] = Int32.Parse(Console.ReadLine());
				Y[i] = Console.ReadLine();
			}
			String dec = avian.Decode(C, K, N, Y, I);
			Console.WriteLine("iunty23v7itdhugh3c" + dec);
		}
		return 0;
	}
	
}
