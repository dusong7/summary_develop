//具体类
class BinarySplitter:public ISplitter
{

};

class TxtSplitter:public ISplitter
{

};

class PictureSplitter:public ISplitter
{

};

class VideoSplitter:public ISplitter
{

};

//具体工厂
class BinarySplitterFactory:public SplitterFactory
{
public:
    virtual ISplitter* createSplitter()
    {
        return new BinarySplitter();
    }    
}

class TxtSplitter:public SplitterFactory
{
public:
    virtual ISplitter* createSplitter()
    {
        return new TxtSplitter();
    }    
}

class PictureSplitter:public SplitterFactory
{
public:
    virtual ISplitter* createSplitter()
    {
        return new PictureSplitter();
    }    
}

class VideoSplitter:public SplitterFactory
{
public:
    virtual ISplitter* createSplitter()
    {
        return new VideoSplitter();
    }    
}