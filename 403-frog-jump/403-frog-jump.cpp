class Solution {
public:
  int dp[2001][2001];
  bool find(vector<int> &stones, int i,int k){
  	//we reached the ith stone with k jumps 
  	
      if(i==stones.size()-1) // if i== n-1 i.e. we have reached the last stone so we simply return true
          return true;
      if(i>=stones.size()) 
          return false;
  	
      if(dp[i][k]!=-1) // if we already encountered this state ,we'll simply return it
          return dp[i][k]; 
  		
      bool res = false;
  	// from here we can either go to k-1 , k , k +1 th stone 
      for(int j=-1;j<=1;j++){
          int next_jump=k+j;
          if(next_jump>0){
  		
  		//now the next stone would be = currstone + jump
  		//using binary search to find the index of next stone if it exists
           int in= lower_bound(stones.begin(),stones.end(),stones[i]+next_jump)-stones.begin();
  			
           if(in == stones.size() || stones[in]!=stones[i]+next_jump) // checking existence of next_stone in array
                  continue;
  			//if next stone exists then we will move to that index (in) with the jump that we took
              res=res||find(stones,in,next_jump);
          }
      }
  	
      return dp[i][k]=res;
      
  }
  
  bool canCross(vector<int>& stones) {
     memset(dp,-1,sizeof(dp));
     
      return find(stones, 0,0);
      
  }
};