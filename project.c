#include <stdio.h>

// Define a structure for the currency conversion rates
struct CurrencyConverter {
    char currencyName[20]; // Currency name (e.g., USD, EUR)
    float conversionRate;  // Conversion rate to a base currency (e.g., USD)
};

// Function to convert amount from one currency to another
float convertCurrency(struct CurrencyConverter fromCurrency, struct CurrencyConverter toCurrency, float amount) {
    // Convert amount into base currency first, then to the target currency
    return (amount / fromCurrency.conversionRate) * toCurrency.conversionRate;
}

int main() {
    // Define conversion rates for some currencies (base currency assumed as USD)
    struct CurrencyConverter usd = {"USD", 1.0};
    struct CurrencyConverter eur = {"EUR", 0.92};   // Example: 1 USD = 0.92 EUR
    struct CurrencyConverter gbp = {"GBP", 0.76};   // Example: 1 USD = 0.76 GBP
    struct CurrencyConverter thb = {"THB", 34.51};  // Example: 1 USD = 34.51 THB
    struct CurrencyConverter bdt = {"BDT", 121.50};  // Example: 1 USD = 121.50 BDT
    struct CurrencyConverter sar = {"SAR", 3.75};  // Example: 1 USD = 3.75 SAR
    struct CurrencyConverter kwd = {"KWD", 0.31};  // Example: 1 USD = 0.31 KWD


    struct CurrencyConverter fromCurrency, toCurrency;
    float amount, convertedAmount;

    // Display available currencies
    printf("Available currencies: \n");
    printf("1. USD\n");
    printf("2. EUR\n");
    printf("3. GBP\n");
    printf("4. THB\n");
    printf("5. BDT\n");
    printf("6. SAR\n");
    printf("7. KWD\n");

    int choiceFrom, choiceTo;

    // User selects 'from' and 'to' currencies
    printf("Enter the currency number you want to convert from: ");
    scanf("%d", &choiceFrom);

    printf("Enter the currency number you want to convert to: ");
    scanf("%d", &choiceTo);

    // Select the appropriate structure based on user choice
    switch (choiceFrom) {
        case 1: fromCurrency = usd; break;
        case 2: fromCurrency = eur; break;
        case 3: fromCurrency = gbp; break;
        case 4: fromCurrency = thb; break;
        case 5: fromCurrency = bdt; break;
        case 6: fromCurrency = sar; break;
        case 7: fromCurrency = kwd; break;
        default: printf("Invalid choice\n"); return 0;
    }

    switch (choiceTo) {
        case 1: toCurrency = usd; break;
        case 2: toCurrency = eur; break;
        case 3: toCurrency = gbp; break;
        case 4: toCurrency = thb; break;
         case 5: toCurrency = bdt; break;
          case 6: toCurrency = sar; break;
           case 7: toCurrency = kwd; break;
        default: printf("Invalid choice\n"); return 0;
    }

    // User inputs the amount to convert
    printf("Enter the amount to convert: ");
    scanf("%f", &amount);

    // Perform the conversion
    convertedAmount = convertCurrency(fromCurrency, toCurrency, amount);

    // Display the result
    printf("%.2f %s = %.2f %s\n", amount, fromCurrency.currencyName, convertedAmount, toCurrency.currencyName);

    return 0;
}

