#include <bits/stdc++.h>
#define int long long
using namespace std;

int seive1[1000001];

void seive() {
    for (int i = 0; i <= 1000000; i++) {
        seive1[i] = i;
    }

    for (int i = 2; i * i <= 1000000; i++) {
        if (seive1[i] == i) {
            for (int j = i * i; j <= 1000000; j += i) {
                if (seive1[j] == j) {
                    seive1[j] = i;
                }
            }
        }
    }
}

void prime_factor(int x, vector<int>& prime) {
    while (x > 1) {
        prime.push_back(seive1[x]);
        x /= seive1[x];
    }
}

int32_t main() {
    seive(); // call sieve once

    int t;
    cin >> t;
    while (t--) {
        int x;
        cin >> x;

        vector<int> prime;
        prime_factor(x, prime);

        if (prime.empty()) {
            cout << "1\n";
            continue;
        }

        int ans = 1;
        int count = 1;

        for (int i = 1; i < prime.size(); i++) {
            if (prime[i] == prime[i - 1]) {
                count++;
            } else {
                ans *= (count + 1);
                count = 1;
            }
        }

        ans *= (count + 1); // for the last group
        cout << ans << "\n";
    }

    return 0;
}
