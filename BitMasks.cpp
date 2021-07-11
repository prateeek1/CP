
// Ways to Count Number of set bits in a Number

ll countBits(ll n)
{
	ll ans = 0;
	while (n > 0)
	{
		ans += (n & 1);
		n = n >> 1;
	}

	return ans;
}


ll cntBits(ll n)
{
	ll ans = 0;

	while (n > 0)
	{
		n = n & n - 1;
		ans++;
	}
	return ans;
}


__builtin_popcount(n)  // Inbuilt method



// Decimal to Binary

ll decimalToBinary(ll n)
{
	ll ans = 0;
	ll p = 1;
	while (n > 0)
	{
		last = n & 1;
		ans += p * last;
		p = p * 10;
		n = n >> 1;
	}
	return ans;
}




// Fast Exponentiation
ll expo(ll a, ll n)
{
	while (n > 0)
	{
		ll last_bit = n & 1;
		if (last_bit)
		{
			ans = ans * a;
		}
		a = a * a;
		n = n >> 1;
	}
}



_builtin_parity(x) //This function is used to check the parity of a number.
//This function returns true(1) if the number has odd parity else it returns false(0) for even parity.


__builtin_clz(x) //This function is used to count the leading zeros of the integer. Note : clz = count leading zero’s


__builtin_ctz(x) //This function is used to count the trailing zeros of the given integer. Note : ctz = count trailing zeros.