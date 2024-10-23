bool isValid(char* s) {
    int top=-1;
    int stck[10000];
    for(int i=0;s[i]!='\0';i++)
    {
        char cur=s[i];
        if(cur=='('||cur=='{'||cur=='[')
        {
            stck[++top]=cur;
        }
        else
        {
            if(top==-1)
            {
                return false;
            }
            char topchar=stck[top--];
            if ((cur==')'&& topchar!='(')||(cur=='}'&& topchar!='{')||(cur==']'&& topchar!='['))
            {
                return false;
            }
        }
    }
    return top==-1;
}
