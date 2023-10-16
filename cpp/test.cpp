class Test
{
public:
    Test(){};
    ~Test(){};
    void print(){};
};

int main()
{
    // Test *test = new Test();
    Test *test;
    // test->print();
    delete test;
    return (0);
}

