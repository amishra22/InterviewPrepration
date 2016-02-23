/*

			pattern = "abba", str = "dog cat cat dog" should return true.
			pattern = "abba", str = "dog cat cat fish" should return false.
			pattern = "aaaa", str = "dog cat cat dog" should return false.
			pattern = "abba", str = "dog dog dog dog" should return false.
		
			return true if pattern matches with the given string (one to one mapping)

*/


class Solution {
public:
    bool wordPattern(string pattern, string str) {
        
        map<char, string> mymapC;
		map<string, char> mymapS;
        
        int p=0;
        
        for(int i=0;i<pattern.length();i++){
            
            string tmp="";
            
            if(p>=str.length())
                return false;
            
			while(p!=str.length() && str[p]!=' '){
                tmp += str[p];
                p++;
            }
			
            if(mymapC.count(pattern[i])>0 && mymapC[pattern[i]] != tmp)
            	return false;
            if(mymapS.count(tmp)>0 && mymapS[tmp] != pattern[i])
            	return false;
            	
            mymapC[pattern[i]] = tmp;
            mymapS[tmp] = pattern[i];
            p++;
           
        }
        
        if(p >= str.length())
        	return true;
        else
        	return false;
        
    }
};