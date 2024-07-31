
#include <QtTest>
#include "src/helper/filehelper.h"

// add necessary includes here

class TestFileHelper : public QObject
{
    Q_OBJECT

public:
    TestFileHelper();
    ~TestFileHelper();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_readAllTxt();

};

TestFileHelper::TestFileHelper()
{

}

TestFileHelper::~TestFileHelper()
{

}

void TestFileHelper::initTestCase()
{

}

void TestFileHelper::cleanupTestCase()
{

}

void TestFileHelper::test_readAllTxt()
{
//    FileHelper::readAllTxt();
}

QTEST_APPLESS_MAIN(TestFileHelper)

#include "tst_testfilehelper.moc"
