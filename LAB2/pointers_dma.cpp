// write a menu driven program to check whether a number is a palindrome,armstrong,perfect number using only dma
#include <iostream>


//function to calculate number of digits of an integer
int digits(int *num) {
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;

    int *count = (int *)malloc(sizeof(int));
    *count = 0;
    while ((*temp) != 0) {
        *temp = (*temp)/10;
        (*count)++;
    }

    return *count;

    free(count);
    free(temp);
}

//function to raise an integer to the given power
int pow(int *num,int *power) {
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;

    int *exp = (int *)malloc(sizeof(int));
    *exp = 1;
    int *i = (int *)malloc(sizeof(int));
    for ((*i) = 0;(*i) < (*power);(*i)++) {
        *exp = (*exp)*(*temp);
    }

    return *exp;

    free(exp);
    free(i);
    free(temp);

}

//function to check if an integer is a palindrome
int palindrome(int *num) {
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;

    int *num1 = (int *)malloc(sizeof(int));
    *num1 = *temp;
    int *num2 = (int *)malloc(sizeof(int));
    *num2 = 0;

    int *n = (int *)malloc(sizeof(int));
    *n = digits(num1);
    int *i = (int *)malloc(sizeof(int));

    for ((*i) = 0;(*i) < (*n);(*i)++) {
        *num2 = ((*num2)*10) + ((*num1)%10);
        *num1 = (*num1)/10;
    }

    if ((*num2) == (*temp)) {
        return 0;
    }

    else {
        return 1;
    }

    free(num1);
    free(num2);
    free(n);
    free(i);
    free(temp);
}

//function to check if an integer is an armstrong number
int armstrong(int *num) {
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;

    int *number = (int *)malloc(sizeof(int));
    *number = *temp;
    int *power = (int *)malloc(sizeof(int));
    *power = digits(temp);

    int *sum = (int *)malloc(sizeof(int));
    *sum = 0;
    int *i = (int *)malloc(sizeof(int));
    int *digit = (int *)malloc(sizeof(int));
    for ( (*i) = 0; (*i) < (*power);(*i)++) {

        *digit = (*number)%10;
        *sum =  (*sum) + pow(digit,power);
        *number = (*number)/10;
    }

    if ((*sum) == (*temp)) {
        return 0;
    }

    else {
        return 1;
    }

    free(number);
    free(sum);
    free(power);
    free(i);
    free(digit);
    free(temp);
}

//function to check if a integer is a perfect number
int perfect(int *num) {
    int *temp = (int *)malloc(sizeof(int));
    *temp = *num;

    int *factors = (int *)malloc(sizeof(int));
    *factors = 0;

    int *i = (int *)malloc(sizeof(int));
    for ((*i) = 1;(*i) < (*temp);(*i)++) {
        if ((*temp)%(*i) == 0) {  
            *factors = (*factors) + (*i);
        }
    }

    if ((*factors) == (*temp)) {
        return 0;
    }

    else {
        return 1;
    }

    free(factors);
    free(i);
    free(temp);

}



int main() {
    int *option = (int *)malloc(sizeof(int));
    int *num = (int *)malloc(sizeof(int));

    while (1) {
        std::cout << "\nMenu:\n 1. Palindrome\n 2. Armstrong number\n 3. Perfect number\n 4. Exit\n";
        std::cin >> *option;


        if ( *option == 1) {
            std::cout << "Enter a number: ";
            std::cin >> *num;
            if (palindrome(num) == 0) {
                std::cout << *num << " is a palindrome.";
            }

            else {
                std::cout << *num << " is not a palindrome.";
            }
        }

        if (*option == 2) {
            std::cout << "Enter a number: ";
            std::cin >> *num;

            if (armstrong(num) == 0) {
                std::cout << *num << " is an armstrong number.";
            }

            else {
                std::cout << *num << " is not an armstrong number.";
            }
        }

        if (*option == 3) {
            std::cout << "Enter a number: ";
            std::cin >> *num;

            if (perfect(num) == 0) {
                std::cout << *num << " is a perfect number.";
            }
            
            else {
                std::cout << *num << " is not a perfect number.";
            }
        }

        if (*option == 4) {
            break;
        }
    }

    return 0;

    free(option);
    free(num);
}