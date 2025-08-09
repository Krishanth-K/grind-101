def thebestpow(memo, x, n):
    if n <= 0:
        return 1
    elif n == 1:
        return x

    if n in memo:
        return memo[n]

    if n % 2 == 0:
        temp =  thebestpow(memo, x, n/2)
        memo[n/2] = temp

        return temp * temp

    else:
        result = thebestpow(memo, x, (n + 1)/2) * thebestpow(memo, x, (n - 1)/2)

    memo[n] = result

    return result


class Solution(object):
    def myPow(self, x, n):
        """
        :type x: float
        :type n: int
        :rtype: float
        """
        memo = {}

        result = thebestpow(memo, x, abs(n))

        if n < 0:
            return 1/result

        return result

soln = Solution()
print(soln.myPow(0.000001, 2147483647))

