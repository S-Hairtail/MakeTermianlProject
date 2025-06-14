#include "TerminalWindow.h"
#include <QLineEdit>
#include <QPlainTextEdit>
#include <QProcess>
#include <QVBoxLayout>
#include <QWidget>

TerminalWindow::TerminalWindow(QWidget *parent)
    : QMainWindow(parent),
      m_outputArea(new QPlainTextEdit(this)),
      m_inputLine(new QLineEdit(this)),
      m_process(new QProcess(this))
{
    QWidget *central = new QWidget(this);
    setCentralWidget(central);

    m_outputArea->setReadOnly(true);

    QVBoxLayout *layout = new QVBoxLayout(central);
    layout->addWidget(m_outputArea);
    layout->addWidget(m_inputLine);

    connect(m_inputLine, &QLineEdit::returnPressed,
            this, &TerminalWindow::executeCommand);
    connect(m_process, &QProcess::readyReadStandardOutput,
            this, &TerminalWindow::readProcessOutput);
    connect(m_process, &QProcess::readyReadStandardError,
            this, &TerminalWindow::readProcessError);
}

void TerminalWindow::executeCommand()
{
    QString cmd = m_inputLine->text();
    if (cmd.isEmpty())
        return;

    m_outputArea->appendPlainText("$ " + cmd);
    m_process->start("/bin/sh", {"-c", cmd});
    m_inputLine->clear();
}

void TerminalWindow::readProcessOutput()
{
    m_outputArea->appendPlainText(QString::fromLocal8Bit(m_process->readAllStandardOutput()));
}

void TerminalWindow::readProcessError()
{
    m_outputArea->appendPlainText(QString::fromLocal8Bit(m_process->readAllStandardError()));
}
