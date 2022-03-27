class SplitterFactory
{
public:
    virtual ISplitter* CreateSplitter()=0;
    virtual ~SplitterFactory(){}

}

//工厂基类
class ISplitter
{
public:
    virtual void split()=0;
    virtual ~ISplitter(){}
};
