enum TaxBase
{
    CN_Tax;
    US_Tax;
    GE_Tax;
    FR_Tax;//更改
}


class SalesOrder
{
    TaxBase tax;
public:
    double CalculateTax()
    {
        //..
        if (tax == CN_Tax ) 
        {
            //CN-----
        }
        else if(tax == US_Tax)
        {
            //US----
        }
        else if (tax == GE_Tax)
        {
            //GE----
        }
        else if(tax == FR_Tax)  //更改
        {
            //FR----   
        }
        
        //...
        
    }
}