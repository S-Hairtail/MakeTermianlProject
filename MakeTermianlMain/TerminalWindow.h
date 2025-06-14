#ifndef TERMINALWINDOW_H
#define TERMINALWINDOW_H

#include <QMainWindow>

class QLineEdit;
class QPlainTextEdit;
class QProcess;

class TerminalWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit TerminalWindow(QWidget *parent = nullptr);

private slots:
    void executeCommand();
    void readProcessOutput();
    void readProcessError();

private:
    QPlainTextEdit *m_outputArea;
    QLineEdit *m_inputLine;
    QProcess *m_process;
};

#endif // TERMINALWINDOW_H
