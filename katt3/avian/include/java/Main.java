import java.io.*;
import java.util.*;

public class Main {

	public static void main(String... args) throws InterruptedException, IOException {
		if (args.length == 0) {
			Runtime rt = Runtime.getRuntime();
			Process enc = new ProcessBuilder("/usr/bin/java", "-cp", System.getProperty("java.class.path"), "Main", "encoder")
				.redirectInput(ProcessBuilder.Redirect.INHERIT)
				.redirectError(ProcessBuilder.Redirect.INHERIT)
				.redirectOutput(ProcessBuilder.Redirect.PIPE)
				.start();

			Process dec = new ProcessBuilder("/usr/bin/java", "-cp", System.getProperty("java.class.path"), "Main", "decoder")
				.redirectOutput(ProcessBuilder.Redirect.INHERIT)
				.redirectError(ProcessBuilder.Redirect.INHERIT)
				.redirectInput(ProcessBuilder.Redirect.PIPE)
				.start();

			byte[] buf = new byte[16000];
			try {
				int has;
				while ((has = enc.getInputStream().read(buf)) >= 0) {
					dec.getOutputStream().write(buf, 0, has);
				}
				dec.getOutputStream().close();
			} catch (Exception e) {
			}
			int encWF = enc.waitFor();
			if (encWF != 0) {
				System.exit(encWF);
			}
			int decWF = dec.waitFor();
			if (decWF != 0) {
				System.exit(encWF);
			}
		} else if (args[0].equals("encoder")) {
			Scanner sc = new Scanner(System.in);
			int C, K, N;
			String X;
			C = sc.nextInt();
			K = sc.nextInt();
			N = sc.nextInt();
			X = sc.next();

			System.out.println(C);
			System.out.println(K);
			System.out.println(N);
			String[] Y = avian.encode(C, K, N, X);
			if (Y.length != K) return;
			for (String s : Y) {
				if (s.length() != N) return;
				for (char c : s.toCharArray()) {
					if (c != '0' && c != '1') return;
				}
			}
			for (int i = 0; i < C; i++) {
				int I = sc.nextInt();
				System.out.println(I);
				System.out.println(Y[I]);
			}
		} else if (args[0].equals("decoder")) {
			Scanner sc = new Scanner(System.in);
			int C, K, N;
			C = sc.nextInt();
			K = sc.nextInt();
			N = sc.nextInt();
			String[] Y = new String[C];
			int[] I = new int[C];
			for (int i = 0; i < C; i++) {
				I[i] = sc.nextInt();
				Y[i] = sc.next();
			}
			String dec = avian.decode(C, K, N, Y, I);
			System.out.println("iunty23v7itdhugh3c" + dec);
		}
	}
	
}
