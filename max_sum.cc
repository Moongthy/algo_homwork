// 5-b
int maxSumAtleastK(int a[], int n, int k) // O(N)
{ 
    int maxSum[n]; 

	//maxSum[i] : maximum sum of contiguos subarray that "a[i] is part of the sum" range of a[0] ~ a[i]
    maxSum[0] = a[0]; 
  
	// kadane algorithm : O(N)
    int curr_max = a[0]; 
    for (int i = 1; i < n; i++) 
    { 
        curr_max = max(a[i], curr_max+a[i]); 
        maxSum[i] = curr_max; 
    } 
  
    int sum = 0; 
    for (int i = 0; i < k; i++) 
        sum += a[i]; 
  
	// sliding window : O(N)
    int result = sum; 
    for (int i = k; i < n; i++) 
    { 
        sum = sum + a[i] - a[i-k]; 
  
        result = max(result, sum); 
  
        result = max(result, sum + maxSum[i-k]); 
    } 
    return result; 
} 

// 5-c
int maxSumAtMostK(int a[], int n, int k) // O(N)
{
	// kadane algorithm : O(N)
	int global_max = 0, local_max = 0, local_len = 0;	
	for(int i = 0; i < n; ++i)
	{
		if(local_max + a[i] >= 0)
		{
			local_max += a[i];
			len += 1;
		}else
		{
			local_max = 0;
			local_len = 0;
		} 
		
		if(local_max > global_max && local_len <= k) // length is at most k
		{
			global_max = local_max;
			continue;
		}
	}
	return global_max;
}

// 5-d
sum[a] >= sum[b] - K;
int maxSumEqualToOrLessThanK_Integer(int a[], int n, int k) // O(NlgN)
{
	std::set<int> sumSet; // bst
	sumSet.insert(0);

	int best = 0, sum = 0;

	for(int i = 0; i < n; ++i) // O(N)
	{
		sum += a[i];
		sumSet<int>::iterator sit = sumSet.lower_bound(sum - k); // O(lgN)
		if(sit != sumSet.end())
			best = max(best, cum - *sit);
		sumSet.insert(sum); // O(lgN)
	}

	return best;
}

// d-e
int maxSumEqualToOrLessThanK_non_negative(int a[], int n, int k) // O(N)
{
	int global_max = 0, local_max = a[0], head = 0;
 	for(int tail = 1; tail < n; ++tail)
	{
		if(local_max <= k)
			global_max = max(global_max, local_max);

		while(local_max + a[tail] > k && head < tail)
		{
			local_max -= a[head];
			++head;
		}
		local_max += a[tail];
	}

	if(local_max <= k)
		global_max = max(global_max, local_max);

	return global_max;

}





