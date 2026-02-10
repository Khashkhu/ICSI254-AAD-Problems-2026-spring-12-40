#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;


long long calculateResult(int N, int K, const vector<long long>& A, const vector<long long>& B) {
    vector<long long> D(N);
    for (int i = 0; i < N; i++)
        D[i] = B[i] - A[i];

    sort(D.begin(), D.end());
    long long X = D[N/2];

    vector<long long> diff(N);
    for (int i = 0; i < N; i++)
        diff[i] = llabs(D[i] - X);

    sort(diff.begin(), diff.end(), greater<long long>());

    long long result = 0;
    for (int i = K; i < N; i++)
        result += diff[i];

    return result;
}

int main() {
    // 1. engiin
    {
        int N = 5, K = 2;
        long long tmpA[] = {1, 2, 3, 4, 5};
		vector<long long> A(tmpA, tmpA + 5);

		long long tmpB[] = {5, 4, 3, 2, 1};
		vector<long long> B(tmpB, tmpB + 5);
        long long res = calculateResult(N, K, A, B);
        cout << "Test 1: " << res << " (expected: 4)\n"; 
    }

    // 2. buh element ijil
    {
        int N = 4, K = 1;
        long long tmpA[] = {2, 2, 2, 2, 2};
		vector<long long> A(tmpA, tmpA + 5);

		long long tmpB[] = {2, 2, 2, 2, 2};
		vector<long long> B(tmpB, tmpB + 5);
        long long res = calculateResult(N, K, A, B);
        cout << "Test 2: " << res << " (expected: 0)\n";
    }

    // 3. sanamsargui
    {
        int N = 8, K = 2;
        long long tmpA[] = {3,1,4,1,5,9,2,6};
		vector<long long> A(tmpA, tmpA + 8);

		long long tmpB[] = {8,5,10,4,7,15,3,20};
		vector<long long> B(tmpB, tmpB + 8);
        long long res = calculateResult(N, K, A, B);
        cout << "Test 3: " << res << " (expected: 8)\n";
    }

    // 4. N < K
    {
        int N = 3, K = 5;
        long long tmpA[] = {1, 2, 3};
		vector<long long> A(tmpA, tmpA + 3);

		long long tmpB[] = {3, 2, 1};
		vector<long long> B(tmpB, tmpB + 3);
        long long res = calculateResult(N, min(K, N), A, B); // min(K,N) 
        cout << "Test 4: " << res << " (expected: 0)\n";
    }

    return 0;
}
