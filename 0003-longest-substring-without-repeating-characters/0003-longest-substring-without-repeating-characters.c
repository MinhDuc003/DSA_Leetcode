int lengthOfLongestSubstring(char* s) {
    int last[256];//Extended ASCII
    int maxlen=0;
    int start=0;
    //set all charater not appear
    for(int i=0;i<256;i++){
        last[i]=-1;
    }
    //using sliding window
    for(int i=0; s[i]!='\0';i++){
        //if the string have same character, set up start 
        if(last[s[i]]>=start){
            start=last[s[i]]+1;
        }
        //if the string don`t have the same character, exten the string
        last[s[i]]=i;
        //calculate the lenght of string
        int len=i-start+1;

        if(len>maxlen){
            maxlen=len;
        }
    }
    return maxlen;
}