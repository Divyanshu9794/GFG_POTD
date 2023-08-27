<h2><a href="https://practice.geeksforgeeks.org/problems/maximum-value5946/1?page=1&difficulty[]=-1&difficulty[]=0&difficulty[]=1&difficulty[]=2&category[]=Dynamic%20Programming&category[]=Linked%20List&sortBy=difficulty">Maximum value</a></h2><h3>Difficulty Level : Easy</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">Given an array <strong>arr[]</strong> of size N. Find the maximum value of arr[j] – arr[i] + arr[l] – arr[k], such that i &lt; j &lt; k &lt; l.<br>
<br>
<strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>
N = 3
Arr[]  = {1, 2, 3}
<strong>Output:</strong>-1
<strong>Explanation: 
</strong>N&lt;4 so no such i,j,k,l is possible.
</span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
N = 5
Arr[] = {4, 8, 9, 2, 20}
<strong>Output: </strong>23
<strong>Explanation:
</strong>Here i = 0, j = 2, k = 3, l = 4 so
arr[j] – arr[i] + arr[l] – arr[k] 
= 9 – 4 + 20 – 2 = 23
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>findMaxValue()</strong>&nbsp;which takes the array <strong>arr[]</strong> and its size <strong>N</strong><strong> </strong>as input parameters&nbsp;and returns the maximum value of arr[j] – arr[i] + arr[l] – arr[k].</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity :</strong> O(N)<br>
<strong>Expected Auxiliary Space :</strong> O(N)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1 ≤ N ≤ 10<sup>5</sup><br>
1 ≤ A[i] ≤ 10<sup>5</sup></span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Arrays</code>&nbsp;<code>Dynamic Programming</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;