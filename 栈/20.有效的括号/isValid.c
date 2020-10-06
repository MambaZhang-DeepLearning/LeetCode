/**
 * Date:2020-10-06
 * Author:MambaZhang
 **/
bool isValid(char * s){
    int i = 0, top = -1;
    int len = strlen(s);

    if (NULL==s || 0==*s)    //空字符串，满足
    {
        return true;
    }
    if (len & 1 != 0)   //如果是奇数，不满足
    {
        return false;
    }

    char stack[len];
    for(i=0; i<len; i++)
    {
        if (s[i]=='(' || s[i]=='{' || s[i]=='[')    //左括号
        {
            stack[++top] = s[i];
        }
        else if (-1 == top) //没有左括号
        {
            return false;
        }
        else if (s[i]==stack[top]+1 || s[i]==stack[top]+2)  //'()'是+1，'{}[]'是+2
        {
            top--;
        }
        else    //没有左括号与右括号匹配
        {
            return false;
        }
    }

    return -1 == top ? true:false;
}