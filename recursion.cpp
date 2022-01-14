#include<bits/stdc++.h>

using namespace std;

void print_number(int n) {

    if(n==6) return;

    cout << n << endl;
    print_number(n+1);
}

void print_sum(int i, int n, int sum) {

    if(i == n) {
        sum += i;

        cout << sum << endl;
        return;
    }
    sum += i;
    print_sum(i+1, n, sum);
}

int main() {

    int n = 1;
    print_sum(1, 5, 0);

    return 0;
}