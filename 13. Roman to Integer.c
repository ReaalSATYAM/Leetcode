int romanToInt(char* s) {
    int sum = 0;
    while(*s != '\0')
    {
        switch(*s)
        {
            case 'I': sum += 1;
                if(*(s+1) == 'V'){
                    sum+= 3;
                    s++;
                }
                else if(*(s+1) == 'X'){
                    sum += 8;
                    s++;
                }
                s++;
                break;

            case 'V': sum += 5; s++;
                break;

            case 'X': sum += 10;
                if(*(s+1) == 'L'){
                    sum+= 30;
                    s++;
                }
                else if(*(s+1) == 'C'){
                    sum += 80;
                    s++;
                }
                s++;
                break;

            case 'L': sum += 50; s++;
                break;

            case 'C': sum += 100;
                if(*(s+1) == 'D'){
                    sum+= 300;
                    s++;
                }
                else if(*(s+1) == 'M'){
                    sum += 800;
                    s++;
                }
                s++;
                break;

            case 'D': sum += 500; s++;
                break;

            case 'M': sum += 1000; s++;
                break;

        }
    }
    return sum;
}
