#include <stdio.h>
#include <stdbool.h>
#include <cs50.h>

bool check_validity(long long card_number);
int find_length(long long n);
bool checksum(long long card_number);
void print_card_brand(long long card_number);


int main(void)
{
    long long card_number;
    do
    {
        card_number = get_long_long("Please enter the card number: \n");
    }
    while (card_number < 0);
    
    if (check_validity(card_number) == true)
    {
        print_card_brand(card_number);
    }
        
    else
        printf("INVALID\n");
}




//Defining check_validity
bool check_validity(long long card_number)
{
    int len = find_length(card_number);
    return (len == 13 || len == 15 || len == 16) && checksum(card_number);
}



//defining find_length
int find_length(long long n)
{
    int len;
    for (len = 0; n != 0; n /=10, len++);
    return len;
}




//Defining checksum
bool checksum(long long card_number)
{
    int sum = 0;
    for (int i = 0; card_number != 0; i++, card_number /= 10)
    {
        if (i % 2 == 0)
            sum += card_number%10;
        else
        {
            int digit = 2 * (card_number % 10);
            sum += digit / 10 + digit % 10;
            
        }
    }
    return (sum % 10) == 0;
}

void print_card_brand(long long card_number)
{
    if ((card_number >= 34e13 && card_number < 35e13) || (card_number >= 37e13 && card_number < 38e13))
        printf("AMEX\n");
    else if (card_number >= 51e14 || card_number < 56e14)
        printf("MASTERCARD\n");
    else if ((card_number >= 4e12 && card_number < 5e12) || (card_number >= 4e12 && card_number < 5e15))
        printf("VISA\n");
    else
        printf("INVALID\n");
}
