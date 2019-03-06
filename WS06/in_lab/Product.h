#ifndef _SICT_PRODUCT_H

double price() const;
void display(std::ostream&os) const;
operator<<(std::ostream& os, const iProduct& p);
iProduct* readRecord(std::ifstream& file);
#endif // !_SICT_PRODUCT_H

