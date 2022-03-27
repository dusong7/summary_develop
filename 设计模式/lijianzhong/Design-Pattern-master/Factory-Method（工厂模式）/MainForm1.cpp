class MainForm
{
    TextBox* txtFilePath;
    TextBox* txtFileNumer;
    ProgressBar* progressBar;

public:
    void Button_Click()
    {
        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumer->getText().c_str());

        //编译时的细节依赖 违背了依赖倒置原则
        ISplitter *splitter = new BinarySplitter(filePath, number); //依赖具体类
        splitter->split();
    }
}