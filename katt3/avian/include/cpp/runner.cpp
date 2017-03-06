#include <bits/stdc++.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#include "avian.h"

using namespace std;

static const int USER_FAIL = 120;
static const char* SECRET_KEY = "iunty23v7itdhugh3c";

int main() {
	ios_base::sync_with_stdio(false);
	int C, K, N;
	string X;
	cin >> C >> K >> N >> X;
	vector<int> I(C);
	for (int i = 0; i < C; i++) {
		cin >> I[i];
	}

	int pipefds[2];
	ignore = pipe(pipefds);

	pid_t pid = fork();
	if (pid == 0) {
		close(pipefds[0]);
		vector<string> encoder = encode(C, K, N, X);
		if (encoder.size() != (size_t)K) {
			cerr << "Encoder gave " << encoder.size() << " strings, expected " << K << endl;
		close(pipefds[1]);
			exit(USER_FAIL);
		}
		for (const string& s : encoder) {
			if (s.size() != (size_t)N) {
				cerr << "Encoder gave string of length " << s.size() << ", expected " << N << endl;
		close(pipefds[1]);
				exit(USER_FAIL);
			}
			for (char c : s) {
				if (c != '0' && c != '1') {
					cerr << "Encoder gave string containing character " << c << ", expected either 0 or 1" << endl;
		close(pipefds[1]);
					exit(USER_FAIL);
				}
			}
		}
		for (int i = 0; i < C; i++) {
			ignore = write(pipefds[1], encoder[I[i]].c_str(), N);
			ignore = write(pipefds[1], "\n", 1);
		}
		close(pipefds[1]);
		exit(EXIT_SUCCESS);
	} else {
		int status;
		vector<string> subset;
		char buf[C * (N + 1)];
		if (waitpid(pid, &status, 0) == -1) {
			perror("waitpid fail");
			return EXIT_FAILURE;
		}
		if (WIFSIGNALED(status)) {
			kill(getpid(), WTERMSIG(status));
			exit(1);
		}
		int ex = WEXITSTATUS(status);
		if (ex == USER_FAIL) { exit(EXIT_SUCCESS); exit(1); }
		if (ex != EXIT_SUCCESS) { exit(ex); exit(1); }
		ignore = read(pipefds[0], buf, sizeof(buf));
		for (int i = 0; i < C; i++) {
			subset.push_back(string(buf + i*(N + 1), buf + (i + 1) * (N + 1) - 1));
		}
		string decoded = decode(C, K, N, subset, I);
		cout << SECRET_KEY << decoded << endl;
		exit(EXIT_SUCCESS);
	}

}
