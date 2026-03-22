bool isValid(char* s) {
    // creat stack and position stack(-1 mean stack is empty)
    char stack[10000];
    int top=-1;
    //creat loop browse the string (\0 mean null character, end the string)
    for(int i=0; s[i]!='\0';i++){
        char c=s[i];
        //if character is ({[, push into stack
        if (c=='(' || c=='{' || c=='['){
            stack[++top]=c;// ++top mean top = top+1
        }
        else if (c==')' ||c=='}' || c==']'){
            // check stack isempty
            if(top==-1){
                return false;
            }
            // decrease top when pop character from stack
            char last=stack[top--];
            //check character pair
            if((c==')' && last !='(') ||(c=='}' && last !='{') || (c==']' && last !='[')  ){
                return false;
            }
        }
    }
    //check stack, if stack is empty after all, retrun true
    return top ==-1;
}
