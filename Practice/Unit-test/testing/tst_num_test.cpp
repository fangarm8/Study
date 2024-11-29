#include <QtTest>
#include "../main-proj/num.h"
// add necessary includes here

class num_test : public QObject
{
    Q_OBJECT

public:
    num_test();
    ~num_test();

private slots:
    void testNOD();
};

num_test::num_test() {}

num_test::~num_test() {}

void num_test::testNOD() {
    num tmp(25,5);
    QCOMPARE(tmp.NOD(), 5);
    num tmp1(53, 4);
    QCOMPARE(tmp1.NOD(), 1);
}

QTEST_APPLESS_MAIN(num_test)

#include "tst_num_test.moc"
