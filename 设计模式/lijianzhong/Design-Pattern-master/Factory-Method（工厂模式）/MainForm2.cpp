class MainForm
{

    SplitterFacetory *factory; //工厂


public:

    MainForm(SplitterFactory* factory)
    {
        this->factory = factory;
    }
    void Button_Click()
    {
        string filePath = txtFilePath->getText();
        int number = atoi(txtFileNumer->getText().c_str());

        ISplitter *splitter = factory->CreateSplitter(); //多态new
        splitter->split();
    }
}