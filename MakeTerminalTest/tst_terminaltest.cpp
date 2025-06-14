#include <QCoreApplication>
#include <QtTest>

// add necessary includes here

class TerminalTest : public QObject
{
    Q_OBJECT

public:
    TerminalTest();
    ~TerminalTest();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_case1();
};

TerminalTest::TerminalTest() {}

TerminalTest::~TerminalTest() {}

void TerminalTest::initTestCase() {}

void TerminalTest::cleanupTestCase() {}

void TerminalTest::test_case1() {}

QTEST_MAIN(TerminalTest)

#include "tst_terminaltest.moc"
