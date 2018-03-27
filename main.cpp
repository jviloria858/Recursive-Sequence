#include<bits/stdc++.h>
using namespace std;

/*
A function f is defined as follows F(n)= (1) +(2*3) + (4*5*6) ... n. Given an integer n the task is to print the F(n)th term.

Input:
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test contains an integer n.

Output:
For each test case print the nth term of the sequence. .

Constraints:
1<=T<=100
1<=N<=10

1	2x3	4x5x6	7x8x9x10	11x12x13x14x15	
1	6	120	    5040	    360360	365527
1	2	3	    4	        5	

Example:
Input:
2
5
7

Output:
365527
6006997207
*/
int f(int num, long long* ans)
{
   
    if(num == 1)
    {
        *ans = 1;
        return 1;
    }

    int resultDiff = f(num-1, ans);
    int TopProd = num + resultDiff;
    int prod = 1;
    for (int i=0; i<num; i++)
    {
        cout << TopProd << "*";
        prod = prod * TopProd;
        TopProd = TopProd - 1;
    }
    cout << endl;
    
    *ans = *ans + prod;
    cout << "ans = " << *ans << endl;
    
    return num + resultDiff;
}

int callf(int n)
{
    long long ans = 0;
    int retVal;
    retVal = f(n, &ans);
    
    return ans;
}


int main() {
	//code
	
	int t;
	cin>>t;
	int* ans;
	while(t--)
	{
	        int num;
	        cin>>num;
	        cout<<callf(num)<<"\n";
	}
	return 0;
}
