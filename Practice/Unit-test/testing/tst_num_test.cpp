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
    QCOMPARE(num(25,5).NOD(), 5);
    QCOMPARE(num(53, 4).NOD(), 4);
}

QTEST_APPLESS_MAIN(num_test)

#include "tst_num_test.moc"
