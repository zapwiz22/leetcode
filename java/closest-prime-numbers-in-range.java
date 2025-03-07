import java.util.ArrayList;

class Solution {
    public int[] closestPrimes(int left, int right) {
        boolean sieve[] = new boolean[1000010];
        ArrayList<Integer> primes = new ArrayList<>();
        sieve[0]=true;
        sieve[1]=true;
        for (int i=2;i*i<=right;i++) {
            if (sieve[i]==false) {
                for (int j=i*i;j<=right;j+=i) {
                    sieve[j]=true;
                }
            }
        }
        for (int i=left;i<=right;i++) {
            if (sieve[i]==false) {
                primes.add(i);
            }
        }
        int num1 = -1,num2 = -1;
        int diff = 10000010;
        for (int i = 0;i<primes.size()-1;i++) {
            int first = primes.get(i);
            int second = primes.get(i+1);
            if ((second-first)<diff) {
                diff = second -first;
                num1 = first;
                num2 = second;
            }
        }
        return new int[]{num1,num2};
    }
}
