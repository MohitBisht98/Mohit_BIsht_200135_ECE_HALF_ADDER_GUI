/*#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Set up input options
    ui->comboBoxA->addItems({"0", "1"});
    ui->comboBoxB->addItems({"0", "1"});

    // Connect signals to the slot
    connect(ui->comboBoxA, SIGNAL(currentIndexChanged(int)), this, SLOT(onInputChanged()));
    connect(ui->comboBoxB, SIGNAL(currentIndexChanged(int)), this, SLOT(onInputChanged()));

    // Initialize outputs
    updateOutputs();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onInputChanged()
{
    updateOutputs();
}

void MainWindow::updateOutputs()
{
    // Get the input values
    int a = ui->comboBoxA->currentText().toInt();
    int b = ui->comboBoxB->currentText().toInt();

    // Calculate sum and carry
    int sum = a ^ b; // XOR operation
    int carry = a & b; // AND operation

    // Update the labels
    ui->labelSum->setText(QString::number(sum));
    ui->labelCarry->setText(QString::number(carry));
}
