class Solution {
public:
     string longestPalindrome(string s) 
{   
    int len = s.size();
    int dp[len][len];
    memset(dp,0,sizeof(dp));
    int end=1;
    int start=0;
	
    for(int i=0;i<len;i++)
    {
        dp[i][i] = 1;
    }
    for(int i=0;i<len-1;i++)
    {
        if(s[i]==s[i+1])
        { dp[i][i+1]=1;start=i;end=2;}
    }
    
    for(int j=2;j<len;j++)
    {
        for(int i=0;i< len-j;i++)
        {  
            int left=i; //start point
            int right = i+j;  //ending point
            
            if(dp[left+1][right-1]==1 && s[left]==s[right]) 
            {
                dp[left][right]=1; start=i; end=j+1; 
            }        
        }
    }
   return s.substr(start, end);
}
};


/*
DP: Instead of going through all the previous Palindromes again and again, how about we save them somewhere and calculate the new ones based on them, but how do we d that? Lets see it below

Concept: To check a Palindrome of length ,say l, we just have to check if
i.) s[first character]==s[last character]
ii.) s[first character+1, last charcter -1] is a Palindrome

For example : say s=" balab"
Now, to check , if "s" is Palindrome or not, we just have to look at
i.) s[first character]==s[last character] -> b==b -> True
ii.)s[first character+1, last charcter -1] is a Palindrome --> "aba" is a Palindrome??
To check for "aba", a==a--> True , and "b" is a Palindrome(of length 1)
==> s is a Plaindrome


*/