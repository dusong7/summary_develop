class Messager
{
public:
    virtual void Login(string username,string password) = 0;
    virtual void SendMessage(string message) = 0;
    virtual void SendPicture(Image image) = 0;

    virtual void PlaySound()=0;
    virtual void DrawShape()=0;
    virtual void WriteText()=0;
    virtual void Connect()=0;

    virtual ~Messager(){}
};


class PCMessagerBase : public Messager
{
public:
    virtual void PlaySound()
    {
        //.....
    }
    virtual void DrawShape()
    {
        //.....
    }
    virtual void WriteText()
    {
        //.....
    }
    virtual void Connect()
    {
        //.....
    }

};

class MobileMessagerBase : public Messager
{
public:
    virtual void PlaySound()
    {
        //.....
    }
    virtual void DrawShape()
    {
        //.....
    }
    virtual void WriteText()
    {
        //.....
    }
    virtual void Connect()
    {
        //.....
    }

};


class PCMessagerLite : public PCMessagerBase
{
    virtual void Login(string username,string password)
    {
        PCMessagerBase::Connect();
        //.....
    }
    virtual void SendMessage(string message)
    {
        PCMessagerBase::WriteText();
        //.....
    }
    virtual void SendPicture(Image image)
    {
        PCMessagerBase::DrawShape();
        //.....
    }
}


class MobileMessagerLite : public MobileMessagerBase
{
    virtual void Login(string username,string password)
    {
        MobileMessagerBase::Connect();
        //.....
    }
    virtual void SendMessage(string message)
    {
        MobileMessagerBase::WriteText();
        //.....
    }
    virtual void SendPicture(Image image)
    {
        MobileMessagerBase::DrawShape();
        //.....
    }
}


class PCMessagerPerfect : public PCMessagerBase
{
    virtual void Login(string username,string password)
    {
        PCMessagerBase::Connect();
        //.....
        PCMessagerBase::PlaySound();
    }
    virtual void SendMessage(string message)
    {
        PCMessagerBase::WriteText();
        //.....
        PCMessagerBase::PlaySound();
    }
    virtual void SendPicture(Image image)
    {
        PCMessagerBase::DrawShape();
        //.....
        PCMessagerBase::PlaySound();
    }
}

class MobileMessagerPerfect : public MobileMessagerBase
{
    virtual void Login(string username,string password)
    {
        MobileMessagerBase::Connect();
        //.....
        MobileMessagerBase::PlaySound();
    }
    virtual void SendMessage(string message)
    {
        MobileMessagerBase::WriteText();
        //.....
        MobileMessagerBase::PlaySound();
    }
    virtual void SendPicture(Image image)
    {
        MobileMessagerBase::DrawShape();
        //.....
        MobileMessagerBase::PlaySound();
    }
}

void Process()
{
    Messager *m = new MobileMessagerPerfect();
}