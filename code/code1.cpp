#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib> // modul

using namespace std;

int main() {
    int N, K;
    cout << "N, K: ";
    if (!(cin >> N >> K)){
    	cout << "Zov too oruulna uu!";
    	return 0;
	}
	// N bolon K toog shalgah
	if(N < 1 || N > 100000){
		cout << "N n 1-ees 100000 baih ystoi!";
		return 0;
	}
	if(K < 0 || K > N){
		cout << "K n 0-ees N hurtel baih ystoi!";
		return 0;
	}
	
    vector<long long> A(N), B(N), D(N);

    for(int i = 0; i < N; i++)
        cin >> A[i];

	//1. D massiv uusgeh
    for(int i = 0; i < N; i++) {
        cin >> B[i];
        D[i] = B[i] - A[i];
    }

    //2. D-g erembeleed X toog oloh
    sort(D.begin(), D.end());
    long long X = D[N/2];  // median

    //3. X toogoo nemsnii daraah ylgaatai baidliig oloh
    vector<long long> diff(N);
    for(int i = 0; i < N; i++)
        diff[i] = llabs(D[i] - X);

    //4. K shirheg toog oorchloh
    sort(diff.begin(), diff.end(), greater<long long>());

    long long result = 0;
    for(int i = K; i < N; i++)
        result += diff[i];

    cout << "Ylgaatai baidal: " << result << "\n";

    return 0;
}
