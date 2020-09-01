int Factorial(int x){
    int answ = 1;
    if (x <= 1) return 1;
    else
        for (int i = 2; i <= x; ++i){
            answ *= i;
        }
    return answ;
}