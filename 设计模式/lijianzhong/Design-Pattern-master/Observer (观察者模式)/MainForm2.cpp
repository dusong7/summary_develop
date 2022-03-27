class MainForm:public Form, public IProgrss
{
    TextBox* txtFilePath;
    TextBox* txtFileNumber;

    ProgressBar *progressBar;

public:
    void Button1_Click()
    {
        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumber->getText().c_str());

        ConsoleNotifier cn;

        FileSplitter splitter(filePath,number);

        splitter.addIprogress(this);//订阅通知
        splitter.addIprogress(&cn);//订阅通知

    
        splitter.split();
        splitter.removeIprogress(this);

    }

    virtual void DoProgress(float value)
    {
        progressBar->setValue(value);
    }
};

class ConsoleNotifier : public IProgess
{
public:
    virtual void DoProgress(float value)
    {
        std::cout<<".";
    }
}；