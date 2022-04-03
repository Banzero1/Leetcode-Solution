class Encrypter {
    map<char,string> kmap;
    map<string,int> rmap;
public:
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dic) {
        int n = keys.size();
        for(int i  = 0 ; i < n ; i++){
            kmap[keys[i]] = values[i];
        }
        for(auto x : dic){
            rmap[encrypt(x)]++;
        }
    }
    
    string encrypt(string word1) {
        string ans = "";
        for(auto x : word1){
            ans += kmap[x];
        }
        return ans;
    }
    int decrypt(string word2) {
        return rmap[word2];
    }
};