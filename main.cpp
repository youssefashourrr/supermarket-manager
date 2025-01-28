#include "gui/GuiClass.h"
#include <QApplication>
#include <QString>

int main(int argc, char* argv[])
{
    QApplication app(argc, argv);

    QPalette lightPalette;
    lightPalette.setColor(QPalette::Window, QColor(255, 255, 255));  // White window background
    lightPalette.setColor(QPalette::WindowText, QColor(0, 0, 0));   // Black text
    lightPalette.setColor(QPalette::Base, QColor(255, 255, 255));   // White for input fields
    lightPalette.setColor(QPalette::AlternateBase, QColor(240, 240, 240)); // Slightly darker white for alternate backgrounds
    lightPalette.setColor(QPalette::ToolTipBase, QColor(255, 255, 220));  // Light yellow for tooltips
    lightPalette.setColor(QPalette::ToolTipText, QColor(0, 0, 0));  // Black text in tooltips
    lightPalette.setColor(QPalette::Text, QColor(0, 0, 0));         // Black text
    lightPalette.setColor(QPalette::Button, QColor(240, 240, 240)); // Light gray for buttons
    lightPalette.setColor(QPalette::ButtonText, QColor(0, 0, 0));   // Black text on buttons
    lightPalette.setColor(QPalette::BrightText, QColor(255, 0, 0)); // Bright red for errors
    lightPalette.setColor(QPalette::Highlight, QColor(76, 163, 224)); // Blue for selected text
    lightPalette.setColor(QPalette::HighlightedText, QColor(255, 255, 255)); // White text on selected background

    app.setPalette(lightPalette);


    GuiClass Mainwin;
    QString iconPath = "D:\\PBLB\\UNI\\Data Stucts\\SuperMarket\\SM-GUI\\data\\chinaflag.png";
    Mainwin.setWindowIcon(QIcon(iconPath));
    Mainwin.setFixedSize(1100, 800);
    Mainwin.setWindowTitle("Supermarket-Manager");
    Mainwin.setStyleSheet("background-color: #FFFFFF;");
    Mainwin.show();
    return app.exec();
}