class Application : public Library
{
protected:
    virtual bool Step2()
    {
        //...子类重写实现
    }

    virtual bool Step4()
    {
        //...子类重写实现
    }
};

int main()
{
    Library *pLib = new Application();
    pLib->Run();
    delete pLib;
}
