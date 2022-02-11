#ifndef TMTAXCALCULATOR_H
#define TMTAXCALCULATOR_H

class TMTaxCalculator
{
public:
    TMTaxCalculator(int price);
    virtual ~TMTaxCalculator();
    void execute();
    int getTotal() const;

private:
    int price;
    int total;
};

#endif
