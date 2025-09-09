// this ques was solved using stack
bool isValid(char* s) {
    int n=strlen(s);
    char stack [n]; 
    int top=-1;
  for(int i=0;i<strlen(s);i++){
    if(s[i]=='('||s[i]=='{'||s[i]=='['){
        stack[++top]=s[i];

    }
    else{
        if(top==-1){
        return false;
    }
    char last=stack[top--];
    if(s[i]==')'&&last!='('||s[i]=='}'&&last!='{'||s[i]==']'&&last!='['){
        return false;
    }

  }
}
return top==-1;
}
