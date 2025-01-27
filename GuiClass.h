#include <QMainWindow>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QIcon>
#include <QString>
#include <QFile>
#include <QDir>
#include <QTableWidget>
#include <QLineEdit>
#include <QScrollArea>
#include <QString>
#include <QComboBox>
#include <QMessageBox>
#include <QToolButton>
#include <QHBoxLayout>
#include <QListWidget>
#include "../supermarket-manager/headers/store.h"

class GuiClass : public QWidget
{
    Q_OBJECT // Enables signal-slot mechanism

public:
    explicit GuiClass(QWidget *parent = nullptr);
    void BuildTable();
    void SubmitProduct(string,string,float,int);
    void ClearDynamicWidgets();
    bool MakeUser();
    void DisplaySuperMarket();
    void DisplayScroll();
    void DisplayProducts(const string &categoryName);
    void ViewSummary();
    QWidget* CreateOrderWidget(Order* order);
    private slots:
        void DisplayMainMenu();// Slot for handling button clicks
        void DisplayAdmin();
        void DisplayUser();

        void AddCategoryWindow();
        void AddProductWindow();
        void RemoveCategoryWindow();
        void RemoveProductWindow();
        void SubmitRemoveProduct();
        void SubmitRemoveCategory();
        void SubmitCategory();
        void validateProduct();
        void VerifyLogin();
        void AddToShoppingCart(const Product &product);
        void RemoveFromShoppingCart(const Product &product);
        void DeleteFromShoppingCart(const Product &product);
        void ViewCart();
        void Add(QLabel* ql,const Product &p);
        void Remove(QLabel* ql,const Product &p);
        void Delete(const Product &p);
        void CheckOut();
        void GoToCheckout();
        void DisplayOrders();
        void ProcessTheOrder();
        void PreviousOrdersView();
        void UserData();

private:
    Store store;

    QMainWindow* AdditionalWin;

    QPushButton *user;
    QPushButton *admin;
    QPushButton *NewCategory;
    QPushButton *NewProduct;
    QPushButton *RemoveCategory;
    QPushButton *RemoveProduct;
    QPushButton *Submit;
    QPushButton *LogIn;
    QPushButton *SignUp;
    QPushButton *Return;
    QPushButton *ReturnUser;
    QPushButton *Cart;
    QPushButton *OrderDisplay;
    QPushButton *PreviousOrders;


    QTableWidget *ProductTable;

    QLabel *welcome;
    QLabel* AWlabel;
    QLabel* alertIconLabel;
    QLabel* itemsQuantityLabel;

    QLineEdit *AdditionalInput;
    QLineEdit *productPrice;
    QLineEdit *productQuantity;
    QLineEdit *Username;
    QLineEdit *Email;
    QLineEdit *Password;
    QLineEdit* SearchwithTrie;

    QComboBox* DDMCategories;
    QComboBox* DDMProduct;

    QList<QLabel*> alertLabels;

    QString UserName;

    QToolButton *toggleButton;
    QScrollArea *scrollArea;
    QScrollArea *productsScrollArea;

    QWidget *productContainer;
    QWidget *cartWidget;

    QListWidget *resultsList;
};
