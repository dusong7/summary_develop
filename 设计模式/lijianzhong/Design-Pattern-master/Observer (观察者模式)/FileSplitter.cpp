class FileSplitter
{
public:
    FileSplitter(const string& filePath,int fileNumber，ProgressBar *progessBar):m_filePath(filePath),m_fileNumber(fileNumber)，m_progessBar(progessBar)
    {

    }
    ~FileSplitter();

    void split()
    {
        //1、读取大文件
        //2、分批次向小文件写入
        for(int i = 0; i < m_fileNumber; i++)
        {
            /* code */
        }
        
    }

private:
    string m_filePath;
    int m_fileNumber;

    ProgressBar *m_progessBar;//分割进度条   扮演了一个通知者的角色
};
