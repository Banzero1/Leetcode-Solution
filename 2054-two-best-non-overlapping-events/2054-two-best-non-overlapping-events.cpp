class Solution {
public:
  
/*
For every event, I've two options. Whether I choose that event or not.
If choose, then I add its value to my answer. If not choosen I move forward to the next event.
Now if I select a event, my next event has to have start time > end time of choosen event. Also of all the possible next events I should choose the one with max value
To select the next event with start time > end time of choosen event, I can do a Binary search.
What to select the Max value I can find the value of all legal subsets possible, and select the maximum of all the values.
*/
    vector<int> start;
    int dp[100002][2];
    
    int solve(vector<vector<int>>& events, int i, int choose){
        if(i>=events.size()){
            return 0; 
        }       
        
        if(choose>=2){    // since I cannot chose more than two elemnts.
            return 0;
        }
        
        if(dp[i][choose]!=-1){
            return dp[i][choose];
        }
        
        int idx = upper_bound(start.begin(),start.end(),events[i][1])-start.begin(); // binary search to find the next event's index
            
        return dp[i][choose]=max(events[i][2]+solve(events,idx,choose+1),solve(events,i+1,choose)); //either I select an event, or I dont
        
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        
        for(int i=0;i<100002;i++){
            for(int j=0;j<2;j++){
                dp[i][j]=-1;
            }
        }
        int n = events.size();
		//sort elemts acc to start time
        sort(events.begin(),events.end());
		
        start.clear();
        for(int i=0;i<n;i++){
            start.push_back(events[i][0]);            
        }
        
        return solve(events,0,0);
    }
};