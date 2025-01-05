#include<iostream>
using namespace std;

int maximum(int A[], int N) {
    int max = A[0];
    for(int i = 1; i < N; i++) {
        if(A[i] > max) {
            max = A[i];
        }
    }
    return max;
}

int minimum(int A[], int N) {
    int min = A[0];
    for(int i = 1; i < N; i++) {
        if(A[i] < min) {
            min = A[i];
        }
    }
    return min;
}

int primeNumber(int A[], int N) {
    int countPrime = 0;
    for(int i = 0; i < N; i++) {
        bool isPrime = true;
        if(A[i] <= 1) {
            isPrime = false;
        } else {
            for(int j = 2; j * j <= A[i]; j++) {
                if(A[i] % j == 0) {
                    isPrime = false;
                    break;
                }
            }
        }
        if(isPrime) {
            countPrime++;
        }
    }
    return countPrime;
}

int palindromeNumber(int A[], int N) {
    int countPalindrome = 0;
    for(int i = 0; i < N; i++) {
        int num = A[i];
        int reverse = 0, temp = num;
        while(temp > 0) {
            reverse = reverse * 10 + (temp % 10);
            temp /= 10;
        }
        if(num == reverse) {
            countPalindrome++;
        }
    }
    return countPalindrome;
}

int maxDivisors(int A[], int N) {
    int maxDiv = 0, maxNumber = A[0];
    for(int i = 0; i < N; i++) {
        int countDiv = 0;
        for(int j = 1; j <= A[i]; j++) {
            if(A[i] % j == 0) {
                countDiv++;
            }
        }
        if(countDiv > maxDiv || (countDiv == maxDiv && A[i] > maxNumber)) {
            maxDiv = countDiv;
            maxNumber = A[i];
        }
    }
    return maxNumber;
}

int main() {
    int N;
    cin >> N;
    int A[N];
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    cout << "The maximum number : " << maximum(A, N) << endl;
    cout << "The minimum number : " << minimum(A, N) << endl;
    cout << "The number of prime numbers : " << primeNumber(A, N) << endl;
    cout << "The number of palindrome numbers : " << palindromeNumber(A, N) << endl;
    cout << "The number that has the maximum number of divisors : " << maxDivisors(A, N) << endl;

    return 0;
}