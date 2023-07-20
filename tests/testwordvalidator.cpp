#include "testwordvalidator.h"

void TestWordValidator::isValid()
{
    lib::WordValidator validator;
    QVERIFY(validator.isValid("") == false);
    QVERIFY(validator.isValid("a") == false);
    QVERIFY(validator.isValid("ads") == false);
    QVERIFY(validator.isValid("fire") == true);
    QVERIFY(validator.isValid("pain") == true);
    QVERIFY(validator.isValid("iliketoeatwaffles") == true);
    QVERIFY(validator.isValid("Fire") == false);
    QVERIFY(validator.isValid("i like to eat") == false);
    QVERIFY(validator.isValid("     ") == false);
    QVERIFY(validator.isValid("abc123") == false);
    QVERIFY(validator.isValid("/?.;'][") == false);
    for (const auto c : "`~-=+_[]\\|';:/?.>,<!@#$%^&*()\"")
        QVERIFY(validator.isValid(QString("fire%1").arg(c)) == false);
}

QTEST_MAIN(TestWordValidator)
