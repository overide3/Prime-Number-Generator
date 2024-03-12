#include <iostream>
#include <vector>
#include <cmath>
#include <chrono>
#include <fstream>
using namespace std;


//can currently ignore this warning. when the file gets too big this can become an issue.
/*
!!!!WARNING!!!!
trying to open the primes.txt file will crash replit. It will connect and disconnect constantly. refreshing the page will fix this. 
Attempting to download the file will crash chrome and possibly your computer. 
!!!!WARNING!!!!
*/


int main() 
{
	ifstream file; // initiate file
	unsigned int itt = 2;
	vector <unsigned int> prime;
	file.open("primes.txt"); // read file
	string line;
	while(getline(file,line)) 
	{
		prime.emplace_back(stoul(line));// take the prime and insert into the array. use emplace as its slightly more efficent also use stoul to get unsigned int
		itt = stoul(line);
	}
	file.close();
	line.~string();//close the file and string to reduce the impact on ram. 
	ofstream file2;
	file2.open("primes.txt",ios_base::app); // open file in append mode
	while(1)
	{
		bool x = true;
		for(int i = 0; i < prime.size();i++) // check the current number with each prime number lower than the square root of the current number
		{
			if(prime[i] > sqrt(itt))
			{
				break;
			}
			if(itt % prime[i] == 0)
			{
				x = false;
				break;
			}
		}
		if(x)
		{
			prime.emplace_back((itt)); // if its a prime add to the array .
			file2 << itt << "\n"; // add to the file. can take out to speed up but it makes the primes volatile 
			if(prime.size() % 1000000 == 0 ) // changes how much is printed. for best results print every 1000000
			{
				cout << itt << " " << prime.size() << endl;
			}
		}
		itt++;
	}
}


//highest prime so far: 1769068657 87409892
