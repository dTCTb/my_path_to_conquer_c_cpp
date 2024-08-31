// Fig. 17.7: Integer.h
// Integer class definition

class Integer {
  public:
    Integer(int i = 0);
    ~Integer();
    void setInteger(int i);
    int getInteger() const;

  private:
    int value;
};
