class IProgess
{
public:
    virtual void DoProgress(float value) = 0;
    ~IProgess();
};

class FileSplitter
{
public:
    FileSplitter(const string& filePath,int fileNumber):m_filePath(filePath),m_fileNumber(fileNumber)
    {

    }
    ~FileSplitter();

    void addIProgress(IProgess* iprogress)  //订阅者自主决定是否订阅此通知
    {
        m_iprogressList.add(iprogress);
    }


    void removeIProgress(IProgess* iprogress)
    {
        m_iprogressList.remove(iprogress);
    }


    void split()
    {
        //1、读取大文件
        //2、分批次向小文件写入
        for(int i = 0; i < m_fileNumber; i++)
        {
            //...
            float progessValue = m_fileNumber;
            progessValue = (i+1)/progessValue
            onProgress(progessValue);// 更新进度条
            
        }
        
    }

protected:
    void onProgress(float value)
    {
        List<IProgess*>::Iterator itor = m_iprogressList.begin();//向list里的每一个订阅者进行通知
        while(itor != m_iprogressList.end())                     
        {
            m_iprogress->DoProgress(value);
            itor++;
        } 
    }


private:
    string m_filePath;
    int m_fileNumber;

   // ProgressBar *m_progessBar;//分割进度条   扮演了一个通知者的角色
   //IProgess* m_iprogress; //抽象的通知机制
   List<IProgess*> m_iprogressList;//抽象的通知机制,支持多个观察者
};
