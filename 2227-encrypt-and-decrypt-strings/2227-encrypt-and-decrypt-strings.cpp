class Encrypter {
public:
    unordered_map<char,string>m;
    vector<string>v1;
    Encrypter(vector<char>& k, vector<string>& v, vector<string>& d) {
        
        int i,n=v.size();
        for(i=0;i<n;i++)
        {
            m[k[i]]=v[i];
        }
     
        for(i=0;i<d.size();i++)
        {
            v1.push_back(d[i]);
        }
    
    }
    
    string encrypt(string w) {
      
        int i,n=w.size();
        string s;
        for(i=0;i<n;i++)
        {
            s+=m[w[i]];
        }
        return s;
        
    }
    
    int decrypt(string w) {
        
        int i,n=w.size(),ans=0;
     
        for(i=0;i<v1.size();i++)
        {
            string s="";
            for(int j=0;j<v1[i].size();j++)
            {
                s+=m[v1[i][j]];
            }
          
           
                ans+=s==w;
            
        }
        
        return ans;
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */