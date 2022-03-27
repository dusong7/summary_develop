class IProgess
{
public:
    virtual void DoProgress(float value) = 0;
    ~IProgess();
};

class FileSplitter
{
public:
    FileSplitter(const string& filePath,int fileNumber，IProgess* m_iprogress):m_filePath(filePath),m_fileNumber(fileNumber),m_iprogessBar(iprogress)
    {

    }
    ~FileSplitter();

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
        if (m_iprogess != nullptr )
        {
            m_iprogress->DoProgress(value);
        }
    }

private:
    string m_filePath;
    int m_fileNumber;

   // ProgressBar *m_progessBar;//分割进度条   扮演了一个通知者的角色
    IProgess* m_iprogress; //抽象的通知机制
};
