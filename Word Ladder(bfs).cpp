/******************************************************************************
127. Word Ladder
A transformation sequence from word beginWord to word endWord using a
dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... ->
sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need 
to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the
number of words in the shortest transformation sequence from beginWord to
endWord, or 0 if no such sequence exists.

 

Example 1:
Input: beginWord = "hit", endWord = "cog", 
wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is
"hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.

Example 2:
Input: beginWord = "hit", endWord = "cog",
wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is
no valid transformation sequence.
*******************************************************************************/
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string>myset;
        bool ispresent=false;
        
        for(auto word:wordList){
            if(endWord.compare(word)==0)
                ispresent=true;
            myset.insert(word);
        }
        if(ispresent==false) return 0;
        
        queue<string>q;
        q.push(beginWord);
        int depth=0;
        
        while(!q.empty()){
            depth+=1;
            int lsize=q.size();
            while(lsize--){
                string curr=q.front();
                q.pop();
                for(int i=0;i<curr.length();i++){

                    string temp=curr;
                    for(char c='a';c<='z';c++){
                        temp[i]=c;
                        if(curr.compare(temp)==0) continue;
                        if(temp.compare(endWord)==0) return depth+1;
                        if(myset.find(temp)!=myset.end()){
                            q.push(temp);
                            myset.erase(temp);
                        }
                    }
                }
            }
            
        }
        return 0;
    }
};