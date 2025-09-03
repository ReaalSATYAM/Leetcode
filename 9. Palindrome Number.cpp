bool isPalindrome(int x) {
    long res = 0, temp = x;
    // reverse the number
    while(temp > 0)
    {
        res = res*10 + temp%10;
        temp /= 10;
    }
    if(x == res)
        return true;
    else
        return false;
}
