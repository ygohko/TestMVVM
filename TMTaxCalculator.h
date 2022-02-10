#ifndef TMTAXCALCULATOR_H
#define TMTAXCALCULATOR_H

class TMTaxCalculator
{
public:
    TMTaxCalculator(int price);
    virtual ~TMTaxCalculator();
    int execute();

private:
    int price;
};

#endif
