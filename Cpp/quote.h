#ifndef __QUOTE_H__
#define __QUOTE_H__

#include <string>

class Quote {
public:
    Quote() = default;
    Quote(const Quote&) = default;
    Quote(Quote&&) = default;
    Quote& operator=(const Quote&) = default;
    Quote& operator=(Quote &&) = default;
    virtual ~Quote() = default;

    Quote(const std::string &book, double sales_price) :
            bookNo(book), price(sales_price) { }
    std::string isbn() const { return bookNo; }

    virtual double net_price(std::size_t n) const
    {
        return n * price;
    }

private:
    std::string bookNo;
protected:
    double price = 0.0;
};

/*class Bulk_quote : public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);

    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;
    double discount = 0.0;
};
*/

class Disc_quote : public Quote {
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc) :
        Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0;
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote {
public:
    Bulk_quote() = default;
    using Disc_quote::Disc_quote;
    //Bulk_quote(const std::string &book, double price, std::size_t qty, double disc) :
    //    Disc_quote(book, price, qty, disc) { }
    double net_price(std::size_t) const override;
};
#endif
