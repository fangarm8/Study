#include <QtTest>
#include "../main-proj/num.h"
#include <math.h>
// add necessary includes here

class num_test : public QObject
{
    Q_OBJECT

public:
    num_test();
    ~num_test();

private slots:
    void initTestCase();
    void cleanupTestCase();
    void test_primary();
    void test_sin();
    void test_sq();
};

num_test::num_test() {}

num_test::~num_test() {}

void num_test::initTestCase() {}

void num_test::cleanupTestCase() {}

void num_test::test_primary() {
    QVector<uint> res_vec = num().PrimaryMultiple(2147483647);
    QCOMPARE(res_vec.size(), 1);
    uint res_mul = 1;
    for (qsizetype i = 0; i < 1; i++) {
        res_mul *= res_vec[i];
    }
    QCOMPARE(res_mul, 2147483647);
    res_vec = num().PrimaryMultiple(2000000000);
    QCOMPARE(res_vec.size(), 19);
    res_mul = 1;
    for (qsizetype i = 0; i < 19; i++) {
        res_mul *= res_vec[i];
    }
}

void num_test::test_sin() {
    num ob;
    double eps = 0.001;
    QVERIFY(abs(ob.sin(1000, eps) - sin(1000)) < eps);
}

void num_test::test_sq() {
    num ob;
    double eps = 0.001;
    QVERIFY((ob.SqEq(1,2,1)[0] + 1) * (ob.SqEq(1,2,1)[0] + 1) < eps);
    QVERIFY((6*ob.SqEq(-6, 5, 1)[0] + 1)*(ob.SqEq(-6, 5, 1)[1] - 1) < eps);
}

QTEST_APPLESS_MAIN(num_test)

#include "tst_num_test.moc"
