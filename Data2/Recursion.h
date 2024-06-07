#pragma once
class Recursion {
	public:
		void NSU(int n);
		int Power(int n, int x);
		int Multiplication(int a, int b);
		int GCD(int a, int b);
		int sum_arr(int a[], int b);
		int sum_digits(int num);
		int sum_first_even(int n);
		int min_array(int a[],int n, int m);
		void back_array(int a[], int n);
		int fibonacci(int n);
};
int Recursion::fibonacci(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
		
	return fibonacci(n - 1) + fibonacci(n - 2);

}

void Recursion::back_array(int a[], int n) {
	if (n != 0) {
		cout << a[n - 1] << " ";
		back_array(a, n - 1);
	}
}

int Recursion::min_array(int a[], int n, int m) {
	if (n == 0)
		return m;

	if (a[n - 1] < m)
		m = a[n - 1];
	return min_array(a, n-1 , m);

}

int Recursion::sum_first_even(int n) {
	if (n == 0)
		return 0;

	return sum_first_even(n - 1) + (2*n);

}

int Recursion::sum_digits(int num) {

	if (num <10)
		return num;
	return num % 10+sum_digits(num / 10) ;
}

int Recursion::sum_arr(int a[], int n) {

	if (n == 0)
		return 0;


	return sum_arr(a,n-1) + a[n-1];


}

int Recursion::GCD(int a, int b) {
	if (a%b == 0)
		return b;
	return GCD(a,a%b);
}

void Recursion::NSU(int n) {
	if (n != 0) {
		NSU(n - 1);
		cout << n << " ";
	}
}
int Recursion::Power(int n, int x) {
	if (x==0)
		return 1;

	return Power(n,x-1) * n;

}

int Recursion::Multiplication(int a, int b) {
	if (b == 0)
		return 0;

	return Multiplication(a, b - 1) + a ;

}
