#include "GuiClass.h"

GuiClass::GuiClass(QWidget *parent) : QWidget(parent)
{
   DisplayMainMenu();
}

void GuiClass::DisplayMainMenu()
{

    ClearDynamicWidgets();
    user = new QPushButton(this);
    admin = new QPushButton(this);
    Return = new QPushButton(this);
    Return->hide();
    welcome = new QLabel("Welcome To Sh3b el Seny Mart",this);


    welcome->setFont(QFont("Arial", 50, QFont::Bold));
    welcome->setGeometry(QRect(10, 10, 1000, 200));
    welcome->setStyleSheet("color:black;");
    welcome->move(50,100);

    user->move(700,300);
    QIcon userIcon("D:\\PBLB\\UNI\\Data Stucts\\SuperMarket\\SM-GUI\\data\\UserIcon.png");
    user->setIcon(userIcon);
    user->setIconSize(QSize(150,150));
    user->setStyleSheet("border:none;");
    user->setFixedSize(225,200);

    admin->move(250,300);
    QIcon AdminIcon("D:\\PBLB\\UNI\\Data Stucts\\SuperMarket\\SM-GUI\\data\\admin.png");
    admin->setIcon(AdminIcon);
    admin->setIconSize(QSize(150,150));
    admin->setStyleSheet("border:none;");
    admin->setFixedSize(225,200);

    welcome->show();
    user->show();
    admin->show();

    QIcon ReturnIcon("D:\\PBLB\\UNI\\Data Stucts\\SuperMarket\\SM-GUI\\data\\Return.png");
    Return->setIcon(ReturnIcon);
    Return->setGeometry(10,10,100,100);
    Return->setIconSize(QSize(50,50));
    Return->setStyleSheet("border:none;");
    Return->hide();
    QObject::connect(admin, &QPushButton::clicked,this,&GuiClass::DisplayAdmin);
    QObject::connect(user,&QPushButton::clicked,this,&GuiClass::DisplayUser);
}
void GuiClass::DisplayAdmin()
{
    user->hide();
    admin->hide();
    welcome->hide();

    ProductTable = new QTableWidget(this);
    NewCategory = new QPushButton(this);
    NewProduct = new QPushButton(this);
    RemoveCategory = new QPushButton(this);
    RemoveProduct = new QPushButton(this);
    OrderDisplay = new QPushButton(this);

    ProductTable->setColumnCount(5);
    ProductTable->setHorizontalHeaderLabels({"ID","Product", "Price", "Quantity","Category"});
    ProductTable->show();
    ProductTable->setAlternatingRowColors(true);
    ProductTable->setRowCount(0);
    ProductTable->setColumnWidth(0, 101);        // Adjust column width for better visibility
    ProductTable->setColumnWidth(1, 300);// Example width for the second column
    ProductTable->setColumnWidth(2, 101);
    ProductTable->setColumnWidth(3, 101);
    ProductTable->setColumnWidth(4, 265);
    ProductTable->setGeometry(100, 150, 900, 600);
    QString ACpath = "D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/AddCategory.png";
    NewCategory->setIcon(QIcon(ACpath));
    NewCategory->setIconSize(QSize(100,50));
    NewCategory->setGeometry(950, 10, 110,50);
    NewCategory->setStyleSheet("background-color: #3E64FF;"
                               "border-radius: 5px;");
    NewCategory->show();
    QObject::connect(NewCategory, &QPushButton::clicked,this,&GuiClass::AddCategoryWindow);


    QString APpath = "D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/AddProduct.png";
    NewProduct->setIcon(QIcon(APpath));
    NewProduct->setIconSize(QSize(100,50));
    NewProduct->setGeometry(950, 70, 110,50);
    NewProduct->setStyleSheet("background-color: #3E64FF;"
        "border-radius: 5px;");

    QObject::connect(NewProduct, &QPushButton::clicked,this,&GuiClass::AddProductWindow);
    NewProduct->show();

     QString RCpath = "D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/RemoveCategory.png";
     RemoveCategory->setIcon(QIcon(RCpath));
     RemoveCategory->setIconSize(QSize(100,50));
     RemoveCategory->setGeometry(825, 10, 110,50);
     RemoveCategory->setStyleSheet("background-color: #ff3131;"
         "border-radius: 5px;");
     RemoveCategory->show();

     QObject::connect(RemoveCategory, &QPushButton::clicked,this,&GuiClass::RemoveCategoryWindow);

     QString RPpath = "D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/RemoveProduct.png";
     RemoveProduct->setIcon(QIcon(RPpath));
     RemoveProduct->setIconSize(QSize(100,50));
     RemoveProduct->setGeometry(825, 70, 110,50);
     RemoveProduct->setStyleSheet("background-color: #ff3131;"
         "border-radius: 5px;");
     RemoveProduct->show();

    QObject::connect(RemoveProduct, &QPushButton::clicked,this,&GuiClass::RemoveProductWindow);
    BuildTable();

    Return->show();
    QObject::connect(Return, &QPushButton::clicked,this,&GuiClass::DisplayMainMenu);

    OrderDisplay->setGeometry(100, 32, 200,50);
    OrderDisplay->setText("Display Orders");
    OrderDisplay->setStyleSheet("font-size: 16px;"             // Increased font size
                      "font-family: 'Courier New', monospace;" // Changed to a different font
                      "font-weight: bold;"          // Made the text bold
                      "border-radius: 5px;"         // Rounded corners
                      "color: white;"               // Button text color
                      "background-color: #00bf63;"  // Light orange background
                      "padding: 10px;");            // Padding for better appearance

    OrderDisplay->show();
    connect(OrderDisplay,QPushButton::clicked,this,DisplayOrders);
}
void GuiClass::AddCategoryWindow()
{
    QString ACpath = "D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/AddCategory.png";
    AdditionalWin = new QMainWindow();
    AdditionalWin->setWindowIcon(QIcon(ACpath));
    AdditionalWin->setIconSize(QSize(10,5));
    AdditionalWin->setWindowTitle("Add Category");

    AdditionalWin->setFixedSize(300,270);
    AdditionalWin->setStyleSheet("background-color: #FFFFFF;");

    AWlabel = new QLabel("Add Category",AdditionalWin);
    AWlabel->setGeometry(QRect(50,40,200,50));
    AWlabel->setStyleSheet("font-size: 25px;"
                      "font-family: Arial, sans-serif;"
                      "font-weight: bold;"
                      "color: black;"); // Fixed color property

    AdditionalInput = new QLineEdit(AdditionalWin);
    AdditionalInput->setGeometry(QRect(50,100,200,50));
    AdditionalInput->setPlaceholderText("Enter A New Category");
    AdditionalInput->setStyleSheet("font-size: 14px;"
                      "font-family: sans-serif;"
                      "padding: 5px;"
                      "border: 1px solid #3E64FF;"
                      "color: #4D4D4D;"
                      "border-radius: 5px;"); // Style the input field
    Submit = new QPushButton("SUBMIT",AdditionalWin);
    Submit->setGeometry(QRect(50,175,200,50));
    Submit->setStyleSheet("font-size: 16px;"             // Increased font size
                      "font-family: 'Courier New', monospace;" // Changed to a different font
                      "font-weight: bold;"          // Made the text bold
                      "border-radius: 5px;"         // Rounded corners
                      "color: white;"               // Button text color
                      "background-color: #FFA500;"  // Light orange background
                      "padding: 10px;");            // Padding for better appearance

    QObject::connect(Submit, &QPushButton::clicked,this,&GuiClass::SubmitCategory);
    AdditionalInput->show();
    AWlabel->show();
    Submit->show();
    AdditionalWin->show();
}
void GuiClass::SubmitCategory()
{
    string categoryName = AdditionalInput->text().toStdString();
    store.addCategory(categoryName);
    AdditionalWin->close();
}
void GuiClass::AddProductWindow()
{
    QString ACpath = "D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/AddProduct.png";
    AdditionalWin = new QMainWindow();
    AdditionalWin->setWindowIcon(QIcon(ACpath));
    AdditionalWin->setIconSize(QSize(10,5));
    AdditionalWin->setWindowTitle("Add Product");
    AdditionalWin->setFixedSize(550,450);
    AdditionalWin->setStyleSheet("background-color: #FFFFFF;");

    DDMCategories = new QComboBox(AdditionalWin);
    DDMCategories->setPlaceholderText("Select a Category");
    set<Category*>* categories= store.getCategories()->getGroups();
    for (const auto& c:*categories)
    {
        DDMCategories->addItem(QString::fromStdString(c->getName()));
    }
    DDMCategories->setGeometry(300,100,200,50);
    DDMCategories->setStyleSheet(
       "QComboBox {"
    "    color: black;" // Text color for the combo box
    "    background-color: white;" // Background color for the combo box
    "    border: 1px solid #3E64FF;" // Border color for the combo box
    "    border-radius: 5px;" // Rounded corners
    "    padding: 5px;" // Padding inside the combo box
    "    font-size: 14px;" // Font size for the text
    "    font-family: Arial, sans-serif;" // Font family
    "}"
    "QComboBox::drop-down {"
    "    background-color: #FFA500;" // Background color of the drop-down button
    "    border-left: 1px solid #3E64FF;" // Border between text field and drop-down
    "    border-top-right-radius: 5px;" // Rounded top-right corner
    "    border-bottom-right-radius: 5px;" // Rounded bottom-right corner
    "    width: 20px;" // Increase drop-down button size if needed
    "}"
    "QComboBox QAbstractItemView {"
    "    color: black;" // Text color of the items in the dropdown list
    "    background-color: white;" // Background color of the dropdown list
    "    border-radius: 5px;" // Rounded corners for the dropdown list
    "    selection-background-color: #3E64FF;" // Background color of the selected item
    "    selection-color: white;" // Text color of the selected item
    "    padding: 5px;" // Padding for each item in the dropdown
    "    font-size: 14px;" // Font size of the dropdown items
    "    font-family: Arial, sans-serif;" // Font family for the dropdown items
    "    max-height: 150px;" // Ensure dropdown is not too tall
    "    min-width: 200px;" // Set a minimum width for the dropdown
    "}"
    "QComboBox QAbstractItemView::item {"
    "    padding: 10px 20px;" // Adds space around each item
    "    border-bottom: 1px solid #ddd;" // Subtle line between items
    "    transition: background-color 0.3s ease, color 0.3s ease;"
    "}"
    "QComboBox QAbstractItemView::item:hover {"
    "    background-color: #F1F1F1;" // Light gray background when hovering
    "    color: #3E64FF;" // Text color changes to blue on hover
    "}"
    );


    AWlabel = new QLabel("Add Product",AdditionalWin);
    AWlabel->setGeometry(QRect(50,40,200,50));
    AWlabel->setStyleSheet("font-size: 25px;"
                      "font-family: Arial, sans-serif;"
                      "font-weight: bold;"
                      "color: black;"); // Fixed color property

    AdditionalInput = new QLineEdit(AdditionalWin);
    AdditionalInput->setGeometry(QRect(50,100,200,50));
    AdditionalInput->setPlaceholderText("Enter A New Product");
    AdditionalInput->setStyleSheet("font-size: 14px;"
                      "font-family: sans-serif;"
                      "padding: 5px;"
                      "border: 1px solid #3E64FF;"
                      "color: #4D4D4D;"
                      "border-radius: 5px;");

    productPrice = new QLineEdit(AdditionalWin);
    productPrice->setGeometry(QRect(50,175,200,50));
    productPrice->setPlaceholderText("Set Product Price");
    productPrice->setStyleSheet("font-size: 14px;"
                      "font-family: sans-serif;"
                      "padding: 5px;"
                      "border: 1px solid #3E64FF;"
                      "color: #4D4D4D;"
                      "border-radius: 5px;");

    productQuantity = new QLineEdit(AdditionalWin);
    productQuantity->setGeometry(QRect(300,175,200,50));
    productQuantity->setPlaceholderText("Set Product Quantity");
    productQuantity->setStyleSheet("font-size: 14px;"
                      "font-family: sans-serif;"
                      "padding: 5px;"
                      "border: 1px solid #3E64FF;"
                      "color: #4D4D4D;"
                      "border-radius: 5px;");

    Submit = new QPushButton("SUBMIT",AdditionalWin);
    Submit->setGeometry(QRect(175,325,200,50));
    Submit->setStyleSheet("font-size: 16px;"             // Increased font size
                      "font-family: 'Courier New', monospace;" // Changed to a different font
                      "font-weight: bold;"          // Made the text bold
                      "border-radius: 5px;"         // Rounded corners
                      "color: white;"               // Button text color
                      "background-color: #FFA500;"  // Light orange background
                      "padding: 10px;");            // Padding for better appearance

    QObject::connect(Submit, &QPushButton::clicked,this,&GuiClass::validateProduct);
    AdditionalWin->show();
    AdditionalInput->show();
    DDMCategories->show();
    productPrice->show();
    productQuantity->show();
    Submit->show();

}
void GuiClass::BuildTable()
{
    ProductTable->setRowCount(0);
    int currentRow = 0;
    for (QLabel* label : alertLabels)
    {
        label->hide();       // Hide the label
        delete label;        // Delete the QLabel object
    }
    alertLabels.clear();
    for (const auto& c:*(store.getCategories()->getGroups()))
    {
        for (const auto& p:c->getProducts()->AvlTreeAsVector())
        {
            auto mp = *(store.getInventory()->getStock());
            auto ms = *(store.getInventory()->getAlert());
            QColor lightRed(255, 200, 200);
            if (ms[p.getName()])
            {
                ProductTable->insertRow(currentRow);
                ProductTable->setItem(currentRow, 0, new QTableWidgetItem(QString::fromStdString(p.getCode()))); // Row number or any default data
                ProductTable->setItem(currentRow, 1, new QTableWidgetItem(QString::fromStdString(p.getName())));
                ProductTable->setItem(currentRow, 2, new QTableWidgetItem(QString::number(p.getPrice())));
                ProductTable->setItem(currentRow, 3, new QTableWidgetItem(QString::number(mp[p])));
                ProductTable->setItem(currentRow, 4, new QTableWidgetItem(QString::fromStdString(c->getName())));

                QLabel* alertIconLabel = new QLabel(this);
                QPixmap alertIcon("D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/AlertIcon.png");
                alertIcon = alertIcon.scaled(30, 30, Qt::KeepAspectRatio, Qt::SmoothTransformation);
                alertIconLabel->setPixmap(alertIcon);
                currentRow++;
                // Position QLabel outside the table, dynamically adjusted
                alertIconLabel->setGeometry(ProductTable->geometry().right() + 10,
                                            150 + (currentRow * 32), 30, 30);
                alertIconLabel->show();

                // Add QLabel to the list
                alertLabels.append(alertIconLabel);




            }
        }
    }
    for (const auto& c:*(store.getCategories()->getGroups()))
    {
        for (const auto& p:c->getProducts()->AvlTreeAsVector())
            {
                auto mp = *(store.getInventory()->getStock());
                auto ms = *(store.getInventory()->getAlert());
                if (!ms[p.getName()])
                {
                    ProductTable->insertRow(currentRow);
                    ProductTable->setItem(currentRow, 0, new QTableWidgetItem(QString::fromStdString(p.getCode()))); // Row number or any default data
                    ProductTable->setItem(currentRow, 1, new QTableWidgetItem(QString::fromStdString(p.getName())));
                    ProductTable->setItem(currentRow, 2, new QTableWidgetItem(QString::number(p.getPrice())));
                    ProductTable->setItem(currentRow, 3, new QTableWidgetItem(QString::number(mp[p])));
                    ProductTable->setItem(currentRow, 4, new QTableWidgetItem(QString::fromStdString(c->getName())));
                    currentRow++;
                }
            }
    }
     ProductTable->setStyleSheet(
    "QTableWidget {"
    "    border: 2px solid black;"              // Outer border of the table
    "    border-radius: 5px;"                  // Rounded corners for the table
    "    gridline-color: black;"               // Black gridlines between cells
    "    alternate-background-color: #E8F4FF;" // Light blue for alternate rows
    "    background-color: white;"            // Default row color
    "}"
    "QHeaderView::section {"
    "    background-color: #3E64FF;"          // Header background color
    "    color: white;"                       // Header text color
    "    padding: 5px;"                       // Padding inside headers
    "    border: 1px solid black;"            // Black border for header sections
    "    font-weight: bold;"                  // Bold text for headers
    "    font-size: 14px;"                    // Font size for headers
    "    font-family: Arial, sans-serif;"     // Font family for headers
    "}"
    "QTableWidget::item {"
    "    padding: 10px;"                      // Cell padding for better spacing
    "    color: black;"
    "    font-size: 14px;"                    // Font size for cell text
    "    font-family: Arial, sans-serif;"     // Font family for cell text
    "}"
    "QTableWidget::item:hover {"
    "    background-color: #F1F1F1;"          // Hover effect: light gray background
    "    color: black;"                       // Hover effect: black text
    "}"
    "QTableWidget::item:selected {"
    "    background-color: #FFC107;"          // Highlighted row background: yellow
    "    color: black;"                       // Highlighted row text: black
    "}"
    "QScrollBar:horizontal {"
    "    background: #F4F4F4;"                // Background for the horizontal scrollbar
    "    height: 12px;"                       // Height of the scrollbar
    "}"
    "QScrollBar::handle:horizontal {"
    "    background: #3E64FF;"                // Handle color for the scrollbar
    "    border-radius: 5px;"                 // Rounded scrollbar handle
    "}"
    "QTableWidget::item {"
    "    background-color: white;"              // Default row background
    "    border: 1px solid #DDDDDD;"            // Light border around cells
    "    font-family: Arial, sans-serif;"       // Font style
    "    font-size: 14px;"                      // Font size
    "    padding: 5px;"                         // Padding inside cells
    "}"
    "QTableWidget::item:alternate {"
    "    background-color: #F0F8FF;"            // Alternate row background
    "}"
    "QTableWidget::item:selected {"
    "    background-color: #FFC107;"            // Highlighted row background
    "    color: black;"                         // Highlighted text color
    "}"
);

}
void GuiClass::validateProduct()
{
    bool priceOk = !productPrice->text().isEmpty();
    bool quantityOk = !productQuantity->text().isEmpty();

    // Check if both fields contain valid integers
    if (priceOk && quantityOk)
    {
        float price =  productPrice->text().toFloat();
        int quantity = productQuantity->text().toInt();
        SubmitProduct(DDMCategories->currentText().toStdString(),AdditionalInput->text().toStdString(),price,quantity);
    }
    else
    {
        // Show an error message if the fields are empty or invalid
        QMessageBox::warning(this, "Input Error", "Please enter valid integer values for both price and quantity.");
    }
}
void GuiClass::SubmitProduct(string cname,string pname,float p ,int q)
{
    store.addProduct(cname,pname,p,q);
    BuildTable();
    AdditionalWin->close();
}
void GuiClass::RemoveProductWindow()
{
    QString RPpath = "D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/RemoveProduct.png";
    AdditionalWin = new QMainWindow();
    AdditionalWin->setWindowIcon(QIcon(RPpath));
    AdditionalWin->setIconSize(QSize(10,5));
    AdditionalWin->setWindowTitle("Remove Product");

    AdditionalWin->setFixedSize(300,270);
    AdditionalWin->setStyleSheet("background-color: #FFFFFF;");

    AWlabel = new QLabel("Remove Product",AdditionalWin);
    AWlabel->setGeometry(QRect(50,40,200,50));
    AWlabel->setStyleSheet("font-size: 25px;"
                      "font-family: Arial, sans-serif;"
                      "font-weight: bold;"
                      "color: black;");

    DDMProduct= new QComboBox(AdditionalWin);
    DDMProduct->setGeometry(50,100,200,50);
    DDMProduct->setPlaceholderText("Select a Product");
    auto stock= store.getInventory()->getStock();
    for (const auto& p:*stock)
    {
        DDMProduct->addItem(QString::fromStdString(p.first.getName()));
    }
    DDMProduct->setStyleSheet(
       "QComboBox {"
    "    color: black;" // Text color for the combo box
    "    background-color: white;" // Background color for the combo box
    "    border: 1px solid #3E64FF;" // Border color for the combo box
    "    border-radius: 5px;" // Rounded corners
    "    padding: 5px;" // Padding inside the combo box
    "    font-size: 14px;" // Font size for the text
    "    font-family: Arial, sans-serif;" // Font family
    "}"
    "QComboBox::drop-down {"
    "    background-color: #FFA500;" // Background color of the drop-down button
    "    border-left: 1px solid #3E64FF;" // Border between text field and drop-down
    "    border-top-right-radius: 5px;" // Rounded top-right corner
    "    border-bottom-right-radius: 5px;" // Rounded bottom-right corner
    "    width: 20px;" // Increase drop-down button size if needed
    "}"
    "QComboBox QAbstractItemView {"
    "    color: black;" // Text color of the items in the dropdown list
    "    background-color: white;" // Background color of the dropdown list
    "    border-radius: 5px;" // Rounded corners for the dropdown list
    "    selection-background-color: #3E64FF;" // Background color of the selected item
    "    selection-color: white;" // Text color of the selected item
    "    padding: 5px;" // Padding for each item in the dropdown
    "    font-size: 14px;" // Font size of the dropdown items
    "    font-family: Arial, sans-serif;" // Font family for the dropdown items
    "    max-height: 150px;" // Ensure dropdown is not too tall
    "    min-width: 200px;" // Set a minimum width for the dropdown
    "}"
    "QComboBox QAbstractItemView::item {"
    "    padding: 10px 20px;" // Adds space around each item
    "    border-bottom: 1px solid #ddd;" // Subtle line between items
    "    transition: background-color 0.3s ease, color 0.3s ease;" // Smooth transitions
    "}"
    "QComboBox QAbstractItemView::item:hover {"
    "    background-color: #F1F1F1;" // Light gray background when hovering
    "    color: #3E64FF;" // Text color changes to blue on hover
    "}"
    );
    Submit = new QPushButton("SUBMIT",AdditionalWin);
    Submit->setGeometry(QRect(50,175,200,50));
    Submit->setStyleSheet("font-size: 16px;"             // Increased font size
                      "font-family: 'Courier New', monospace;" // Changed to a different font
                      "font-weight: bold;"          // Made the text bold
                      "border-radius: 5px;"         // Rounded corners
                      "color: white;"               // Button text color
                      "background-color: #FFA500;"  // Light orange background
                      "padding: 10px;");            // Padding for better appearance

    QObject::connect(Submit, &QPushButton::clicked,this,&GuiClass::SubmitRemoveProduct);

    DDMProduct->show();
    Submit->show();
    AWlabel->show();
    AdditionalWin->show();

}
void GuiClass::SubmitRemoveProduct()
{
    store.removeProduct(DDMProduct->currentText().toStdString());
    BuildTable();
    AdditionalWin->close();
}
void GuiClass::RemoveCategoryWindow()
{
    QString RPpath = "D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/RemoveCategory.png";
    AdditionalWin = new QMainWindow();
    AdditionalWin->setWindowIcon(QIcon(RPpath));
    AdditionalWin->setIconSize(QSize(10,5));
    AdditionalWin->setWindowTitle("Remove Category");

    AdditionalWin->setFixedSize(330,300);
    AdditionalWin->setStyleSheet("background-color: #FFFFFF;");

    AWlabel = new QLabel("Remove Category",AdditionalWin);
    AWlabel->setGeometry(QRect(50,40,250,50));
    AWlabel->setStyleSheet("font-size: 25px;"
                      "font-family: Arial, sans-serif;"
                      "font-weight: bold;"
                      "color: black;");

     DDMCategories = new QComboBox(AdditionalWin);
    DDMCategories->setPlaceholderText("Select a Category");
    set<Category*>* categories= store.getCategories()->getGroups();
    for (const auto& c:*categories)
    {
        DDMCategories->addItem(QString::fromStdString(c->getName()));
    }
    DDMCategories->setGeometry(50,100,200,50);
    DDMCategories->setStyleSheet(
       "QComboBox {"
    "    color: black;" // Text color for the combo box
    "    background-color: white;" // Background color for the combo box
    "    border: 1px solid #3E64FF;" // Border color for the combo box
    "    border-radius: 5px;" // Rounded corners
    "    padding: 5px;" // Padding inside the combo box
    "    font-size: 14px;" // Font size for the text
    "    font-family: Arial, sans-serif;" // Font family
    "}"
    "QComboBox::drop-down {"
    "    background-color: #FFA500;" // Background color of the drop-down button
    "    border-left: 1px solid #3E64FF;" // Border between text field and drop-down
    "    border-top-right-radius: 5px;" // Rounded top-right corner
    "    border-bottom-right-radius: 5px;" // Rounded bottom-right corner
    "    width: 20px;" // Increase drop-down button size if needed
    "}"
    "QComboBox QAbstractItemView {"
    "    color: black;" // Text color of the items in the dropdown list
    "    background-color: white;" // Background color of the dropdown list
    "    border-radius: 5px;" // Rounded corners for the dropdown list
    "    selection-background-color: #3E64FF;" // Background color of the selected item
    "    selection-color: white;" // Text color of the selected item
    "    padding: 5px;" // Padding for each item in the dropdown
    "    font-size: 14px;" // Font size of the dropdown items
    "    font-family: Arial, sans-serif;" // Font family for the dropdown items
    "    max-height: 150px;" // Ensure dropdown is not too tall
    "    min-width: 200px;" // Set a minimum width for the dropdown
    "}"
    "QComboBox QAbstractItemView::item {"
    "    padding: 10px 20px;" // Adds space around each item
    "    border-bottom: 1px solid #ddd;" // Subtle line between items
    "    transition: background-color 0.3s ease, color 0.3s ease;"
    "}"
    "QComboBox QAbstractItemView::item:hover {"
    "    background-color: #F1F1F1;" // Light gray background when hovering
    "    color: #3E64FF;" // Text color changes to blue on hover
    "}"
    );
    Submit = new QPushButton("SUBMIT",AdditionalWin);
    Submit->setGeometry(QRect(50,175,200,50));
    Submit->setStyleSheet("font-size: 16px;"             // Increased font size
                      "font-family: 'Courier New', monospace;" // Changed to a different font
                      "font-weight: bold;"          // Made the text bold
                      "border-radius: 5px;"         // Rounded corners
                      "color: white;"               // Button text color
                      "background-color: #FFA500;"  // Light orange background
                      "padding: 10px;");            // Padding for better appearance

    QObject::connect(Submit, &QPushButton::clicked,this,&GuiClass::SubmitRemoveCategory);

    AdditionalWin->show();
    DDMCategories->show();
    AWlabel->show();

}
void GuiClass::SubmitRemoveCategory()
{
    store.removeCategory(DDMCategories->currentText().toStdString());
    BuildTable();
    AdditionalWin->close();
}

void GuiClass::DisplayUser()
{
    admin->hide();
    user->hide();
    Username =  new QLineEdit(this);
    Username->setGeometry(340,290,400,100);
    Username->setPlaceholderText("Enter Username");
    Username->setStyleSheet("font-size: 30px;"
                      "font-family: sans-serif;"
                      "padding: 5px;"
                      "border: 1px solid #3E64FF;"
                      "color: #4D4D4D;"
                      "border-radius: 5px;");

    Email = new QLineEdit(this);
    Email->setGeometry(340,410,400,100);
    Email->setPlaceholderText("Enter Email");
    Email->setStyleSheet("font-size: 30px;"
                      "font-family: sans-serif;"
                      "padding: 5px;"
                      "border: 1px solid #3E64FF;"
                      "color: #4D4D4D;"
                      "border-radius: 5px;");

    Password = new QLineEdit(this);
    Password = new QLineEdit(this);
    Password->setGeometry(340, 540, 400, 100);
    Password->setPlaceholderText("Enter Password");
    Password->setEchoMode(QLineEdit::Password); // Initially set to password mode
    Password->setStyleSheet("font-size: 30px;"
                            "font-family: sans-serif;"
                            "padding: 5px;"
                            "border: 1px solid #3E64FF;"
                            "color: #4D4D4D;"
                            "border-radius: 5px;");

    // Create the toggle button (eye icon)
    toggleButton = new QToolButton(Password);
    toggleButton->setIcon(QIcon("D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/openedEye.png")); // Replace with actual eye icon path
    toggleButton->setCheckable(true); // Make the button toggleable
    toggleButton->setStyleSheet("border: none;"); // Remove border for a clean look

    // Add the button inside the QLineEdit
    QHBoxLayout *layout = new QHBoxLayout(Password);
    layout->addStretch();               // Push the toggle button to the right
    layout->addWidget(toggleButton);    // Add the button
    layout->setContentsMargins(0, 0, 10, 0); // Adjust padding for proper alignment
    Password->setLayout(layout);

    // Connect the toggle button to toggle the password visibility
    connect(toggleButton, &QToolButton::toggled, this, [=](bool checked)
        {
        if (checked) {
            Password->setEchoMode(QLineEdit::Normal); // Show password
            toggleButton->setIcon(QIcon("D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/closedEye.png")); // Change to eye-off icon
        } else {
            Password->setEchoMode(QLineEdit::Password); // Hide password
            toggleButton->setIcon(QIcon("D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/openedEye.png")); // Change to eye icon
        }
    });


    Submit = new QPushButton(this);
    QString SBpath = "D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/Proceed.png";
    Submit->setIcon(QIcon(SBpath));
    Submit->setIconSize(QSize(150,100));
    Submit->setGeometry(800, 420, 150,100);
    Submit->setStyleSheet("background-color: #00bf63;"
                               "border-radius: 5px;");
    Submit->show();

    Username->show();
    Email->show();
    Password->show();
    Return->show();
    QObject::connect(Return, &QPushButton::clicked,this,&GuiClass::DisplayMainMenu);
    QObject::connect(Submit, &QPushButton::clicked,this,VerifyLogin);

}
bool GuiClass::MakeUser()
{
    string UserEmail = Email->text().toStdString();
    string UserPassword = Password->text().toStdString();
    return store.enterStore(UserEmail,UserPassword);
}
void GuiClass::VerifyLogin()
{
    if (!MakeUser())
    {
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setWindowTitle("Login Error");
        msgBox.setText("Invalid email or password.");
        msgBox.setInformativeText("Please check your credentials and try again.");
        msgBox.setStandardButtons(QMessageBox::Ok);
        msgBox.setDefaultButton(QMessageBox::Ok);
        msgBox.exec(); // Displays the message box
    }
    else
    {
        UserName = Username->text();
        ClearDynamicWidgets();
        DisplaySuperMarket();
    }
}
void GuiClass::DisplaySuperMarket()
{
    ClearDynamicWidgets();
    user->setFixedSize(50,50);
    user->move(150,10);
    user->setIconSize(QSize(40,40));
    user->show();

    connect(user,QPushButton::clicked,this,UserData);
    connect(Return,&QPushButton::clicked,this,DisplayMainMenu);
    Return->show();
    DisplayScroll();
}
void GuiClass::DisplayScroll()
{
    scrollArea = new QScrollArea(this);
    QWidget *buttonContainer = new QWidget(scrollArea);
    QHBoxLayout *buttonLayout = new QHBoxLayout(buttonContainer);

    // Add buttons to the layout
    for (auto c:*(store.getCategories()->getGroups()))
        {
        QPushButton *button = new QPushButton( QString::fromStdString(c->getName()),buttonContainer);
        buttonLayout->addWidget(button);
        button->setFixedSize(180,120);


        // Style each button
        button->setStyleSheet(
            "QPushButton {"
            "    background-color: #FFA500;"
            "    color: white;"                      // White text color
            "    border: none;"                      // Remove border
            "    padding: 10px 20px;"                // Padding inside the button
            "    border-radius: 5px;"                // Rounded corners
            "    font-size: 20px;"                   // Text size
            "    font-family: Arial, sans-serif;"    // Font family
            "}"
            "QPushButton:hover {"
            "    background-color: #2A4FB0;"         // Darker blue when hovered
            "    cursor: pointer;"                   // Change cursor to pointer
            "}"
            "QPushButton:pressed {"
            "    background-color: #1A3C8C;"         // Even darker blue when clicked
            "    box-shadow: 0 2px 5px rgba(0, 0, 0, 0.2);"
            "}"
        );
        connect(button, &QPushButton::clicked, [this, categoryName = c->getName()]() {
        DisplayProducts(categoryName);
    });
    }

    // Set the button container as the widget inside the scroll area
    scrollArea->setWidget(buttonContainer);
    scrollArea->setWidgetResizable(true);  // Allow resizing of the scrollable content
    scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);  // Enable horizontal scrollbar
    scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);  // Disable vertical scrollbar

    // Set the geometry and style for the scroll area
    scrollArea->setGeometry(100, 100, 900, 200);  // Adjust the position and size as per your requirement

    // Set custom styling for the scrollbars
    scrollArea->setStyleSheet(
     "QScrollArea {"
     "    border: 2px solid #DCDCDC;"       // Light border around the scroll area
     "    border-radius: 8px;"             // Rounded corners for the scroll area
     "    background-color: #F9F9F9;"      // Light background color
     "}"
     "QScrollBar:horizontal {"
     "    border: none;"                   // No border for the horizontal scrollbar
     "    background: #EDEDED;"            // Light grey background for the scrollbar
     "    height: 12px;"                   // Height of the horizontal scrollbar
     "    border-radius: 6px;"             // Rounded corners for the scrollbar
     "}"
     "QScrollBar::handle:horizontal {"
     "    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, "
     "                                stop:0 #4DA8FF, stop:1 #0073E6);" // Blue gradient
     "    border-radius: 6px;"             // Rounded corners for the handle
     "    min-width: 50px;"                // Minimum width for the handle
     "}"
     "QScrollBar::handle:horizontal:hover {"
     "    background: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:1, "
     "                                stop:0 #0073E6, stop:1 #005BB5);" // Darker blue gradient
     "    box-shadow: 0 0 8px rgba(0, 115, 230, 0.6);" // Glow effect
     "}"
     "QScrollBar::add-line:horizontal, QScrollBar::sub-line:horizontal {"
     "    background: none;"               // No add/sub arrows
     "    border: none;"                   // No border for add/sub arrows
     "}"
     "QScrollBar::up-arrow:horizontal, QScrollBar::down-arrow:horizontal {"
     "    border: none;"                   // No arrows
     "    background: none;"               // No arrow background
     "}"
     "QScrollBar::corner {"
     "    background: none;"               // No corner background
     "}"
 );


    // Show the scroll area with buttons
    scrollArea->show();
}
void GuiClass::DisplayProducts(const string &categoryName)
{
    // Create a new scroll area for displaying products
    productsScrollArea = new QScrollArea(this);
    productContainer = new QWidget(productsScrollArea);
    QVBoxLayout *productLayout = new QVBoxLayout(productContainer);

    // Style the product container
    productContainer->setStyleSheet(
        "QWidget {"
        "    background-color: #FAFAFA;"       // Light background for the entire container
        "    padding: 10px;"                   // Padding around the content
        "}"
    );

    // Fetch products from the category
    auto category = *(store.getCategories()->findCategory(categoryName));
    for (const auto &product : category->getProducts()->AvlTreeAsVector())
{
    // Create a widget for each product
    QWidget *productWidget = new QWidget(productContainer);
    QHBoxLayout *layout = new QHBoxLayout(productWidget);

    // Style the product widget container
    productWidget->setStyleSheet(
        "QWidget {"
        "    background-color: #FFFFFF;"       // White background for product widget
        "    border: 1px solid #E0E0E0;"       // Light grey border
        "    border-radius: 10px;"             // Rounded corners
        "    padding: 15px;"                   // Padding inside the widget
        "    margin-bottom: 15px;"             // Space between widgets
        "    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1);" // Subtle shadow for elevation
        "}"
    );

    // Product name
    QLabel *nameLabel = new QLabel(QString::fromStdString(product.getName()), productWidget);
    nameLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #333333;");

    // Product price in L.E
    QLabel *priceLabel = new QLabel(QString::number(product.getPrice()) + " L.E", productWidget);
    priceLabel->setStyleSheet("font-size: 16px; color: #4CAF50; font-weight: bold;");

    // Horizontal layout for action buttons
    QHBoxLayout *buttonLayout = new QHBoxLayout();

    // Add to Cart button
    QPushButton *addToCartButton = new QPushButton("+", productWidget);
    addToCartButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #3E64FF;"        // Button background color
        "    color: white;"                     // Text color
        "    padding: 10px 15px;"               // Padding for the button
        "    border-radius: 5px;"               // Rounded corners
        "    font-size: 14px;"                  // Text size
        "    font-family: Arial, sans-serif;"   // Font family
        "    box-shadow: 0px 3px 6px rgba(0, 0, 0, 0.2);" // Subtle shadow
        "}"
        "QPushButton:hover {"
        "    background-color: #2A4FB0;"        // Darker blue when hovered
        "    box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.3);" // Glow effect on hover
        "}"
        "QPushButton:pressed {"
        "    background-color: #1A3C8C;"        // Even darker blue when pressed
        "    transform: scale(0.97);"           // Slightly shrink on press
        "}"
    );
    connect(addToCartButton, &QPushButton::clicked, [this, product, addToCartButton]() {
        AddToShoppingCart(product);
    });

    // Remove from Cart button
    QPushButton *removeFromCartButton = new QPushButton("-", productWidget);
    removeFromCartButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #FF6347;"        // Red background for remove button
        "    color: white;"                     // White text color
        "    padding: 10px 15px;"               // Padding
        "    border-radius: 5px;"               // Rounded corners
        "    font-size: 14px;"                  // Text size
        "    font-family: Arial, sans-serif;"   // Font family
        "}"
        "QPushButton:hover {"
        "    background-color: #E5533A;"        // Darker red when hovered
        "}"
        "QPushButton:pressed {"
        "    background-color: #D12A1F;"        // Even darker red when pressed
        "    transform: scale(0.97);"           // Shrink on press
        "}"
    );
        connect(removeFromCartButton, &QPushButton::clicked, [this, product]() {
        RemoveFromShoppingCart(product);});

    // Delete from Cart button
    QPushButton *deleteFromCartButton = new QPushButton(productWidget);
        deleteFromCartButton->setIcon(QIcon("D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/Trash.png"));
        deleteFromCartButton->setIconSize(QSize(20,20));
    deleteFromCartButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #FF4500;"        // Orange-red background
        "    color: white;"                     // White text color
        "    padding: 10px 15px;"               // Padding
        "    border-radius: 5px;"               // Rounded corners
        "    font-size: 14px;"                  // Text size
        "    font-family: Arial, sans-serif;"   // Font family
        "}"
        "QPushButton:hover {"
        "    background-color: #CC3700;"        // Darker orange-red when hovered
        "}"
        "QPushButton:pressed {"
        "    background-color: #AA2900;"        // Even darker orange-red when pressed
        "    transform: scale(0.97);"           // Shrink on press
        "}"
    );
    connect(deleteFromCartButton, &QPushButton::clicked, [this, product]() {
        DeleteFromShoppingCart(product);
    });

    // Add buttons to the button layout
    buttonLayout->addWidget(addToCartButton);
    buttonLayout->addWidget(removeFromCartButton);
    buttonLayout->addWidget(deleteFromCartButton);

    // Add widgets to product layout
    layout->addWidget(nameLabel);
    layout->addStretch(); // Add stretch for spacing
    layout->addWidget(priceLabel);
    layout->addLayout(buttonLayout); // Add the button layout to the main layout

    productWidget->setLayout(layout);
    productLayout->addWidget(productWidget);
}

    // Set the product container layout
    productContainer->setLayout(productLayout);
    productsScrollArea->setWidget(productContainer);
    productsScrollArea->setWidgetResizable(true);
    productsScrollArea->setGeometry(100, 350, 900, 400);

    // Style the scroll area
    productsScrollArea->setStyleSheet(
        "QScrollArea {"
        "    border: 1px solid #DCDCDC;"          // Light grey border
        "    border-radius: 8px;"                // Rounded corners
        "    background-color: #FFFFFF;"         // White background for scroll area
        "}"
        "QScrollBar:vertical {"
        "    background: #E0E0E0;"               // Light grey scrollbar background
        "    width: 10px;"                       // Narrow scrollbar width
        "    border-radius: 5px;"                // Rounded scrollbar
        "}"
        "QScrollBar::handle:vertical {"
        "    background: #3E64FF;"               // Blue scrollbar handle
        "    border-radius: 5px;"                // Rounded handle
        "}"
        "QScrollBar::handle:vertical:hover {"
        "    background: #2A4FB0;"               // Darker blue on hover
        "}"
    );
    productsScrollArea->show();
    // Create the main cart widget
    cartWidget = new QWidget(this);
    cartWidget->setGeometry(850, 10, 150, 80); // Adjust size and position
    cartWidget->setStyleSheet(
        "QWidget {"
        "    background-color: #FFFFFF;"
        "    border: 1px solid #CCCCCC;"
        "    border-radius: 10px;"
        "    padding: 5px;"
        "    box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.1);"
        "}"
    );

    // Create the cart button
    Cart = new QPushButton(cartWidget);
    QIcon SCIcon("D:\\PBLB\\UNI\\Data Stucts\\SuperMarket\\SM-GUI\\data\\Shopping Cart.png");
    Cart->setIcon(SCIcon);
    Cart->setGeometry(10, 10, 60, 60); // Position inside the widget
    Cart->setIconSize(QSize(40, 40));
    Cart->setStyleSheet("border: none;");
    connect(Cart,&QPushButton::clicked,this,ViewCart);

    // Create the quantity label
    itemsQuantityLabel = new QLabel("0", cartWidget);
    itemsQuantityLabel->setGeometry(80, 10, 60, 60); // Position inside the widget
    itemsQuantityLabel->setStyleSheet(
        "font-size: 18px;"
        "font-weight: bold;"
        "color: #3E64FF;"
        "text-align: center;"
    );
    itemsQuantityLabel->setAlignment(Qt::AlignCenter);
    cartWidget->show();


}
void GuiClass::AddToShoppingCart(const Product &product)
{
    // Update the cart with the new product
    store.addToCart(product);

    // Calculate total item quantity in the cart
    int itemsQuantity = 0;
    auto headofItems = store.getShoppingCart()->getItems()->getHead();
    while (headofItems)
    {
        itemsQuantity += headofItems->quantity;
        headofItems = headofItems->next;
    }

    // Update the quantity label
    itemsQuantityLabel->setText(QString::number(itemsQuantity));

}
void GuiClass::RemoveFromShoppingCart(const Product &product)
{
    if (!store.getShoppingCart()->getItems()->search(product)) return;
    store.removeFromCart(product);
    // Calculate total item quantity in the cart
    int itemsQuantity = 0;
    auto headofItems = store.getShoppingCart()->getItems()->getHead();
    while (headofItems)
    {
        itemsQuantity += headofItems->quantity;
        headofItems = headofItems->next;
    }

    // Update the quantity label
    itemsQuantityLabel->setText(QString::number(itemsQuantity));
}
void GuiClass::DeleteFromShoppingCart(const Product &product)
{
    if (!store.getShoppingCart()->getItems()->isEmpty() && store.getShoppingCart()->getItems()->search(product))
    {
        auto h = store.getShoppingCart()->getItems()->getHead();
        while (h->data != product) h = h->next;
        store.getShoppingCart()->setPrice(store.getShoppingCart()->getPrice()-(h->quantity * product.getPrice()));
        store.getShoppingCart()->getItems()->RemoveItem(product);
        int itemsQuantity = 0;
        auto headofItems = store.getShoppingCart()->getItems()->getHead();
        while (headofItems)
        {
            itemsQuantity += headofItems->quantity;
            headofItems = headofItems->next;
        }

        // Update the quantity label
        itemsQuantityLabel->setText(QString::number(itemsQuantity));
    }
}
void GuiClass::ViewCart()
{
    connect(Return,&QPushButton::clicked,this,DisplaySuperMarket);
    ClearDynamicWidgets();
     // Create a new scroll area for displaying products
    productsScrollArea = new QScrollArea(this);
    productContainer = new QWidget(productsScrollArea);
    QVBoxLayout *productLayout = new QVBoxLayout(productContainer);

    // Style the product container
    productContainer->setStyleSheet(
        "QWidget {"
        "    background-color: #FAFAFA;"       // Light background for the entire container
        "    padding: 10px;"                   // Padding around the content
        "}"
    );

    // Fetch products from the category
    auto hp = store.getShoppingCart()->getItems()->getHead();
    while (hp)
    {
        // Create a widget for each product
        QWidget *productWidget = new QWidget(productContainer);
        QHBoxLayout *layout = new QHBoxLayout(productWidget);

        // Style the product widget container
        productWidget->setStyleSheet(
            "QWidget {"
            "    background-color: #FFFFFF;"       // White background for product widget
            "    border: 1px solid #E0E0E0;"       // Light grey border
            "    border-radius: 10px;"             // Rounded corners
            "    padding: 15px;"                   // Padding inside the widget
            "    margin-bottom: 15px;"             // Space between widgets
            "    box-shadow: 0px 4px 6px rgba(0, 0, 0, 0.1);" // Subtle shadow for elevation
            "}"
        );

        // Product name
        QLabel *nameLabel = new QLabel(QString::fromStdString(hp->data.getName()), productWidget);
        nameLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #333333;");

        // Product price in L.E
        QLabel *quantityLabel = new QLabel(QString::number(hp->quantity), productWidget);
        quantityLabel->setStyleSheet("font-size: 16px; color: #4CAF50; font-weight: bold;");

        // Horizontal layout for action buttons
        QHBoxLayout *buttonLayout = new QHBoxLayout();

        // Add to Cart button
        QPushButton *addToCartButton = new QPushButton("+", productWidget);
        addToCartButton->setStyleSheet(
            "QPushButton {"
            "    background-color: #3E64FF;"        // Button background color
            "    color: white;"                     // Text color
            "    padding: 10px 15px;"               // Padding for the button
            "    border-radius: 5px;"               // Rounded corners
            "    font-size: 14px;"                  // Text size
            "    font-family: Arial, sans-serif;"   // Font family
            "    box-shadow: 0px 3px 6px rgba(0, 0, 0, 0.2);" // Subtle shadow
            "}"
            "QPushButton:hover {"
            "    background-color: #2A4FB0;"        // Darker blue when hovered
            "    box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.3);" // Glow effect on hover
            "}"
            "QPushButton:pressed {"
            "    background-color: #1A3C8C;"        // Even darker blue when pressed
            "    transform: scale(0.97);"           // Slightly shrink on press
            "}"
        );
        connect(addToCartButton, &QPushButton::clicked, [this,quantityLabel,product = hp->data]()
            {
            Add(quantityLabel,product);
        });

        // Remove from Cart button
        QPushButton *removeFromCartButton = new QPushButton("-", productWidget);
        removeFromCartButton->setStyleSheet(
            "QPushButton {"
            "    background-color: #FF6347;"        // Red background for remove button
            "    color: white;"                     // White text color
            "    padding: 10px 15px;"               // Padding
            "    border-radius: 5px;"               // Rounded corners
            "    font-size: 14px;"                  // Text size
            "    font-family: Arial, sans-serif;"   // Font family
            "}"
            "QPushButton:hover {"
            "    background-color: #E5533A;"        // Darker red when hovered
            "}"
            "QPushButton:pressed {"
            "    background-color: #D12A1F;"        // Even darker red when pressed
            "    transform: scale(0.97);"           // Shrink on press
            "}"
        );
            connect(removeFromCartButton, &QPushButton::clicked, [this, quantityLabel,product = hp->data]() {
            Remove(quantityLabel,product);});

        // Delete from Cart button
        QPushButton *deleteFromCartButton = new QPushButton(productWidget);
            deleteFromCartButton->setIcon(QIcon("D:/PBLB/UNI/Data Stucts/SuperMarket/SM-GUI/data/Trash.png"));
            deleteFromCartButton->setIconSize(QSize(20,20));
        deleteFromCartButton->setStyleSheet(
            "QPushButton {"
            "    background-color: #FF4500;"        // Orange-red background
            "    color: white;"                     // White text color
            "    padding: 10px 15px;"               // Padding
            "    border-radius: 5px;"               // Rounded corners
            "    font-size: 14px;"                  // Text size
            "    font-family: Arial, sans-serif;"   // Font family
            "}"
            "QPushButton:hover {"
            "    background-color: #CC3700;"        // Darker orange-red when hovered
            "}"
            "QPushButton:pressed {"
            "    background-color: #AA2900;"        // Even darker orange-red when pressed
            "    transform: scale(0.97);"           // Shrink on press
            "}"
        );
        connect(deleteFromCartButton, &QPushButton::clicked, [this,product = hp->data]() {
            Delete(product);
        });

        // Add buttons to the button layout
        buttonLayout->addWidget(addToCartButton);
        buttonLayout->addWidget(removeFromCartButton);
        buttonLayout->addWidget(deleteFromCartButton);

        // Add widgets to product layout
        layout->addWidget(nameLabel);
        layout->addStretch(); // Add stretch for spacing
        layout->addWidget(quantityLabel);
        layout->addLayout(buttonLayout); // Add the button layout to the main layout

        productWidget->setLayout(layout);
        productLayout->addWidget(productWidget);
        hp = hp->next;
    }

    // Set the product container layout
    productContainer->setLayout(productLayout);
    productsScrollArea->setWidget(productContainer);
    productsScrollArea->setWidgetResizable(true);
    productsScrollArea->setGeometry(100, 100, 900, 400);

    // Style the scroll area
    productsScrollArea->setStyleSheet(
        "QScrollArea {"
        "    border: 1px solid #DCDCDC;"          // Light grey border
        "    border-radius: 8px;"                // Rounded corners
        "    background-color: #FFFFFF;"         // White background for scroll area
        "}"
        "QScrollBar:vertical {"
        "    background: #E0E0E0;"               // Light grey scrollbar background
        "    width: 10px;"                       // Narrow scrollbar width
        "    border-radius: 5px;"                // Rounded scrollbar
        "}"
        "QScrollBar::handle:vertical {"
        "    background: #3E64FF;"               // Blue scrollbar handle
        "    border-radius: 5px;"                // Rounded handle
        "}"
        "QScrollBar::handle:vertical:hover {"
        "    background: #2A4FB0;"               // Darker blue on hover
        "}"
    );
    productsScrollArea->show();
    ViewSummary();
}
void GuiClass::Add(QLabel *ql,const Product &p)
{
    store.addToCart(p);
    auto hp = store.getShoppingCart()->getItems()->getHead();
    while (hp->data != p) hp = hp->next;
    ql->setText(QString::number(hp->quantity));
    ViewSummary();
}
void GuiClass::Remove(QLabel *ql,const Product &p)
{
    auto hp = store.getShoppingCart()->getItems()->getHead();
    while (hp->data != p) hp = hp->next;
    store.removeFromCart(p);
    ql->setText(QString::number(hp->quantity));
    if (hp->quantity-1 == 0)
    {
        ClearDynamicWidgets();
        ViewCart();
    }
    ViewSummary();
}
void GuiClass::Delete(const Product &p)
{
    if (!store.getShoppingCart()->getItems()->isEmpty())
    {
        auto h = store.getShoppingCart()->getItems()->getHead();
        while (h->data != p && h != nullptr) h = h->next;
        store.getShoppingCart()->setPrice(store.getShoppingCart()->getPrice()-(h->quantity * p.getPrice()));
        store.getShoppingCart()->getItems()->RemoveItem(p);
        ClearDynamicWidgets();
        ViewCart();
        ViewSummary();
    }
}
void GuiClass::DisplayOrders()
{
    connect(Return,QPushButton::clicked,this,DisplayAdmin);
    store.getOrders()->loadPendingOrders();
    ClearDynamicWidgets();
    // Create a scroll area for displaying the order summary
    PreviousOrders = new QPushButton(this);
    PreviousOrders->setGeometry(100, 32, 200,50);
    PreviousOrders->setText("Previous Orders");
    PreviousOrders->setStyleSheet("font-size: 16px;"             // Increased font size
                      "font-family: 'Courier New', monospace;" // Changed to a different font
                      "font-weight: bold;"          // Made the text bold
                      "border-radius: 5px;"         // Rounded corners
                      "color: white;"               // Button text color
                      "background-color: #00bf63;"  // Light orange background
                      "padding: 10px;");            // Padding for better appearance

    PreviousOrders->show();
    connect(PreviousOrders,&QPushButton::clicked,this,PreviousOrdersView);
    QScrollArea *orderScrollArea = new QScrollArea(this);
    QWidget *orderContainer = new QWidget(orderScrollArea);
    QVBoxLayout *orderLayout = new QVBoxLayout(orderContainer);

    // Style the order container
    orderContainer->setStyleSheet(
        "QWidget {"
        "    background-color: #FAFAFA;"       // Light background for the entire container
        "    padding: 10px;"                   // Padding around the content
        "}");

    // User email label
    for (const auto order : store.getPendingQueue())
    {
        QLabel *emailLabel = new QLabel("User Email: " + QString::fromStdString(order->getBuyer()), orderContainer);
        emailLabel->setStyleSheet(
            "QLabel {"
            "    font-size: 18px;"
            "    font-weight: bold;"
            "    color: #333333;"
            "    margin-bottom: 10px;"
            "}");

        // Total price label
        QLabel *priceLabel = new QLabel("Total Price: " + QString::number(order->getCart()->getPrice()) + " L.E", orderContainer);
        priceLabel->setStyleSheet(
            "QLabel {"
            "    font-size: 16px;"
            "    color: #4CAF50;"
            "    font-weight: bold;"
            "    margin-bottom: 20px;"
            "}");

        // Process button
        QPushButton *processButton = new QPushButton("Process", orderContainer);
        processButton->setStyleSheet(
            "QPushButton {"
            "    background-color: #4CAF50;"       // Green background
            "    color: white;"                    // White text color
            "    padding: 10px 20px;"              // Padding for the button
            "    border-radius: 5px;"              // Rounded corners
            "    font-size: 16px;"                 // Larger font size
            "    font-family: Arial, sans-serif;"  // Font family
            "    box-shadow: 0px 3px 6px rgba(0, 0, 0, 0.2);" // Subtle shadow
            "}"
            "QPushButton:hover {"
            "    background-color: #45a049;"       // Slightly darker green on hover
            "}"
            "QPushButton:pressed {"
            "    background-color: #388e3c;"       // Darker green on press
            "    transform: scale(0.97);"          // Slightly shrink on press
            "}");

        // Connect the Process button to a slot or lambda function
        QObject::connect(processButton, &QPushButton::clicked,this,ProcessTheOrder);

        // Add widgets to the order layout
        orderLayout->addWidget(emailLabel);
        orderLayout->addWidget(priceLabel);
        orderLayout->addWidget(processButton);

        // Set layout and style for the order container
        orderContainer->setLayout(orderLayout);
    }
    // Set the scroll area properties
    orderScrollArea->setWidget(orderContainer);
    orderScrollArea->setWidgetResizable(true);
    orderScrollArea->setGeometry(100, 130, 900, 500); // Increased size for better usability

    // Style the scroll area and scrollbar
    orderScrollArea->setStyleSheet(
        "QScrollArea {"
        "    border: 2px solid #DCDCDC;"       // Slightly darker border
        "    border-radius: 10px;"             // Rounded corners for the scroll area
        "    background-color: #FFFFFF;"       // White background
        "}"
        "QScrollBar:vertical {"
        "    background: #E0E0E0;"             // Light grey background
        "    width: 12px;"                     // Wider scrollbar for better interaction
        "    border-radius: 6px;"              // Rounded edges
        "}"
        "QScrollBar::handle:vertical {"
        "    background: #4CAF50;"             // Green scrollbar handle
        "    border-radius: 6px;"              // Rounded handle
        "}"
        "QScrollBar::handle:vertical:hover {"
        "    background: #45a049;"             // Darker green on hover
        "}"
        "QScrollBar::handle:vertical:pressed {"
        "    background: #388e3c;"             // Dark green on press
        "}"
        "QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {"
        "    background: none;"                // No up/down buttons for cleaner design
        "}");
    // Show the scroll area
    orderScrollArea->show();
}
void GuiClass::ProcessTheOrder()
{
    if (!store.checkOrderValidity())
    {
        while (!store.getOrders()->getPending()->empty()) store.getOrders()->getPending()->pop();
        QMessageBox stockErrorBox(nullptr);
        stockErrorBox.setWindowTitle("Order Error");
        stockErrorBox.setText("Cannot process order. Please check stock.");
        stockErrorBox.setIcon(QMessageBox::Warning);
        stockErrorBox.setStandardButtons(QMessageBox::Ok);

        stockErrorBox.exec();
    }
    ClearDynamicWidgets();
    store.getOrders()->loadPendingOrders();
    DisplayOrders();

}
void GuiClass::PreviousOrdersView()
{
    connect(Return, QPushButton::clicked, this, DisplayOrders);
ClearDynamicWidgets();

// Create the scroll area
QScrollArea* scrollArea = new QScrollArea(this);
QWidget* scrollWidget = new QWidget();
QVBoxLayout* orderLayout = new QVBoxLayout(scrollWidget);

// Style the scroll area
scrollArea->setStyleSheet(
    "QScrollArea {"
    "    border: 1px solid #DCDCDC;"
    "    border-radius: 8px;"
    "    background-color: #F9F9F9;"
    "}"
    "QScrollBar:vertical {"
    "    background: #E0E0E0;"
    "    width: 12px;"
    "    border-radius: 6px;"
    "}"
    "QScrollBar::handle:vertical {"
    "    background: #3E64FF;"
    "    border-radius: 6px;"
    "}"
    "QScrollBar::handle:vertical:hover {"
    "    background: #2A4FB0;"
    "}"
);

// Fetch orders
auto orders = *(store.getOrders()->getProcessed());

// Iterate through orders
for (const auto& order : orders) {
    QWidget* orderWidget = new QWidget();
    QHBoxLayout* orderContentLayout = new QHBoxLayout(orderWidget);

    // Style the order widget
    orderWidget->setStyleSheet(
        "QWidget {"
        "    background-color: #FFFFFF;"
        "    border: 1px solid #E0E0E0;"
        "    border-radius: 10px;"
        "    padding: 10px;"
        "    margin-bottom: 10px;"
        "}"
    );

    // Buyer label
    QLabel* buyerLabel = new QLabel("Buyer: " + QString::fromStdString(order->getBuyer()));
    buyerLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333333;");

    // Price label
    QLabel* priceLabel = new QLabel("Price: " + QString::number(order->getCart()->getPrice()) + " L.E");
    priceLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #4CAF50;");

    // More button
    QPushButton* moreButton = new QPushButton("More");
    moreButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #3E64FF;"
        "    color: white;"
        "    padding: 8px 15px;"
        "    border-radius: 5px;"
        "    font-size: 14px;"
        "    font-family: Arial, sans-serif;"
        "}"
        "QPushButton:hover {"
        "    background-color: #2A4FB0;"
        "}"
        "QPushButton:pressed {"
        "    background-color: #1A3C8C;"
        "    transform: scale(0.98);"
        "}"
    );

    // Connect the "More" button
    QObject::connect(moreButton, &QPushButton::clicked, [this, order]() {
    // Create and show a dialog with all the items bought in this order
    QWidget* detailsWindow = new QWidget();
    QVBoxLayout* detailsLayout = new QVBoxLayout(detailsWindow);

    // Buyer label
    QLabel* buyerLabel = new QLabel("Buyer: " + QString::fromStdString(order->getBuyer()));
    buyerLabel->setStyleSheet("font-size: 18px; font-weight: bold; color: #333333;");
    detailsLayout->addWidget(buyerLabel);

    // Price label
    QLabel* priceLabel = new QLabel("Total Price: " + QString::number(order->getCart()->getPrice()) + " L.E");
    priceLabel->setStyleSheet("font-size: 16px; color: #4CAF50;");
    detailsLayout->addWidget(priceLabel);

    // Items label
    QLabel* itemsLabel = new QLabel("Items Bought:");
    itemsLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #555555;");
    detailsLayout->addWidget(itemsLabel);

    // List items
    Node<Product>* itemNode = order->getCart()->getItems()->getHead();
    while (itemNode != nullptr) {
        QLabel* itemLabel = new QLabel(
            QString::fromStdString(itemNode->data.getName()) + " - " +
            QString::fromStdString(itemNode->data.getCode()) + " x " +
            QString::number(itemNode->quantity) + " @ " +
            QString::number(itemNode->data.getPrice()) + " L.E"
        );
        itemLabel->setStyleSheet("font-size: 14px; color: #333333;");
        detailsLayout->addWidget(itemLabel);
        itemNode = itemNode->next;
    }

    // Finalize details window
    detailsWindow->setLayout(detailsLayout);
    detailsWindow->setWindowTitle("Order Details");
    detailsWindow->resize(400, 300);
    detailsWindow->show();
});

    // Add components to the order layout
    orderContentLayout->addWidget(buyerLabel);
    orderContentLayout->addStretch();
    orderContentLayout->addWidget(priceLabel);
    orderContentLayout->addWidget(moreButton);

    // Set the layout for the order widget and add to scroll area
    orderWidget->setLayout(orderContentLayout);
    orderLayout->addWidget(orderWidget);
}

// Finalize the scroll area
scrollWidget->setLayout(orderLayout);
scrollArea->setWidget(scrollWidget);
scrollArea->setWidgetResizable(true);
scrollArea->setGeometry(100,50,900, 500);
scrollArea->show();

}
void GuiClass::UserData()
{
    connect(Return,QPushButton::clicked,this,DisplaySuperMarket);
    // Clear previous dynamic widgets
    ClearDynamicWidgets();

    // Main container and layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Helper to create partitions with individual scroll areas
    auto createScrollPartition = [](QWidget* content, const QString& title, const QString& color) -> QWidget* {
        QWidget* partition = new QWidget();
        QVBoxLayout* partitionLayout = new QVBoxLayout(partition);

        QLabel* partitionTitle = new QLabel(title);
        partitionTitle->setStyleSheet("font-size: 20px; font-weight: bold; color: " + color + ";");
        partitionLayout->addWidget(partitionTitle);

        QScrollArea* scrollArea = new QScrollArea();
        scrollArea->setWidget(content);
        scrollArea->setWidgetResizable(true);
        scrollArea->setStyleSheet("border: 1px solid #CCCCCC; background-color: #F9F9F9;");

        partitionLayout->addWidget(scrollArea);
        partition->setLayout(partitionLayout);

        partition->setStyleSheet("border: 2px solid #DDDDDD; border-radius: 10px; margin: 5px; padding: 10px; background-color: #FFFFFF;");
        return partition;
    };

    // *** Frequently Purchased Items ***
    QWidget* frequentlyPurchasedWidget = new QWidget();
    QVBoxLayout* frequentlyPurchasedLayout = new QVBoxLayout(frequentlyPurchasedWidget);

    for (const auto& item : store.getUser()->frequentlyPurchased()) {
        QLabel* itemLabel = new QLabel(QString::fromStdString(item));
        itemLabel->setStyleSheet("font-size: 14px; color: #555555;");
        frequentlyPurchasedLayout->addWidget(itemLabel);
    }
    frequentlyPurchasedWidget->setLayout(frequentlyPurchasedLayout);

    QWidget* frequentlyPurchasedPartition = createScrollPartition(frequentlyPurchasedWidget, "Frequently Purchased Items", "#333333");
    mainLayout->addWidget(frequentlyPurchasedPartition);

    // Processed and Unprocessed Orders Side by Side
    QHBoxLayout* ordersLayout = new QHBoxLayout();

    // *** Processed Orders ***
    QWidget* processedOrdersWidget = new QWidget();
    QVBoxLayout* processedOrdersLayout = new QVBoxLayout(processedOrdersWidget);

    auto orders = store.getUserHistory();
    for (const auto& [order, isProcessed] : orders) {
        if (isProcessed) {
            QWidget* orderWidget = CreateOrderWidget(order);
            processedOrdersLayout->addWidget(orderWidget);
        }
    }
    processedOrdersWidget->setLayout(processedOrdersLayout);

    QWidget* processedOrdersPartition = createScrollPartition(processedOrdersWidget, "Processed Orders", "#4CAF50");
    ordersLayout->addWidget(processedOrdersPartition);

    // *** Unprocessed Orders ***
    QWidget* unprocessedOrdersWidget = new QWidget();
    QVBoxLayout* unprocessedOrdersLayout = new QVBoxLayout(unprocessedOrdersWidget);

    for (const auto& [order, isProcessed] : orders) {
        if (!isProcessed) {
            QWidget* orderWidget = CreateOrderWidget(order);
            unprocessedOrdersLayout->addWidget(orderWidget);
        }
    }
    unprocessedOrdersWidget->setLayout(unprocessedOrdersLayout);

    QWidget* unprocessedOrdersPartition = createScrollPartition(unprocessedOrdersWidget, "Unprocessed Orders", "#FF6347");
    ordersLayout->addWidget(unprocessedOrdersPartition);

    // Add orders layout to main layout
    mainLayout->addLayout(ordersLayout);

    // Set the main layout for the window
    QWidget* containerWidget = new QWidget(this);
    containerWidget->setLayout(mainLayout);
    containerWidget->setGeometry(100, 50, 800, 600);
    containerWidget->show();
}

QWidget* GuiClass::CreateOrderWidget(Order* order)
{
    QWidget* orderWidget = new QWidget(this);
    QVBoxLayout* layout = new QVBoxLayout(orderWidget);

    QLabel* buyerLabel = new QLabel("Buyer: " + QString::fromStdString(order->getBuyer()));
    buyerLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #333333;");
    layout->addWidget(buyerLabel);

    QLabel* priceLabel = new QLabel("Price: " + QString::number(order->getCart()->getPrice()) + " L.E");
    priceLabel->setStyleSheet("font-size: 14px; color: #4CAF50;");
    layout->addWidget(priceLabel);

    QLabel* itemsLabel = new QLabel("Items:");
    itemsLabel->setStyleSheet("font-size: 14px; font-weight: bold; color: #555555;");
    layout->addWidget(itemsLabel);

    Node<Product>* itemNode = order->getCart()->getItems()->getHead();
    while (itemNode != nullptr) {
        QLabel* itemLabel = new QLabel(QString::fromStdString(itemNode->data.getName()) + " - " +
                                        QString::fromStdString(itemNode->data.getCode()) + " x " +
                                        QString::number(itemNode->quantity) + " @ " +
                                        QString::number(itemNode->data.getPrice()) + " L.E");
        itemLabel->setStyleSheet("font-size: 12px; color: #333333;");
        layout->addWidget(itemLabel);
        itemNode = itemNode->next;
    }

    orderWidget->setLayout(layout);
    return orderWidget;
}

void GuiClass::ClearDynamicWidgets()
{
    for (QWidget* child : this->findChildren<QWidget*>())
    {
        if (child != Return)
        {
            child->hide();    // Hide the widget
            child = nullptr;     // Delete the widget
        }
    }
}
void GuiClass::GoToCheckout()
{
    ClearDynamicWidgets();
    int width = 200;
    int height = 30;
    int x = (this->width() - width) / 2;
    int y = (this->height() - height) / 2;
    QString styleSheet =
    "QLineEdit {"
    "    background-color: #ffffff;"   // Pure white background for a clean look
    "    color: #333333;"              // Dark grey text for better readability
    "    border: 1px solid #dcdcdc;"   // Subtle grey border for a softer look
    "    border-radius: 8px;"          // Slightly more rounded corners
    "    padding: 8px;"                // Increased padding for spaciousness
    "    font-size: 14px;"             // Larger font for better visibility
    "    font-family: Arial, sans-serif;" // Clean and professional font
    "    box-shadow: 0px 2px 4px rgba(0, 0, 0, 0.1);" // Subtle shadow for depth
    "}"
    "QLineEdit:focus {"
    "    border: 1px solid #3E64FF;"   // Highlighted blue border on focus
    "    box-shadow: 0px 0px 6px rgba(62, 100, 255, 0.5);" // Glow effect on focus
    "}";

    QString comboBoxStyleSheet =
    "QComboBox {"
    "    background-color: #ffffff;"            // White background for the combo box
    "    color: #333333;"                       // Dark grey text for better readability
    "    border: 1px solid #dcdcdc;"            // Light grey border
    "    border-radius: 8px;"                   // Rounded corners
    "    padding: 8px;"                         // Padding for spacing
    "    font-size: 14px;"                      // Font size for better legibility
    "    font-family: Arial, sans-serif;"       // Clean and modern font
    "    min-width: 180px;"                     // Minimum width for the combo box
    "}"
    "QComboBox::drop-down {"
    "    border-left: 1px solid #dcdcdc;"       // Subtle border for the dropdown
    "    width: 25px;"                          // Width of the drop-down button
    "}"
    "QComboBox QAbstractItemView {"
    "    background-color: #ffffff;"            // White background for dropdown list
    "    color: #333333;"                       // Dark grey text for the dropdown items
    "    border: 1px solid #dcdcdc;"            // Light border around the dropdown
    "    border-radius: 8px;"                   // Rounded corners for the dropdown
    "    selection-background-color: #3E64FF;" // Blue highlight for selected item
    "    selection-color: #ffffff;"             // White text for the selected item
    "}"
    "QComboBox:focus {"
    "    border: 1px solid #3E64FF;"            // Blue border when focused
    "    box-shadow: 0px 0px 6px rgba(62, 100, 255, 0.5);" // Glow effect on focus
    "}";

    QString pushButtonStyleSheet =
    "QPushButton {"
    "    background-color: #4CAF50;"            // Green background for the button
    "    color: white;"                          // White text color
    "    border: 1px solid #4CAF50;"            // Border matching the button color
    "    border-radius: 8px;"                   // Rounded corners
    "    padding: 10px 20px;"                   // Adequate padding for the button
    "    font-size: 14px;"                      // Font size for better readability
    "    font-family: Arial, sans-serif;"       // Clean font
    "    text-align: center;"                   // Center align the text
    "    cursor: pointer;"                     // Pointer cursor on hover
    "    box-shadow: 0px 2px 4px rgba(0, 0, 0, 0.1);" // Subtle shadow for depth
    "}"
    "QPushButton:hover {"
    "    background-color: #45a049;"            // Darker green on hover
    "    box-shadow: 0px 4px 8px rgba(0, 0, 0, 0.3);" // Slightly stronger shadow on hover
    "}"
    "QPushButton:pressed {"
    "    background-color: #388e3c;"            // Even darker green on press
    "    transform: scale(0.98);"                // Slight shrink effect on press
    "    box-shadow: none;"                      // Remove shadow when pressed
    "}"
    "QPushButton:disabled {"
    "    background-color: #cccccc;"            // Light grey when disabled
    "    color: #888888;"                       // Grey text for disabled state
    "    border: 1px solid #cccccc;"            // Grey border when disabled
    "}";

    QLineEdit *Namebar = new QLineEdit(this);
    //QLineEdit *PEmail = new QLineEdit(this);
    QLineEdit *CardNumber = new QLineEdit(this);
    QLineEdit *CardHolder = new QLineEdit(this);
    QComboBox *Month = new QComboBox(this);
    QComboBox *Year = new QComboBox(this);
    QPushButton *Payment = new QPushButton("Confrim Payment",this);

    for (int i = 1; i <= 12; ++i) { Month->addItem(QString("%1").arg(i, 2, 10, QChar('0')));}
    for (int i = 2024; i <= 2032; ++i) {Year->addItem(QString::number(i));}

    Namebar->show();
    CardNumber->show();
    CardHolder->show();
    Month->show();
    Year->show();
    Payment->show();

    Namebar->setPlaceholderText("Name: ");
    CardNumber->setPlaceholderText("Card Number: ");
    CardHolder->setPlaceholderText("Holder Name: ");

    Namebar->setStyleSheet(styleSheet);
    CardNumber->setStyleSheet(styleSheet);
    CardHolder->setStyleSheet(styleSheet);
    Month->setStyleSheet(comboBoxStyleSheet);
    Year->setStyleSheet(comboBoxStyleSheet);
    Payment->setStyleSheet(pushButtonStyleSheet);

    Namebar->setGeometry(x, y-210, width, height);
    CardNumber->setGeometry(x, y - 170, width, height);
    CardHolder->setGeometry(x, y - 130, width, height);
    Month->setGeometry(x, y-90, 50, 30);
    Year->setGeometry(x, y-50, 50, 30);
    Payment->setGeometry(x, y - 10, width, height+5);
    //Payment->setGeometry(x, y - 50, width, height);
    connect(Payment, &QPushButton::clicked, this, CheckOut);
    //connect(cancel, &QPushButton::clicked, this, &GUItesting::CancelReservation);
}
void GuiClass::ViewSummary()
{
    QWidget *summaryWidget = new QWidget(this);
    QHBoxLayout *summaryLayout = new QHBoxLayout(summaryWidget);

    // Quantities label
    int quantityI = 0;
    auto th = store.getShoppingCart()->getItems()->getHead();
    while (th)
    {
        quantityI+=th->quantity;
        th = th->next;
    }
    QLabel *quantitiesLabel = new QLabel(QString::number(quantityI), summaryWidget);
    quantitiesLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333333;");

    // Total price label
    int totalPrice = store.getShoppingCart()->getPrice();
    QLabel *totalPriceLabel = new QLabel("Total Price: " + QString::number(totalPrice) + " L.E", summaryWidget);
    totalPriceLabel->setStyleSheet("font-size: 16px; font-weight: bold; color: #333333;");

    // Check Out button
    QPushButton *checkOutButton = new QPushButton("Check Out", summaryWidget);
    checkOutButton->setStyleSheet(
        "QPushButton {"
        "    background-color: #4CAF50;"       // Green background for the button
        "    color: white;"                    // White text
        "    padding: 10px 20px;"              // Padding for the button
        "    border-radius: 8px;"              // Rounded corners
        "    font-size: 16px;"                 // Font size
        "    font-weight: bold;"               // Bold text
        "    font-family: Arial, sans-serif;"  // Font family
        "} "
        "QPushButton:hover {"
        "    background-color: #45A049;"       // Darker green on hover
        "} "
        "QPushButton:pressed {"
        "    background-color: #388E3C;"       // Even darker green on press
        "    transform: scale(0.97);"          // Slight shrink effect
        "}"
    );
    connect(checkOutButton, &QPushButton::clicked, this, GoToCheckout);
    summaryLayout->addWidget(quantitiesLabel);
    summaryLayout->addStretch(); // Add stretch to separate components
    summaryLayout->addWidget(totalPriceLabel);
    summaryLayout->addWidget(checkOutButton);

    // Style the summary widget
    summaryWidget->setLayout(summaryLayout);
    summaryWidget->setGeometry(100, 520, 900, 100); // Adjust position and size as needed
    summaryWidget->setStyleSheet(
        "QWidget {"
        "    background-color: #FAFAFA;"       // Light background for the widget
        "    border: 1px solid #DCDCDC;"       // Light grey border
        "    border-radius: 8px;"              // Rounded corners
        "    padding: 10px;"                   // Padding around the content
        "    margin-top: 10px;"                // Margin from the scroll area
        "}"
    );
    summaryWidget->show();
}
void GuiClass::CheckOut()
{
    store.checkout();
    store.getShoppingCart()->getItems()->clear();

    QMessageBox thankYouMessage;
    thankYouMessage.setWindowTitle("Order Confirmation");
    thankYouMessage.setText("Thank you for buying at Sh3b el Seny Mart.");
    thankYouMessage.setInformativeText("Your order is being processed.");
    thankYouMessage.setIcon(QMessageBox::Information);
    QPushButton *okButton = thankYouMessage.addButton("Proceed", QMessageBox::AcceptRole);

    thankYouMessage.setStyleSheet(
        "QMessageBox {"
        "    background-color: #f9f9f9;"      // Light grey background for the box
        "    color: #333333;"                 // Dark text color for readability
        "    font-size: 14px;"                // Font size for better readability
        "    font-family: Arial, sans-serif;" // Clean and modern font
        "}"
        "QPushButton {"
        "    background-color: #4CAF50;"      // Green background for the button
        "    color: white;"                   // White text on the button
        "    padding: 10px 15px;"             // Padding for better button size
        "    border-radius: 5px;"             // Rounded corners
        "    font-size: 14px;"
        "}"
        "QPushButton:hover {"
        "    background-color: #45a049;"      // Slightly darker green on hover
        "}"
        "QPushButton:pressed {"
        "    background-color: #388e3c;"      // Dark green on press
        "}"
    );
    thankYouMessage.exec();

    if (thankYouMessage.clickedButton() == okButton)
    {
        Return->hide();
        DisplayMainMenu();
    }

}