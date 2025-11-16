#include <cs50.h>
#include <stdio.h>

bool luhnsAlgormith(long creditCard);

int main(void)
{
    long creditCard = get_long("Please insert you credit card Number?\n");

    long cardLenght = creditCard;
    long numberDigits = 0;

    while (cardLenght > 0)
    {
        cardLenght = cardLenght / 10;
        numberDigits++;
    }

    // printf("Number of digits is %ld\n", numberDigits);

    // Length check Check

    if (numberDigits != 13 && numberDigits != 15 && numberDigits != 16)
    {
        printf("INVALID\n");
        return 0;
    }

    // Luhn Check

    bool isValid = luhnsAlgormith(creditCard);
    if (!isValid)
    {
        printf("INVALID\n");
        return 0;
    }

    // Extract digits

    long twoDigits = creditCard;

    while (twoDigits >= 100)
    {
        twoDigits = twoDigits / 10;
    }

    // printf("The first two digits of this credit card are %ld\n", twoDigits);

    if (numberDigits == 15 && (twoDigits == 34 || twoDigits == 37))
    {
        printf("Number: %ld\n", creditCard);
        printf("AMEX\n");
    }
    else if (twoDigits > 50 && twoDigits < 56 && numberDigits == 16)
    {
        printf("Number: %ld\n", creditCard);
        printf("MASTERCARD\n");
    }
    else if (twoDigits > 39 && twoDigits < 50 && (numberDigits == 16 || numberDigits == 13))
    {
        printf("Number: %ld\n", creditCard);
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool luhnsAlgormith(long creditCard)
{
    long luhns = creditCard;
    long digit;
    int counter = 0;
    int sum = 0;

    while (luhns > 0)
    {

        digit = luhns % 10;
        luhns = luhns / 10;

        if (counter % 2 == 1)
        {

            int doubled = digit * 2;

            int ones = doubled % 10;
            int tens = doubled / 10;

            sum += ones + tens;
        }
        else
        {

            sum = digit + sum;
        }

        counter++;
    }

    if (sum % 10 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
